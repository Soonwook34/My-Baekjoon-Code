#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	char cmd[6];
	vector<int> myQueue;		//큐 구현
	int front = 0, back = 0;
	
	for (int i = 0; i < N; i++) {
		scanf("%s", cmd);
		//push
		if (strcmp(cmd, "push") == 0) {
			int x;
			scanf("%d", &x);
			myQueue.push_back(x);
			back++;
		}
		//pop
		else if (strcmp(cmd, "pop") == 0) {
			if (back - front == 0)
				printf("-1\n");
			else {
				printf("%d\n", myQueue[front]);
				front++;
			}
		}
		//size
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", back - front);
		}
		//empty
		else if (strcmp(cmd, "empty") == 0) {
			printf("%d\n", back - front == 0 ? 1 : 0);
		}
		//front
		else if (strcmp(cmd, "front") == 0) {
			if (back - front == 0)
				printf("-1\n");
			else
				printf("%d\n", myQueue[front]);
		}
		//back
		else {
			if (back - front == 0)
				printf("-1\n");
			else
				printf("%d\n", myQueue[back-1]);
		}
	}

	return 0;
}
