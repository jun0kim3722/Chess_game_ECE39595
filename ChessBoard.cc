
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

    // check castling
    int rowMag = abs(toRow - fromRow);
    int colMag = abs(toColumn - fromColumn);
    if (piece -> getType() == King && (rowMag == 2 || colMag == 2)) {
        int vec[2] = {(rowMag != 0) ? (toRow - fromRow) / rowMag : 0, (colMag != 0) ? (toColumn - fromColumn) / colMag : 0};
        int rook_pos[2] = {fromRow + vec[0], fromColumn + vec[1]};
        while (rook_pos[0] >= 0 && rook_pos[0] < numRows && rook_pos[1] >= 0 && rook_pos[1] < numCols) {
                ChessPiece *rook = getPiece(rook_pos[0], rook_pos[1]);
            if (rook != nullptr) {
                // move Rook in correct place
                int new_pos[2] = {fromRow + vec[0], fromColumn + vec[1]};
                rook -> setPosition(new_pos[0], new_pos[1]);
                rook -> addMove();
                board.at(rook_pos[0]).at(rook_pos[1]) = nullptr;
                board.at(new_pos[0]).at(new_pos[1]) = rook;
                break;
            }
            rook_pos[0] += vec[0];
            rook_pos[1] += vec[1];
        }
    }

    // move piece
    piece -> setPosition(toRow, toColumn);
    piece -> addMove();
    board.at(toRow).at(toColumn) = piece;
    board.at(fromRow).at(fromColumn) = nullptr;

    turn = turn == White ? Black : White; // update turn

    return true;
}

bool ChessBoard::isCheckMate(Color kingColor, int fromRow, int fromColumn, int toRow, int toColumn) {
    // check skip over pos
    int skipPos[2] = {(fromRow + toRow) / 2, (fromColumn + toColumn) / 2};
    for (std::vector<ChessPiece *> row_board : board) {
        for (ChessPiece *opp : row_board) {
            if (opp != nullptr && opp -> getColor() != kingColor &&
                opp -> canMoveToLocation(skipPos[0], skipPos[1])) {
                    return true;
            }
        }
    }
    return isPieceUnderThreat(toRow, toColumn);
}

bool ChessBoard::isCheckMate(Color kingColor) {
    int currRow = -1, currCol = -1;
    for (std::vector<ChessPiece *> row_board : board) {
        for (ChessPiece *piece : row_board) {
            if (piece != nullptr && piece->getType() == King && piece->getColor() == kingColor) {
                currRow = piece -> getRow();
                currCol = piece -> getColumn();
                break;
            }
        }
        if (currRow != -1 || currCol != -1) break;
    }
    if (currRow == -1 || currCol == -1) return false; // No king
    return isPieceUnderThreat(currRow, currCol);
}

bool ChessBoard::isValidMove(int fromRow, int fromColumn, int toRow, int toColumn) {
    ChessPiece *piece = getPiece(fromRow, fromColumn);
    if (piece == nullptr) return false;

    Color piece_color = piece -> getColor();
    if (piece -> canMoveToLocation(toRow, toColumn)) { // Only move when no check
        // check castling
        bool isCastling = false;
        ChessPiece *rook;
        int rook_pos[2];
        int new_pos[2];

        int rowMag = abs(toRow - fromRow);
        int colMag = abs(toColumn - fromColumn);
        if (piece -> getType() == King && (rowMag == 2 || colMag == 2)) {
            int vec[2] = {(rowMag != 0) ? (toRow - fromRow) / rowMag : 0, (colMag != 0) ? (toColumn - fromColumn) / colMag : 0};
            rook_pos[0] = fromRow + vec[0];
            rook_pos[1] = fromColumn + vec[1];
            while (rook_pos[0] >= 0 && rook_pos[0] < numRows && rook_pos[1] >= 0 && rook_pos[1] < numCols) {
                rook = getPiece(rook_pos[0], rook_pos[1]);
                if (rook != nullptr) {
                    // move Rook in correct place
                    isCastling = true;
                    new_pos[0] = fromRow + vec[0];
                    new_pos[1] = fromColumn + vec[1];

                    rook -> setPosition(new_pos[0], new_pos[1]);
                    board.at(rook_pos[0]).at(rook_pos[1]) = nullptr;
                    board.at(new_pos[0]).at(new_pos[1]) = rook;
                    break;
                }
                rook_pos[0] += vec[0];
                rook_pos[1] += vec[1];
            }
        }

        // move piece
        ChessPiece* temp = getPiece(toRow, toColumn);
        piece -> setPosition(toRow, toColumn);
        board.at(toRow).at(toColumn) = piece;
        board.at(fromRow).at(fromColumn) = nullptr;

        bool is_check;
        
        if (isCastling) {
            is_check = isCheckMate(piece_color, fromRow,fromColumn, toRow, toColumn);
        }
        else {
            is_check = isCheckMate(piece_color);
        }


        // restore
        piece -> setPosition(fromRow, fromColumn);
        board.at(toRow).at(toColumn) = temp;
        board.at(fromRow).at(fromColumn) = piece;

        // restore Rook's pos
        if (isCastling) {
            rook -> setPosition(rook_pos[0], rook_pos[1]);
            board.at(rook_pos[0]).at(rook_pos[1]) = rook;
            board.at(new_pos[0]).at(new_pos[1]) = nullptr;
        }

        return !is_check;
    }
    else{
        return false;
    }
}

bool ChessBoard::isPieceUnderThreat(int row, int column) {
    ChessPiece *piece = getPiece(row, column);
    if (piece == nullptr) return false;

    Color tar_color = piece -> getColor();
    for (std::vector<ChessPiece *> row_board : board) {
        for (ChessPiece *opp : row_board) {
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