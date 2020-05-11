#include <iostream>
#include <cmath>
using namespace std;

int board[9][9] = { 0, };       //스도쿠 판
int Row[9] = { 0, };            //i열에 쓰인 수를 비트로 저장하는 Row[i]
int Col[9] = { 0, };            //i행에 쓰인 수를 비트로 저장하는 Col[i]
int Square[9] = { 0, };         //i번째 3*3칸에 쓰인 수를 비트로 저장하는 Square[i]
int bitNum[10] = { 0, 1, 2, 4, 8, 16, 32, 64, 128, 256 };   //비트 연산을 위한 변수

void makeSudoku(int);       //스도쿠를 완성하는 함수
void printSudoku();         //완성한 스도쿠를 출력하는 함수

int main() {
    //입력 받기
    for (int x = 0; x < 9; x++) {
        for (int y = 0; y < 9; y++) {
            scanf("%d", &board[x][y]);
            if (board[x][y] != 0) {
                //Row, Col, Square에 정보 저장
                Row[x] |= bitNum[board[x][y]];
                Col[y] |= bitNum[board[x][y]];
                Square[(x / 3) * 3 + (y / 3)] |= bitNum[board[x][y]];
            }
        }
    }
    makeSudoku(0);

    return 0;
}

void makeSudoku(int cnt) {
    //현재 위치 구하기
    int x = cnt / 9;
    int y = cnt % 9;
    int square = (x / 3 * 3) + (y / 3);

    //마지막 칸까지 다 채워졌으면 출력하고 프로그램 종료
    if (cnt == 81) {
        printSudoku();
        exit(0);
    }

    //빈 칸이라면
    if (board[x][y] == 0) {
        for (int i = 1; i <= 9; i++) {
            //해당 행과 열과 3*3칸에 i가 쓰이지 않았다면
            if (((Row[x] & bitNum[i]) == 0) && ((Col[y] & bitNum[i]) == 0) && ((Square[square] & bitNum[i]) == 0)) {
                //i가 해당 칸에 쓰인다고 가정하고 저장
                Row[x] |= bitNum[i];
                Col[y] |= bitNum[i];
                Square[square] |= bitNum[i];
                board[x][y] = i;
                //다음 칸으로 이동
                makeSudoku(cnt + 1);
                //마지막 칸까지 가지 못하면(해당 가정이 틀렸을 경우) 정보 삭제
                Row[x] -= bitNum[i];
                Col[y] -= bitNum[i];
                Square[square] -= bitNum[i];
                board[x][y] = 0;
            }
        }
    }
    //채워진 칸이라면 다음 칸으로 이동
    else makeSudoku(cnt + 1);

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
