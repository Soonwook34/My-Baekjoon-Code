#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 100

int N, M;
bool path[MAX + 1][MAX + 1][2];
long long dp[MAX + 1][MAX + 1];

long long findPath(int, int);

int main() {
	scanf("%d %d", &N, &M);
	memset(path, true, sizeof(path));
	
	int K;
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int direction = 1;
		if (a - c == 0)
			direction = 0;
		path[min(a,c)][min(b,d)][direction] = false;

	}
	memset(dp, -1, sizeof(dp));

	printf("%lld\n", findPath(0, 0));

	return 0;
}

//Memoization
long long findPath(int x, int y) {
	if (x < 0 || y < 0 || x > N || y > M)
		return 0;
	if (x == N && y == M)
		return 1;

	long long& ret = dp[x][y];
	if (ret != -1)
		return ret;
	ret = 0;

	if (path[x][y][1])
		ret += findPath(x + 1, y);
	if (path[x][y][0])
		ret += findPath(x, y + 1);

	return ret;
}
