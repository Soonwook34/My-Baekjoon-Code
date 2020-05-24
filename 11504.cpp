#include <iostream>
#include <vector>
using namespace std;

int getInput(int);						//M자리수의 숫자를 불러와 리턴하는 함수 getInput(M)
int getState(vector<int>&, int, int);	//돌림판에서 i번째부터 M자리수의 숫자를 리턴하는 함수 getState(돌림판, i, M)

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N, M;
		scanf("%d %d", &N, &M);
		
		//X와 Y 가져오기
		int X = getInput(M);
		int Y = getInput(M);
		
		//돌림판 불러오기
		vector<int> turnTable(N);
		for (int i = 0; i < N; i++)
			scanf("%d", &turnTable[i]);
		
		//돌림판 읽어 비교하기
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			int num = getState(turnTable, i, M);
			if (X <= num && num <= Y)
				cnt++;
		}
		printf("%d\n", cnt);
	}

	return 0;
}

//M자리수의 숫자를 불러와 리턴하는 함수 getInput(M)
int getInput(int M) {
	char num[10] = "";
	for (int i = 0; i < M; i++) {
		int x;
		scanf("%d", &x);
		num[i] = x + '0';
	}
	num[M] = '\0';

	return atoi(num);
}

//돌림판에서 i번째부터 M자리수의 숫자를 리턴하는 함수 getState(돌림판, i, M)
int getState(vector<int>& turnTable, int x, int M) {
	char num[10] = "";
	int N = turnTable.size();

	for (int i = 0; i < M; i++) {
		num[i] = turnTable[(x + i) % N] + '0';
	}
	num[M] = '\0';

	return atoi(num);
}
