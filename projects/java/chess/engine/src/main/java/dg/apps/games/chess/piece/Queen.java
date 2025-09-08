package dg.apps.games.chess.piece;

import dg.apps.games.chess.board.ChessBoard;
import dg.apps.games.chess.board.position.BoardPosition;
import dg.apps.games.chess.player.PlayerAllegiance;

import java.util.ArrayList;
import java.util.List;

public class Queen extends AbstractChessPiece {
    /**
     * Create a new instance.
     */
    public Queen(PlayerAllegiance player) {
        super(player, ChessPieceType.Queen);
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public List<BoardPosition> getLegalMoves(BoardPosition currentPosition, ChessBoard chessBoard) {
        final List<BoardPosition> moves = new ArrayList<BoardPosition>();
        //
        return moves;
    }
}
