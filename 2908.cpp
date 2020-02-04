#include <iostream>
using namespace std;

void reverse_int (int &);

int main() {
    int a, b;
    cin >> a >> b;
    
    reverse_int(a);
    reverse_int(b);
    cout << ((a>b) ? a : b) << endl;
    
    return 0;
}

void reverse_int(int &src) {
    src = (src%10)*100 + ((src/10)%10)*10 + (src/100);
    return;
}
