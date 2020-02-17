#include <iostream>
#include <climits>
using namespace std;

int N;
int maxValue = INT_MIN;
int minValue = INT_MAX;
int operandList[11];
int operatorCnt[4];

void getValue(int, int);

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d", &operandList[i]);
    }
    
    for(int i=0; i<4; i++) {
        scanf("%d", &operatorCnt[i]);
    }
    
    getValue(1, operandList[0]);
    printf("%d\n%d\n", maxValue, minValue);
    
    return 0;
}

void getValue(int step, int value) {
    if(step == N) {
        if(value > maxValue)
            maxValue = value;
        if(value < minValue)
            minValue = value;
        return;
    }
    
    for(int i=0; i<4; i++) {
        if(operatorCnt[i] != 0) {
            switch(i) {
                case 0:
                    operatorCnt[i]--;
                    getValue(step+1, value+operandList[step]);
                    operatorCnt[i]++;
                    break;
                case 1:
                    operatorCnt[i]--;
                    getValue(step+1, value-operandList[step]);
                    operatorCnt[i]++;
                    break;
                case 2:
                    operatorCnt[i]--;
                    getValue(step+1, value*operandList[step]);
                    operatorCnt[i]++;
                    break;
                case 3:
                    operatorCnt[i]--;
                    getValue(step+1, value/operandList[step]);
                    operatorCnt[i]++;
                    break;
                default:
                ;
            }
        }
    }
}
