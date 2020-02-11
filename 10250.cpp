#include <iostream>
using namespace std;

int main() {
    int T, H, W, N;
    int floor, room;
    cin >> T;
    
    for(int i=0; i<T; i++) {
        cin >> H >> W >> N;
        N--;
        //층수
        floor = N%H + 1;
        //호수
        room = N/H + 1;
        
        if(room < 10)
            cout << floor << '0' << room << endl;
        else
            cout << floor << room << endl;
    }
    
    return 0;
}
