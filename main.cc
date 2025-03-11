#include <assert.h>
#include "Chess.h"
#include "ChessBoard.hh"
#include "ChessPiece.hh"
#include <iostream>

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
    // Student::ChessBoard sBoard(4, 4);
    // std::cout << "\nPawn White Test" << std::endl;
    // sBoard.createChessPiece(White, Pawn, 2, 2);
    // std::cout << (1 == sBoard.isValidMove(2,2, 1,2)) << std::endl; // move 1 up
    // std::cout << (1 == sBoard.isValidMove(2,2, 0,2)) << std::endl; // move 2 up
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move dig up
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move dig up
    // std::cout << (0 == sBoard.isValidMove(2,2, 2,0)) << std::endl; // move side

    
    // std::cout << "\nPawn Black Test" << std::endl;
    // sBoard.createChessPiece(Black, Pawn, 1, 1);
    // std::cout << (1 == sBoard.isValidMove(1,1, 2,1)) << std::endl; // move 1 down
    // std::cout << (1 == sBoard.isValidMove(1,1, 3,1)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 3,2)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 3,0)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 4,0)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 4,2)) << std::endl; // move 1 down
    
    // std::cout << "\nPawn boundary Test" << std::endl;
    // sBoard.createChessPiece(White, Pawn, 0, 0);
    // sBoard.createChessPiece(Black, Pawn, 3, 0);
    // std::cout << (0 == sBoard.isValidMove(2,2, 4,2)) << std::endl; // move down
    // std::cout << (0 == sBoard.isValidMove(0,0, -1,0)) << std::endl; // move 1 up
    

    // std::cout << "\nPawn kill Test" << std::endl;
    // std::cout << (1 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move down
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move down


    // std::cout << "\nPawn Block Test" << std::endl;
    // sBoard.createChessPiece(White, Pawn, 1, 2);
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,2)) << std::endl; // move 1 up
    // std::cout << (0 == sBoard.isValidMove(2,2, 0,2)) << std::endl; // move 2 up

    // std::cout << sBoard.displayBoard().str() << std::endl;

    // sBoard.createChessPiece(White, Pawn, 2, 2);
    // std::cout << (1 == sBoard.isValidMove(2,2, 1,2)) << std::endl; // move 1 up
    // std::cout << (1 == sBoard.isValidMove(2,2, 0,2)) << std::endl; // move 2 up
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move dig up
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move dig up
    // std::cout << (0 == sBoard.isValidMove(2,2, 2,0)) << std::endl; // move side

    
    // std::cout << "\nPawn Black Test" << std::endl;
    // sBoard.createChessPiece(Black, Pawn, 1, 1);
    // std::cout << (1 == sBoard.isValidMove(1,1, 2,1)) << std::endl; // move 1 down
    // std::cout << (1 == sBoard.isValidMove(1,1, 3,1)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 3,2)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 3,0)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 4,0)) << std::endl; // move 1 down
    // std::cout << (0 == sBoard.isValidMove(1,1, 4,2)) << std::endl; // move 1 down
    
    // std::cout << "\nPawn boundary Test" << std::endl;
    // sBoard.createChessPiece(White, Pawn, 0, 0);
    // sBoard.createChessPiece(Black, Pawn, 3, 0);
    // std::cout << (0 == sBoard.isValidMove(2,2, 4,2)) << std::endl; // move down
    // std::cout << (0 == sBoard.isValidMove(0,0, -1,0)) << std::endl; // move 1 up
    

    // std::cout << "\nPawn kill Test" << std::endl;
    // std::cout << (1 == sBoard.isValidMove(2,2, 1,1)) << std::endl; // move down
    // std::cout << (0 == sBoard.isValidMove(2,2, 1,3)) << std::endl; // move down

    // std::cout << sBoard.displayBoard().str() << std::endl;

    // sBoard.createChessPiece(White, Rook, 3, 2);
    // // sBoard.createChessPiece(Black, Bishop, 1, 3);
    // sBoard.createChessPiece(Black, Rook, 1, 1);
    // sBoard.createChessPiece(White, Rook, 2, 3);

    // std::cout << "\nRook Test" << std::endl;
    // std::cout << (1 == sBoard.isValidMove(3,2, 0,2)) << std::endl;  
    // std::cout << (1 == sBoard.isValidMove(3,2, 3,0)) << std::endl; 
    // std::cout << (1 == sBoard.isValidMove(1,1, 1,3)) << std::endl;  
    // std::cout << (1 == sBoard.isValidMove(1,1, 3,1)) << std::endl;
    // std::cout << (1 == sBoard.isValidMove(2,3, 3,3)) << std::endl; 
    // std::cout << (1 == sBoard.isValidMove(2,3, 0,3)) << std::endl;  

    // std::cout << "\nError Test" << std::endl;
    // std::cout << (0 == sBoard.isValidMove(3,2, 2,3)) << std::endl;
    // std::cout << (0 == sBoard.isValidMove(3,2, 1,1)) << std::endl;
    // std::cout << (0 == sBoard.isValidMove(3,2, 1,3)) << std::endl;

    // sBoard.createChessPiece(White, Bishop, 3, 2);
    // sBoard.createChessPiece(Black, Bishop, 1, 3);

    // std::cout << "\nBishop Test" << std::endl;
    // std::cout << (1 == sBoard.isValidMove(3,2, 1,0)) << std::endl;
    // std::cout << (1 == sBoard.isValidMove(3,2, 2,1)) << std::endl;
    // std::cout << (1 == sBoard.isValidMove(1,3, 0,2)) << std::endl;
    // std::cout << (1 == sBoard.isValidMove(1,3, 2,2)) << std::endl;
    // std::cout << (1 == sBoard.isValidMove(1,3, 3,1)) << std::endl;
    
    // std::cout << "\nError Test" << std::endl;
    // std::cout << (0 == sBoard.isValidMove(3,2, 1,1)) << std::endl;
    // std::cout << (0 == sBoard.isValidMove(3,2, 1,3)) << std::endl;
    // std::cout << (0 == sBoard.isValidMove(1,3, 2,3)) << std::endl;
    // std::cout << (0 == sBoard.isValidMove(1,3, 1,2)) << std::endl;


    std::cout << sBoard.displayBoard().str() << std::endl;

    // Calls isValidMove() from every position to every
    // other position on the chess board for all pieces.
    return;
}


void test_part1_4x4_PawnTest_movePiece()
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
    
    std::cout << "\n After move1 Black Wrong Turn: " << std::endl;
    if (sBoard.movePiece(0,0, 2,0)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move1 White: " << std::endl;
    if (sBoard.movePiece(3,3, 2,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move1 Black: " << std::endl;
    if (sBoard.movePiece(0,0, 2,0)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 White Wrong move: " << std::endl;
    if (sBoard.movePiece(2,3, 0,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 White: " << std::endl;
    if (sBoard.movePiece(2,3, 1,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 Black: " << std::endl;
    if (sBoard.movePiece(1,1, 2,1)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 White: " << std::endl;
    if (sBoard.movePiece(1,3, 0,3)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    std::cout << "\n After move2 Black Kill White: " << std::endl;
    if (sBoard.movePiece(2,1, 3,2)) {
        std::cout << sBoard.displayBoard().str() << std::endl;
    }

    return;
};

int main()
{
    test_part1_4x4_PawnTest_isValid();
    test_part1_4x4_PawnTest_movePiece();
    return EXIT_SUCCESS;
}