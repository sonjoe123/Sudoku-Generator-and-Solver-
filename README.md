# Sudoku-Generator-and-Solver
The Sudoku Game project is an interactive console-based game that allows players to play the classic Sudoku puzzle. The project provides instructions on how to play the game and implements the backtracking algorithm to solve the Sudoku grid.

### Instructions on How to Play:

1. The game starts by choosing the difficulty of the game.

2. The player is presented with the initial Sudoku grid, which contains some pre-filled numbers.

3. The player can request to solve the whole puzzle or solve it by themselves.

4. The player needs to fill in the remaining empty cells by providing the position (row and column) and the value (1-9) to fill in.

5. The game validates the input and checks if the provided number is valid based on the Sudoku rules (no repetition of numbers in the same row, column, or 3x3 sub-grid).

6. If the input is valid, the game updates the grid with the provided number.

7. The player continues to fill in the numbers until the entire grid is filled.

### Backtracking Algorithm:
The project utilizes the backtracking algorithm to solve the Sudoku puzzle. The backtracking algorithm is a systematic approach that explores all possible solutions by making choices and undoing them if they lead to an invalid solution. In the context of Sudoku, the algorithm tries different numbers at empty cells, checks if the number is valid based on the rules of Sudoku, and recursively explores further until a solution is found.

The backtracking algorithm employed in the project is implemented using a recursive function. The function iterates through each cell in the Sudoku grid, and if the cell is empty, it tries different numbers from 1 to 9. It checks if the number is valid by verifying that it does not violate the Sudoku rules in its row, column, and 3x3 sub-grid. If a valid number is found, it fills in the cell and recursively calls itself to solve the rest of the grid. If a solution cannot be found with the current number, it backtracks by undoing the previous choice and tries the next number.