#include <stdio.h>

int main() {
    int a, b, c;

    scanf("%d %d %d", &a, &b, &c);

    if(a>b) {
        if(a>c) {
            printf("%d\n", b>c ? b : c);
        }
        else {
            printf("%d\n", a);
        }
    }
    else if(a>c) {
        printf("%d\n", a);
    }
    else {
        printf("%d\n", b>c ? c : b);
    }

    return 0;
}
