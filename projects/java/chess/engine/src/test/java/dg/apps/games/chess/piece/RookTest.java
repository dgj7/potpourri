package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.player.PlayerAllegiance;
import org.junit.Test;

import java.util.List;

public class RookTest extends AbstractChessPieceTest {
    @Test
    public final void testBlackRookCenterD5() {
        final ChessBoard chessBoard = new ChessBoard();

        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.A8, PositionName.D5, chessBoard);

        final List<BoardPosition> moves = createLegalMovesList(PositionName.D5, chessBoard);

        validateList(moves, 11);

        validateLegalMove(moves, PositionName.D6);

        validateLegalMove(moves, PositionName.C5);
        validateLegalMove(moves, PositionName.B5);
        validateLegalMove(moves, PositionName.A5);

        validateLegalMove(moves, PositionName.D4);
        validateLegalMove(moves, PositionName.D3);
        validateLegalMove(moves, PositionName.D2);

        validateLegalMove(moves, PositionName.E5);
        validateLegalMove(moves, PositionName.F5);
        validateLegalMove(moves, PositionName.G5);
        validateLegalMove(moves, PositionName.H5);
    }

    @Test
    public final void testWhiteRookCenterE4() {
        final ChessBoard chessBoard = new ChessBoard();

        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.H1, PositionName.E4, chessBoard);

        final List<BoardPosition> moves = createLegalMovesList(PositionName.E4, chessBoard);

        validateList(moves, 11);

        validateLegalMove(moves, PositionName.E5);
        validateLegalMove(moves, PositionName.E6);
        validateLegalMove(moves, PositionName.E7);

        validateLegalMove(moves, PositionName.D4);
        validateLegalMove(moves, PositionName.C4);
        validateLegalMove(moves, PositionName.B4);
        validateLegalMove(moves, PositionName.A4);

        validateLegalMove(moves, PositionName.E3);

        validateLegalMove(moves, PositionName.F4);
        validateLegalMove(moves, PositionName.G4);
        validateLegalMove(moves, PositionName.H4);
    }

    @Test
    public final void testBlackRookOriginA8() {
        final List<BoardPosition> moves = createLegalMovesList(PositionName.A8, chessBoardOrigin);
        validateList(moves, 0);
    }

    @Test
    public final void testBlackRookOriginH8() {
        final List<BoardPosition> moves = createLegalMovesList(PositionName.H8, chessBoardOrigin);
        validateList(moves, 0);
    }

    @Test
    public final void testWhiteRookOriginA1() {
        final List<BoardPosition> moves = createLegalMovesList(PositionName.A1, chessBoardOrigin);
        validateList(moves, 0);
    }

    @Test
    public final void testWhiteRookOriginH1() {
        final List<BoardPosition> moves = createLegalMovesList(PositionName.H1, chessBoardOrigin);
        validateList(moves, 0);
    }
}