package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.BoardSpace;
import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.board.position.PositionName;
import dg.apps.games.chess.player.PlayerAllegiance;
import org.junit.Assert;
import org.junit.Before;

import java.util.ArrayList;
import java.util.List;

public abstract class AbstractChessPieceTest {
    protected ChessBoard chessBoardOrigin = null;

    @Before
    public void setUp() throws Exception {
        chessBoardOrigin = new ChessBoard();
    }

    protected List<BoardPosition> createLegalMovesList(final PositionName positionName, final ChessBoard chessBoard) {
        final BoardPosition boardPosition = new BoardPosition(positionName.getRow(), positionName.getColumn());
        final BoardSpace boardSpace = chessBoard.getBoardSpace(boardPosition);
        final AbstractChessPiece chessPiece = boardSpace.getChessPiece();
        return chessPiece.getLegalMoves(boardPosition, chessBoard);
    }

    protected void validateList(final List<BoardPosition> positions, final int expectedSize) {
        Assert.assertNotNull(positions);
        Assert.assertEquals(expectedSize, positions.size());
    }

    protected void validateLegalMove(final List<BoardPosition> positions, final PositionName positionName) {
        Assert.assertNotNull(positions);
        Assert.assertNotNull(positionName);
        final List<BoardPosition> matchingPositions = new ArrayList<BoardPosition>(0);
        for (BoardPosition boardPosition : positions) {
            if (boardPosition != null)
                if (positionName.getRow() == boardPosition.getRow() && positionName.getColumn() == boardPosition.getColumn())
                    matchingPositions.add(boardPosition);
        }

        Assert.assertNotNull(matchingPositions);
        Assert.assertEquals(1, matchingPositions.size());
        Assert.assertNotNull(matchingPositions.get(0));
        Assert.assertEquals(positionName.getRow(), matchingPositions.get(0).getRow());
        Assert.assertEquals(positionName.getColumn(), matchingPositions.get(0).getColumn());
    }

    protected void executeMoveAgainstBoard(final PlayerAllegiance player, final PositionName fromPosName, final PositionName toPosName, final ChessBoard chessBoard) {
        final BoardPosition fromPosition = new BoardPosition(fromPosName);
        final BoardSpace fromSpace = chessBoard.getBoardSpace(fromPosition);

        final BoardPosition toPosition = new BoardPosition(toPosName);
        final BoardSpace toSpace = chessBoard.getBoardSpace(toPosition);

        final AbstractChessPiece chessPiece = fromSpace.getChessPiece();

        fromSpace.setChessPiece(null);
        toSpace.setChessPiece(chessPiece);
    }
}