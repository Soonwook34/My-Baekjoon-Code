#include <stdio.h>

int main() {
    int a, cnt=0;
    int rem[42] = {0};
    
    for(int i=0; i<10; i++) {
        scanf("%d", &a);
        rem[a%42] = 1;
    }
    for(int i=0; i<42; i++) {
        cnt += rem[i];
    }
    
    printf("%d\n", cnt);
    
    return 0;
}
