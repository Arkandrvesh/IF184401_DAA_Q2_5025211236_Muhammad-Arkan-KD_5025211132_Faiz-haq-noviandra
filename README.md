# IF184401_DAA_Q2_5025211236_Muhammad-Arkan-KD_5025211132_Faiz-haq-noviandra_5025211083_Bernisko-Fancy-Aljunes-P

## Description
1.	Preprocessor Directives and Libraries:
•	#include <stdio.h>: Standard library for input/output functions.
•	#include <stdlib.h>: Standard library for general functions like memory allocation and data type conversions.
•	#include <stdbool.h>: Library for boolean data type.
2.	Constants:
•	WIDTH and HEIGHT: Define the width and height of the Minesweeper board.
•	NUM_MINES: Number of mines in the game.
3.	Data Types:
•	Cell: A structure representing the row and column coordinates on the Minesweeper board.
•	Minesweeper: A structure representing the Minesweeper game. It has two-dimensional arrays, board to store the Minesweeper board data, and visited to track which cells have been visited.
4.	generateMines Function:
•	Generates random positions for mines and places them on the Minesweeper board.
•	Uses the mines array to temporarily store mine positions.
•	Loops to generate random numbers and ensures that the numbers are unique and within the board range.
•	Then, places the mines on the board by changing the board value at the corresponding positions to -1.

5.	countNeighborMines Function:
•	Counts the number of mines around a cell at position (row, col).
•	Loops to check the neighboring cells of the given cell.
•	Checks if the neighboring cell contains a mine (-1) and increments the count if true.
•	Returns the count of neighboring mines found.
6.	updateBoard Function:
•	Updates the board based on the cell selection by the player.
•	Checks if the selected cell is within the board range and hasn't been visited.
•	If the selected cell is empty (value 0), then recursively updates the neighboring empty cells as well.
•	After performing the update, marks the selected cell as visited.
7.	printBoard Function:
•	Prints the Minesweeper board to the console.
•	If reveal is true, all cells will be displayed, including hidden mines.
•	If reveal is false, only the visited cells will be displayed.
•	Visited cells are marked with "-" if reveal is false or with numbers inside if reveal is true.
•	Mines are marked with "*" if reveal is true.
8.	playGame Function:
•	Starts the Minesweeper game.
•	Calls the generateMines function to randomly place mines on the board.
•	Enters the main game loop.
•	In each iteration, prints the board to the console using the printBoard function (with reveal set to false to hide the mines).
•	Asks the player to enter the row and column of the cell they want to select.
•	If the selected cell contains a mine, prints "Game Over!" and displays the board with the printBoard function (with reveal set to true to show all cells including mines).
•	If the selected cell does not contain a mine, updates the board by calling the updateBoard function and checks for a win condition.
•	If the player wins, prints "You Win!" and displays the board with the printBoard function (with reveal set to true to show all cells including mines)..
9.	main Function:
•	The main function of the program.
•	Creates a game object of type Minesweeper and initializes it with 0.
•	Calls the playGame function using the address of the game object.
•	Returns 0 as an indication of successful program execution.

##output
The output of the program can vary depending on the user's input and the randomly generated mine positions. However, here's an example of what the output might look like during a game of Minesweeper:

![image](https://github.com/Arkandrvesh/IF184401_DAA_Q2_5025211236_Muhammad-Arkan-KD_5025211132_Faiz-haq-noviandra/assets/116497822/238025c9-d5ae-42e6-a600-45e9a8e4fa8c)

In this example, the player selected cells (9, 1), (0, 0), and (1, 2) during their turns. They avoided the mine at position (9, 1) and successfully uncovered all non-mine cells, resulting in a win. The numbers on the board represent the count of neighboring mines in each cell.
Use depth-first search when revealing squares after a player’s click. When the player clicks on a square with no mines nearby, I reveal that square. Then I check to see if the square above it has any mines nearby. If it does not, I check the square above that one and so on until I find a square with mines nearby. After I find a square with mines nearby I check all of its neighbors, (upper right, right, lower right…) going clockwise until I find a neighbor without any mines nearby (value 0) and then making that one my current focus.

