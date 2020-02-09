#include <iostream>
using namespace std;

int combination(int, int);

int main() {
    int T, k, n;
    cin >> T;
    
    for(int t=0; t<T; t++) {
        cin >> k >> n;
        cout << combination(k+n, n-1) << endl;
    }
    
    return 0;
}

int combination(int n, int c) {
    int i, ans = 1;
    for(i=0; i<c; i++) {
        ans = ans * n / (i+1);
        n--;
    }
    return ans;
}
