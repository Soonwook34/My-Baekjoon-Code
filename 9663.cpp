#include <iostream>
using namespace std;

int N;
int cnt=0;
int location[16];

void queen(int);

int main() {
    scanf("%d", &N);
    
    queen(0);
    printf("%d", cnt);
    
    return 0;
}

void queen(int num) {
    if(num == N) {
        cnt++;
        return;
    }
    bool valid = true;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=num; j++) {
            if(i == location[j]) {
                valid = false;
                break;
            }
            else if(i==location[j]+(num+1-j) || i==location[j]-(num+1-j)) {
                valid = false;
                break;
            }
        }
        if(valid) {
            location[num+1] = i;
            queen(num+1);
        }
        valid = true;
    }
}
