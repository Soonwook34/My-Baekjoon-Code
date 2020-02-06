#include <iostream>
using namespace std;

int main() {
    int X, a, b, diff, sum=1, cnt=1;
    cin >> X;
    
    while(sum < X) {
        cnt++;
        sum += cnt;
    }
    
    if(cnt%2) {
        a = sum - X + 1;
        b = cnt - a + 1;
    }
    else {
        b = sum - X + 1;
        a = cnt - b + 1;
    }
    
    cout << a << '/' << b << endl;
    
    return 0;
}
