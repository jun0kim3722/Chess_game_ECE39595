#include "ChessBoard.hh"
#include "PawnPiece.hh"

using Student::PawnPiece;

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column), _row(row), _col(column), _num_move(0), _board(board), _color(color) {
            _forward = color == White ? 1 : -1;
        }

Type get_type() {
    return Pawn;
}

void PawnPiece::setPosition(int row, int column) {
    _row = row;
    _col = column;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
    if (_num_move == 0) {
        return (toRow == _row + _forward * 2);
    }
    else if (toRow == _row + _forward && ((toColumn - _col) * (toColumn - _col)) == _forward){
        ChessPiece *piece = _board.getPiece(toRow, toColumn);

        if (piece != nullptr) {
            Color op_color = piece -> getColor();

            return op_color != _color;
        }
        else {
            return false;
        }
    }
    else {
        return (toRow == _row + _forward);
    }
}

const char *PawnPiece::toString() {
    if (_color == White) {
        return "\u265f";
    }
    else {
        return "\u2659";
    }
}