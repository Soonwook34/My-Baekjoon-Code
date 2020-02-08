#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    bool isPrime[1000001];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    
    for(int i=2; i<N+1; i++)
        if(isPrime[i])
            for(int j=i*2; j<N+1; j+=i)
                if(isPrime[j])
                    isPrime[j] = false;
    
    for(int i=M; i<=N; i++) {
        if(isPrime[i]) {
            printf("%d\n", i);
        }
    }
    
    return 0;
}
