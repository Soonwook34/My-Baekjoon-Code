#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int a, b, c, maxValue;
    bool isRight;
    
    scanf("%d %d %d", &a, &b, &c);
    while(!(a==0 && b==0 && c==0)) {
        maxValue = max(max(a, b), c);
        if(maxValue == a)
            isRight = !(a*a - (b*b + c*c));
        else if(maxValue == b)
            isRight = !(b*b - (a*a + c*c));
        else
            isRight = !(c*c - (a*a + b*b));
        
        printf("%s\n", isRight ? "right" : "wrong");
        scanf("%d %d %d", &a, &b, &c);
    }
    
    return 0;
}
