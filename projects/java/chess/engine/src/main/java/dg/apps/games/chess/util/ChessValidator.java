package dg.apps.games.chess.util;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.move.MoveHistory;
import dg.apps.games.chess.board.move.MoveRequest;
import dg.apps.games.chess.exception.IllegalMoveRequestException;
import dg.apps.games.chess.player.PlayerAllegiance;

/**
 * <p>
 * Various game state validators.
 * </p>
 */
public class ChessValidator {
    /**
     * Validate a move request.
     */
    public static void validateMoveRequest(final MoveRequest moveRequest, final PlayerAllegiance currentPlayerTurn, final MoveHistory moveHistory) {
        validateMoveRequestStructure(moveRequest);
        validatePlayerTurn(moveRequest, currentPlayerTurn);
        validateMoveRequestNotIntoCheck(moveHistory, moveRequest);
    }

    /**
     * Validate a move request structure.
     */
    private static void validateMoveRequestStructure(final MoveRequest moveRequest) {
        if (moveRequest == null || moveRequest.getMove() == null || moveRequest.getMove().getPlayerThatMoved() == null)
            throw new IllegalMoveRequestException(ChessConstants.ILLEGAL_MOVE_REQUEST_NULL);
    }

    /**
     * Validate a player turn.
     */
    private static void validatePlayerTurn(final MoveRequest moveRequest, final PlayerAllegiance currentPlayerTurn) {
        if (!currentPlayerTurn.equals(moveRequest.getMove().getPlayerThatMoved()))
            throw new IllegalMoveRequestException(ChessConstants.ILLEGAL_MOVE_REQUEST_NOT_YOUR_TURN + moveRequest.getMove().getPlayerThatMoved());
    }

    /**
     * Validate that the given move request isn't moving into check.
     */
    private static void validateMoveRequestNotIntoCheck(final MoveHistory moveHistory, final MoveRequest moveRequest) {
        ChessBoard hypotheticalChessBoard = new ChessBoard(moveHistory, moveRequest);
        if (isKingInCheck(hypotheticalChessBoard))
            throw new IllegalMoveRequestException(ChessConstants.ILLEGAL_MOVE_REQUEST_CANNOT_MOVE_KING_INTO_CHECK);
    }

    /**
     * Determine if the King is in check.
     */
    public static boolean isKingInCheck(final ChessBoard chessBoard) {
        // TODO: implement me
        return false;
    }
}
