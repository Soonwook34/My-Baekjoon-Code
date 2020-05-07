#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	
	scanf("%d", &N);

	priority_queue<int> front;								//전체 수의 앞 반(홀수면 n/2 + 1), 오름차순
	priority_queue<int, vector<int>, greater<int>> back;	//전체 수의 뒤 반(홀수면 n/2), 내림차순

	for (int i = 0; i < N; i++) {
		int op;
		scanf("%d", &op);
		//항상 front가 back의 수와 같거나 하나 많게 유지
		if (front.size() > back.size())
			back.push(op);
		else
			front.push(op);
		//front의 가장 큰 수가 back의 가장 작은 수보다 크다면
		if (!front.empty() && !back.empty() && front.top() > back.top()) {
			//둘이 교체
			front.push(back.top());
			back.push(front.top());
			front.pop();
			back.pop();
		}

		printf("%d\n", front.top());
	}

	return 0;
}
