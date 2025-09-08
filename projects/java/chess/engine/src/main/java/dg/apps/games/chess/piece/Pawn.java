package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.MoveDirection;

import java.util.ArrayList;
import java.util.List;

public class Pawn extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public Pawn(final PlayerAllegiance player) {
        super(player, ChessPieceType.Pawn);
    }

    /**
     * get all possible moves for this pawn in this position.
     *
     * <ul>
     * <li>pawns may not move backward, only forward
     * <li>on a pawn's first move, it may advance two squares instead of one (unless blocked in either of the two squares directly in front of it)
     * <li>for normal moves, a pawn may move one square directly forward (unless blocked)
     * <li>pawns may capture other pieces only by moving diagonally one space (may NOT move diagonally if not capturing)
     * </ul>
     */
    @Override
    public List<BoardPosition> getLegalMoves(final BoardPosition currentPosition, final ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<BoardPosition>();

        /* get move positions */
        final BoardPosition firstMoveOneSpaceFoward = calculateBoardPositionStraightByDirection(currentPosition, 1, getPlayerAllegiance(), MoveDirection.forward);
        final BoardPosition firstMoveTwoSpacesForward = calculateBoardPositionStraightByDirection(currentPosition, 2, getPlayerAllegiance(), MoveDirection.forward);
        final List<BoardPosition> capturePositions = calculateBoardPositionDiagonalForward(currentPosition, 1, getPlayerAllegiance());

        /* in any case, we can move forward one space if that space is not occupied */
        if (!chessBoard.isBoardSpaceOccupied(firstMoveOneSpaceFoward))
            moves.add(firstMoveOneSpaceFoward);

        /* pawns may move forward two spaces if it's their first move, and neither of the two spaces is occupied */
        if (!firstMoveTaken && !chessBoard.isBoardSpaceOccupied(firstMoveOneSpaceFoward) && !chessBoard.isBoardSpaceOccupied(firstMoveTwoSpacesForward))
            moves.add(firstMoveTwoSpacesForward);

        /* pawns may capture pieces by moving one space diagonally - so if a diagonal space one diagonal is occupied by an enemy, we can move there */
        for (BoardPosition capturePosition : capturePositions)
            if (chessBoard.isBoardSpaceOccupiedByEnemy(capturePosition, getPlayerAllegiance()))
                moves.add(capturePosition);

        return moves;
    }
}
