#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <cstdlib>


using namespace std; 
class Board {

public: 
    Board(int a);
    Board(const string &filename);

    void generateBoard();
    void printBoard();
    int solveBoard();

    int getSize();
    

private: 
    static const int BOX_SIZE = 3;
    static const int DEFAULT_DIM = 3;
    int rootSize;
    int fullSize;

    void readFile(const string &filename);
    void setDims(int a);
    void printHline();
    bool isValidNum(int r, int c);
    int **boardData;
};

#endif