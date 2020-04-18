#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	int R, C;
	scanf("%d %d", &R, &C);

	vector<int> garo(C + 2);
	vector<vector<int>> apple(R + 2, garo);
	vector<vector<int>> banana(R + 2, garo);

	for (int r = 1; r <= R; r++) {
		char s[4];
		for (int c = 1; c <= C; c++) {
			scanf("%s", s);
			switch (s[0]) {
			case 'A':
				apple[r][c] = atoi(s + 1);
				break;
			case 'B':
				banana[r][c] = atoi(s + 1);
				break;
			}
		}
	}

	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			apple[r][c] += apple[r][c - 1];
			banana[r][C - c + 1] += banana[r][C - c + 2];
		}
	}
	vector<vector<int>> maxSum(R + 2, garo);
	for (int r = 1; r <= R; r++) {
		for (int c = 1; c <= C; c++) {
			if (r == 1 || c == 1)
				maxSum[r][c] = maxSum[r - 1][c] + banana[r][c + 1];
			else {
				int fromUp = maxSum[r - 1][c] + apple[r][c - 1] + banana[r][c + 1];
				int fromLeft = maxSum[r][c - 1] - banana[r][c] + banana[r][c + 1];
				int fromDiagonal = maxSum[r - 1][c - 1] + apple[r][c - 1] + banana[r][c + 1];
				maxSum[r][c] = max(fromUp, max(fromLeft, fromDiagonal));
			}
		}
	}
	printf("%d\n", maxSum[R][C]);
    
	return 0;
}
