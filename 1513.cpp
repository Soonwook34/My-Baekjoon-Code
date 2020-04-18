#include <iostream>
#include <cstring>
using namespace std;

#define MOD 1000007

int N, M, C;
int loc[51][51] = { 0, };	//오락실의 위치 정보
/*path[a][b][x][y]는 총 a개의 오락실을 지나쳐야하는 조건에서
	(x, y)까지 오는데 가장 마지막으로 지나쳐온 오락실이 b번인 경로의 수*/
int path[51][51][51][51];

//path[x][y][arcadeCnt][prevArcade]를 계산하는 함수
int findPath(int arcadeCnt, int prevArcade, int x, int y);

int main() {
	scanf("%d %d %d", &N, &M, &C);

	for (int i = 1; i <= C; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		//(x, y)에 i번 오락실 번호 저장
		loc[x][y] = i;
	}

	//아직 한번도 지나가지 않은 경우는 -1
	memset(path, -1, sizeof(path));

	//지나온 오락실의 개수가 0~C인 경로 찾기 및 정답 출력
	for (int i = 0; i <= C; i++)
		printf("%d ", findPath(i, 0, 1, 1));

	return 0;
}

int findPath(int arcadeCnt, int prevArcade, int x, int y) {
	//도시를 넘어간 경우 또는 거쳐야하는 오락실 수보다 많은 수의 오락실을 지나온 경우
	if (x > N || y > M || arcadeCnt < 0)
		return 0;

	//학원에 도착한 경우
	if (x == N && y == M) {
		//학원이 위치한 곳에 오락실이 없을 때, 남은 지나와야하는 오락실의 개수가 0이면
		if (arcadeCnt == 0 && loc[x][y] == 0)
			//경로 1가지 추가
			return 1;
		//학원이 위치한 곳에 오락실이 있을 때, 남은 지나와야하는 오락실의 개수가 1이면
		else if (arcadeCnt == 1 && loc[x][y] > prevArcade)
			//경로 1가지 추가
			return 1;
		//조건을 만족하지 않으면 0 리턴
		else
			return 0;
	}

	//이미 계산된 조건이라면 그 값을 리턴
	if (path[arcadeCnt][prevArcade][x][y] >= 0)
		return path[arcadeCnt][prevArcade][x][y];

	//계속 진행
	//현재 위치가 오락실이 아니라면
	if (loc[x][y] == 0)
		//아래로, 오른쪽으로 이동하며 탐색하며 두 경로의 수의 합을 자신의 값으로 가진다.
		path[arcadeCnt][prevArcade][x][y] = (findPath(arcadeCnt, prevArcade, x + 1, y) + findPath(arcadeCnt, prevArcade, x, y + 1)) % MOD;

	//현재 위치가 오락실이고 이전에 방문한 오락실보다 번호가 높은 경우
	else if (loc[x][y] > prevArcade)
		/*arcadeCnt를 하나 줄이고(현재 위치의 오락실 방문) prevArcade를 현 오락실 번호로 대체하며, 
		아래로, 오른쪽으로 이동하며 탐색하며 두 경로의 수의 합을 자신의 값으로 가진다.*/
		path[arcadeCnt][prevArcade][x][y] = (findPath(arcadeCnt-1, loc[x][y], x + 1, y) + findPath(arcadeCnt-1, loc[x][y], x, y + 1)) % MOD;

	//현재 위치가 오락실이지만 가장 마지막으로 지나쳐온 오락실의 번호보다 낮은 번호의 오락실인 경우
	else
		//조건을 만족하지 않으므로 경로의 수는 0
		path[arcadeCnt][prevArcade][x][y] = 0;

	//계산된 경우의 수 리턴
	return path[arcadeCnt][prevArcade][x][y];
}
