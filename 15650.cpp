#include <iostream>
using namespace std;

int N, M;
int permutation[9];
bool check[9] = {false, };

void backTracking(int, int);

int main() {
    scanf("%d %d", &N, &M);
    
    backTracking(0, 0);
    
    return 0;
}

void backTracking(int prev, int step) {
    if(step == M) {
        for(int i=0; i<M; i++) {
            printf("%d ", permutation[i]);
        }
        printf("\n");
        return;
    }
    
    for(int i=prev+1; i<=N; i++) {
        permutation[step] = i;
        backTracking(i, step+1);
    }
    
}
