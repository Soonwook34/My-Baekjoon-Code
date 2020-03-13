#include <iostream>
#include <vector>
using namespace std;

int N;
char video[64][64];			//영상 정보
vector<char> compression;	//video의 압축 결과를 출력할 vector

void makeQuadTree(int, int, int);	//쿼드 트리를 이용하여 video를 압축하는 함수
bool isCompressible(int, int, int);	//해당 구역이 압축가능하면 true, 불가능하면 false를 리턴하는 함수

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> video[i][j];
		}
	}

	makeQuadTree(N, 0, 0);
	//압축 정보 출력
	for (int i = 0; i < compression.size(); i++) {
		printf("%c", compression[i]);
	}
	printf("\n");

	return 0;
}

void makeQuadTree(int level, int x, int y) {
	//가장 낮은 단계(1개)
	if (level == 1) {
		compression.push_back(video[x][y]);
		return;
	}
	//압축 가능하면 압축하고
	if (isCompressible(level, x, y)) {
		compression.push_back(video[x][y]);
	}
	//불가능하면 4분할 하여 압축 시도
	else {
		compression.push_back('(');
		makeQuadTree(level / 2, x, y);
		makeQuadTree(level / 2, x, y + (level / 2));
		makeQuadTree(level / 2, x + (level / 2), y);
		makeQuadTree(level / 2, x + (level / 2), y + (level / 2));
		compression.push_back(')');
	}
}

bool isCompressible(int level, int x, int y) {
	char check = video[x][y];	//첫 색 확인
	//해당 구역이 전부 같은 색인지 확인
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			if (video[x + i][y + j] != check)
				return false;
		}
	}
	return true;
}
