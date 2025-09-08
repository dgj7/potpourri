package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.BoardQuadrant;
import dg.apps.games.chess.util.MoveDirection;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * King chess piece.
 * </p>
 */
public class King extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public King(PlayerAllegiance player) {
        super(player, ChessPieceType.King);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<BoardPosition> getLegalMoves(final BoardPosition currentPosition, final ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<BoardPosition>();
        final List<BoardPosition> potentials = getPotentialMoves(currentPosition, chessBoard);

        for (BoardPosition potential : potentials) {
            final boolean isSpaceOccupied = chessBoard.isBoardSpaceOccupied(potential);
            final boolean isSpaceOccupiedByEnemy = chessBoard.isBoardSpaceOccupiedByEnemy(potential, getPlayerAllegiance());
            if (!isSpaceOccupied || isSpaceOccupiedByEnemy)
                moves.add(potential);
        }

        return moves;
    }

    /**
     * Find all the (mathematically) possible moves; they may not be legal.
     */
    protected List<BoardPosition> getPotentialMoves(final BoardPosition currentPosition, final ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<BoardPosition>();

        for (MoveDirection moveDirection : MoveDirection.values()) {
            final BoardPosition potentialMove = calculateBoardPositionStraightByDirection(currentPosition, 1, getPlayerAllegiance(), moveDirection);
            if (potentialMove != null)
                moves.add(potentialMove);
        }

        for (BoardQuadrant boardQuadrant : BoardQuadrant.values()) {
            final BoardPosition potentialMove = calculateBoardPositionDiagonalByQuadrant(currentPosition, 1, boardQuadrant);
            if (potentialMove != null)
                moves.add(potentialMove);
        }

        return moves;
    }
}
