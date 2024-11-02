#include <stdio.h>
void displayGrid(char grid[5][5]);
void findPlayer(char grid[5][5], int* playerRow, int* playerCol);
void movePlayer(char grid[5][5], int* playerRow, int* playerCol, char move, int* itemsCollected);
int main() {
    
    char grid[5][5] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    int playerRow, playerCol;
    int itemsCollected = 0;
    char move;
    findPlayer(grid, &playerRow, &playerCol);
    while (1) {
        displayGrid(grid);

        printf("Enter move (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);
        if (move == 'Q' || move == 'q') {
            printf("Game exited. Total items collected: %d\n", itemsCollected);
            break;
        }

        
        movePlayer(grid, &playerRow, &playerCol, move, &itemsCollected);
    }

    return 0;
}
void displayGrid(char grid[5][5]) {
    printf("Grid:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}


void findPlayer(char grid[5][5], int* playerRow, int* playerCol) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (grid[i][j] == 'P') {
                *playerRow = i;
                *playerCol = j;
                return;
            }
        }
    }
}


void movePlayer(char grid[5][5], int* playerRow, int* playerCol, char move, int* itemsCollected) {
    int newRow = *playerRow;
    int newCol = *playerCol;

    
    if (move == 'W' || move == 'w') newRow--;
    else if (move == 'S' || move == 's') newRow++;
    else if (move == 'A' || move == 'a') newCol--;
    else if (move == 'D' || move == 'd') newCol++;

   
    if (newRow < 0 || newRow >= 5 || newCol < 0 || newCol >= 5) {
        printf("Move out of bounds!\n");
        return;
    }
    if (grid[newRow][newCol] == 'X') {
        printf("Obstacle encountered! Cannot move there.\n");
        return;
    }

    
    if (grid[newRow][newCol] == 'I') {
        (*itemsCollected)++;
        printf("Item collected! Total items: %d\n", *itemsCollected);
    }

    
    grid[*playerRow][*playerCol] = ' '; 
    grid[newRow][newCol] = 'P';         
    *playerRow = newRow;
    *playerCol = newCol;
}

