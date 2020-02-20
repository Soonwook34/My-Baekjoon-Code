#include <iostream>
#include <cmath>
using namespace std;

//R = 0, G = 1, B = 2
int N;
int color[1000];
int RGBprice[1000][3];
int totalPrice[1000][3] = {0, };

int RGBstreet(void);

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d", &RGBprice[i][j]);
        }
    }
    
    printf("%d\n", RGBstreet());
    
    return 0;
}

int RGBstreet() {
    totalPrice[0][0] = RGBprice[0][0];
    totalPrice[0][1] = RGBprice[0][1];
    totalPrice[0][2] = RGBprice[0][2];
    
    for(int i=1; i<N; i++) {
        totalPrice[i][0] = RGBprice[i][0] + min(totalPrice[i-1][1], totalPrice[i-1][2]);
        totalPrice[i][1] = RGBprice[i][1] + min(totalPrice[i-1][0], totalPrice[i-1][2]);
        totalPrice[i][2] = RGBprice[i][2] +  min(totalPrice[i-1][0], totalPrice[i-1][1]);
    }
    
    return min(totalPrice[N-1][0], min(totalPrice[N-1][1], totalPrice[N-1][2]));
}
