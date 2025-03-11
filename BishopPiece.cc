#include "BishopPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::BishopPiece;

BishopPiece::BishopPiece(ChessBoard &board, Color color, int row, int col) 
    : ChessPiece(board, color, row, col), _board(board)
{
    _row = row;
    _col = col;
    _color = color;
}

Type BishopPiece::getType()
{
    return Bishop;
}

bool BishopPiece::canMoveToLocation(int toRow, int toCol)
{
    if (abs(getRow() - toRow) != abs(getColumn() - toCol))
    {
        return false;
    }

    int rowDirection = (toRow > getRow()) ? 1 : -1;
    int colDirection = (toCol > getColumn()) ? 1 : -1;

    for (int i = 1; i < abs(getRow() - toRow); i++)
    {
        if (_board.getPiece(getRow() + i * rowDirection, getColumn() + i * colDirection) != nullptr)
        {
            return false;
        }
    }

    ChessPiece* destinationPiece = _board.getPiece(toRow, toCol);
    if (destinationPiece == nullptr || destinationPiece->getColor() != _color)
    {
        return true;
    }

    return false;
}

const char *BishopPiece::toString()
{
    return (getColor() == White) ? u8"\u2657" : u8"\u265D";
}
