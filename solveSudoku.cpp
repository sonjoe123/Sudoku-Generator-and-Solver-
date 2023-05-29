//
// Created by phant on 5/29/2023.
//

#include "solveSudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "solveSudoku.h"

using namespace std;

// Function to check if the Sudoku grid has any zero value
bool solveSudoku:: hasZeroValue(int arr[9][9]){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (arr[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}
// Function to print the Sudoku grid
void solveSudoku::printSudoku(int arr[9][9]){
    int sp = 0;
    cout << "--------------------------------------\n";
    for (int i = 0; i < 9; ++i) {
        int seper = 0;
        for (int j = 0; j < 9; ++j) {
            cout << arr[i][j] << " ";
            seper++;
            if(seper %3 == 0 && seper !=9){
                cout << "|| ";
            } else { cout << "| ";}
        }
        sp++;
        cout << endl;
        if(sp%3 == 0 && sp!=9){
            cout << "======================================\n";
        } else {
            cout << "--------------------------------------";
        }
        cout << endl;
    }
}

// Function to check if a value can be placed at a specific position in the Sudoku grid
bool solveSudoku:: validValue(int value, int rowID, int colID, int arr[9][9]){
    // Check both row and column at the same time
    for (int i = 0; i < 9; i++) {
        if(arr[rowID][i] == value || arr[i][colID] == value){
            return false;
        }
    }
    // Check the sub-square
    int sqrRow = (rowID/3) *3;
    int sqrCol = (colID/3) *3;
    // Loop through the 3x3 sub-square
    for (int i = sqrRow; i < sqrRow + 3; i++) {
        for (int j = sqrCol; j < sqrCol + 3; j++) {
            if(arr[i][j] == value){
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku grid using backtracking
bool  solveSudoku::solverSudoku(int arr[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (arr[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (validValue(num, row, col, arr)) {
                        arr[row][col] = num;

                        if (solverSudoku(arr)) {
                            return true;
                        }

                        arr[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Function to generate a Sudoku puzzle
void solveSudoku::generateSudoku(int arr[9][9], int difficultLevel) {

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Solve the puzzle
    solverSudoku(arr);

    // Remove some numbers to create the puzzle
    while (difficultLevel > 0) {
        int row = std::rand() % 9;
        int col = std::rand() % 9;
        if (arr[row][col] != 0) {
            arr[row][col] = 0;
            --difficultLevel;
        }
    }
}

// Function to prompt the user for a position and value to fill in
void solveSudoku::getUserInput(int& row, int& col, int& value) {
    std::cout << "Enter the position (row column) and value (1-9) to fill in: ";
    std::cin >> row >> col >> value;
    std::cout << std::endl;
}
// Start the game function
void solveSudoku::startGame(int arr[9][9]) {
    srand(time(nullptr));
    // Randomly fill in some squares to create a partially filled Sudoku grid
    // This makes the puzzle different every single run

    int rowId, colId, value;
    int prefilled = 0;
    while(prefilled < 15){
        rowId = generateRandom();
        colId = generateRandom();
        value = generateRandom() + 1;

        if (validValue(value,rowId,colId,arr)) {
            arr[rowId][colId] = value;
            prefilled++;
        }
    }
    // Set the difficulty level based on user input
    // The harder the level, the less prefilled number

    int numToRemove;
    int diffiLevel;
    cout << "Choose your difficulty: 1.Beginner 2.Medium 3.Hard: ";
    cin >> numToRemove;
    if(numToRemove == 1){
        diffiLevel = 25;
    } else if(numToRemove == 2){
        diffiLevel = 35;
    } else if(numToRemove == 3){
        diffiLevel = 45;
    }
    generateSudoku(arr, diffiLevel);
    printSudoku(arr);

    while (hasZeroValue(arr)) {
        int row, col, value;int answer;
        // Solve the puzzle on request
        cout << "Solve the sudoku above: ";
        cout << "Press 1 to solve it or press any to solve it yourself.\n";
        cin >> answer;
        if (answer == 1){
            solverSudoku(arr);
            printSudoku(arr);
            break;
        }
        // User solve it
        getUserInput(row, col, value);

        if (row >= 0 && row < 9 && col >= 0 && col < 9 && value >= 1 && value <= 9 ) {
            if(validValue(value,row,col,arr)) {
                if (arr[row][col] == 0) {
                    arr[row][col] = value;
                    printSudoku(arr);
                } else {
                    std::cout << "That position is already filled.\n";
                }
            } else { cout<< "This number has already existed in either row, column or box.\n";}
        } else {
            std::cout << "Invalid input. Please try again.\n";
        }
    }


}
// Function to generate a random number from 0 to 8
int solveSudoku:: generateRandom(){
    return rand() % 9;
}
