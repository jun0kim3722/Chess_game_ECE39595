#ifndef __KINGPIECE_H__
#define __KINGPIECE_H__

#include "ChessPiece.hh"

/**
 * Student implementation of a King chess piece.
 * The class is defined within the Student namespace.
 */
namespace Student
{
    class KingPiece : public ChessPiece
    {
        public:
            KingPiece(ChessBoard &board, Color color, int row, int col);

            Type getType();

            bool isCheckMate();

            bool isCastling(int toRow, int toCol);

            bool canMoveToLocation(int toRow, int toCol);

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
