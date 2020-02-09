#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int M, N, sum=0, min=0;
    cin >> M >> N;
    bool isPrime[10001];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    
    for(int i=2; i<10001; i++)
        if(isPrime[i])
            for(int j=i*2; j<10001; j+=i)
                if(isPrime[i])
                    isPrime[j] = false;
    
    for(int i=M; i<=N; i++) {
        if(isPrime[i]) {
            sum += i;
            if(min == 0)
                min = i;
        }
    }
    if(sum == 0) {
        cout << -1 << endl;
        return 0;
    }
    
    cout << sum << '\n' << min << endl;
    
    return 0;
}
