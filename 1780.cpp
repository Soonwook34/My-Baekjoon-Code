#include <iostream>

using namespace std;

int N;
int paper[2187][2187] = { 0, };
int numCnt[3] = { 0, };
void divide(int, int, int);
bool isOkay(int, int, int);

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &paper[i][j]);
	}

	divide(0, 0, N);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", numCnt[i]);
	}

	return 0;
}

void divide(int x, int y, int size) {
	if (size == 1) {
		numCnt[paper[x][y] + 1]++;
		return;
	}

	if (isOkay(x, y, size)) {
		numCnt[paper[x][y] + 1]++;
		return;
	}
	else {
		size /= 3;
		divide(x, y, size);
		divide(x, y + size, size);
		divide(x, y + size * 2, size);
		divide(x + size, y, size);
		divide(x + size, y + size, size);
		divide(x + size, y + size * 2, size);
		divide(x + size * 2, y, size);
		divide(x + size * 2, y + size, size);
		divide(x + size * 2, y + size * 2, size);
	}
}

bool isOkay(int x, int y, int size) {
	int num = paper[x][y];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (paper[x + i][y + j] != num)
				return false;
		}
	}
	return true;
}
