#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int N;
	scanf("%d", &N);

	//입력받기
	vector<int> list(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &list[i]);

	//오름차순 정렬
	sort(list.begin(), list.end());

	//list[i] - list[i-1]이 가장 작은 수 찾기(min)
	int min = list[1] - list[0];
	for (int i = 2; i < N; i++) {
		if (list[i] - list[i - 1] < min)
			min = list[i] - list[i - 1];
	}

	int divide, remain;
	bool isSame;
	//1을 제외한 min의 약수 중 문제의 조건을 만족하는 수 출력
	for (int i = min/2; i >= 1; i--) {
		if (min % i != 0)
			continue;
		divide = min / i;
		remain = list[0] % divide;
		isSame = true;
		for (int j = 1; j < N; j++) {
			if (list[j] % divide != remain) {
				isSame = false;
				break;
			}
		}
		if (isSame)
			printf("%d ", divide);
	}

	return 0;
}
