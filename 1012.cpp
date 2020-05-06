#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void visitFarm(int, int);			//해당 배추와 이어져있는 밭을 전부 방문하는 함수

int T, N, M, K;
int farm[50][50];						//밭 정보를 저장하는 배열
int wormCnt;							//필요한 배추흰지렁이의 수

int main() {
	scanf("%d", &T);
	for(int t=0; t<T; t++) {
		scanf("%d %d %d", &M, &N, &K);
		memset(farm, 0, sizeof(farm));
		wormCnt = 0;
		//밭 정보 입력받기
		for (int k = 0; k < K; k++) {
			int x, y;
			scanf("%d %d", &y, &x);
			farm[x][y] = 1;
		}
		//DFS
		//필요한 배추흰지렁이의 수 구하기
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (farm[i][j] == 1) {
					wormCnt++;
					visitFarm(i, j);
				}
			}
		}

		printf("%d\n", wormCnt);
	}

	return 0;
}

void visitFarm(int x, int y) {
	//방문했으면 0
	farm[x][y] = 0;

	//탐색 이어가기
	int size = 1;
	if (y > 0 && farm[x][y-1] == 1)	//왼쪽
		visitFarm(x, y - 1);
	if (x > 0 && farm[x - 1][y] == 1)	//위쪽
		visitFarm(x - 1, y);
	if (y < M - 1 && farm[x][y + 1] == 1)	//오른쪽
		visitFarm(x, y + 1);
	if (x < N - 1 && farm[x + 1][y] == 1)	//아래쪽
		visitFarm(x + 1, y);

	return;
}
