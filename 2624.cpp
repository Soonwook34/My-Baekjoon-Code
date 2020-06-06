#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000;

int T, k;
vector<pair<int, int>> coin;

int knapsack();

int main() {
	scanf("%d", &T);
	scanf("%d", &k);
	
	for (int i = 0; i < k; i++) {
		int value, num;
		scanf("%d %d", &value, &num);
		coin.push_back(make_pair(value, num));
	}

	printf("%d\n", knapsack());

	return 0;
}

int knapsack() {
	vector<int> change(T + 1, 0);
	change[0] = 1;

	for (int i = 0; i < k; i++) {
		int value = coin[i].first;
		int num = coin[i].second;
		for (int total = T; total >= 0; total--) {
			for (int cnt = 1; cnt <= num; cnt++) {
				if (total - value * cnt < 0)
					break;

				change[total] += change[total - value * cnt];
			}
		}
	}

	return change[T];
}
