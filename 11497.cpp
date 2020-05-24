#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		int N;
		scanf("%d", &N);
		vector<int> v(N);

		for (int i = 0; i < N; i++)
			scanf("%d", &v[i]);
		//오름차순으로 정렬한 다음 양끝에서부터 하나씩 채워나가면 최소 난이도
		sort(v.begin(), v.end());

		int level = 0;
		//앞쪽 반
		for (int i = 2; i < N; i += 2)
			level = max(level, v[i] - v[i - 2]);
		//뒤쪽 반
		for (int i = 3; i < N; i += 2)
			level = max(level, v[i] - v[i - 2]);
		
		printf("%d\n", level);
	}

	return 0;
}
