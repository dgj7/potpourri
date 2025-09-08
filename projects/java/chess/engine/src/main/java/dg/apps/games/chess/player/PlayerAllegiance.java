package dg.apps.games.chess.player;

import lombok.Getter;

/**
 * <p>
 * Enumerate all players; white and black.
 * </p>
 */
public enum PlayerAllegiance {
    Black("B"),
    White("W"),
    None("N"),
    ;

    @Getter
    private final String description;

    /**
     * Create a new instance.
     */
    PlayerAllegiance(final String desc) {
        description = desc;
    }

    /**
     * Determine if the given player allegiance is the enemy.
     */
    public boolean isEnemy(final PlayerAllegiance otherPlayer) {
        if (PlayerAllegiance.Black.equals(this))
            if (PlayerAllegiance.White.equals(otherPlayer))
                return true;

        if (PlayerAllegiance.White.equals(this))
            if (PlayerAllegiance.Black.equals(otherPlayer))
                return true;

        return false;
    }
}
