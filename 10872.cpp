#include <iostream>

int factorial(int);

int main() {
    int a;
    scanf("%d", &a);
    
    printf("%d\n", factorial(a));
    
    return 0;
}

int factorial(int n) {
    if(n <= 1)
        return 1;
    
    return n * factorial(n-1);
}
