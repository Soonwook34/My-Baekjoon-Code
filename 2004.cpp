#include <iostream>
#include <algorithm>
using namespace std;

pair<long, long> twoFiveCount[3];

pair<long, long> getTwoFiveCount(long);

int main() {
	long N, M;
	scanf("%d %d", &N, &M);

	if (M > N / 2)
		M = N - M;

	twoFiveCount[0] = getTwoFiveCount(N);
	twoFiveCount[1] = getTwoFiveCount(M);
	twoFiveCount[2] = getTwoFiveCount(N-M);

	printf("%ld\n", min(twoFiveCount[0].first - twoFiveCount[1].first - twoFiveCount[2].first, twoFiveCount[0].second - twoFiveCount[1].second - twoFiveCount[2].second));

	return 0;
}

pair<long, long> getTwoFiveCount(long X) {
	long twoCount = 0, fiveCount = 0;

	for (long i = 2; i <= X; i *= 2)
		twoCount += X / i;
	for (long i = 5; i <= X; i *= 5)
		fiveCount += X / i;

	return pair<long, long>(twoCount, fiveCount);
}
