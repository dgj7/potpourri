package dg.apps.games.chess;

import dg.apps.games.chess.board.BoardSpace;
import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.move.MoveHistory;
import dg.apps.games.chess.board.move.MoveRequest;
import dg.apps.games.chess.exception.IllegalMoveRequestException;
import dg.apps.games.chess.piece.AbstractChessPiece;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.ChessConstants;
import dg.apps.games.chess.util.ChessValidator;
import lombok.Getter;
import lombok.ToString;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * Store the state of an in-progress game.
 * </p>
 */
@Slf4j
@ToString
public class ChessGame {
    private final List<AbstractChessPiece> slainChessPieces = new ArrayList<AbstractChessPiece>();
    private final MoveHistory moveHistory = new MoveHistory();
    private final ChessBoard chessBoard = new ChessBoard();

    @Getter
    private PlayerAllegiance currentPlayerTurn = PlayerAllegiance.White;

    /**
     * Create a new instance.
     */
    public ChessGame() {
        log.debug("created instance.");
    }

    /**
     * Accept a move request; this is the main game change method.
     */
    public void requestMove(final MoveRequest moveRequest) {
        ChessValidator.validateMoveRequest(moveRequest, currentPlayerTurn, moveHistory);

        final BoardSpace fromBoardSpace = chessBoard.getBoardSpace(moveRequest.getMove().getStartPosition());
        final AbstractChessPiece chessPiece = fromBoardSpace.getChessPiece();

        if (chessPiece == null)
            throw new IllegalMoveRequestException(ChessConstants.ILLEGAL_MOVE_REQUEST_BOARD_SPACE_EMPTY);
        if (chessPiece.isLegalMove(moveRequest.getMove(), chessBoard)) {
            final BoardSpace toBoardSpace = chessBoard.getBoardSpace(moveRequest.getMove().getEndPosition());
            final AbstractChessPiece pieceInDestinationSpace = toBoardSpace.getChessPiece();
            final AbstractChessPiece movingPiece = fromBoardSpace.getChessPiece();

            /* 1. if any piece is in the destination, we need to remove it (and potentially record it's death somewhere */
            if (pieceInDestinationSpace != null) {
                slainChessPieces.add(pieceInDestinationSpace);
                log.info("oh no! chess piece [" + pieceInDestinationSpace.toString() + " was slain by " + movingPiece.toString());
            }
            toBoardSpace.setChessPiece(null);

            /* 2. the space previously occupied by the source piece is now empty */
            fromBoardSpace.setChessPiece(null);

            /* 3. the destination space should now house the source piece */
            toBoardSpace.setChessPiece(movingPiece);

            /* 4. record the move, and set some other recording fields */
            moveHistory.addMove(moveRequest.getMove());
            movingPiece.setFirstMoveTaken(true);

            /* 5. increment turn */
            incrementTurn();
        } else {
            throw new IllegalMoveRequestException(ChessConstants.ILLEGAL_MOVE_REQUEST_CANNOT_MOVE_TO_THAT_SPACE + moveRequest.getMove().getStartPosition().toString() + " to " + moveRequest.getMove().getEndPosition().toString());
        }
    }

    /**
     * Update to be the next player's turn.
     */
    private void incrementTurn() {
        if (PlayerAllegiance.White.equals(currentPlayerTurn))
            currentPlayerTurn = PlayerAllegiance.Black;
        else if (PlayerAllegiance.Black.equals(currentPlayerTurn))
            currentPlayerTurn = PlayerAllegiance.White;
    }
}
