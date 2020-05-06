#include <iostream>
using namespace std;

long long A, B, C;

long long myPow(long long, long long);

int main() {
	scanf("%lld %lld %lld", &A, &B, &C);

	printf("%lld\n", myPow(A, B) % C);

	return 0;
}

long long myPow(long long X, long long Y) {
	//0제곱이면 1리턴
	if (Y == 0)
		return 1;
	//1제곱이면 X리턴
	if (Y == 1)
		return X;
	//2n제곱이면 n제곱을 구한 후 n제곱 * n제곱
	if (Y % 2 == 0) {
		long long half = myPow(X, Y / 2) % C;
		return (half * half) % C;
	}
	//2n+1제곱이면 2n제곱 * X
	else {
		return myPow(X, Y - 1) * X;
	}
}
