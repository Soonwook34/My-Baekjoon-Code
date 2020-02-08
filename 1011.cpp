#include <iostream>
using namespace std;

int main() {
    int T;
    double x, y, d, i, cnt=2;
    cin >> T;
    
    for(int t=0; t<T; t++){
        cin >> x >> y;
        d = y - x;
        
        for(i=1, cnt=2; cnt<d; i++) {
            cnt += (i+1)*2;
        }
        
        if(cnt-i < d) {
        	cout << i*2 << endl;
        }
        else {
        	cout << i*2-1 << endl;
        }
    }
    
    return 0;
}
