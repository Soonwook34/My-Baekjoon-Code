#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000

int N;
int arr[MAX + 1];
int LIS[MAX + 1];
int position[MAX + 1];

int getUpperBound(int, int);

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", arr + i);

	fill(LIS, LIS + N, MAX + 1);

	int p = 0, maxP = 0;
	LIS[0] = -MAX;
	for (int i = 0; i < N; i++) {
		p = getUpperBound(arr[i], N - 1);
		position[i] = p;
		LIS[p] = arr[i];
		maxP = max(maxP, p);
	}

	printf("%d\n", maxP);
}

int getUpperBound(int x, int p) {
	while (p >= 0) {
		if (x > LIS[p])
			break;
		p--;
	}
	
	return p + 1;
}
