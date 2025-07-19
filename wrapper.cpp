#include <pybind11/pybind11.h>
#include "board.h"
#include <pybind11/stl.h> // For std::vector, etc. if needed

namespace py = pybind11;


void generate_board(int a, difficulty d) 
{
    Board board(a);
    board.generateBoard(d);
    board.printBoard();
}

PYBIND11_MODULE(sudoku, m)
{
    py::enum_<difficulty>(m, "difficulty")
        .value("EASY", difficulty::EASY)
        .value("MEDIUM", difficulty::MEDIUM)
        .value("HARD", difficulty::HARD);
    m.def("generate_board", &generate_board);
}