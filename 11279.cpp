#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	//우선순위 큐
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int op;
		scanf("%d", &op);

		if (op == 0) {
			//비었으면 0 출력
			if (pq.empty())
				printf("0\n");
			//하나라도 있으면 가장 큰 수 출력, 제거
			else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		}
		else
			pq.push(op);
	}
}
