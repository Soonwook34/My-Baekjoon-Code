#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define WEST 1
#define NORTH 2
#define EAST 4
#define SOUTH 8
#define EXCEPT(I) 15-I					//I 벽을 제외한 나머지 벽의 합

int countRoom(int, int);				//해당 칸과 이어져있는 방의 크기를 리턴하는 함수

int n, m;
int wall[50][50] = { 0, };				//지도 정보를 저장하는 배열
bool is_visited[50][50] = { false, };	//해당 칸을 방문하였는지 저장하는 배열
vector<int> room;						//방의 크기를 저장하는 vector


int main() {
	scanf("%d %d", &n, &m);
	//지도 정보 입력받기
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &wall[i][j]);
		}
	}

	//DFS
	//1, 2번 풀기(성에 있는 방의 개수, 가장 큰 방의 넓이)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (is_visited[i][j] == false) {
				room.push_back(countRoom(i, j));
			}
		}
	}
	//방의 크기 오름차순으로 정렬
	sort(room.begin(), room.end());
	//1, 2번 답 출력
	printf("%d\n%d\n", room.size(), room[room.size() - 1]);

	//3번 풀기
	room.clear();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			//벽을 하나씩 제거하면서 방의 크기 세기
			//동쪽에 벽이 있을 경우
			if ((wall[i][j] & EAST) != 0 && j != n - 1) {
				wall[i][j] &= EXCEPT(EAST);
				wall[i][j + 1] &= EXCEPT(WEST);
				memset(is_visited, false, sizeof(is_visited));
				room.push_back(countRoom(i, j));
				wall[i][j] |= EAST;
				wall[i][j + 1] |= WEST;
			}
			//남쪽에 벽이 있을 경우
			if ((wall[i][j] & SOUTH) != 0 && i != m - 1) {
				wall[i][j] &= EXCEPT(SOUTH);
				wall[i + 1][j] &= EXCEPT(NORTH);
				memset(is_visited, false, sizeof(is_visited));
				room.push_back(countRoom(i, j));
				wall[i][j] |= SOUTH;
				wall[i + 1][j] |= NORTH;
			}
		}
	}
	//각각 벽을 하나씩 제거하며 만들어진 방을 크기 오름차순으로 정렬
	sort(room.begin(), room.end());
	//3번 답 출력
	printf("%d\n", room[room.size() - 1]);
}

int countRoom(int x, int y) {
	is_visited[x][y] = true;

	//벽이 없는 칸으로 탐색 이어가기
	int size = 1;
	if ((wall[x][y] & WEST) == 0 && is_visited[x][y - 1] == false)	//서
		size += countRoom(x, y - 1);
	if ((wall[x][y] & NORTH) == 0 && is_visited[x - 1][y] == false)	//북
		size += countRoom(x - 1, y);
	if ((wall[x][y] & EAST) == 0 && is_visited[x][y + 1] == false)	//동
		size += countRoom(x, y + 1);
	if ((wall[x][y] & SOUTH) == 0 && is_visited[x + 1][y] == false)	//남
		size += countRoom(x + 1, y);

	return size;
}
