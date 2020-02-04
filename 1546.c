#include <stdio.h>

int main() {
    int n, sum = 0, a, m = 0, i;

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%d", &a);
        sum += a;
        if(a>m) {
            m = a;
        }
    }
    printf("%.2f\n", (float)sum/m/n*100);

    return 0;
}
