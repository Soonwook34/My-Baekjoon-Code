#include <stdio.h>

int main() {
    int a, b, c, ans;
    int cnt[10] = {0};
    scanf("%d %d %d", &a, &b, &c);
    ans = a*b*c;
    
    while(ans > 0) {
        cnt[ans%10]++;
        ans /= 10;
    }
    
    for(int i=0; i<10; i++) {
        printf("%d\n", cnt[i]);
    }
    return 0;
}
