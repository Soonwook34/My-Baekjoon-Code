#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 10000;

int N, M;
vector<int> arr;

bool isOkay(int);

int main() {
	scanf("%d %d", &N, &M);
	arr.resize(N);

	for (int i = 0; i < N; i++)
		scanf("%d", &arr[i]);

	int left = 0, right = MAX;
	int mid, minMaxV = MAX;
	while (left <= right) {
		mid = (left + right) / 2;
		if (isOkay(mid)) {
			minMaxV = min(minMaxV, mid);
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	printf("%d\n", minMaxV);

	return 0;
}

bool isOkay(int maxV) {
	int section = 1;
	int minS = arr[0], maxS = arr[0];

	for (int i = 1; i < N; i++) {
		minS = min(minS, arr[i]);
		maxS = max(maxS, arr[i]);
		if (maxS - minS > maxV) {
			minS = maxS = arr[i];
			section++;
		}
	}

	return section <= M;
}
