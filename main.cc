#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>

void test_part1_4x4_1()
{
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
    std::cout << "Pown White Test" << std::endl;
    Student::ChessBoard sBoard(4, 4);
    sBoard.createChessPiece(White, Pawn, 2, 2);
    std::cout << (1 == sBoard.isValidMove(2,2, 1,2)) << std::endl; // move 1 up
    std::cout << (1 == sBoard.isValidMove(2,2, 0,2)) << std::endl; // move 2 up
    std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move dig up
    std::cout << (0 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move dig up
    std::cout << (0 == sBoard.isValidMove(2,2, 2,0)) << std::endl; // move side

    
    std::cout << "\nPown Black Test" << std::endl;
    sBoard.createChessPiece(Black, Pawn, 1, 1);
    std::cout << (1 == sBoard.isValidMove(1,1, 2,1)) << std::endl; // move 1 down
    std::cout << (1 == sBoard.isValidMove(1,1, 3,1)) << std::endl; // move 1 down
    std::cout << (0 == sBoard.isValidMove(1,1, 3,2)) << std::endl; // move 1 down
    std::cout << (0 == sBoard.isValidMove(1,1, 3,0)) << std::endl; // move 1 down
    std::cout << (0 == sBoard.isValidMove(1,1, 4,0)) << std::endl; // move 1 down
    std::cout << (0 == sBoard.isValidMove(1,1, 4,2)) << std::endl; // move 1 down
    
    std::cout << "\nPown boundary Test" << std::endl;
    sBoard.createChessPiece(White, Pawn, 0, 0);
    sBoard.createChessPiece(Black, Pawn, 3, 0);
    std::cout << (0 == sBoard.isValidMove(2,2, 4,2)) << std::endl; // move down
    std::cout << (0 == sBoard.isValidMove(0,0, -1,0)) << std::endl; // move 1 up
    

    std::cout << "\nPown kill Test" << std::endl;
    std::cout << (1 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move down
    std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move down

    std::cout << sBoard.displayBoard().str() << std::endl;
    // sBoard.createChessPiece(White, Rook, 3, 2);
    // sBoard.createChessPiece(Black, Bishop, 1, 3);
    // sBoard.createChessPiece(Black, Rook, 1, 1);
    // sBoard.createChessPiece(White, Rook, 2, 3);

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.

    return;
}

int main()
{
    test_part1_4x4_1();
    return EXIT_SUCCESS;
}
