#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
int info[21][21] = { 0, };
int start[10] = { 0, };
int link[10] = { 0, };
int minV = 200000;
void solve(int);

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &info[i][j]);
		}
	}

	solve(0);

	printf("%d\n", minV);

	return 0;
}

void solve(int cnt) {
	if (cnt == N / 2) {
		bool isInStart = false;
		int num = 0;
		for (int i = 1; i <= N; i++) {
			isInStart = false;
			for (int j = 0; j < cnt; j++) {
				if (start[j] == i) {
					isInStart = true;
					break;
				}
			}
			if (!isInStart) {
				link[num] = i;
				num++;
			}
		}
		int startS = 0;
		int linkS = 0;
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				startS += info[start[i]][start[j]];
				linkS += info[link[i]][link[j]];
			}
		}

		minV = min(minV, abs(startS - linkS));
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (cnt == 0 || i > start[cnt - 1]) {
			start[cnt] = i;
			solve(cnt + 1);
		}
	}
}
