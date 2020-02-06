#include <iostream>
using namespace std;

int main() {
    int N;
    int i=1, cnt=1;
    cin >> N;
    
    while(i < N) {
    	i += cnt*6;
    	cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
