#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 100

int N;
int dot[MAX];						//검은점과 하얀점 정보
int blackDot[MAX][MAX] = { 0, };	//i부터 j까지 검은점의 개수 blakcDot[i][j]
int minLength[MAX][MAX] = { 0, };	//i부터 j까지 연결된 길의 최소 길이 minLength[i][j]
int level[MAX][MAX] = { 0, };		//i와 j가 연결될 때의 최고 높이 level[i][j]
int connection[MAX][MAX] = { 0, };	//i부터 j까지 연결했을 때 i와 연결되는 점 connection[i][j] 

void printConnection(int, int);		//연결 정보 출력

int main() {
	scanf("%d", &N);

	char dotTemp[101];
	scanf("%s", dotTemp);
	for (int i = 0; i < N; i++)
		dot[i] = dotTemp[i] - '0';

	//검은점 개수 세기 + minDist 초기화 
	for (int i = 0; i < N; i++) {
		blackDot[i][i] = dot[i];
		for (int j = i; j < N; j++) {
			blackDot[i][j] = blackDot[i][j - 1] + dot[j];
			minLength[i][j] = MAX * MAX;
		}
	}

	//Chained matrix Multiplication을 이용하여 최소 길이 찾기
	for (int len = 1; len < N; len += 2) {
		for (int i = 0; i < N - len; i++) {
			int j = i + len;
			//구간 [i, j]에 검은점과 하얀점의 개수가 다르면 continue
			if (blackDot[i][j] != (len + 1) / 2)
				continue;
			//구간 [i, j]에 검은점과 하얀점의 개수가 같고 i와 j번째 점이 서로 다른 색의 점이라면
			else if(dot[i] != dot[j]) {
				//i와 j를 연결하기
				connection[i][j] = j;
				level[i][j] = level[i + 1][j - 1] + 1;
				minLength[i][j] = minLength[i + 1][j - 1] + (j - i) + level[i][j] * 2;
			}
			
			//구간 [i, j]에서 최소 길이 찾기
			for (int k = i + 1; k < j; k += 2) {
				if (minLength[i][j] > minLength[i][k] + minLength[k + 1][j]) {
					connection[i][j] = k;
					level[i][j] = max(level[i][k], level[k + 1][j]);
					minLength[i][j] = minLength[i][k] + minLength[k + 1][j];
				}
			}
		}
	}

	//정답 출력
	printf("%d\n", minLength[0][N - 1]);
	printConnection(0, N-1);

	return 0;
}

//연결 정보 출력
void printConnection(int i, int j) {
	if (i >= j)
		return;
	int k = connection[i][j];
	printf("%d %d\n", i + 1, k + 1);
	printConnection(i+1, k-1);
	printConnection(k + 1, j);

	return;
}
