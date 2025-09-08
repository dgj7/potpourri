package dg.apps.games.chess.board.move;

import lombok.extern.slf4j.Slf4j;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * <p>
 * All the moves that have happened during this game.
 * </p>
 */
@Slf4j
public class MoveHistory {
    private final Map<Integer, Move> history = new HashMap<>();

    private Integer latestMoveIndex;

    /**
     * Create a new instance.
     */
    public MoveHistory() {
        latestMoveIndex = 0;
        log.debug("created instance.");
    }

    /**
     * Add another move.
     */
    public void addMove(final Move move) {
        if (move != null) {
            history.put(latestMoveIndex, move);
            latestMoveIndex = latestMoveIndex + 1;
            log.info("moved " + move + ".");
        }
    }

    /**
     * Find a specific move.
     */
    public Move findMove(final Integer moveIndex) {
        return history.get(moveIndex);
    }

    /**
     * Find the number of moves so far in the game.
     */
    public Integer countMoves() {
        return history.size();
    }

    /**
     * Get all the moves, as a {@link List}.
     */
    public List<Move> allMoves() {
        List<Move> moves = new ArrayList<>();

        for (Integer index = 0; index < countMoves(); index++) {
            Move move = history.get(index);
            moves.add(move);
        }

        return moves;
    }
}
