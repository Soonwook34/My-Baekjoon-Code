#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define MAX 1000000

bool isPrime[MAX + 1] = { false, };		//isPrime[i]가 true면 i는 소수
vector<pair<int, int>> totalPrimeCnt;	//소수 i가 j번 포함되는지 알려주는 totalPrimeCnt(i, j)

void getPrimeNumber();	//primeCnt를 초기화시키는 함수

int main() {
	int N;
	cin >> N;

	getPrimeNumber();
	//각 점수의 소인수분해 정보 저장
	vector<vector<pair<int, int>>> scorePrimeCnt(N, totalPrimeCnt);	//i번째 점수의 j번째 소수 k가 l번 포함되는지 알려주는 scorePrimeCnt[i][j](k, l)
	for (int i = 0; i < N; i++) {
		int num, temp;
		cin >> num;
		temp = num;
		//소인수분해
		for (int j = 0; totalPrimeCnt[j].first <= num; j++) {
			while (temp % totalPrimeCnt[j].first == 0) {
				temp /= totalPrimeCnt[j].first;
				totalPrimeCnt[j].second++;
				scorePrimeCnt[i][j].second++;
			}
		}
	}
	//최대공약수와 최소횟수 구하기
	int gcd = 1, minCnt = 0;
	for (int i = 0; i < totalPrimeCnt.size(); i++) {
		if (totalPrimeCnt[i].second >= N) {
			int commonDivisorCnt = totalPrimeCnt[i].second / N;
			//최대공약수
			gcd *= pow(totalPrimeCnt[i].first, commonDivisorCnt);
			//최소횟수
			for (int j = 0; j < N; j++) {
				if (scorePrimeCnt[j][i].second < commonDivisorCnt) {
					minCnt += commonDivisorCnt - scorePrimeCnt[j][i].second;
				}
			}
		}
	}

	printf("%d %d\n", gcd, minCnt);

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
			totalPrimeCnt.push_back(pair<int, int>(i, 0));
		}
	}
}
