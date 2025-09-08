package dg.apps.games.chess.board.move;

import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;
import lombok.Getter;

import java.time.LocalDateTime;

/**
 * <p>
 * A single move for a game piece.
 * </p>
 */
@Getter
public class Move {
    private final LocalDateTime when;
    private final PlayerAllegiance playerThatMoved;
    private final BoardPosition startPosition;
    private final BoardPosition endPosition;

    /**
     * Create a new instance.
     */
    public Move(final LocalDateTime pWhen, final PlayerAllegiance player, final BoardPosition start, final BoardPosition end) {
        when = pWhen;
        playerThatMoved = player;
        startPosition = start;
        endPosition = end;
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(playerThatMoved.name());
        sb.append(" from ");
        sb.append(startPosition);
        sb.append(" to ");
        sb.append(endPosition);
        return sb.toString();
    }
}
