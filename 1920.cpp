#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, X;
vector<int> A;

int find(int);

int main() {
	scanf("%d", &N);

	A.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	//정렬
	sort(A.begin(), A.end());

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &X);
		printf("%d\n", find(X));
	}
}

//A에 X가 있으면 1, 없으면 0 리턴
int find(int X) {
	//이진 탐색 수행
	int low = 0, high = N - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] == X)
			return 1;
		if (A[mid] > X)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return 0;
}
