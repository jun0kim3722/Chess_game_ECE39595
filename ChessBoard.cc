#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"

using Student::ChessBoard;

ChessBoard::ChessBoard(int numRow, int numCol) {
    board.resize(numRow, std::vector<ChessPiece *>(numCol, nullptr));
    numRows = numRow;
    numCols = numCol;
}

void ChessBoard::createChessPiece(Color col, Type ty, int startRow, int startColumn) {
    delete board.at(startRow).at(startColumn);

    if (ty == Pawn) {
        PawnPiece* newPiece = new PawnPiece(*this, col, startRow, startColumn);
        board.at(startRow).at(startColumn) = newPiece;
    }
    else if (ty == Rook) {
        RookPiece* newPiece = new RookPiece(*this, col, startRow, startColumn);
        board.at(startRow).at(startColumn) = newPiece;
    }
    else if (ty == Bishop) {
        BishopPiece* newPiece = new BishopPiece(*this, col, startRow, startColumn);
        board.at(startRow).at(startColumn) = newPiece;
    }
    else if (ty == King) {
        KingPiece* newPiece = new KingPiece(*this, col, startRow, startColumn);
        board.at(startRow).at(startColumn) = newPiece;
    }
}

bool ChessBoard::movePiece(int fromRow, int fromColumn, int toRow, int toColumn) {
    if (!isValidMove(fromRow, fromColumn, toRow, toColumn)) return false;

    // check Turn
    ChessPiece *piece = getPiece(fromRow, fromColumn);
    Color move_color = piece -> getColor();
    if (move_color != turn) return false;

    ChessPiece* temp = getPiece(toRow, toColumn);
    delete temp; // deleted killed piece
    
    // move piece
    piece -> setPosition(toRow, toColumn);
    board.at(toRow).at(toColumn) = piece;
    board.at(fromRow).at(fromColumn) = nullptr;

    turn = turn == White ? Black : White; // update turn

    return true;
}

// need to consider isPieceUnderThreat during isValidMove function because of King
bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece *piece = getPiece(fromRow, fromColumn);
    
    if (piece == nullptr) return false;
    return piece -> canMoveToLocation(toRow, toColumn);
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
    ChessPiece *piece = getPiece(row, column);
    if (piece == nullptr) return false;

    Color tar_color = piece -> getColor();
    for (std::vector<ChessPiece *> r_board : board) {
        for (ChessPiece *opp : r_board) {
            if (opp != nullptr && opp -> getColor() != tar_color &&
                opp -> canMoveToLocation(row, column)) return true;
        }
    }
    return false;
}


std::ostringstream ChessBoard::displayBoard()
{
    std::ostringstream outputString;
    // top scale
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << i;
    }
    outputString << std::endl
                 << "  ";
    // top border
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl;

    for (int row = 0; row < numRows; row++)
    {
        outputString << row << "|";
        for (int column = 0; column < numCols; column++)
        {
            ChessPiece *piece = board.at(row).at(column);
            outputString << (piece == nullptr ? " " : piece->toString());
        }
        outputString << "|" << std::endl;
    }

    // bottom border
    outputString << "  ";
    for (int i = 0; i < numCols; i++)
    {
        outputString << "-";
    }
    outputString << std::endl
                 << std::endl;

    return outputString;
}