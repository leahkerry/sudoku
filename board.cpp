#include "board.h"
using namespace std; 

Board::Board(int a) {
    try {
        setDims(a);
    } catch (runtime_error& error) {
        cerr << "Error:" << error.what() << "... setting board to 9x9" << endl;
        rootSize = 3;
        fullSize = 3 * 3;
    }

    generateBoard();

}

Board::Board(const string &filename) {

    setDims(DEFAULT_DIM); // Assume we have a 3x3 file for now
    generateBoard();

    readFile(filename);

}

void Board::readFile(const string &filename) {
    ifstream inFile(filename);
    if (!inFile) { throw runtime_error("File could not be read."); }

    char c;
    int chars = 0;
    int row, col;
    while (inFile.get(c) && chars < fullSize * fullSize) {
        row = chars % fullSize;
        col = chars / fullSize;

        int num = int(c) - '0';
        if (num < 0 || num > 9) num = 0; // space filler is 0
        boardData[row][col] = num;
        chars++;
    }
    inFile.close();
}

void Board::setDims(int a) {
    if (a <= 0) throw runtime_error("Board dimension must be > 0.");
    else if (a > 5) throw runtime_error("Board dimension must be between 1-5.");
    rootSize = a;
    fullSize = a * a;
}

void Board::generateBoard() {

    boardData = new int*[fullSize];

    for (int i = 0; i < fullSize; i++) {

        boardData[i] = new int[fullSize];

        for (int j = 0; j < fullSize; j++) {

            boardData[i][j] = 0;

        }
    }
}

void Board::printHline(){
    for (int l = 0; l < (rootSize * rootSize * 4); l++) {
        cout << "_";
    }
    cout << endl << endl;
}

void Board::printBoard() {
    printHline();

    for (int i = 0; i < fullSize; i++) {
        cout << "| ";
        for (int j = 0; j < fullSize; j ++) {

            if (boardData[i][j] != 0)    cout << boardData[i][j] << "  ";
            else                         cout << "   ";
            if ((j + 1) % rootSize == 0) cout << "|  "; 

        }
        cout << endl << endl;
        if ((i + 1) % rootSize == 0) printHline();
    }
    
}

int Board::getSize() {
    return fullSize;
}

bool Board::isValidNum(int r, int c) {
    
    int val = boardData[r][c];
    cout << "is " << val << " valid?\n";
    // if val is 0, then it is a valid empty cell
    if (val == 0) return true; 

    for (int i = 0; i < fullSize; i++) {
        // check box
        
        int sq_c_i = ((c / rootSize) * rootSize) + (i % rootSize);
        int sq_r_i = ((r / rootSize) * rootSize) + (i / rootSize);
        if (val == boardData[sq_r_i][sq_c_i] && (sq_c_i != c && sq_r_i != r)) return false; 
        // check col
        if (val == boardData[r][i] && (i != c))                               return false; 
        // check row
        if (val == boardData[i][c] && (i != r))                               return false; 
    }
    return true;
}   

int Board::solveBoard() {
    cout << isValidNum(0, 0) << endl;
    cout << isValidNum(4,5) << endl;
    boardData[4][5] = 4;
    cout << isValidNum(4,5) << endl;
    return 0; 
}