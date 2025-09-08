package dg.apps.games.chess.board.position;

import dg.apps.games.chess.exception.BoardPositionOutOfBoundsException;
import dg.apps.games.chess.util.ChessConstants;
import lombok.Getter;

/**
 * <p>
 * A position on the game board.
 * </p>
 * <p>
 * Note that this could represent many things, including (but not limited to):
 * <ul>
 *     <li>the position of a potential move, which hasn't taken place yet</li>
 *     <li>the position of a past move</li>
 * </ul>
 * </p>
 */
@Getter
public class BoardPosition {
    private final int row;
    private final int column;

    /**
     * Create a new instance.
     */
    public BoardPosition(final int r, final int c) {
        validate(r, c);
        row = r;
        column = c;
    }

    /**
     * Create a new instance.
     */
    public BoardPosition(final PositionName positionName) {
        final int r = positionName.getRow();
        final int c = positionName.getColumn();
        validate(r, c);
        row = r;
        column = c;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        return PositionName.derivePositionName(row, column).toString();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public boolean equals(final Object object) {
        if (object instanceof BoardPosition right) {
            return (row == right.getRow()) && (column == right.getColumn());
        }
        return false;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public int hashCode() {
        return (row * 100) + column;
    }

    /**
     * Validate the 'proposed' board position - that is, the position supplied to the constructor.
     */
    private void validate(final int r, final int c) {
        if (r > ChessConstants.MAX_ROW_INDEX || c > ChessConstants.MAX_COL_INDEX || r < 0 || c < 0)
            throw new BoardPositionOutOfBoundsException(ChessConstants.BOARD_POSITION_OOB_MESSAGE + this);
    }
}
