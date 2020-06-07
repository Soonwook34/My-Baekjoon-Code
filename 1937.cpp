#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 500

int N;
int forest[MAX + 2][MAX + 2];
int dp[MAX + 2][MAX + 2];

int findMaxDay(int, int);

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &forest[i][j]);
	}
	
	memset(dp, -1, sizeof(dp));

	int maxDay = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			maxDay = max(maxDay, findMaxDay(i, j));
	}
	printf("%d\n", maxDay);

	return 0;
}

//Memoization
int findMaxDay(int x, int y) {
	if (x < 1 || y < 1 || x > N || y > N)
		return 0;

	int& day = dp[x][y];
	if (day != -1)
		return day;
	day = 1;
	if (forest[x - 1][y] > forest[x][y])
		day = max(day, findMaxDay(x - 1, y) + 1);
	if (forest[x][y - 1] > forest[x][y])
		day = max(day, findMaxDay(x, y - 1) + 1);
	if (forest[x + 1][y] > forest[x][y])
		day = max(day, findMaxDay(x + 1, y) + 1);
	if (forest[x][y + 1] > forest[x][y])
		day = max(day, findMaxDay(x, y + 1) + 1);

	return day;
}
