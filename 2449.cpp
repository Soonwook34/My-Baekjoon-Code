#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 200

int N, K;
int bulb[MAX];
int dp[MAX][MAX];	//dp[i][j]는 i~j까지 i의 색으로 바꾸는데 필요한 최소 횟수	

int solve(int, int);

int main() {
	scanf("%d %d", &N, &K);

	int count = 0;
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		if (i == 0 || bulb[i - 1] != x) {
			bulb[count] = x;
			count++;
		}
	}

	memset(dp, -1, sizeof(dp));

	printf("%d\n", solve(0, count - 1));

	return 0;
}

//Chained Matrix Multiplication
int solve(int start, int end) {
	if (start == end)
		return 0;

	int& cnt = dp[start][end];
	if (cnt != -1)
		return cnt;
	cnt = MAX + 1;

	for (int i = start; i < end; i++) {
		int left = solve(start, i);
		int right = solve(i + 1, end);
		int last;

		if (bulb[start] == bulb[i + 1])
			last = 0;
		else
			last = 1;

		cnt = min(cnt, left + right + last);
	}

	return cnt;
}
