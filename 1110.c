#include <stdio.h>

int main() {
    int a, n=1, t_a, t_b, temp;
    scanf("%d", &a);
    
    temp = a/10;
    t_a = a%10;
    t_b = (temp+t_a)%10;
    while(t_a*10+t_b != a) {
        temp = t_a;
        t_a = t_b;
        t_b = (temp+t_a)%10;
        n++;
    }
    
    printf("%d\n", n);
    return 0;
}
