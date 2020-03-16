#include <iostream>
using namespace std;

int main() {
    int N = 5;

    int total = 0;
    for (int i = 0; i < N; i++) {
        int score;
        scanf("%d", &score);
        if (score < 40)
            total += 40;
        else
            total += score;
    }

    printf("%d\n", total / 5);

    return 0;
}
