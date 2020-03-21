#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	
	long stairNumber[101][10];

	stairNumber[1][0] = 0;
	for (int i = 1; i < 10; i++)
		stairNumber[1][i] = 1;

	for (int n = 2; n <= N; n++) {
		for (int i = 0; i < 10; i++) {
			switch (i) {
			case 0:
				stairNumber[n][i] = stairNumber[n - 1][1];
				break;
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
				stairNumber[n][i] = (stairNumber[n - 1][i - 1] + stairNumber[n - 1][i + 1]) % 1000000000;
				break;
			case 9:
				stairNumber[n][i] = stairNumber[n - 1][8];
				break;
			}
		}
	}
	
	long sum = 0;
	for (int i = 0; i < 10; i++)
		sum = (sum + stairNumber[N][i]) % 1000000000;

	printf("%ld\n", sum);

	return 0;
}
