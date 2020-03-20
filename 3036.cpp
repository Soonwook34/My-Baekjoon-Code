#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000;

int getGCD(int, int);

int main() {
    int N;
    scanf("%d", &N);
    
    vector<int> ring(N);
    for(int i=0; i<N; i++) {
        scanf("%d", &ring[i]);
    }
    
    for(int i=1; i<N; i++) {
        int gcd = getGCD(max(ring[0], ring[i]), min(ring[0], ring[i]));
        printf("%d/%d\n", ring[0]/gcd, ring[i]/gcd);
    }
    
    return 0;
}

int getGCD(int a, int b) {
    if(a % b == 0) {
        return b;
    }
    else {
        return getGCD(b, a % b);
    }
}
