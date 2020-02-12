#include <iostream>
#include <cstring>
using namespace std;

bool isPrime[10001];

void goldbach(int);
int nextBigPrime(int);

int main() {
    int T, x;
    scanf("%d", &T);
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    
    for(int i=2; i<10001; i++)
        if(isPrime[i])
            for(int j=i*2; j<10001; j+=i)
                if(isPrime[j])
                    isPrime[j] = false;
    
    for(int t=0; t<T; t++) {
        scanf("%d", &x);
        goldbach(x);
    }
    
    return 0;
}

void goldbach(int x) {
    int num1=3, num2=10000;
    for(int i=2; i<x/2+1; i=nextBigPrime(i)) {
        if(isPrime[x-i]) {
            if(num2-num1 > x-i-i) {
                num1 = i;
                num2 = x-i;
            }
        }
    }
    printf("%d %d\n", num1, num2);
}

int nextBigPrime(int x) {
    for(int i=x+1; i<10000; i++) {
        if(isPrime[i])
            return i;
    }
    return x;
}
