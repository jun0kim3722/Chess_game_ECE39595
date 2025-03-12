#ifndef __PAWNPIECE_H__
#define __PAWNPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Pawn chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class PawnPiece : public ChessPiece
    {
    public:
        PawnPiece(ChessBoard &board, Color color, int row, int column);

        Type get_type();

        void setPosition(int row, int column);

        bool canMoveToLocation(int toRow, int toColumn);

        const char *toString();


    private:
        int _row;
        int _col;
        int _num_move = 0;
        ChessBoard& _board;
        Color _color;
        int _forward;
    };
}

#endif
