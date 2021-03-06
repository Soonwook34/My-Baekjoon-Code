#include <iostream>
using namespace std;

int N, M;
int permutation[9];

void backTracking(int);

int main() {
    scanf("%d %d", &N, &M);
    
    backTracking(0);
    
    return 0;
}

void backTracking(int step) {
    if(step == M) {
        for(int i=0; i<M; i++) {
            printf("%d ", permutation[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=1; i<=N; i++) {
        permutation[step] = i;
        backTracking(step+1);
    }
    
}
