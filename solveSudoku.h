//
// Created by phant on 5/29/2023.
//

#ifndef SUDOKU_SOLVESUDOKU_H
#define SUDOKU_SOLVESUDOKU_H


class solveSudoku {

public:
    bool hasZeroValue(int arr[9][9]);
    void printSudoku(int arr[9][9]);
    bool validValue(int value, int rowID, int colID, int arr[9][9]);
    bool solverSudoku(int arr[9][9]);
    void generateSudoku(int arr[9][9], int difficultLevel);
    void getUserInput(int& row, int& col, int& value);
    int generateRandom();
    void startGame(int arr[9][9]);
};


#endif //SUDOKU_SOLVESUDOKU_H
