#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;
	//초기 상태
	for (int i = 1; i <= N; i++)
		q.push(i);
	//시작
	printf("<");

	for (int i = 0; i < N - 1; i++) {
		//K번째 사람 찾기
		for (int j = 0; j < K - 1; j++) {
			q.push(q.front());
			q.pop();
		}
		//K번째 사람 제거
		printf("%d, ", q.front());
		q.pop();
	}
	//마지막
	printf("%d>\n", q.front());

	return 0;
}
