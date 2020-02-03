#include <stdio.h>

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d", a/b);

    a %= b;

    for(int i=0; i<15; i++) {
        if(a < b) {
            a *= 10;
            if(i==0) {
                printf(".");
                continue;
            }
            printf("0");
        }
        else {
            printf("%d", a/b);
            a %= b;
            a *= 10;
        }
    }
    return 0;
}
