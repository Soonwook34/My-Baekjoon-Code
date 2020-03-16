#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < N; j++) {
            if (i % 2 == j % 2)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
