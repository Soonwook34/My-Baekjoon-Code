#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> weight;
vector<int> value;

int knapsack();

int main() {
	//입력
	scanf("%d %d", &N, &K);
	weight.resize(N);
	value.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &weight[i], &value[i]);

	//정답 구하기
	printf("%d\n", knapsack());
}

//kanpsack 알고리즘
int knapsack() {
	vector<int> totalValue(K + 1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = K; j > 0; j--)
			//점화식
			if (weight[i] <= j)
				totalValue[j] = max(totalValue[j], totalValue[j - weight[i]] + value[i]);
	}

	return totalValue[K];
}
