#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>
#include <fstream>

void test_part1_4x4_PawnTest_isValid()
{
    std::cout << "------------Pawn isValid Test-------------" << std::endl;
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    // std::cout << "Pawn White Test" << std::endl;
    Student::ChessBoard sBoard(4, 4);
    std::cout << "\nPawn White Test--" << std::endl;
    sBoard.createChessPiece(White, Pawn, 2, 2);
    if (!(1 == sBoard.isValidMove(2,2, 1,2))) std::cout<< "Failed1" << std::endl; // move 1 up
    if (!(1 == sBoard.isValidMove(2,2, 0,2))) std::cout<< "Failed2" << std::endl; // move 2 up
    if (!(0 == sBoard.isValidMove(2,2, 1,3))) std::cout<< "Failed3" << std::endl; // move dig up
    if (!(0 == sBoard.isValidMove(2,2, 1,1))) std::cout<< "Failed4" << std::endl; // move dig up
    if (!(0 == sBoard.isValidMove(2,2, 2,0))) std::cout<< "Failed5" << std::endl; // move side
    std::cout << sBoard.displayBoard().str() << std::endl;

    
    std::cout << "\nPawn Black Test--" << std::endl;
    sBoard.createChessPiece(Black, Pawn, 1, 1);
    if (!(1 == sBoard.isValidMove(1,1, 2,1))) std::cout<< "Failed" << std::endl; // move 1 down
    if (!(1 == sBoard.isValidMove(1,1, 3,1))) std::cout<< "Failed" << std::endl; // move 1 down
    if (!(0 == sBoard.isValidMove(1,1, 3,2))) std::cout<< "Failed" << std::endl; // move 1 down
    if (!(0 == sBoard.isValidMove(1,1, 3,0))) std::cout<< "Failed" << std::endl; // move 1 down
    if (!(0 == sBoard.isValidMove(1,1, 4,0))) std::cout<< "Failed" << std::endl; // move 1 down
    if (!(0 == sBoard.isValidMove(1,1, 4,2))) std::cout<< "Failed" << std::endl; // move 1 down
    
    std::cout << "\nPawn boundary Test--" << std::endl;
    sBoard.createChessPiece(White, Pawn, 0, 0);
    sBoard.createChessPiece(Black, Pawn, 3, 0);
    if (!(0 == sBoard.isValidMove(2,2, 4,2))) std::cout<< "Failed" << std::endl; // move down
    if (!(0 == sBoard.isValidMove(0,0, -1,0))) std::cout<< "Failed" << std::endl; // move 1 up
    

    std::cout << "\nPawn kill Test--" << std::endl;
    if (!(1 == sBoard.isValidMove(2,2, 1,1))) std::cout<< "Failed" << std::endl; // move down
    if (!(0 == sBoard.isValidMove(2,2, 1,3))) std::cout<< "Failed" << std::endl; // move down


    std::cout << "\nPawn Block Test--" << std::endl;
    sBoard.createChessPiece(White, Pawn, 1, 2);
    if (!(0 == sBoard.isValidMove(2,2, 1,2))) std::cout<< "Failed" << std::endl; // move 1 up
    if (!(0 == sBoard.isValidMove(2,2, 0,2))) std::cout<< "Failed" << std::endl; // move 2 up

    std::cout << sBoard.displayBoard().str() << std::endl;
}

void test_part1_4x4_RookTest_isValid() {
    std::cout << "------------Rook isValid Test-------------" << std::endl;
    Student::ChessBoard sBoard(4, 4);

    sBoard.createChessPiece(White, Rook, 3, 2);
    sBoard.createChessPiece(Black, Rook, 1, 1);
    sBoard.createChessPiece(White, Rook, 2, 3);

    std::cout << "\nValid move Test--" << std::endl;
    if (!(1 == sBoard.isValidMove(3,2, 0,2))) std::cout<< "Failed" << std::endl;  
    if (!(1 == sBoard.isValidMove(3,2, 3,0))) std::cout<< "Failed" << std::endl; 
    if (!(1 == sBoard.isValidMove(1,1, 1,3))) std::cout<< "Failed" << std::endl;  
    if (!(1 == sBoard.isValidMove(1,1, 3,1))) std::cout<< "Failed" << std::endl;
    if (!(1 == sBoard.isValidMove(2,3, 3,3))) std::cout<< "Failed" << std::endl; 
    if (!(1 == sBoard.isValidMove(2,3, 0,3))) std::cout<< "Failed" << std::endl;  

    std::cout << "\nError move Test--" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,3))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,1))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,5))) std::cout<< "Failed" << std::endl;
}

void test_part1_4x4_BishopTest_isValid() {
    std::cout << "------------Bishop isValid Test-------------" << std::endl;
    Student::ChessBoard sBoard(4, 4);

    sBoard.createChessPiece(White, Bishop, 3, 2);
    sBoard.createChessPiece(Black, Bishop, 1, 3);

    std::cout << "\nBishop Test--" << std::endl;
    if (!(1 == sBoard.isValidMove(3,2, 1,0))) std::cout<< "Failed" << std::endl;
    if (!(1 == sBoard.isValidMove(3,2, 2,1))) std::cout<< "Failed" << std::endl;
    if (!(1 == sBoard.isValidMove(1,3, 0,2))) std::cout<< "Failed" << std::endl;
    if (!(1 == sBoard.isValidMove(1,3, 2,2))) std::cout<< "Failed" << std::endl;
    if (!(1 == sBoard.isValidMove(1,3, 3,1))) std::cout<< "Failed" << std::endl;
    
    std::cout << "\nInvalid Move Test--" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,1))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,3))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(1,3, 2,3))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(1,3, 1,2))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isValidMove(1,3, 1,5))) std::cout<< "Failed" << std::endl;


    std::cout << sBoard.displayBoard().str() << std::endl;

    // Calls isValidMove() from every position tos board for) std::cout<< "Failed" all pieces.
    return;
}

void test_part1_4x4_PawnTest_movePiece_UnderThreat()
{
    std::cout << "------------Pawn movePiece Test-------------" << std::endl;
    // Config file content:
    // 0
    // 4 4
    // w r 3 2
    // b b 1 3
    // b r 1 1
    // w r 2 3
    // ~
    // isValidScan

    // Corresponding code
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(Black, Pawn, 1, 0);
    sBoard.createChessPiece(Black, Pawn, 1, 1);
    sBoard.createChessPiece(White, Pawn, 3, 3);
    sBoard.createChessPiece(White, Pawn, 3, 2);
    std::cout << "\n Before move: " << std::endl;
    std::cout << sBoard.displayBoard().str() << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(0,0))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,1))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,3))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed" << std::endl;


    
    std::cout << "\n After move1 Black Wrong Turn: " << std::endl;
    if (sBoard.movePiece(0,0, 2,0)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move1 White: " << std::endl;
    if (sBoard.movePiece(3,3, 2,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }
    if (!(0 == sBoard.isPieceUnderThreat(0,0))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,1))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(2,3))) std::cout<< "Failed" << std::endl;


    std::cout << "\n After move1 Black: " << std::endl;
    if (sBoard.movePiece(1,0, 2,0)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }
    if (!(0 == sBoard.isPieceUnderThreat(2,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(2,3))) std::cout<< "Failed4" << std::endl;


    std::cout << "\n After move2 White Wrong move: " << std::endl;
    if (sBoard.movePiece(2,3, 0,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 White: " << std::endl;
    if (sBoard.movePiece(2,3, 1,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }
    if (!(0 == sBoard.isPieceUnderThreat(2,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,3))) std::cout<< "Failed4" << std::endl;


    std::cout << "\n After move2 Black: " << std::endl;
    if (sBoard.movePiece(1,1, 2,1)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }
    if (!(0 == sBoard.isPieceUnderThreat(2,0))) std::cout<< "Failed1" << std::endl;
    if (!(1 == sBoard.isPieceUnderThreat(2,1))) std::cout<< "Failed2" << std::endl;
    if (!(1 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(1,3))) std::cout<< "Failed4" << std::endl;


    std::cout << "\n After move3 White: " << std::endl;
    if (sBoard.movePiece(1,3, 0,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    if (!(0 == sBoard.isPieceUnderThreat(2,0))) std::cout<< "Failed1" << std::endl;
    if (!(1 == sBoard.isPieceUnderThreat(2,1))) std::cout<< "Failed2" << std::endl;
    if (!(1 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(0,3))) std::cout<< "Failed4" << std::endl;


    std::cout << "\n After move3 Black Kill White: " << std::endl;
    if (sBoard.movePiece(2,1, 3,2)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }
    if (!(0 == sBoard.isPieceUnderThreat(2,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(2,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(3,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isPieceUnderThreat(0,3))) std::cout<< "Failed4" << std::endl;


    return;
}

std::vector<int> stringToIntVector(const std::string& input) {
    std::vector<int> result;
    std::stringstream ss(input);
    int num;
    while (ss >> num) {
        result.push_back(num);
        if (ss.peek() == ' ') { // Check for space, and consume it.
            ss.ignore();
        }
    }
    if(ss.fail() && !ss.eof()){
        throw std::invalid_argument("Invalid input string");
    }
    return result;
}

void isValid_scan(Student::ChessBoard& board) {
    int max_row = board.getNumRows();
    int max_col = board.getNumCols();

    std::vector<std::pair<int, int>> piece_vec;
    for (int r = 0; r < max_row; r++) {
        for (int c = 0; c < max_col; c++) {
            Student::ChessPiece *piece = board.getPiece(r,c);
            if (piece != nullptr) piece_vec.push_back(std::make_pair(r, c));
        }
    }

    std::cout << std::boolalpha;
    for (std::pair<int, int> pos : piece_vec) {
        // board.check();

        Student::ChessPiece *piece = board.getPiece(pos.first, pos.second);
        assert(pos.first == piece->getRow() && pos.second == piece->getColumn());
        std::cout << "Move: " << pos.first << "," << pos.second
            << " " << piece -> toString() << "--" << std::endl;
        
        for (int r = 0; r < max_row; r++) {
            for (int c = 0; c < max_col; c++) {

                // if (piece -> getType() == King && pos.first == 7 && pos.second == 4 && r == 7 && c == 2) {
                //     printf(" ");
                // }

                // if (board.getPiece(0,3) == nullptr) {
                //     printf(" ");
                // }

                bool is_valid = board.isValidMove(pos.first, pos.second, r, c);
                if (is_valid) {
                    std::cout << pos.first << ", " << pos.second
                    << " -> " << r << ", " << c << " | " << is_valid << std::endl;
                }
            }
        }
    }
    std::cout << std::noboolalpha;

}

void move_Piece(Student::ChessBoard& board, std::string move_info) {
    move_info = move_info.substr(10, move_info.size());
    std::vector<int> move_vec = stringToIntVector(move_info);

    std::cout << "Move from: " << move_vec[0] << ", " << move_vec[1] << " | To: " << move_vec[2] << ", " << move_vec[3] << std::endl;
    board.movePiece(move_vec[0], move_vec[1], move_vec[2], move_vec[3]);
    std::cout << board.displayBoard().str() << std::endl;

    // check incorrect moves;
    int max_row = board.getNumRows();
    int max_col = board.getNumCols();
    for (int r = 0; r < max_row; r++) {
        for (int c = 0; c < max_col; c++) {
            Student::ChessPiece *piece = board.getPiece(r,c);
            if (piece != nullptr) {
                assert(r == piece->getRow() && c == piece->getColumn());
            }
        }
    }
}

void read_test_file(std::string file_name) {
    std::ifstream f("test_files/" + file_name);

    // String variable to store the read data
    std::vector<std::string> lines;
    std::string s;

    while (getline(f, s)) {
        lines.push_back(s);
    }
    f.close();

    // add Pieces
    std::string board_size_str = lines[1];
    std::vector<int> board_size  = stringToIntVector(lines[1]);
    Student::ChessBoard sBoard(board_size[0], board_size[1]);

    size_t i = 2;
    for (;lines[i] != "~" and i < lines.size(); i++) {
        std::string piece_info = lines[i];

        Color color;
        switch(piece_info[0]) {
            case 'w':
                color = White;
                break;
            case 'b':
                color = Black;
                break;
        }

        Type type;
        switch(piece_info[2]) {
            case 'p':
                type = Pawn;
                break;
            case 'r':
                type = Rook;
                break;
            case 'b':
                type = Bishop;
                break;
            case 'k':
                type = King;
                break;
        }

        sBoard.createChessPiece(color, type, piece_info[4] - '0', piece_info[6] - '0');
    }
    std::cout << sBoard.displayBoard().str() << std::endl;

    // sBoard.check();

    // task
    for (;i < lines.size(); i++) {

        if (i == 21) {
            printf("v");
        }
        
        if (lines[i] == "isValidScan") {
            std::cout << "-------------------------- Line: " << i + 1 << "-------------------------------" << std::endl;
            isValid_scan(sBoard);
        }
        // if (lines[i] == "underThreatScan") {isValid_scan(sBoard);
        if (lines[i].substr(0,9) == "movePiece") {
            std::cout << "-------------------------- Line: " << i + 1 << "-------------------------------" << std::endl;
            move_Piece(sBoard, lines[i]);
        }
        // case "underThreatScan":
                // break;
    }
}

// };
// b b 0 1
// b b 1 1
// b b 2 1
// w p 2 0
void part1_4x4_5 () {
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(Black, Bishop, 0, 1);
    sBoard.createChessPiece(Black, Bishop, 1, 1);
    sBoard.createChessPiece(Black, Bishop, 2, 1);
    sBoard.createChessPiece(White, Pawn, 2, 0);
    sBoard.createChessPiece(Black, Pawn, 1, 2);
    std::cout << sBoard.displayBoard().str() << std::endl;
    std::cout << "\n(2,1) test" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(1 == sBoard.isValidMove(2,1, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(1 == sBoard.isValidMove(2,1, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(1 == sBoard.isValidMove(2,1, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 3,3))) std::cout<< "Failed16" << std::endl;
    if (!(0 == sBoard.isValidMove(2,1, 4,4))) std::cout<< "Failed17" << std::endl;

    std::cout << "\n(2,0) test" << std::endl;
    if (!(1 == sBoard.isValidMove(2,0, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(1 == sBoard.isValidMove(2,0, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(1 == sBoard.isValidMove(2,0, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 3,3))) std::cout<< "Failed16" << std::endl;
    if (!(0 == sBoard.isValidMove(2,0, 4,4))) std::cout<< "Failed17" << std::endl;

    std::cout << "\n(1,2) test" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(1 == sBoard.isValidMove(1,2, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(1 == sBoard.isValidMove(1,2, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 3,3))) std::cout<< "Failed16" << std::endl;
    if (!(0 == sBoard.isValidMove(1,2, 4,4))) std::cout<< "Failed17" << std::endl;
}

// w b 2 2
// w r 1 0
// w p 1 1
// b p 0 1

void part1_4x4_3 () {
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Bishop, 2, 2);
    sBoard.createChessPiece(White, Rook, 1, 0);
    sBoard.createChessPiece(White, Pawn, 1, 1);
    sBoard.createChessPiece(Black, Pawn, 0, 1);
    std::cout << sBoard.displayBoard().str() << std::endl;
    std::cout << "\n(2,2) test" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(1 == sBoard.isValidMove(2,2, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(1 == sBoard.isValidMove(2,2, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(1 == sBoard.isValidMove(2,2, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(1,0) test" << std::endl;
    if (!(1 == sBoard.isValidMove(1,0, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(1 == sBoard.isValidMove(1,0, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(1 == sBoard.isValidMove(1,0, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(1,1) test" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(1,1, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(0,1) test" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(1 == sBoard.isValidMove(0,1, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(0,1, 3,3))) std::cout<< "Failed16" << std::endl;
}

// b p 2 2
// b r 3 2
// w p 3 1
// b p 1 0
void part1_4x4_7 () {
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(Black, Pawn, 2, 2);
    sBoard.createChessPiece(Black, Rook, 3, 2);
    sBoard.createChessPiece(White, Pawn, 3, 1);
    sBoard.createChessPiece(Black, Pawn, 1, 0);
    std::cout << sBoard.displayBoard().str() << std::endl;
    std::cout << "\n(2,2) test" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(1 == sBoard.isValidMove(2,2, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(2,2, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(3,2) test" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(1 == sBoard.isValidMove(3,2, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(3,2, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(1 == sBoard.isValidMove(3,2, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(3,1) test" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(1 == sBoard.isValidMove(3,1, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(1 == sBoard.isValidMove(3,1, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(3,1, 3,3))) std::cout<< "Failed16" << std::endl;

    std::cout << "\n(1,0) test" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,0))) std::cout<< "Failed1" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,1))) std::cout<< "Failed2" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,2))) std::cout<< "Failed3" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 0,3))) std::cout<< "Failed4" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,0))) std::cout<< "Failed5" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,1))) std::cout<< "Failed6" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,2))) std::cout<< "Failed7" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 1,3))) std::cout<< "Failed8" << std::endl;
    if (!(1 == sBoard.isValidMove(1,0, 2,0))) std::cout<< "Failed9" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,1))) std::cout<< "Failed10" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,2))) std::cout<< "Failed11" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 2,3))) std::cout<< "Failed12" << std::endl;
    if (!(1 == sBoard.isValidMove(1,0, 3,0))) std::cout<< "Failed13" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,1))) std::cout<< "Failed14" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,2))) std::cout<< "Failed15" << std::endl;
    if (!(0 == sBoard.isValidMove(1,0, 3,3))) std::cout<< "Failed16" << std::endl;
}

// 4 4
// b r 3 3
// b b 0 0
// b b 3 0
// w r 2 3
// b k 3 1
// w k 1 0

int main()
{
    // test_part1_4x4_PawnTest_isValid();
    // test_part1_4x4_RookTest_isValid();
    // test_part1_4x4_BishopTest_isValid();
    // test_part1_4x4_PawnTest_movePiece_UnderThreat();
    // read_test_file("part2_4x4_5.txt");
    // part1_4x4_5();
    // part1_4x4_3();
    // part1_4x4_7();
    // part3_basic_test();

    // int num_of_test = 19;
    // for (int i = 0; i <= num_of_test; i++) {
    //     std::cout << "*****************TEST" + std::to_string(i) + "********************" << std::endl;
    //     read_test_file("part4_8x8_" + std::to_string(i) + ".txt");
    // }

    read_test_file("part4_8x8_1.txt");

    // Student::ChessBoard sBoard(4, 4);
    // sBoard.createChessPiece(White, King, 0, 0);
    // std::cout << sBoard.getPiece(0, 0) -> getRow() << sBoard.getPiece(0, 0) -> getColumn() << std::endl;

    return EXIT_SUCCESS;
}