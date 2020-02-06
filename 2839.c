#include <stdio.h>

int main() {
    int n, five, three = 0;

    scanf("%d", &n);

    five = n/5;
    n %= 5;

    if(five == 0) {
        printf("%d\n", n%3? -1 : n/3);
        return 0;
    }

    while(five+1) {
        if(!(n%3)) {
            printf("%d\n", five + n/3);
            return 0;
        }
        five--;
        n += 5;
    }
    printf("%d\n", -1);
    return 0;
}
