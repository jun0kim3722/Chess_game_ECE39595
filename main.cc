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
    sBoard.createChessPiece(Black, Pawn, 0, 0);
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
    if (sBoard.movePiece(0,0, 2,0)) {
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

// void isValid_scan() {

// }

// void read_test_file(std::string file_name) {
//     std::ifstream f("test_files/" + file_name);

//     // String variable to store the read data
//     std::vector<std::string> lines;
//     std::string s;

//     while (getline(f, s)) {
//         std::cout << s << std::endl;
//         lines.push_back(s);
//     }
//     f.close();

//     // add Pieces
//     std::string board_size_str = lines[1];
//     std::vector<int> board_size  = stringToIntVector(lines[1]);
//     Student::ChessBoard sBoard(board_size[0], board_size[1]);

//     size_t i = 2;
//     for (lines[i] != "~" and i < lines.size(); i++) {
//         std::string piece_info = lines[i];
//         std::cout << piece_info << std::endl;

//         Color color;
//         switch(piece_info[0]) {
//             case 'w':
//                 color = White;
//                 break;
//             case 'b':
//                 color = Black;
//                 break;
//         }

//         Type type;
//         switch(piece_info[2]) {
//             case 'p':
//                 type = Pawn;
//                 break;
//             case 'r':
//                 type = Rook;
//                 break;
//             case 'b':
//                 type = Bishop;
//                 break;
//             case 'k':
//                 type = King;
//                 break;
//         }

//         sBoard.createChessPiece(color, type, piece_info[4] - '0', piece_info[6] - '0');
//     }

//     // task
//     for (i < lines.size(); i++) {
//         switch(lines[i]) {
//             case 'isValidScan':

//                 break;
//             case 'underThreatScan':
//                 break;
//             case 'b':
//                 break;
//             case 'k':
//                 break;
//         }
//     }
// }

int main()
{
    test_part1_4x4_PawnTest_isValid();
    test_part1_4x4_RookTest_isValid();
    test_part1_4x4_BishopTest_isValid();
    test_part1_4x4_PawnTest_movePiece_UnderThreat();
    // read_test_file("part1_4x4_1.txt");
    return EXIT_SUCCESS;
}