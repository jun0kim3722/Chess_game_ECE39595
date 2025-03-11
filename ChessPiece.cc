#include "ChessPiece.hh"

using Student::ChessPiece;


ChessPiece::ChessPiece(ChessBoard &board, Color color, int row, int column) {
    _color = color;
    _row = row;
    _col = column;
}

Color ChessPiece::getColor() {
    return _color;
}

Type ChessPiece::getType() {
    return Pawn;
}

int ChessPiece::getRow() {
    return _row;
}

int ChessPiece::getColumn() {
    return _col;
}

void ChessPiece::setPosition(int row, int column) {
    _row = row;
    _col = column;
};
