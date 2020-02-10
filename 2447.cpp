#include <iostream>
#include <cstring>
#include <cmath>

char star[2188][2188];

void draw(int);
void copy(int, int, int);

int main() {
    int N;
    scanf("%d", &N);
    memset(star, ' ', sizeof(star));
    star[0][0] = '*';
    
    for(int n=3; n<=N; n*=3)
        draw(n);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%c", star[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void draw(int n) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i==1 && j==1)
                continue;
            copy(n/3, n/3*i, n/3*j);
        }
    }
}

void copy(int n, int a, int b) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            star[a+i][b+j] = star[i][j];
        }
    }
    return;
}
