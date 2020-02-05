#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int getMaxD(int);

int N;
int D[1001];
int maxD[1001];
int rule[1001][1001];

int main() {
    int T;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        int K, a, b, x;
        cin >> N >> K;
        
        for(int j=1; j<=N; j++)
            cin >> D[j];
        memset(rule, 0, sizeof(rule));
        memset(maxD, -1, sizeof(maxD));
        
        for(int j=0; j<K; j++) {
            cin >> a >> b;
            rule[a][b] = 1;
        }
        cin >> x;
        cout << getMaxD(x) << endl;
    }
}
int getMaxD(int x) {
    int m = 0;
    
    if(maxD[x] != -1)
        return maxD[x];
    
    for(int i=1; i<=N; i++) {
        if(rule[i][x])
            m = max(m, getMaxD(i));
    }
    maxD[x] = D[x] + m;
    return maxD[x];
}
