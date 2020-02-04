#include <stdio.h>

int main() {
    int n, k, sum = 0;

    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        scanf("%1d", &k);
        sum +=k;
    }

    printf("%d\n", sum);

    return 0;
}
