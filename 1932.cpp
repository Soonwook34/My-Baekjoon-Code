#include <iostream>
using namespace std;

int N;
int triangle[500][500];
int tempSum[500][500];

int getMaxSum();

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<i+1; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }
    
    printf("%d\n", getMaxSum());
    
    return 0;
}

int getMaxSum() {
    tempSum[0][0] = triangle[0][0];
    
    for(int i=1; i<N; i++) {
        for(int j=0; j<=i; j++) {
            if(j == 0)
                tempSum[i][j] = triangle[i][j] + tempSum[i-1][0];
            else
                tempSum[i][j] = triangle[i][j] + max(tempSum[i-1][j-1], tempSum[i-1][j]);
        }
    }
    
    int maxSum = tempSum[N-1][0];
    for(int i=1; i<N; i++) {
        maxSum = max(maxSum, tempSum[N-1][i]);
    }
    
    return maxSum;
}
