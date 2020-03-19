#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 10000000

bool isPrime[MAX + 1] = { false, };
vector<int> totalPrimeCnt;

void getPrimeNumber();

int main() {
	int N;
	scanf("%d\n", &N);
	
	getPrimeNumber();
	
	for (int j = 0; totalPrimeCnt[j] <= N; j++) {
		while (N % totalPrimeCnt[j] == 0) {
			N /= totalPrimeCnt[j];
			printf("%d\n", totalPrimeCnt[j]);
		}
	}

	return 0;
}

void getPrimeNumber() {
	//전체가 소수라고 가정
	for (int i = 2; i <= MAX; i++) {
		isPrime[i] = true;
	}
	//에라토스테네스의 체를 이용한 소수 구하기
	for (int i = 2; i <= sqrt(MAX); i++) {
		if (isPrime[i] == false) {
			continue;
		}
		for (int j = i * i; j <= MAX; j += i) {
			isPrime[j] = false;
		}
	}
	//totalPrimeCnt에 소수 입력
	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			totalPrimeCnt.push_back(i);
		}
	}
}
