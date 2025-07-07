/***********************************************
 *                   BOARD 
 * Created: 7/4/25
 * Purpose: Main functionality of a sudoku board
 *          including generating, printing, and 
 *          solving
 ***********************************************/
#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <chrono> 
#include "arith.h"

enum difficulty {
    EASY, MEDIUM, HARD
};

using namespace std; 
class Board {

public: 
    Board(int a);
    Board(const string &filename);

    void generateEmptyBoard();
    void generateBoard(difficulty);
    
    void printBoard();
    int solveBoard();

    int getSize();
    void outputBoard();
    bool isValidBoard();
    

private: 
    static const int BOX_SIZE = 3;
    static const int DEFAULT_DIM = 3;
    int rootSize;
    int fullSize;
    int **boardData;
    unsigned seed;

    void readFile(const string &filename);
    void setDims(int a);
    void printHline();
    bool isValidNum(int r, int c, int val);
    
    int solveBoardRec(int r, int c);
};

#endif