package dg.apps.games.chess.exception;

/**
 * <p>
 * Complain when an illegal move is requested.
 * </p>
 */
public class IllegalMoveRequestException extends RuntimeException {
    private static final long serialVersionUID = -7012834825328744123L;

    /**
     * Create a new instance.
     */
    public IllegalMoveRequestException(final String message) {
        super(message);
    }
}
