#include <stdio.h>

int check(int);

int main() {
    int n, cnt=0;
    scanf("%d", &n);
    
    for(int i=1; i<=n; i++) {
        if(check(i) == 1)
            cnt++;
    }
    
    printf("%d\n", cnt);
    
    return 0;
}

int check(int x) {
    if(x < 100)
        return 1;
    int d = x%10 - (x/10)%10;
    x /= 10;
    while(x/10) {
        if(x%10 - (x/10)%10 != d)
            return 0;
        x /= 10;
    }
    return 1;
}
