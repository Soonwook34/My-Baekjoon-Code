#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int N, temp, min=4001, max=-4001, modeCount=0, cnt=0;
    int mean, median, mode, range=0;
    double sum = 0;
    bool isHalf = false;
    int numCount[8001];
    fill_n(numCount, 8001, 0);
    scanf("%d", &N);
    
    for(int n=0; n<N; n++) {
        scanf("%d", &temp);
        numCount[temp+4000]++;
        sum += temp;
        if(min > temp)
            min = temp;
        if(max < temp)
            max = temp;
    }
    //산술평균
    mean = round(sum/N);
    //범위
    range = max - min;
    //누적합
    temp = 0;
    for(int i=min+4000; i<max+4001; i++) {
        if(numCount[i] > modeCount)
            modeCount = numCount[i];
        //중간값
        temp += numCount[i];
        if(!isHalf && temp >= round(N/2.0)) {
            isHalf = true;
            median = i-4000;
        }
    }
    //최빈값
    for(int i=min+4000; i<max+4001; i++) {
        if(modeCount == numCount[i]) {
        	mode = i-4000;
            if(cnt == 1) {
                mode = i-4000;
                break;
            }
            cnt++;
        }
    }
    
    printf("%d\n%d\n%d\n%d\n", mean, median, mode, range);
    
    return 0;
}
