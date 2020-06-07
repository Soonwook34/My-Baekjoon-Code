#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 500

int N;
int mul[MAX + 1][MAX + 1] = { 0, };
int matrix[MAX + 1] = { 0, };

int getMinMul();

int main() {
	scanf("%d", &N);

	int r, c;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &r, &c);
		matrix[i] = r;
		matrix[i + 1] = c;
	}

	printf("%d\n", getMinMul());
	
	return 0;
}
//Chained Matrix Multiplication
int getMinMul() {
	for (int diagonal = 1; diagonal < N; diagonal++) {
		for (int i = 1; i <= N - diagonal; i++) {
			int j = i + diagonal;
			int minV = INT_MAX;
			for (int k = i; k < j; k++) {
				minV = min(minV, mul[i][k] + mul[k + 1][j] + matrix[i - 1] * matrix[k] * matrix[j]);
			}
			mul[i][j] = minV;
		}
	}

	return mul[1][N];
}
