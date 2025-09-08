package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PotentialBoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;

import java.util.ArrayList;
import java.util.List;

/**
 * Knight chess piece.
 */
public class Knight extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public Knight(PlayerAllegiance player) {
        super(player, ChessPieceType.Knight);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<BoardPosition> getLegalMoves(BoardPosition currentPosition, ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<>();
        final List<PotentialBoardPosition> positionsToTry = getPotentialKnightMoves();

        for (PotentialBoardPosition potential : positionsToTry) {
            try {
                final BoardPosition position = new BoardPosition(currentPosition.getRow() + potential.getRow(), currentPosition.getColumn() + potential.getColumn());

                /* if the space has an enemy or is empty, then it is a legal move */
                if (chessBoard.isBoardSpaceOccupiedByEnemy(position, getPlayerAllegiance()) || !chessBoard.isBoardSpaceOccupied(position))
                    moves.add(position);
            } catch (Exception ex) {
                // no problem - just happens to be an out-of-bounds move, ignore it
            }
        }

        return moves;
    }

    /**
     * Find all the (mathematically) possible moves; they may not be legal.
     */
    protected List<PotentialBoardPosition> getPotentialKnightMoves() {
        final List<PotentialBoardPosition> positionsToTry = new ArrayList<PotentialBoardPosition>();

        /* above */
        positionsToTry.add(new PotentialBoardPosition(-2, -1));
        positionsToTry.add(new PotentialBoardPosition(-2, +1));

        /* right */
        positionsToTry.add(new PotentialBoardPosition(-1, +2));
        positionsToTry.add(new PotentialBoardPosition(+1, +2));

        /* below */
        positionsToTry.add(new PotentialBoardPosition(+2, -1));
        positionsToTry.add(new PotentialBoardPosition(+2, +1));

        /* left */
        positionsToTry.add(new PotentialBoardPosition(-1, -2));
        positionsToTry.add(new PotentialBoardPosition(+1, -2));

        return positionsToTry;
    }
}
