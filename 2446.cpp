#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = N; i > 0; i--) {
        for (int j = 0; j < N - i; j++)
            printf(" ");
        for (int j = 0; j < i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 0; j < N - i; j++)
            printf(" ");
        for (int j = 0; j < i * 2 - 1; j++)
            printf("*");
        printf("\n");
    }

    return 0;
}
