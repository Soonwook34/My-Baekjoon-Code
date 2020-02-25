#include <iostream>
#include <algorithm>
using namespace std;

int N;
int minCount[1000001] = {0, };

int make1();

int main() {
    scanf("%d", &N);
    
    printf("%d\n", make1());
    
    return 0;
}

int make1() {
    minCount[1] = 0;
    
    for(int i=2; i<=N; i++) {
        //바로 전 수의 최소 횟수 + 1(1을 뺀 경우)
        minCount[i] = minCount[i-1] + 1;
        //2로 나누어 떨어질 경우
        if(i%2 == 0) {
            //min(바로 전 수의 최소 횟수 + 1, 2로 나눈 수의 최소 횟수 + 1)
            minCount[i] = min(minCount[i], minCount[i/2] + 1);
        }
        //3으로 나누어 떨어질 경우
        if(i%3 == 0) {
            //min(바로 전 수의 최소 횟수 + 1, 3으로 나눈 수의 최소 횟수 + 1)
            minCount[i] = min(minCount[i], minCount[i/3] + 1);
        }
    }
    
    return minCount[N];
}
