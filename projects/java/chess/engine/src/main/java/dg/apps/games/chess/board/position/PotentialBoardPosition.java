package dg.apps.games.chess.board.position;

import lombok.Getter;

/**
 * <p>
 * A potential board position.
 * </p>
 * <p>
 * This class differes from {@link BoardPosition} in that it
 * isn't verified upon creation.
 * </p>
 */
// todo: is this needed?  can this just be Pair<Integer,Integer>?
@Getter
public class PotentialBoardPosition {
    private final int row;
    private final int column;

    public PotentialBoardPosition(final int r, final int c) {
        row = r;
        column = c;
    }
}
