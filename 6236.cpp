#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> spending;	//일별 이용할 금액

bool isPossible(int);	//문제의 조건을 만족하면 true, 아니면 false를 리턴

int main() {
	scanf("%d %d", &N, &M);

	int maxSpending = 0;
	for (int i = 0; i < N; i++) {
		int money;
		scanf("%d", &money);
		spending.push_back(money);
		maxSpending = max(maxSpending, money);
	}

	int left = maxSpending, right = 1000000000;
	int mid, pocketMoney = 1000000000;
	//Parametric Search를 이용해 pocketMoney 찾기
	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(mid)) {
			pocketMoney = min(pocketMoney, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", pocketMoney);

	return 0;
}

bool isPossible(int pocketMoney) {
	int budget = 0;			//가장 최근 인출 후 지불해야하는 돈
	int withdrawCnt = 1;	//인출한 횟수
	for (int i = 0; i < spending.size(); i++) {
		//인출이 필요하면
		if (budget + spending[i] > pocketMoney) {
			budget = spending[i];
			withdrawCnt++;
		}
		//그렇지 않으면
		else {
			budget += spending[i];
		}
	}

	if (withdrawCnt <= M)
		return true;
	else
		return false;
}
