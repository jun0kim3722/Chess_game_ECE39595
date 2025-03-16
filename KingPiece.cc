#include "KingPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

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

bool KingPiece::canMoveToLocation(int toRow, int toCol)
{
    int rowDirection = abs(getRow() - toRow);
    int colDirection = abs(getColumn() - toCol);
    
    if (rowDirection > 1 || colDirection > 1)
    {
        return false;
    }
    
    ChessPiece* destinationPiece = _board.getPiece(toRow, toCol);
    if (destinationPiece == nullptr || destinationPiece->getColor() != _color)
    {
        return true;
    }
    
    return false;
}

const char *KingPiece::toString()
{
    return (getColor() == White) ? u8"\u2654" : u8"\u265A";
}
