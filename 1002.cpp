#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int T;
    int x1, y1, r1, x2, y2, r2;
    double d;
    
    scanf("%d", &T);
    
    for(int t=0; t<T; t++) {
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        
        if(x1==x2 && y1==y2 && r1==r2) {
            printf("-1\n");
            continue;
        }
        
        d = sqrt(pow(abs(x1-x2), 2) + pow(abs(y1-y2), 2));
        if(d > r1 + r2)
            printf("0\n");
        else if(d == r1+r2 || d == abs(r1-r2))
            printf("1\n");
        else if(d < abs(r1-r2))
            printf("0\n");
        else
            printf("2\n");
    }
    
    return 0;
}
