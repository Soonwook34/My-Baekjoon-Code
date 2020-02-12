#include <iostream>
#include <cmath>
using namespace std;

char board[50][50];

int boardRequirement(int, int);

int main() {
    int N, M, min=64, temp;
    scanf("%d %d", &N, &M);
    
    for(int n=0; n<N; n++) {
        scanf("%s", board[n]);
    }
    
    for(int n=0; n<N-7; n++) {
        for(int m=0; m<M-7; m++) {
            temp = boardRequirement(n, m);
            if(temp < min)
                min = temp;
        }
    }
    
    printf("%d\n", min);
    
    return 0;
}

int boardRequirement(int a, int b) {
    int first=0, second=0;
    
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[a+i][b+j] == 'W') {
                if((i+j)%2)
                    first++;
                else
                    second++;
            }
        }
    }
    return min(32-first+second, first+32-second);
}
