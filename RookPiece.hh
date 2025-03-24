#ifndef _ROOKPIECE_H__
#define _ROOKPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a Rook chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class RookPiece : public ChessPiece
    {
        public:
            RookPiece(ChessBoard &board, Color color, int row, int col);

            Type getType();

            bool canMoveToLocation(int toRow, int toCol);

            int getNumMoves();

            void setPosition(int row, int column);

            const char *toString();
        private:
            int _row;
            int _col;
            ChessBoard &_board;
            Color _color;
            int _num_move = 0;
    };
}

#endif