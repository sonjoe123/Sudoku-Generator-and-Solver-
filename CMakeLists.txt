cmake_minimum_required(VERSION 3.16)
project(Sudoku)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sudoku main.cpp solveSudoku.cpp solveSudoku.h)
