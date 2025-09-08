package dg.apps.games.chess.board;

import dg.apps.games.chess.board.move.MoveHistory;
import dg.apps.games.chess.board.move.MoveRequest;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.piece.AbstractChessPiece;
import dg.apps.games.chess.player.PlayerAllegiance;
import dg.apps.games.chess.util.ChessConstants;
import dg.apps.games.chess.util.ChessFactory;

import java.util.HashMap;
import java.util.Map;

/**
 * <p>
 * Representation of the chess board.
 * </p>
 * <p>
 * Implemented as a mapping/array from board positions to board spaces.
 * </p>
 */
public class ChessBoard {
    private final Map<BoardPosition, BoardSpace> board = new HashMap<BoardPosition, BoardSpace>();

    /**
     * Create a new instance.
     */
    public ChessBoard() {
        for (int row = 0; row < ChessConstants.MAX_ROW_SIZE; row++) {
            for (int col = 0; col < ChessConstants.MAX_COL_SIZE; col++) {
                BoardSpace space = new BoardSpace(row, col);
                PositionName positionName = PositionName.derivePositionName(row, col);
                AbstractChessPiece piece = ChessFactory.createChessPiece(positionName);
                space.setChessPiece(piece);
                board.put(space.getBoardPosition(), space);
            }
        }
    }

    /**
     * Create a new instance.
     */
    public ChessBoard(final MoveHistory moveHistory, final MoveRequest moveRequest) {
        // todo: implement this
    }

    /**
     * <p>
     * Get the {@link BoardSpace} linked to the given {@link BoardPosition}, if one exists.
     * </p>
     */
    public BoardSpace getBoardSpace(final BoardPosition boardPosition) {
        BoardSpace boardSpace = null;
        if (boardPosition != null) {
            boardSpace = board.get(boardPosition);
        }
        return boardSpace;
    }

    /**
     * Determine if the given board position is occupied.
     */
    // todo: potentially replace this (& method below) with something that returns Optional<AbstractChessPiece>
    public boolean isBoardSpaceOccupied(final BoardPosition boardPosition) {
        BoardSpace boardSpace = null;
        if (boardPosition != null) {
            boardSpace = board.get(boardPosition);
        }

        if (boardSpace != null && boardSpace.getChessPiece() != null)
            return true;
        return false;
    }

    /**
     * Determine if the given board position is occupied, by the enemy.\
     */
    // todo: potentially replace this (& method above) with something that returns Optional<AbstractChessPiece>
    public boolean isBoardSpaceOccupiedByEnemy(final BoardPosition boardPosition, final PlayerAllegiance player) {
        BoardSpace boardSpace = null;
        if (boardPosition != null) {
            boardSpace = board.get(boardPosition);
        }

        if (boardSpace != null && boardSpace.getChessPiece() != null && boardSpace.getChessPiece().getPlayerAllegiance() != null && player != null)
            if (player.isEnemy(boardSpace.getChessPiece().getPlayerAllegiance()))
                return true;
        return false;
    }
}
