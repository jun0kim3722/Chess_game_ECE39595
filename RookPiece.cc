#include "RookPiece.hh"
#include "ChessBoard.hh"
#include "ChessPiece.hh"

using Student::RookPiece;

RookPiece::RookPiece(ChessBoard &board, Color color, int row, int col) : ChessPiece(board, color, row, col), _board(board)
{
    _row = row;
    _col = col;
    _color = color;
}

Type RookPiece::getType()
{
    return Rook;
}

bool RookPiece::canMoveToLocation(int toRow, int toCol)
{
    if (getRow() != toRow && getColumn() != toCol)
    {
        return false;
    }

    int rowDirection = (toRow > getRow()) ? 1 : (toRow < getRow() ? -1 : 0);
    int colDirection = (toCol > getColumn()) ? 1 : (toCol < getColumn() ? -1 : 0);

    for (int i = 1; i < std::max(abs(getRow() - toRow), abs(getColumn() - toCol)); i++)
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

const char *RookPiece::toString()
{
    return (getColor() == White) ? u8"\u2656" : u8"\u265C";
}
