#include <iostream>
using namespace std;

int main() {
    int T, N;
    long long triangle[100] = {1, 1, 1, 2, 2, 3, 4, 5, 7, 9, };
    
    scanf("%d", &T);
    
    for(int i=10; i<100; i++) {
        triangle[i] = triangle[i-1] + triangle[i-5];
    }
    
    for(int t=0; t<T; t++) {
        scanf("%d", &N);
        printf("%lld\n", triangle[N-1]);
    }
    
    return 0;
}
