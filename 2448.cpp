#include <iostream>
#include <cmath>
using namespace std;

void drawBoard(int, int);   //별찍기
void printBoard(int);       //별찍기 출력

bool board[3072][6144] = {false, }; //별찍기 판

int main() {
    int N;
    
    scanf("%d", &N);
    
    drawBoard(N, 0);
    printBoard(N);
    
    return 0;
}

void drawBoard(int N, int step) {
    //마지막 단계
    if(N < 3*pow(2, step)) {
        return;
    }
    //첫 단계
    else if(step == 0) {
        board[0][N-1] = board[1][N-2] = board[1][N] = board[2][N-3] = board[2][N-2] = board[2][N-1] = board[2][N] = board[2][N+1] = true;
    }
    //윗 단계 복사하기
    else {
        int sero = 3 * pow(2, step-1);
        int garo = 3 * pow(2, step);
        
        for(int i=0; i<sero; i++) {
            for(int j=0; j<garo-1; j++) {
                board[i+sero][N-garo+j] = board[i+sero][N+j] = board[i][N-sero+j];
            }
        }
    }
    //다음 단계 호출하기
    drawBoard(N, step+1);
}

void printBoard(int N) {
    int M = N * 2;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == true)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}
