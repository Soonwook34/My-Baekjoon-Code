#include <iostream>
using namespace std;

int main() {
    int n, x;
    int cnt[42] = {1, 0};
    cin >> n;
    
    for(int i=2; i<42; i++) {
        cnt[i] = cnt[i-1] + cnt[i-2];
    }
    for(int i=0; i<n; i++) {
        cin >> x;
        cout << cnt[x] << ' ' << cnt[x+1] << endl;
    }

    return 0;
}
