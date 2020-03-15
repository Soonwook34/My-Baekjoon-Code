#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> numberMarble;	//숫자 구슬

bool isPossible(int);	//문제의 조건을 만족하면 true, 아니면 false를 리턴
void makeGroup(int);	//숫자 구슬 그룹 나누기

int main() {
	scanf("%d %d", &N, &M);

	int maxNumber = 0;
	for (int i = 0; i < N; i++) {
		int marble;
		scanf("%d", &marble);
		numberMarble.push_back(marble);
		maxNumber = max(maxNumber, marble);
	}

	int left = maxNumber, right = 30000;
	int mid, groupNumber = 30000;
	//Parametric Search를 이용해 groupNumber 찾기
	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(mid)) {
			groupNumber = min(groupNumber, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", groupNumber);
	makeGroup(groupNumber);

	return 0;
}

bool isPossible(int groupNumber) {
	int groupSum = 0;	//현재 그룹의 숫자 구슬의 합
	int groupCount = 1;	//그룹 번호
	for (int i = 0; i < numberMarble.size(); i++) {
		//다음 그룹으로 넘어가야하면
		if (groupSum + numberMarble[i] > groupNumber) {
			groupSum = numberMarble[i];
			groupCount++;
		}
		//그렇지 않으면
		else {
			groupSum += numberMarble[i];
		}
	}
	
	if (groupCount <= M)
		return true;
	else
		return false;
}

void makeGroup(int groupNumber) {
	//isPossible()과 같은 방법으로 그룹 나누기
	int groupSum = 0;
	int groupCount = 1;
	vector<int> marbleCount;	//각 그룹의 구슬 개수
	int tempCount = 0;

	for (int i = 0; i < numberMarble.size(); i++, tempCount++) {
		if (groupSum + numberMarble[i] > groupNumber) {
			groupSum = numberMarble[i];
			groupCount++;
			marbleCount.push_back(tempCount);
			tempCount = 0;
		}
		else {
			groupSum += numberMarble[i];
		}
	}
	marbleCount.push_back(tempCount);
	//M보다 marbleCount의 개수가 작다면 M과 같아질 때까지 크기가 2 이상인 그룹을 하나씩 나누어준다
	while (marbleCount.size() < M) {
		vector<int>::iterator it;	//vector 삽입을 위한 iterator 사용
		for (it = marbleCount.begin(); it < marbleCount.end(); it++) {
			if (*it > 1) {
				int temp = *it;
				*it = temp / 2 + temp % 2;
				marbleCount.insert(it, temp / 2);
				break;
			}
		}
	}
	//그룹별 구슬 개수 출력
	for (int i = 0; i < marbleCount.size(); i++) {
		printf("%d ", marbleCount[i]);
	}
	printf("\n");

	return;
}
