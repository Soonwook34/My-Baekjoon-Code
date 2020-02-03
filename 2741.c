#include <stdio.h>

int main() {
    signed int n;

    scanf("%d", &n);

    if(n<=100000) {
        for(int i=1; i<=n; i++) {
            printf("%u\n", i);
        }
    }

    return 0;
}
