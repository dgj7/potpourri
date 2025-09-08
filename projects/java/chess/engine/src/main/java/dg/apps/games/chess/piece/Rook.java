package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.ChessConstants;
import dg.apps.games.chess.util.MoveDirection;

import java.util.ArrayList;
import java.util.List;

/**
 * Rook chess piece.
 */
public class Rook extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public Rook(PlayerAllegiance player) {
        super(player, ChessPieceType.Rook);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<BoardPosition> getLegalMoves(BoardPosition currentPosition, ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<BoardPosition>();

        for (MoveDirection moveDirection : MoveDirection.values()) {
            boolean blocked = false;
            boolean enemyPositionPassed = false;
            for (int moveAmount = 1; moveAmount < ChessConstants.MAX_COL_SIZE; moveAmount++) {
                if (blocked || enemyPositionPassed)
                    break;
                try {
                    BoardPosition boardPosition = calculateBoardPositionStraightByDirection(currentPosition, moveAmount, getPlayerAllegiance(), moveDirection);
                    if (boardPosition == null)
                        break;
                    final boolean isSpaceOccupied = chessBoard.isBoardSpaceOccupied(boardPosition);
                    final boolean isSpaceOccupiedByEnemy = chessBoard.isBoardSpaceOccupiedByEnemy(boardPosition, getPlayerAllegiance());
                    if (!isSpaceOccupied || isSpaceOccupiedByEnemy) {
                        if (isSpaceOccupiedByEnemy)
                            enemyPositionPassed = true;
                        moves.add(boardPosition);
                    } else {
                        blocked = true;
                    }
                } catch (Exception ex) {
                    // ignore - this is a position option that doesn't work
                    break;
                }
            }
        }

        return moves;
    }
}
