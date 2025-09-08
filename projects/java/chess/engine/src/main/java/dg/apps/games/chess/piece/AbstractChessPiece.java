package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.move.Move;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.BoardQuadrant;
import dg.apps.games.chess.util.MoveDirection;
import lombok.Getter;
import lombok.Setter;
import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * Base for chess pieces.
 * </p>
 */
@Slf4j
public abstract class AbstractChessPiece {
    @Setter
    @Getter
    protected boolean firstMoveTaken = false;
    @Getter
    protected PlayerAllegiance playerAllegiance;
    @Getter
    protected ChessPieceType chessPieceType;

    /**
     * Get a list of all legal moves possible for this chess piece.
     */
    public abstract List<BoardPosition> getLegalMoves(final BoardPosition currentPosition, final ChessBoard chessBoard);

    /**
     * Create a new instance.
     */
    protected AbstractChessPiece(final PlayerAllegiance player, final ChessPieceType piece) {
        playerAllegiance = player;
        chessPieceType = piece;
    }

    /**
     * Determine if the given move on the given board is legal.
     */
    public boolean isLegalMove(final Move proposedMove, final ChessBoard chessBoard) {
        final List<BoardPosition> legalMoves = getLegalMoves(proposedMove.getStartPosition(), chessBoard);
        return (legalMoves.contains(proposedMove.getEndPosition()));
    }

    /**
     * Calculate the future/potential board position of a piece.
     */
    protected List<BoardPosition> calculateBoardPositionDiagonalForward(final BoardPosition startingPosition, final int forwardAmount, final PlayerAllegiance player) {
        List<BoardPosition> positions = new ArrayList<BoardPosition>();
        try {
            BoardPosition left = null;
            BoardPosition right = null;
            if (PlayerAllegiance.Black.equals(player)) {
                left = calculateBoardPositionDiagonalByQuadrant(startingPosition, forwardAmount, BoardQuadrant.III);
                right = calculateBoardPositionDiagonalByQuadrant(startingPosition, forwardAmount, BoardQuadrant.IV);
            } else if (PlayerAllegiance.White.equals(player)) {
                left = calculateBoardPositionDiagonalByQuadrant(startingPosition, forwardAmount, BoardQuadrant.II);
                right = calculateBoardPositionDiagonalByQuadrant(startingPosition, forwardAmount, BoardQuadrant.I);
            }
            if (left != null) positions.add(left);
            if (right != null) positions.add(right);
        } catch (Exception ex) {
            log.trace(ex.getClass().getSimpleName() + ": " + ex.getMessage());
            positions.clear();
        }
        return positions;
    }

    /**
     * Calculate the future/potential board position of a piece.
     */
    protected BoardPosition calculateBoardPositionDiagonalByQuadrant(final BoardPosition startingPosition, final int forwardAmount, final BoardQuadrant boardQuadrant) {
        if (boardQuadrant != null && startingPosition != null) {
            final int startingRow = startingPosition.getRow();
            final int startingCol = startingPosition.getColumn();
            try {
                switch (boardQuadrant) {
                    case I:
                        return new BoardPosition(startingRow - forwardAmount, startingCol + forwardAmount);
                    case II:
                        return new BoardPosition(startingRow - forwardAmount, startingCol - forwardAmount);
                    case III:
                        return new BoardPosition(startingRow + forwardAmount, startingCol - forwardAmount);
                    case IV:
                        return new BoardPosition(startingRow + forwardAmount, startingCol + forwardAmount);
                }
            } catch (Exception ex) {
                //
            }
        }
        return null;
    }

    /**
     * Calculate the future/potential board position of a piece.
     */
    protected BoardPosition calculateBoardPositionStraightByDirection(final BoardPosition startingPosition, final int moveAmount, final PlayerAllegiance playerAllegiance, final MoveDirection moveDirection) {
        try {
            final int inputRow = startingPosition.getRow();
            final int inputColumn = startingPosition.getColumn();
            if (PlayerAllegiance.Black.equals(playerAllegiance)) {
                switch (moveDirection) {
                    case forward:
                        return new BoardPosition(inputRow + moveAmount, inputColumn);
                    case backward:
                        return new BoardPosition(inputRow - moveAmount, inputColumn);
                    case left:
                        return new BoardPosition(inputRow, inputColumn + moveAmount);
                    case right:
                        return new BoardPosition(inputRow, inputColumn - moveAmount);
                }
            } else if (PlayerAllegiance.White.equals(playerAllegiance)) {
                switch (moveDirection) {
                    case forward:
                        return new BoardPosition(inputRow - moveAmount, inputColumn);
                    case backward:
                        return new BoardPosition(inputRow + moveAmount, inputColumn);
                    case left:
                        return new BoardPosition(inputRow, inputColumn - moveAmount);
                    case right:
                        return new BoardPosition(inputRow, inputColumn + moveAmount);
                }
            }
        } catch (Exception ex) {
            //
        }
        return null;
    }
}
