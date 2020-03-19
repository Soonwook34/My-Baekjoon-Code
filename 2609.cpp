#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <cstring>
using namespace std;

#define MAX 10000

vector<pair<int, int>> totalPrimeCount;

void getPrimeNumber();

int main() {
    int N = 2;
    int number[N];
    scanf("%d %d", number, number+1);
    
    getPrimeNumber();
    
    vector<vector<pair<int, int>>> numberPrimeCount(N, totalPrimeCount);
    for(int i=0; i<N; i++) {
        int num = number[i];
        for(int j=0; totalPrimeCount[j].first<=num; j++) {
            while(num%totalPrimeCount[j].first == 0) {
                num /= totalPrimeCount[j].first;
                numberPrimeCount[i][j].second++;
            }
        }
    }
    
    int gcd = 1, lcm = 1;
    for(int i=0; i < totalPrimeCount.size(); i++) {
        gcd *= pow(totalPrimeCount[i].first, min(numberPrimeCount[0][i].second, numberPrimeCount[1][i].second));
        lcm *= pow(totalPrimeCount[i].first, max(numberPrimeCount[0][i].second, numberPrimeCount[1][i].second));
    }
    
    printf("%d\n%d\n", gcd, lcm);
    
    return 0;
}

void getPrimeNumber() {
    bool isPrime[MAX + 1];
    memset(isPrime, true, MAX+1);
    
    for(int i=2; i<=sqrt(MAX); i++) {
        if(isPrime[i] == false)
            continue;
        for(int j = i * i; j <= MAX + 1; j += i)
            isPrime[j] = false;
    }
    
    for(int i=2; i <= MAX; i++) {
        if(isPrime[i])
            totalPrimeCount.push_back(pair<int, int>(i, 0));
    }
}
