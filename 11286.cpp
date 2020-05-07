#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	
	scanf("%d", &N);

	//우선순위 큐 이용(-절대값, 음수이면 1 / 양수이면 0)
	priority_queue<pair<int, int>> pq;
	for (int i = 0; i < N; i++) {
		int op;
		scanf("%d", &op);

		if (op == 0) {
			if (pq.size() == 0)
				printf("0\n");
			//출력
			else {
				printf("%d\n", -pq.top().first * (pq.top().second == 1 ? -1 : 1));
				pq.pop();
			}
		}
		else {
			//입력
			if (op > 0)
				pq.push(pair<int, int>(-op, 0));
			else
				pq.push(pair<int, int>(op, 1));
		}
	}
}
