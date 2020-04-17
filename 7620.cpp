#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string a, b;
int check[1000][17001] = { 0, };	//뒤에서부터 1000줄의 LCS를 저장하는 배열

void getCheck(int, int);			//(x,y)까지 check배열을 채우는 함수

int main() {
	cin >> a >> b;

	int x = a.length(), y = b.length();	//check 배열에서 현재 위치를 나타낼 좌표(x, y)
	vector<pair<char, char>> edit;	//편집거리 정보를 저장할 vector
	int checkCnt = 999;

	while (!(x == 0 && y == 0)) {
		//만들어진 check 배열을 다 사용하였다면 현재 위치를 바탕으로 갱신
		if (checkCnt == 999) {
			getCheck(x, y);
			checkCnt = 0;
		}
		
		int yes = 1;
		if (x == 0 || y == 0)
			yes = 0;
		//다음 위치로 이동
		int minX = max(x - 1, 0), minY = max(y - 1, 0);
		int nextPlace = min(check[minX%1000][minY], min(check[minX%1000][y], check[x%1000][minY]));
		//출력(c), 바꾸기(m)
		if (nextPlace == check[minX%1000][minY] && yes == 1) {
			if (a[minX] == b[minY]) {
				edit.push_back(pair<char, char>('c', a[minX]));		//출력
			}
			else{
				edit.push_back(pair<char, char>('m', b[minY]));		//바꾸기
			}
			x = minX;
			y = minY;
		}
		//추가(d)
		else if (nextPlace == check[minX%1000][y]) {
			edit.push_back(pair<char, char>('d', a[minX]));
			x = minX;
		}
		//삭제(a)
		else {
			edit.push_back(pair<char, char>('a', b[minY]));
			y = minY;
		}
		checkCnt++;
	}

	for (int i = edit.size()-1; i >= 0; i--)
		printf("%c %c\n", edit[i].first, edit[i].second);

	return 0;
}

void getCheck(int x, int y) {
	//초기 설정
	for (int i = 0; i < 3; i++)
		check[i][0] = i;
	for (int j = 0; j <= y; j++)
		check[0][j] = j;

	//LCS를 이용하여 1000줄이 넘어갈때마다 덮어쓰면서 check 배열 채우기
	for (int i = 1; i <= x; i++) {
		for (int j = 0; j <= y; j++) {
			if (j == 0) {
				check[i % 1000][0] = i;
				continue;
			}
			if (a[i - 1] == b[j - 1])
				check[i % 1000][j] = check[(i - 1) % 1000][j - 1];
			else
				check[i % 1000][j] = min(check[(i - 1) % 1000][j - 1], min(check[(i - 1) % 1000][j], check[i % 1000][j - 1])) + 1;
		}
	}
}
