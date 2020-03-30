#include <iostream>
#include <vector>	//vector
#include <cstring>	//memset()
#include <cmath>	//sqrt()
using namespace std;

#define MAX_PRICE 10000			//사탕 개당 최대 가격
#define MAX_TOTAL_PRICE 500000	//총합 최고 가격 50개 * 10000원

bool isPrime[MAX_TOTAL_PRICE + 1];		//isPrime[i]가 true면 i는 소수, false면 합성수
int candyCnt[MAX_PRICE + 1];			//candyCnt[i]는 가격이 i인 사탕의 개수
long long caseCnt[MAX_TOTAL_PRICE + 1];	//caseCnt[i]는 가격이 i가 되게 하는 경우의 수(크기 : W)

void getPrimeNumber();	//소수를 구하는 함수

int main() {
	int N;
	scanf("%d", &N);

	//미리 소수 구해놓기
	getPrimeNumber();

	//candyCnt 초기화
	memset(candyCnt, 0, sizeof(candyCnt));
	candyCnt[0] = 1;
	//사탕 가격 정보 받기
	vector<int> candyList;	//사탕의 가격 리스트
	int zeroCnt = 1;		//가격이 0인 사탕의 개수
	for (int i = 0; i < N; i++) {
		int price;
		scanf("%d", &price);
		//가격이 0이면 zeroCnt 증가
		if (price == 0) {
			zeroCnt++;
			continue;
		}
		//아니면 candyList, candyCnt 업데이트
		if (candyCnt[price] == 0)
			candyList.push_back(price);
		candyCnt[price]++;
	}

	//caseCnt 초기화
	memset(caseCnt, 0, sizeof(caseCnt));
	caseCnt[0] = 1;
	//동적계획법을 통한 총합 가격별 경우의 수 구하기
	for (int i = 0; i < candyList.size(); i++) {
		for (int goalPrice = MAX_TOTAL_PRICE; goalPrice >= 0; goalPrice--) {
			for (int cnt = 1; cnt <= candyCnt[candyList[i]]; cnt++) {
				//예외처리
				if (goalPrice - candyList[i] * cnt < 0)
					break;

				//이전까지의 결과와 경우의 수 합하기
				caseCnt[goalPrice] += caseCnt[goalPrice - candyList[i] * cnt];
			}
		}
	}

	//정답 구하기
	long long totalCnt = 0;
	for (int i = 2; i <= MAX_TOTAL_PRICE; i++) {
		//사탕 가격의 합이 소수면 정답에 추가
		if (isPrime[i])
			totalCnt += caseCnt[i];
	}
	//0의 개수만큼 경우의 수 곱하기
	totalCnt *= zeroCnt;

	//정답 출력
	printf("%lld\n", totalCnt);

	return 0;
}

//소수를 구하는 함수
void getPrimeNumber() {
	//isPrime 초기화
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	//에라토스테네스의 체를 통해 소수 구하기
	for (int i = 2; i <= sqrt(MAX_TOTAL_PRICE); i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= MAX_TOTAL_PRICE; j += i)
				isPrime[j] = false;
		}
	}
	return;
}
