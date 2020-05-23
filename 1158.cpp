#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	queue<int> q;

	for (int i = 1; i <= N; i++)
		q.push(i);

	printf("<");
	while (q.size() != 1) {
		for (int i = 0; i < K - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		int k = q.front();
		q.pop();
		printf("%d, ", k);
	}
	printf("%d>\n", q.front());

	return 0;
}
