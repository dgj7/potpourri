package dg.apps.games.chess.piece;

import lombok.Getter;

/**
 * <p>
 * Chess piece types.
 * </p>
 */
public enum ChessPieceType {
    Pawn("P"),
    Rook("R"),
    Knight("N"),
    Bishop("B"),
    Queen("Q"),
    King("K"),
    Empty("E"),
    ;

    @Getter
    private final String description;

    /**
     * Create a new instance.
     */
    ChessPieceType(final String desc) {
        description = desc;
    }
}
