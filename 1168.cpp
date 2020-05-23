#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	vector<int> v(N);

	for (int i = 0; i < N; i++)
		v[i] = i + 1;

	int curr = K - 1;

	printf("<");
	for (int i = 0; i < N - 1; i++) {
		printf("%d, ", v[curr]);
		v.erase(v.begin() + curr);
		curr = (curr + K - 1) % v.size();
	}
	printf("%d>\n", v[0]);

	return 0;
}
