#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES
 
int main() {
    int R;
    double S1, S2;
    
    scanf("%d", &R);
    
    S1 = R * R * M_PI;
    S2 = R * R * 2.0;
 
    printf("%.6f\n%.6f\n", S1, S2);
    
    return 0;
}
