package dg.apps.games.chess.board;

import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.piece.AbstractChessPiece;
import dg.apps.games.chess.piece.ChessPieceType;
import dg.apps.games.chess.player.PlayerAllegiance;
import lombok.Getter;
import lombok.Setter;

/**
 * <p>
 * Storage for all known information about a board space.
 * </p>
 * <p>
 * Includes:
 * <ul>
 *     <li>the board position, incluiding row/column</li>
 *     <li>the chess piece, if one is in the space</li>
 * </ul>
 * </p>
 */
@Getter
public class BoardSpace {
    private final BoardPosition boardPosition;
    @Setter
    private AbstractChessPiece chessPiece = null;

    public BoardSpace(final int row, final int col) {
        boardPosition = new BoardPosition(row, col);
    }

    /**
     * Determine the chess piece type, if available.
     */
    public ChessPieceType determineChessPieceType() {
        if (chessPiece == null)
            return ChessPieceType.Empty;
        return chessPiece.getChessPieceType();
    }

    /**
     * Determine the chess piece's owner/player.
     */
    public PlayerAllegiance determineChessPieceOwnerPlayer() {
        if (chessPiece == null)
            return PlayerAllegiance.None;
        return chessPiece.getPlayerAllegiance();
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(boardPosition);
        sb.append("(hash=");
        sb.append(boardPosition.hashCode());
        sb.append(")-");
        sb.append(determineChessPieceOwnerPlayer());
        sb.append(".");
        sb.append(determineChessPieceType());
        return sb.toString();
    }
}
