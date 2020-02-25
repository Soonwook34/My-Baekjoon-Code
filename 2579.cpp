#include <iostream>
#include <algorithm>
using namespace std;

int N;
int score[300];
int maxScore[300];

int getMaxScore();

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d", &score[i]);
    }
    
    printf("%d\n", getMaxScore());
    
    return 0;
}

int getMaxScore() {
    maxScore[0] = score[0];
    maxScore[1] = max(score[0]+score[1], score[1]);
    maxScore[2] = max(score[0]+score[2], score[1]+score[2]);
    
    for(int i=3; i<N; i++) {
        //max(직전에 두 칸 뛸 때, 먼저 두 칸 뛸 때)
        maxScore[i] = max((maxScore[i-2]+score[i]), (maxScore[i-3]+score[i-1]+score[i]));
    }
    
    return maxScore[N-1];
}
