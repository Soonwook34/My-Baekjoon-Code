#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int x, cnt=0;
    bool isPrime[246913];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    
    for(int i=2; i<246913; i++)
        if(isPrime[i])
            for(int j=i*2; j<246913; j+=i)
                if(isPrime[j])
                    isPrime[j] = false;
    
    while(1) {
        scanf("%d", &x);
        if(x == 0)
            break;
        for(int i=x+1; i<x*2+1; i++) {
            if(isPrime[i])
                cnt++;
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
    
    return 0;
}
