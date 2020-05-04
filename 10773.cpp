#include <iostream>
#include <stack>
using namespace std;

int main() {
	int K;
	scanf("%d", &K);

	stack<int> s;
	int n;
	for (int k = 0; k < K; k++) {
		scanf("%d", &n);
		//0이 아니면 push
		if (n != 0) {
			s.push(n);
		}
		//0이면 pop
		else {
			s.pop();
		}
	}

	//스택에 남아있는 수들 합 구하기
	int sum = 0;
	while (s.empty() == false) {
		sum += s.top();
		s.pop();
	}

	printf("%d\n", sum);

	return 0;
}
