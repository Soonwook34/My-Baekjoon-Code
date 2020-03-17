#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
    vector<int> operand, op;
    char s[50];
    scanf("%s", s);
    
    int index = 0, count = 0, operandTemp;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count++;
        }
        else {
            switch (s[i]) {
            case '+':
                op.push_back(1);
                break;
            case '-':
                op.push_back(0);
                break;
            }
            sscanf(s + index, "%d", &operandTemp);
            operand.push_back(operandTemp);
            index += count + 1;
            count = 0;
        }
    }
    sscanf(s + index, "%d", &operandTemp);
    operand.push_back(operandTemp);

    int answer = 0, minus = 1;
    for (int i = 0; i < operand.size() - 1; i++) {
        answer += operand[i] * minus;
        if (op[i] == 0) {
            minus = -1;
        }
    }
    answer += operand[operand.size()-1] * minus;
    
    printf("%d\n", answer);
    return 0;
}
