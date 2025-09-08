package dg.apps.games.chess.exception;

/**
 * <p>
 * Complain when a potential board position is out of bounds.
 * </p>
 */
public class BoardPositionOutOfBoundsException extends RuntimeException {
    private static final long serialVersionUID = 3867458727940697152L;

    /**
     * Create a new instance.
     */
    public BoardPositionOutOfBoundsException(final String message) {
        super(message);
    }
}
