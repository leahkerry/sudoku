import build.sudoku as sudoku
from enum import Enum


sudoku.generate_board(3, sudoku.difficulty.EASY)
sudoku.generate_board(3, sudoku.difficulty.HARD)
