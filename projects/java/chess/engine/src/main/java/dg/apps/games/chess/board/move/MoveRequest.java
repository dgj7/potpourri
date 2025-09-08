package dg.apps.games.chess.board.move;

import lombok.Getter;

/**
 * <p>
 * Request from a user to the server to make a move.
 * </p>
 * <p>
 * Remember that {@link Move} contains (but isnt limited to):
 * <ul>
 *     <li>when the move was made</li>
 *     <li>the desired move coordinates</li>
 *     <li>which player is attempting to move</li>
 * </ul>
 * </p>
 */
@Getter
public class MoveRequest {
    private final Move move;

    /**
     * Create a new instance.
     */
    public MoveRequest(final Move pMove) {
        move = pMove;
    }
}
