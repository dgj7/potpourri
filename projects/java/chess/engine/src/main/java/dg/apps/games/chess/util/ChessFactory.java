package dg.apps.games.chess.util;

import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.piece.*;
import dg.apps.games.chess.player.PlayerAllegiance;

/**
 * <p>
 * Factory of chess pieces, based on their starting positions.
 * </p>
 */
public class ChessFactory {
    /**
     * Create chess pieces, based on their position.
     */
    public static AbstractChessPiece createChessPiece(final PositionName positionName) {
        switch (positionName) {
            case A8:
            case H8:
                return new Rook(PlayerAllegiance.Black);

            case B8:
            case G8:
                return new Knight(PlayerAllegiance.Black);

            case C8:
            case F8:
                return new Bishop(PlayerAllegiance.Black);

            case D8:
                return new Queen(PlayerAllegiance.Black);
            case E8:
                return new King(PlayerAllegiance.Black);

            case A7:
            case B7:
            case C7:
            case D7:
            case E7:
            case F7:
            case G7:
            case H7:
                return new Pawn(PlayerAllegiance.Black);

            case A2:
            case B2:
            case C2:
            case D2:
            case E2:
            case F2:
            case G2:
            case H2:
                return new Pawn(PlayerAllegiance.White);

            case D1:
                return new Queen(PlayerAllegiance.White);
            case E1:
                return new King(PlayerAllegiance.White);

            case C1:
            case F1:
                return new Bishop(PlayerAllegiance.White);

            case B1:
            case G1:
                return new Knight(PlayerAllegiance.White);

            case A1:
            case H1:
                return new Rook(PlayerAllegiance.White);

            default:
                return null;
        }
    }
}
