#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int T,  cnt=0, x;
    cin >> T;
    
    bool isPrime[1001];
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    
    for(int i=2; i<1001; i++)
        for(int j=i*2; j<1001; j+=i)
            isPrime[j] = false;
    
    for(int t=0; t<T; t++) {
    	cin >> x;
        if(isPrime[x])
        	cnt++;
    }
    
    cout << cnt << endl;
    
    return 0;
}
