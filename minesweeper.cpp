#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 8
#define HEIGHT 8
#define NUM_MINES 10

typedef struct {
    int row;
    int col;
} Cell;

typedef struct {
    int board[HEIGHT][WIDTH];
    bool visited[HEIGHT][WIDTH];
} Minesweeper;

void generateMines(Minesweeper* game) {
    int mines[NUM_MINES];
    for (int i = 0; i < NUM_MINES; i++) {
        mines[i] = rand() % (WIDTH * HEIGHT);
    }
    
    for (int i = 0; i < NUM_MINES; i++) {
        int row = mines[i] / WIDTH;
        int col = mines[i] % WIDTH;
        game->board[row][col] = -1;
    }
}

int countNeighborMines(Minesweeper* game, int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int newRow = row + i;
            int newCol = col + j;
            if (newRow >= 0 && newRow < HEIGHT && newCol >= 0 && newCol < WIDTH &&
                game->board[newRow][newCol] == -1) {
                count++;
            }
        }
    }
    return count;
}

void updateBoard(Minesweeper* game, int row, int col) {
    if (row >= 0 && row < HEIGHT && col >= 0 && col < WIDTH && !game->visited[row][col]) {
        game->visited[row][col] = true;
        if (game->board[row][col] == 0) {
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    updateBoard(game, row + i, col + j);
                }
            }
        }
    }
}

void printBoard(Minesweeper* game, bool reveal) {
    for (int row = 0; row < HEIGHT; row++) {
        for (int col = 0; col < WIDTH; col++) {
            if (game->visited[row][col] || reveal) {
                if (game->board[row][col] == -1) {
                    printf("* ");
                } else {
                    printf("%d ", game->board[row][col]);
                }
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

void playGame(Minesweeper* game) {
    generateMines(game);
    
    while (true) {
        printBoard(game, false);
        
        int row, col;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &col);
        
        if (game->board[row][col] == -1) {
            printf("Game Over!\n");
            printBoard(game, true);
            break;
        }
        
        updateBoard(game, row, col);
        
        bool win = true;
        for (int row = 0; row < HEIGHT; row++) {
            for (int col = 0; col < WIDTH; col++) {
                if (game->board[row][col] != -1 && !game->visited[row][col]) {
                    win = false;
                    break;
                }
            }
        }
        
        if (win) {
            printf("You Win!\n");
            printBoard(game, true);
            break;
        }
    }
}

int main() {
    Minesweeper game = {0};
    playGame(&game);
    
    return 0;
}
