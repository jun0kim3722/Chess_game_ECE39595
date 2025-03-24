#include "KingPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

#include <iostream>

using Student::KingPiece;

KingPiece::KingPiece(ChessBoard &board, Color color, int row, int col) : ChessPiece(board, color, row, col), _board(board)
{
    _row = row;
    _col = col;
    _color = color;
}

Type KingPiece::getType()
{
    return King;
}

bool KingPiece::isCheckMate() {
    for (int row = 0; row < _board.getNumRows(); row++) {
        for (int col = 0; col < _board.getNumCols(); col++) {
            ChessPiece *opp = _board.getPiece(row, col);
            if (opp != nullptr && opp -> getColor() != _color && opp -> canMoveToLocation(_row, _col)) {
                return true;
            }
        }
    }
    return false;
}

bool KingPiece::isCastling(int toRow, int toCol) {
    int rowMag = abs(getRow() - toRow);
    int colMag = abs(getColumn() - toCol);

    if ((rowMag == 0 || colMag == 0) && (rowMag == 2 || colMag == 2) && _num_move == 0 && !isCheckMate()) {
        int max_rows = _board.getNumRows();
        int max_cols = _board.getNumCols();
        int vec[2] = {(rowMag != 0) ? (toRow - _row) / rowMag : 0, (colMag != 0) ? (toCol - _col) / colMag : 0};
        int rook_pos[2] = {_row + vec[0], _col + vec[1]};
        while (rook_pos[0] < max_rows && rook_pos[1] < max_cols) {
            std::cout << rook_pos[0] << rook_pos[1] << std::endl;
            ChessPiece *piece = _board.getPiece(rook_pos[0], rook_pos[1]);
            if (piece != nullptr) {
                // Find Rook
                if (piece -> getType() == Rook && piece -> getColor() == _color && piece -> getNumMoves() == 0) {
                    return true;
                }
                else {
                    return false;
                }
            }
            rook_pos[0] += vec[0];
            rook_pos[1] += vec[1];
        }
    }
    return false;
}

bool KingPiece::canMoveToLocation(int toRow, int toCol)
{
    int rowMag = abs(getRow() - toRow);
    int colMag = abs(getColumn() - toCol);
    
    if (rowMag > 1 || colMag > 1)
    {
        return isCastling(toRow, toCol);
    }
    
    ChessPiece* destinationPiece = _board.getPiece(toRow, toCol);
    if (destinationPiece == nullptr || destinationPiece->getColor() != _color)
    {
        return true;
    }
    
    return false;
}

void KingPiece::setPosition(int row, int column) {
    ChessPiece::setPosition(row, column);
    
    _row = row;
    _col = column;
    _num_move += 1;
}

const char *KingPiece::toString()
{
    return (getColor() == Black) ? u8"\u2654" : u8"\u265A";
}
