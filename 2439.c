#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);

    if(n>=1 && n<=100) {
        for(int i=0; i<n; i++) {
            for(int j=1; j<n-i; j++) {
                printf(" ");
            }
            for(int j=0; j<=i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
