#include <iostream>

int main() {
    int xy[3][2] = {0};
    int x, y;
    
    for(int i=0; i<3; i++) {
        scanf("%d %d", &xy[i][0], &xy[i][1]);
    }
    
    if(xy[0][0] == xy[1][0])
        x = xy[2][0];
    else if(xy[0][0] == xy[2][0])
        x = xy[1][0];
    else
        x = xy[0][0];
    
    if(xy[0][1] == xy[1][1])
        y = xy[2][1];
    else if(xy[0][1] == xy[2][1])
        y = xy[1][1];
    else
        y = xy[0][1];
    
    printf("%d %d\n", x, y);
    
    return 0;
}
