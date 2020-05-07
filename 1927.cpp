#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	//우선순위 큐 이용
	priority_queue<int> pq;
	for (int i = 0; i < N; i++) {
		int op;
		scanf("%d", &op);

		if (op == 0) {
			if (pq.empty())
				printf("0\n");
			else {
				//양수로 출력
				printf("%d\n", -pq.top());
				pq.pop();
			}
		}
		else {
			//음수로 입력
			pq.push(-op);
		}
	}
}
