#include <stdio.h>
#include <stdbool.h>

int main() {
    _Bool isNotSelf[10001] = {false};
    int sum=0, temp=0;
    
    for(int i=1; i<=10000; i++) {
        temp = i;
        sum += i + temp%10;
        while(temp/10 != 0) {
        	temp /= 10;
            sum += temp%10;
        }
        if(sum <= 10000) {
            isNotSelf[sum] = true;
        }
        sum = 0;
    }
    
    for(int i=1; i<=10000; i++)
        if(!isNotSelf[i])
            printf("%d\n", i);
    
    return 0;
}
