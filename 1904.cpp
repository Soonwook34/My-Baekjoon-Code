#include <iostream>
using namespace std;

int N;
int fibonacci[1000001];

int getAnswer();

int main(void) {
        scanf("%d\n", &N);
    
        printf("%d\n", getAnswer());
        return 0;
}

int getAnswer() {
        fibonacci[1] = 1;
        fibonacci[2] = 2;
    
        for (int i=3; i<=N; i++)
            fibonacci[i] = (fibonacci[i-2] + fibonacci[i-1]) % 15746;
    
        return (fibonacci[N] % 15746);
}
