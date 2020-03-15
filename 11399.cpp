#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compareTime(int, int);

int main() {
    int N;
    scanf("%d", &N);
    
    vector<int> withdrawTime(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &withdrawTime[i]);
    }

    sort(withdrawTime.begin(), withdrawTime.end(), compareTime);
    int totalTime = 0;
    for (int i = 0, n = N; i < N; i++) {
        totalTime += withdrawTime[i]*n;
        n--;
    }
    
    printf("%d\n", totalTime);
    
    return 0;
}

bool compareTime(int a, int b) {
    return (a < b);
}
