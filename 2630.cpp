#include <iostream>
#include <vector>
using namespace std;

int N;
char colorPaper[128][128];
int white = 0, blue = 0;

void makeQuadTree(int, int, int);	//쿼드 트리를 이용하여 colorPaper를 압축하는 함수
bool isCompressible(int, int, int);	//해당 구역이 압축가능하면 true, 불가능하면 false를 리턴하는 함수

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> colorPaper[i][j];
		}
	}

	makeQuadTree(N, 0, 0);

	printf("%d\n%d\n", white, blue);

	return 0;
}

void makeQuadTree(int level, int x, int y) {
	//가장 낮은 단계(1개)
	if (level == 1) {
		switch (colorPaper[x][y]) {
		case '0':
			white++;
			break;
		case '1':
			blue++;
			break;
		}
		return;
	}
	//압축 가능하면 압축하고
	if (isCompressible(level, x, y)) {
		switch (colorPaper[x][y]) {
		case '0':
			white++;
			break;
		case '1':
			blue++;
			break;
		}
	}
	//불가능하면 4분할 하여 압축 시도
	else {
		makeQuadTree(level / 2, x, y);
		makeQuadTree(level / 2, x, y + (level / 2));
		makeQuadTree(level / 2, x + (level / 2), y);
		makeQuadTree(level / 2, x + (level / 2), y + (level / 2));
	}
}

bool isCompressible(int level, int x, int y) {
	char check = colorPaper[x][y];	//첫 색 확인
	//해당 구역이 전부 같은 색인지 확인
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			if (colorPaper[x + i][y + j] != check)
				return false;
		}
	}
	return true;
}
