#include <iostream>
using namespace std;

int main() {
    int x, y;
    
    scanf("%d%d", &x, &y);
    
    int quadrant;
    if(x > 0) {
        if(y > 0)
            quadrant = 1;
        else
            quadrant = 4;
    }
    else {
        if(y > 0)
            quadrant = 2;
        else
            quadrant = 3;
    }
    
    printf("%d\n", quadrant);
    
    return 0;
}
