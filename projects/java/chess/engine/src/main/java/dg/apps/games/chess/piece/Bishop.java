package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.BoardQuadrant;
import dg.apps.games.chess.util.ChessConstants;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * Bishop test piece.
 * </p>
 */
public class Bishop extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public Bishop(PlayerAllegiance player) {
        super(player, ChessPieceType.Bishop);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<BoardPosition> getLegalMoves(BoardPosition currentPosition, ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<>();
        for (BoardQuadrant boardQuadrant : BoardQuadrant.values()) {
            boolean blocked = false;
            boolean enemyPositionPassed = false;
            for (int counter = 1; counter < ChessConstants.MAX_ROW_SIZE; counter++) {
                if (blocked || enemyPositionPassed)
                    break;
                try {
                    BoardPosition boardPosition = calculateBoardPositionDiagonalByQuadrant(currentPosition, counter, boardQuadrant);
                    if (boardPosition == null)
                        break;
                    final boolean isSpaceOccupied = chessBoard.isBoardSpaceOccupied(boardPosition);
                    final boolean isSpaceOccupiedByEnemy = chessBoard.isBoardSpaceOccupiedByEnemy(boardPosition, getPlayerAllegiance());
                    if (!isSpaceOccupied || isSpaceOccupiedByEnemy) {
                        if (isSpaceOccupiedByEnemy)
                            enemyPositionPassed = true;
                        moves.add(boardPosition);
                    } else
                        blocked = true;
                } catch (Exception ex) {
                    // ignore - this is a position option that doesn't work
                    break;
                }
            }
        }
        return moves;
    }
}
