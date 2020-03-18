#include <iostream>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    
    while(a != 0 && b != 0) {
        if(a % b == 0)
            printf("multiple\n");
        else if(b % a == 0)
            printf("factor\n");
        else
            printf("neither\n");
        scanf("%d %d", &a, &b);
    }
    
    return 0;
}
