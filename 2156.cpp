#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	vector<int> wine(N+1);

	for (int i = 1; i <= N; i++)
		scanf("%d", &wine[i]);

	vector<int> maxWine(N+1);
	maxWine[0] = 0;
	maxWine[1] = wine[1];
	maxWine[2] = wine[1] + wine[2];

	for (int i = 3; i <= N; i++) {
		maxWine[i] = max(max(maxWine[i - 3] + wine[i - 1] + wine[i], maxWine[i - 2] + wine[i]), maxWine[i-1]);
	}

	printf("%d\n", maxWine[N]);

	return 0;
}
