#include <iostream>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    
    int NK = 1, divide = 1;
    
    for(int i=1; i<=K; i++, N--) {
        NK *= N;
        divide *= i;
    }
    
    printf("%d\n", NK/divide);
    
    return 0;
}
