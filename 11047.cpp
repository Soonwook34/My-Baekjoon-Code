#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    vector<int> coin(N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &coin[i]);
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (coin[i] <= K) {
            while (coin[i] <= K) {
                K -= coin[i];
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
