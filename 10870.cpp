#include <iostream>

int fibonacci(int);

int main() {
    int a;
    scanf("%d", &a);
    
    printf("%d\n", fibonacci(a));
    
    return 0;
}

int fibonacci(int n) {
    if(n < 2)
        return n;
    return fibonacci(n-1) + fibonacci(n-2);
}
