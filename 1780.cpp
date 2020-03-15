#include <iostream>
#include <vector>
using namespace std;

int N;
int paper[2187][2187];
int minusOne = 0, zero = 0, plusOne = 0;

void makeQuadTree(int, int, int);	//쿼드 트리를 이용하여 colorPaper를 압축하는 함수
bool isCompressible(int, int, int);	//해당 구역이 압축가능하면 true, 불가능하면 false를 리턴하는 함수

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &paper[i][j]);
		}
	}

	makeQuadTree(N, 0, 0);

	printf("%d\n%d\n%d\n", minusOne, zero, plusOne);

	return 0;
}

void makeQuadTree(int level, int x, int y) {
	//가장 낮은 단계(1개)
	if (level == 1) {
		switch (paper[x][y]) {
		case -1:
		    minusOne++;
		    break;
		case 0:
			zero++;
			break;
		case 1:
			plusOne++;
			break;
		}
		return;
	}
	//압축 가능하면 압축정보 저장
	if (isCompressible(level, x, y)) {
		switch (paper[x][y]) {
		case -1:
		    minusOne++;
		    break;
		case 0:
			zero++;
			break;
		case 1:
			plusOne++;
			break;
		}
	}
	//불가능하면 9분할 하여 압축 시도
	else {
		makeQuadTree(level / 3, x, y);
		makeQuadTree(level / 3, x, y + (level / 3));
		makeQuadTree(level / 3, x, y + (level / 3 * 2));
		makeQuadTree(level / 3, x + (level / 3), y);
		makeQuadTree(level / 3, x + (level / 3), y + (level / 3));
		makeQuadTree(level / 3, x + (level / 3), y + (level / 3 * 2));
		makeQuadTree(level / 3, x + (level / 3 * 2), y);
		makeQuadTree(level / 3, x + (level / 3 * 2), y + (level / 3));
		makeQuadTree(level / 3, x + (level / 3 * 2), y + (level / 3 * 2));
	}
}

bool isCompressible(int level, int x, int y) {
	int check = paper[x][y];	//첫 색 확인
	//해당 구역이 전부 같은 색인지 확인
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			if (paper[x + i][y + j] != check)
				return false;
		}
	}
	return true;
}
