#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[27][27] = { 0, };				//지도 정보(상하좌우로 1줄의 여백이 있다)
bool isVisited[27][27] = { false, };	//그 위치의 집을 방문했는지 저장하는 배열

int makeBlock(int, int);				//단지를 생성하는 함수

int main() {
	scanf("%d", &N);

	//입력 받기
	char t_string[26] = "";
	for (int i = 1; i <= N; i++) {
		scanf("%s", t_string);
		//지도 생성
		for (int j = 1; j <= N; j++) {
			map[i][j] = t_string[j-1] - '0';
		}
	}

	int block_cnt = 0;
	vector <int> block_info;	//각 단지의 집의 수를 저장하는 변수
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (map[i][j] == 1 && isVisited[i][j] == false) {
				block_info.push_back(makeBlock(i, j));
			}
		}
	}
	//오름차순 정렬
	sort(block_info.begin(), block_info.end());

	//단지 수 출력
	printf("%d\n", block_info.size());
	//각 단지의 집의 수 출력
	for (int i = 0; i < block_info.size(); i++) {
		printf("%d\n", block_info[i]);
	}

	return 0;
}

int makeBlock(int x, int y) {
	//범위를 벗어나면 0 리턴
	if (x < 1 || x > N || y < 1 || y > N)
		return 0;
	//집이 없거나 이미 방문한 집이라면 0 리턴
	if (map[x][y] == 0 || isVisited[x][y] == true)
		return 0;

	//현재 위치 방문
	isVisited[x][y] = true;

	//현재 위치로부터 단지 찾기 시작
	int sum = 1;

	//상하좌우에 아직 방문하지 않은 집이 있으면 방문(DFS)
	if (map[x - 1][y] == 1 && isVisited[x - 1][y] == false)
		sum += makeBlock(x - 1, y);
	if (map[x][y - 1] == 1 && isVisited[x][y - 1] == false)
		sum += makeBlock(x, y - 1);
	if (map[x + 1][y] == 1 && isVisited[x + 1][y] == false)
		sum += makeBlock(x + 1, y);
	if (map[x][y + 1] == 1 && isVisited[x][y + 1] == false)
		sum += makeBlock(x, y + 1);

	return sum;
}
