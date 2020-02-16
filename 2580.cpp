#include<iostream>
using namespace std;
 
int board[9][9];
bool Row[9][9];
bool Col[9][9];
bool Square[9][9];

void sudoku(int);
void printSudoku();

int main() {
    for(int x=0; x<9; x++) {
        for(int y=0; y<9; y++) {
            scanf("%d", &board[x][y]);
            if (board[x][y] != 0) {
                Row[x][board[x][y]] = true;
                Col[y][board[x][y]] = true;
                Square[(x/3)*3 + (y/3)][board[x][y]] = true;
            }
        }
    }
    
    sudoku(0);
    return 0;
}

void sudoku(int cnt)
{
    int x = cnt / 9;
    int y = cnt % 9;
    
    if (cnt == 81) {
        printSudoku();
        exit(0);
    }
 
    if (board[x][y] == 0) {
        for (int i=1; i<=9; i++) {
            if (!Row[x][i] && !Col[y][i] && !Square[(x/3*3)+(y/3)][i]) {
                Row[x][i] = Col[y][i] = true;
                Square[(x/3*3)+(y/3)][i] = true;
                board[x][y] = i;
                
                sudoku(cnt+1);
                
                Row[x][i] = Col[y][i] = false;
                board[x][y] = 0;
                Square[(x/3*3)+(y/3)][i] = false;
            }
        }
    }
    else sudoku(cnt+1);
}

void printSudoku()
{
    for (int i=0; i<9; i++) {
        for (int j=0; j<9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}
