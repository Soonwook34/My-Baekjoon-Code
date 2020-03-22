#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int twoCount = 0;
	int fiveCount = 0;
	int tempFactorial = 1;

	for(int i=1; i<=N; i++) {
		tempFactorial = i;

		while (tempFactorial % 2 == 0) {
			twoCount++;
			tempFactorial /= 2;
		}
		while (tempFactorial % 5 == 0) {
			fiveCount++;
			tempFactorial /= 5;
		}
	}

	printf("%d\n", min(twoCount, fiveCount));

	return 0;
}
