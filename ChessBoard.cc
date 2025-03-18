#include "ChessBoard.hh"
#include "PawnPiece.hh"
#include "RookPiece.hh"
#include "BishopPiece.hh"
#include "KingPiece.hh"
#include <iostream>

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

// need to chagne isValidMove function to check
// if the King is under threat after the move

bool ChessBoard::KingSafety(int toRow, int toCol, Color kingColor) {
    int currRow = -1, currCol = -1;
    ChessPiece* kingPiece = nullptr;

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            ChessPiece *piece = getPiece(row, col);
            if (piece != nullptr && piece->getType() == King && piece->getColor() == kingColor) {
                currRow = row;
                currCol = col;
                kingPiece = piece;
            }
        }
    }

    if (toRow >= 0 && toCol >= 0) {
        currRow = toRow;
        currCol = toCol;
    }

    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            ChessPiece *piece = getPiece(row, col);
            if (piece != nullptr && piece->getColor() != kingColor) {
                if (piece->canMoveToLocation(currRow, currCol)) {
                    return false;
                }
            }
        }
    }

    int kingMoves[8][2] = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1},
        {-1, -1}, {1, -1}, {-1, 1}, {1, 1}
    };

    for (int i = 0; i < 8; i++) {
        int newRow = currRow + kingMoves[i][0];
        int newCol = currCol + kingMoves[i][1];

        if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols) {
            ChessPiece* adjacentPiece = getPiece(newRow, newCol);
            if (adjacentPiece != nullptr && adjacentPiece->getType() == King && adjacentPiece->getColor() != kingColor) {
                return false;
            }
        }
    }

    return true;
}

// need to check both canMoveToLocation and KingSafety
bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece *piece = getPiece(fromRow, fromColumn);
    
    if (piece == nullptr) return false;

    if (!piece->canMoveToLocation(toRow, toColumn)) {
        return false;
    }

    if (piece->getType() == King && !KingSafety(toRow, toColumn, piece->getColor())) {
        return false;
    }
    return true;
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

bool ChessBoard::isValidScan() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            ChessPiece* piece = getPiece(row, col);
            if (piece != nullptr) {
                std::cout << "\nChecking " << "(" << row << "," << col << ")...\n";

                for (int targetRow = 0; targetRow < numRows; targetRow++) {
                    for (int targetCol = 0; targetCol < numCols; targetCol++) {
                        if (isValidMove(row, col, targetRow, targetCol)) {
                            std::cout << "can move to (" 
                                      << targetRow << "," << targetCol << ")\n";
                        } else {
                            std::cout << "cannot move to (" 
                                      << targetRow << "," << targetCol << ")\n";
                        }
                    }
                }
            }
        }
    }
    return true;
}

