#include <stdio.h>

int main() {
    signed int n;

    scanf("%d", &n);

    if(n<=100000) {
        for(int i=n; i>=1; i--) {
            printf("%u\n", i);
        }
    }

    return 0;
}
