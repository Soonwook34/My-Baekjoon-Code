#include <stdio.h>

int main() {
    int a, b, temp;
    scanf("%d\n%d", &a, &b);
    
    printf("%d\n", a*(b%10));
    temp = b/10;
    printf("%d\n", a*(temp%10));
    temp = temp/10;
    printf("%d\n", a*temp);
    printf("%d\n", a*b);
    
    return 0;
}
