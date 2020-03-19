#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int M;
    scanf("%d", &M);
    
    vector<int> factor(M);
    
    for(int i=0; i<M; i++)
        scanf("%d", &factor[i]);
    
    sort(factor.begin(), factor.end());

    int N;
    if(M%2 == 0)
        N = factor[M/2-1] * factor[M/2];
    else
        N = factor[M/2] * factor[M/2];
    
    printf("%d\n", N);
    
    return 0;
}
