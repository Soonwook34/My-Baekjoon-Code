#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> stack(10000);
	int top = -1;
	vector<int> temp;

	char cmd[6] = "";
	for (int n = 0; n < N; n++) {
		scanf("%s", cmd);
		//push
		if (strcmp(cmd, "push") == 0) {
			top++;
			scanf("%d", &stack[top]);
		}
		//pop
		else if (strcmp(cmd, "pop") == 0) {
			if (top >= 0) {
				printf("%d\n", stack[top]);
				top--;
			}
			else {
				printf("-1\n");
			}
		}
		//size
		else if (strcmp(cmd, "size") == 0) {
			printf("%d\n", top + 1);
		}
		//empty
		else if (strcmp(cmd, "empty") == 0) {
			if (top >= 0) {
				printf("0\n");
			}
			else {
				printf("1\n");
			}
		}
		//top
		else {
			if (top >= 0) {
				printf("%d\n", stack[top]);
			}
			else {
				printf("%d\n", top);	//-1
			}
		}
	}

	return 0;
}
