#include "ChessBoard.hh"
#include "PawnPiece.hh"

using Student::PawnPiece;

PawnPiece::PawnPiece(ChessBoard &board, Color color, int row, int column)
        : ChessPiece(board, color, row, column), _row(row), _col(column), _num_move(0), _board(board), _color(color) {
            _forward = (color == White) ? -1 : 1;
        }

Type get_type() {
    return Pawn;
}

void PawnPiece::setPosition(int row, int column) {
    ChessPiece::setPosition(row, column);
    
    _row = row;
    _col = column;
    _num_move += 1;
}

bool PawnPiece::canMoveToLocation(int toRow, int toColumn) {
    int max_row = _board.getNumRows();
    int max_col = _board.getNumCols();
    if (toRow >= max_row || toColumn >= max_col
        || toRow < 0 || toColumn < 0) return false; // moveing to off map

    if (toRow == _row + _forward && abs(toColumn - _col) == 1){
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
        int move1 = _row + _forward;
        if (move1 >= 0 && move1 < max_row && _board.getPiece(_row + _forward, _col) != nullptr) return false; // move blocked

        if (toRow == _row + _forward * 2 && toColumn == _col) {
            int move2 = _row + 2 * _forward;
            bool is_double_row = _row == (_color == White ? max_row - 2 : 1);
            return (is_double_row && move2 >= 0 && move2 < max_row && _board.getPiece(_row + 2 * _forward, _col) == nullptr);
            // return (_num_move == 0 && is_double_row && move2 >= 0 && move2 < max_row && _board.getPiece(_row + 2 * _forward, _col) == nullptr);
        }
        else {
            return (toRow == _row + _forward && toColumn == _col);
        }
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