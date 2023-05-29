#include <iostream>
#include <cstdlib>
#include <ctime>
#include "solveSudoku.h"
using namespace std;
int main() {
    // create the sudoku table and fill in every square with value 0
    int sudoku[9][9] = {0};
    solveSudoku sudokuSolver;
    sudokuSolver.startGame(sudoku);
    return 0;
}
