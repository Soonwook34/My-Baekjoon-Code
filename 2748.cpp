#include <iostream>
using namespace std;

int main() {
    int N;
    //90번째 피보나치 수가 2,880,067,194,370,816,120이므로 long long형 사용
    long long fibonacci[91] = {0, 1, };
    
    scanf("%d", &N);
    
    for(int i=2; i<=N; i++) {
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
    }
    
    cout << fibonacci[N] << '\n';
    
    return 0;
}
