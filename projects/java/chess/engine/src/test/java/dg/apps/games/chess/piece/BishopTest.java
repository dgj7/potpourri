package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.player.PlayerAllegiance;
import org.junit.Test;

import java.util.List;

public class BishopTest extends AbstractChessPieceTest {
    @Test
    public final void testBlackBishopOriginC8() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.C8, chessBoardOrigin);

        validateList(positions, 0);
    }

    @Test
    public final void testBlackBishopOriginF8() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.F8, chessBoardOrigin);

        validateList(positions, 0);
    }

    @Test
    public final void testWhiteBishopOriginC1() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.C1, chessBoardOrigin);

        validateList(positions, 0);
    }

    @Test
    public final void testWhiteBishopOriginF1() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.F1, chessBoardOrigin);

        validateList(positions, 0);
    }

    @Test
    public final void testWhiteBishopC8() {
        final ChessBoard chessBoard = new ChessBoard();

        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.D7, PositionName.D6, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.A2, PositionName.A3, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.C8, PositionName.E6, chessBoard);

        final List<BoardPosition> positions = createLegalMovesList(PositionName.E6, chessBoard);

        validateList(positions, 9);

        /* QII */
        validateLegalMove(positions, PositionName.D7);
        validateLegalMove(positions, PositionName.C8);

        /* QIII */
        validateLegalMove(positions, PositionName.D5);
        validateLegalMove(positions, PositionName.C4);
        validateLegalMove(positions, PositionName.B3);
        validateLegalMove(positions, PositionName.A2);

        /* QIV */
        validateLegalMove(positions, PositionName.F5);
        validateLegalMove(positions, PositionName.G4);
        validateLegalMove(positions, PositionName.H3);
    }
}