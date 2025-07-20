
/**********************************************************
 *                      SUDOKU
 * Features
 *    () Handles different sizes of board (4x4, 9x9, ect.)
 *    () Prints board
 *    () Reads in board data
 *    () Verifies board  
 *    () Solves board
 *    () Generates EASY, MED, or HARD board
 *    () Generates printable sheet of sudoku board
 *
 * Development
 *    (1) Print a board
 *    (2) Read in board data, print it
 *    (3) Verify board
 *    (4) Solve board (backtracking)
 *    (5) Pretty print board
 *    (6) Generate board
 *    (7) Generate board of varying difficulty
 *    
 *********************************************************/
#include <iostream>
#include <fstream>
#include "board.h"

using namespace std; 

int main(int argc, char *argv[]) {

    Board *myBoard; 
    if (argc < 2) {
        myBoard = new Board(3); 
        myBoard->generateBoard(HARD);
    } else {
        myBoard = new Board(argv[1]); 
    }

    myBoard->printBoard();
    myBoard->solveBoard();
    myBoard->printBoard();
    myBoard->outputBoard();
    delete myBoard;
    return 0;

}