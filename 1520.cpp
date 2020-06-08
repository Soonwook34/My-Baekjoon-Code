#include <iostream>
#include <cstring>
using namespace std;

#define MAX 500
int M, N;
int map[MAX + 2][MAX + 2] = { 0, };
int memory[MAX + 2][MAX + 2];

int solve(int, int);

int main() {
	scanf("%d %d", &M, &N);

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	}
	memset(memory, -1, sizeof(memory));

	printf("%d\n", solve(1, 1));

	return 0;
}
//Memoization
int solve(int x, int y) {
	if (x == M && y == N)
		return 1;

	int& ret = memory[x][y];
	if (ret != -1)
		return ret;
	ret = 0;
	if (x > 1 && map[x][y] > map[x - 1][y])
		ret += solve(x - 1, y);
	if (y > 1 && map[x][y] > map[x][y - 1])
		ret += solve(x, y - 1);
	if (x < M && map[x][y] > map[x + 1][y])
		ret += solve(x + 1, y);
	if (y < N && map[x][y] > map[x][y + 1])
		ret += solve(x, y + 1);

	return ret;
}
