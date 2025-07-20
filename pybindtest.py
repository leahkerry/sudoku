import build.sudoku as sudoku
from enum import Enum


# sudoku.generate_board(3, sudoku.difficulty.EASY)
# boardString = sudoku.generate_board(3, "HARD")
boardString = sudoku.generate_board(3, sudoku.difficulty.HARD)
print(boardString)
print("stringed!")