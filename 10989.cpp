#include <iostream>
using namespace std;
 
int main()
{
    int N, temp;
    int numCount[10001];
    fill_n(numCount, 10001, 0);
    scanf("%d", &N);
    
    for(int n=0; n<N; n++) {
        scanf("%d", &temp);
        numCount[temp]++;
    }
    //누적합
    for(int i=1; i<10001; i++)
        numCount[i] += numCount[i-1];
    
    for(int i=1; i<10001; i++) {
        if(numCount[i-1] != numCount[i]) {
            for(int j=0; j<numCount[i]-numCount[i-1]; j++) {
                printf("%d\n", i);
            }
        }
    }
    
    return 0;
}
