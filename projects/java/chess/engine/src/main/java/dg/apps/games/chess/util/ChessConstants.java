package dg.apps.games.chess.util;

/**
 * Various engine-level constants.
 */
public class ChessConstants {
    public static final int MAX_ROW_SIZE = 8;
    public static final int MAX_COL_SIZE = 8;
    public static final int MAX_ROW_INDEX = MAX_ROW_SIZE - 1;
    public static final int MAX_COL_INDEX = MAX_COL_SIZE - 1;

    public static final String BOARD_POSITION_OOB_MESSAGE = "the given board position is out of bounds: ";
    public static final String ILLEGAL_MOVE_REQUEST_BOARD_SPACE_EMPTY = "illegal move request: that space is empty.";
    public static final String ILLEGAL_MOVE_REQUEST_CANNOT_MOVE_TO_THAT_SPACE = "illegal move request: cannot move from ";
    public static final String ILLEGAL_MOVE_REQUEST_NULL = "move request is null.";
    public static final String ILLEGAL_MOVE_REQUEST_NOT_YOUR_TURN = "player cannot move, it is not her turn: ";
    public static final String ILLEGAL_MOVE_REQUEST_CANNOT_MOVE_KING_INTO_CHECK = "cannot move the king into check!";
}
