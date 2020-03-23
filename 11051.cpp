#include <iostream>
using namespace std;

int pascalTriangle[1001][1001] = { 0, };

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	if (K > N / 2)
		K = N - K;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i && j <= K; j++) {
			if (j == 0 || j == i)
				pascalTriangle[i][j] = 1;
			else
				pascalTriangle[i][j] = (pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j]) % 10007;
		}
	}

	printf("%d\n", pascalTriangle[N][K]);

	return 0;
}
