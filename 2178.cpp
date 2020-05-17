#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

int N, M;
bool map[MAX + 2][MAX + 2] = { false, };
bool visited[MAX + 2][MAX + 2] = { false, };
int cnt[MAX + 2][MAX + 2] = { 0, };

void findPath();

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	findPath();
	printf("%d\n", cnt[N][M]);

	return 0;
}

//BFS로 경로찾기
void findPath() {
	int caseX[4] = { 0, 1, 0, -1 };
	int caseY[4] = { 1, 0, -1, 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(1, 1));
	cnt[1][1] = 1;
	visited[1][1] = true;

	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int newX = x + caseX[i];
			int newY = y + caseY[i];
			if (1 <= newX && newX <= M && 1 <= newY && newY <= N && map[newY][newX] && !visited[newY][newX]) {
				cnt[newY][newX] = cnt[y][x] + 1;
				visited[newY][newX] = true;
				q.push(make_pair(newY, newX));
			}
		}
	}
}
