//Input a connect 4 board and connect 4 move (X or O followed by the coordinates) to see whether the move results in a draw,
//win, or loss


#include <stdio.h>

int evaluate(char grid[6][7]);

int main(void) {
    char grid[6][7];
    char placeType; //stores X or O
    int placeColumn; //stores 0-6
    int runEval = 1;
    scanf("%c", &placeType);
    scanf("%d", &placeColumn);
    for (int i = 0; i < 6; i++) {
        scanf("%s", &grid[i]);
    }

    //Check if it's illegal:
    if (grid[0][placeColumn] != '.') {
        printf("Illegal move\n");
        runEval = 0;

    }  
    for (int i = 0; i < 7; i++) {
        if (grid[i][placeColumn] != '.' || i == 6) {
            grid[i-1][placeColumn] = placeType;
            break;
        }
    }
    if (runEval) {
        switch (evaluate(grid)) {
            case 0:
                printf("Tie game\n");
                break;
            case 1: 
                printf("X wins\n");
                break;
            case 2:
                printf("O wins\n");
                break;
            case 3:
                printf("Ongoing game\n");
                break;
        }
    }
}


int evaluate(char grid[6][7]) {
    //check columns, rows, and left/right diagonals:
    int spaceExists = 0; //check if a dot exists to see if game is tied
    int xWins = 0;
    int oWins = 0;
    char tempVal;
    //Check for a tie:
    for (int i = 0; i < 7; i++) {
        if (grid[0][i] == '.') {
            spaceExists = 1;
        }
    }
    if (!spaceExists) {
        return 0;
    }
    //Check for a row:
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            tempVal = grid[i][j];
            if (tempVal != '.') {
                for (int k = 0; k < 4; k++) {
                    if (!(grid[i][j+k] == tempVal)) {
                        break;
                    }
                    if (k == 3) {
                        return (tempVal == 'X') ? 1 : 2;
                    }
                }
            }
        }
    }
    //Check for a column:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 7; j++) {
            tempVal = grid[i][j];
            if (tempVal != '.') {
                for (int k = 0; k < 4; k++) {
                    if (!(grid[i+k][j] == tempVal)) {
                        break;
                    }
                    if (k == 3) {
                        return (tempVal == 'X') ? 1 : 2;
                    }
                }
            }
        }
    }
    //Check for a bottom-right diagonal:
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            tempVal = grid[i][j];
            if (tempVal != '.') {
                for (int k = 0; k < 4; k++) {
                    if (!(grid[i+k][j+k] == tempVal)) {
                        break;
                    }
                    if (k == 3) {
                        return (tempVal == 'X') ? 1 : 2;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 3; j < 7; j++) {
            tempVal = grid[i][j];
            if (tempVal != '.') {
                for (int k = 0; k < 4; k++) {
                    if (!(grid[i+k][j-k] == tempVal)) {
                        break;
                    }
                    if (k == 3) {
                        return (tempVal == 'X') ? 1 : 2;
                    }
                }
            }
        }
    }
    return 3; //draw


    return 1;
}