package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import org.junit.Test;

import java.util.List;

/**
 * testing completed:
 * 1) black pawn at origin, A-H (all)
 * 2) white pawn at origin, A-H (all)
 * 3) ...
 */
public class PawnTest extends AbstractChessPieceTest {
    @Test
    public final void testBlackPawnOriginA7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.A7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.A6);
        validateLegalMove(positions, PositionName.A5);
    }

    @Test
    public final void testBlackPawnOriginB7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.B7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.B6);
        validateLegalMove(positions, PositionName.B5);
    }

    @Test
    public final void testBlackPawnOriginC7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.C7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.C6);
        validateLegalMove(positions, PositionName.C5);
    }

    @Test
    public final void testBlackPawnOriginD7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.D7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.D6);
        validateLegalMove(positions, PositionName.D5);
    }

    @Test
    public final void testBlackPawnOriginE7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.E7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.E6);
        validateLegalMove(positions, PositionName.E5);
    }

    @Test
    public final void testBlackPawnOriginF7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.F7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.F6);
        validateLegalMove(positions, PositionName.F5);
    }

    @Test
    public final void testBlackPawnOriginG7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.G7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.G6);
        validateLegalMove(positions, PositionName.G5);
    }

    @Test
    public final void testBlackPawnOriginH7() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.H7, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.H6);
        validateLegalMove(positions, PositionName.H5);
    }


    @Test
    public final void testWhitePawnOriginA2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.A2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.A3);
        validateLegalMove(positions, PositionName.A4);
    }

    @Test
    public final void testWhitePawnOriginB2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.B2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.B3);
        validateLegalMove(positions, PositionName.B4);
    }

    @Test
    public final void testWhitePawnOriginC2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.C2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.C3);
        validateLegalMove(positions, PositionName.C4);
    }

    @Test
    public final void testWhitePawnOriginD2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.D2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.D3);
        validateLegalMove(positions, PositionName.D4);
    }

    @Test
    public final void testWhitePawnOriginE2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.E2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.E3);
        validateLegalMove(positions, PositionName.E4);
    }

    @Test
    public final void testWhitePawnOriginF2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.F2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.F3);
        validateLegalMove(positions, PositionName.F4);
    }

    @Test
    public final void testWhitePawnOriginG2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.G2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.G3);
        validateLegalMove(positions, PositionName.G4);
    }

    @Test
    public final void testWhitePawnOriginH2() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.H2, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.H3);
        validateLegalMove(positions, PositionName.H4);
    }
}