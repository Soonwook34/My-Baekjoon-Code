#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int N, cnt=0, num=665;
    string test;
    scanf("%d", &N);
    
    while(N != cnt) {
        num++;
        if(to_string(num).find("666") != -1)
            cnt++;
    }
    
    printf("%d\n", num);
    
    return 0;
}
