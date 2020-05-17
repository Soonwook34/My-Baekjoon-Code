#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, X;
vector<int> A;

int find(int);
int count(int, int);

int main() {
	scanf("%d", &N);

	A.resize(N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	//정렬
	sort(A.begin(), A.end());

	vector<int>::iterator low, nextLow;

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &X);
		low = lower_bound(A.begin(), A.end(), X);			//X가 처음으로 나오는 위치
		nextLow = lower_bound(A.begin(), A.end(), X + 1);	//X+1이 처음으로 나오는 위치
		printf("%d ", nextLow - low);
	}
}
