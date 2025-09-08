package dg.apps.games.chess.board.position;

import lombok.Getter;

/**
 * <p>
 * The row names.
 * </p>
 */
// todo: is this needed?  potentially remove.
public enum RowName {
    Eight("8"),
    Seven("7"),
    Six("6"),
    Five("5"),
    Four("4"),
    Three("3"),
    Two("2"),
    One("1"),
    ;

    @Getter
    private final String name;

    /**
     * Create a new instance.
     */
    RowName(final String pName) {
        name = pName;
    }
}
