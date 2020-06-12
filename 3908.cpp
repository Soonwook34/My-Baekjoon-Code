#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int T;
vector<int> prime;
unsigned int dp[15][1121] = { 0, };

void getPrimeNumber(int);
void knapsack(int, int);

int main() {
	scanf("%d", &T);
	int maxNum = 0;
	int maxCnt = 0;
	vector<pair<int, int>> list;

	for (int t = 0; t < T; t++) {
		int n, k;
		scanf("%d %d", &n, &k);
		maxNum = max(maxNum, n);
		maxCnt = max(maxCnt, k);
		list.push_back(make_pair(n, k));
	}

	getPrimeNumber(maxNum);

	knapsack(maxNum, maxCnt);

	for (int t = 0; t < T; t++) {
		printf("%u\n", dp[list[t].second][list[t].first]);
	}
	return 0;
}

void getPrimeNumber(int max) {
	bool isPrime[1121];
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= sqrt(max); i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= max; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = 2; i <= max; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
}

void knapsack(int maxNum, int maxCnt) {
	dp[0][0] = 1;

	for (int i = 0; i < prime.size(); i++) {
		for (int j = maxNum; j >= prime[i]; j--) {
			for (int cnt = 1; cnt <= maxCnt; cnt++) {
				dp[cnt][j] += dp[cnt - 1][j - prime[i]];
			}
		}
	}
}
