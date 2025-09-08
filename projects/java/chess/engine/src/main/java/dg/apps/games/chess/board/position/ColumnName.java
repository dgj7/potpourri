package dg.apps.games.chess.board.position;

import lombok.Getter;

/**
 * <p>
 * The column names.
 * </p>
 */
// todo: is this needed?  potentially remove.
public enum ColumnName {
    A("A"),
    B("B"),
    C("C"),
    D("D"),
    E("E"),
    F("F"),
    G("G"),
    H("H"),
    ;

    @Getter
    private final String name;

    /**
     * Create a new instance.
     */
    ColumnName(final String pName) {
        name = pName;
    }
}
