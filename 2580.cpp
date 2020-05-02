#include<iostream>
using namespace std;

int board[9][9];        //스도쿠 판
bool Row[9][9];         //i열에 j가 쓰였는지 저장하는 Row[i][j]
bool Col[9][9];         //i행에 j가 쓰였는지 저장하는 Col[i][j]
bool Square[9][9];      //i번째 3*3칸에 j가 쓰였는지 저장하는 Square[i][j]

void sudoku(int);       //스도쿠를 완성하는 함수
void printSudoku();     //완성한 스도쿠를 출력하는 함수

int main() {
    //입력 받기
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            scanf("%d", &board[x][y]);
            if (board[x][y] != 0) {
                //Row, Col, Square에 정보 저장
                Row[x][board[x][y]] = true;
                Col[y][board[x][y]] = true;
                Square[(x / 3) * 3 + (y / 3)][board[x][y]] = true;
            }
        }
    }

    sudoku(0);
    
    return 0;
}

void sudoku(int cnt) {
    int x = cnt / 9;
    int y = cnt % 9;

    //마지막 칸까지 다 채워졌으면 출력하고 종료
    if (cnt == 81) {
        printSudoku();
        exit(0);
    }

    //빈 칸이라면
    if (board[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            //해당 행과 열과 3*3칸에 i가 쓰이지 않았다면
            if (!Row[x][i] && !Col[y][i] && !Square[(x / 3 * 3) + (y / 3)][i]) {
                //i가 해당 칸에 쓰인다고 가정하고 저장
                Row[x][i] = Col[y][i] = true;
                Square[(x / 3 * 3) + (y / 3)][i] = true;
                board[x][y] = i;
                //다음 칸으로 이동
                sudoku(cnt + 1);
                //마지막 칸까지 가지 못하면(해당 가정이 틀렸을 경우) 정보 삭제
                Row[x][i] = Col[y][i] = false;
                board[x][y] = 0;
                Square[(x / 3 * 3) + (y / 3)][i] = false;
            }
        }
    }
    //채워진 칸이라면 다음 칸으로 이동
    else sudoku(cnt + 1);

    return;
}

void printSudoku() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return;
}
