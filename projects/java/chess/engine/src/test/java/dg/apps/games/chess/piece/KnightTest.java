package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.player.PlayerAllegiance;
import org.junit.Test;

import java.util.List;

public class KnightTest extends AbstractChessPieceTest {
    @Test
    public final void testBlackKnightOriginB8() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.B8, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.A6);
        validateLegalMove(positions, PositionName.C6);
    }

    @Test
    public final void testBlackKnightOriginG8() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.G8, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.F6);
        validateLegalMove(positions, PositionName.H6);
    }

    @Test
    public final void testWhiteKnightOriginB1() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.B1, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.A3);
        validateLegalMove(positions, PositionName.C3);
    }

    @Test
    public final void testWhiteKnightOriginG1() {
        final List<BoardPosition> positions = createLegalMovesList(PositionName.G1, chessBoardOrigin);

        validateList(positions, 2);
        validateLegalMove(positions, PositionName.F3);
        validateLegalMove(positions, PositionName.H3);
    }

    @Test
    public final void testBlackKnightE5() {
        final ChessBoard chessBoard = new ChessBoard();
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.A2, PositionName.A3, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.D7, PositionName.D6, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.A3, PositionName.A4, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.F7, PositionName.F6, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.A4, PositionName.A5, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.B8, PositionName.C2, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.H2, PositionName.H3, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.Black, PositionName.C2, PositionName.E5, chessBoard);
        executeMoveAgainstBoard(PlayerAllegiance.White, PositionName.H3, PositionName.H4, chessBoard);

        final List<BoardPosition> positions = createLegalMovesList(PositionName.E5, chessBoard);

        validateList(positions, 8);
        validateLegalMove(positions, PositionName.D7);
        validateLegalMove(positions, PositionName.F7);
        validateLegalMove(positions, PositionName.G6);
        validateLegalMove(positions, PositionName.G4);
        validateLegalMove(positions, PositionName.D3);
        validateLegalMove(positions, PositionName.F3);
        validateLegalMove(positions, PositionName.C6);
        validateLegalMove(positions, PositionName.C4);
    }
}