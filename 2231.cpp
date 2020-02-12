#include <iostream>
using namespace std;

int main() {
    int N, sum, temp;
    scanf("%d", &N);
    
    for(int i=1; i<N; i++) {
        sum = temp = i;
        while(temp >= 10) {
            sum += temp%10;
            temp /= 10;
        }
        sum += temp;
        if(sum == N) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("0\n");
    return 0;
}
