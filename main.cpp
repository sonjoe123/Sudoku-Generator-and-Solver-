#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
bool hasZeroValue(int arr[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (arr[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}
void printSudoku(int arr[9][9]){
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

bool validValue(int value, int rowID, int colID, int arr[9][9]){
    // check both row and col at the same time
    for (int i = 0; i < 9; i++) {
        if(arr[rowID][i] == value || arr[i][colID] == value){
            return false;
        }
    }
    // check for subsquare
    int sqrRow = (rowID/3) *3;
    int sqrCol = (colID/3) *3;
    // Loop through that square + 3 because we are starting at the beginning position of the 3x3 square
    for (int i = sqrRow; i < sqrRow + 3; i++) {
        for (int j = sqrCol; j < sqrCol + 3; j++) {
            if(arr[i][j] == value){
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int arr[9][9]) {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            if (arr[row][col] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (validValue(num, row, col, arr)) {
                        arr[row][col] = num;

                        if (solveSudoku(arr)) {
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
void generateSudoku(int arr[9][9], int difficultLevel) {

    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Solve the puzzle
    solveSudoku(arr);

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
void getUserInput(int& row, int& col, int& value) {
    std::cout << "Enter the position (row column) and value (1-9) to fill in: ";
    std::cin >> row >> col >> value;
    std::cout << std::endl;
}
int generateRandom(){
    return rand() % 9;
}

int main() {
    // create the sudoku table and fill in every square with value 0
    int sudoku[9][9] = {0};
    srand(time(nullptr));
    int rowId, colId, value;
    int prefilled = 0;
    while(prefilled < 15){
        rowId = generateRandom();
        colId = generateRandom();
        value = generateRandom() + 1;

        if (validValue(value,rowId,colId,sudoku)) {
            sudoku[rowId][colId] = value;
            prefilled++;
        }
    }
    int numToRemove;
    int diffiLevel;
    cout << "Choose your difficulty: 1.Beginner 2.Medium 3.Hard: ";
    cin >> numToRemove;
    if(numToRemove == 1){
        diffiLevel = 25;
    } else if(numToRemove == 2){
        diffiLevel = 15;
    } else if(numToRemove == 3){
        diffiLevel = 5;
    }
    generateSudoku(sudoku, diffiLevel);
    printSudoku(sudoku);
    while (hasZeroValue(sudoku)) {
            int row, col, value;
            getUserInput(row, col, value);

            if (row >= 0 && row < 9 && col >= 0 && col < 9 && value >= 1 && value <= 9 ) {
                if(validValue(value,row,col,sudoku)) {
                    if (sudoku[row][col] == 0) {
                        sudoku[row][col] = value;
                        printSudoku(sudoku);
                    } else {
                        std::cout << "That position is already filled.\n";
                    }
                } else { cout<< "This number has already existed in either row, column or box.\n";}
            } else {
                std::cout << "Invalid input. Please try again.\n";
            }
        }
        int answer;
        cout << "Solve the sudoku above: ";
        cin >> answer;
        if (answer == 1){
            solveSudoku(sudoku);
            printSudoku(sudoku);
        }
    return 0;
}
