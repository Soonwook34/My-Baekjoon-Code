#include <iostream>
using namespace std;

#define COMPUTER 10

int main() {
	int T, A, B;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		scanf("%d %d", &A, &B);

		int x = 1;
		for (int i = 0; i < B; i++)
			x = x * A % COMPUTER;

		printf("%d\n", x == 0 ? 10 : x);
	}

	return 0;
}
