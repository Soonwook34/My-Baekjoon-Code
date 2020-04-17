#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, S;
	scanf("%d %d", &N, &S);
	
	vector<pair<int, int>> paint;	//그림의 정보를 (높이, 가격)으로 저장하는 vector
	for (int i = 0; i < N; i++) {
		int height, price;
		scanf("%d %d", &height, &price);
		//높이가 S 이상인 그림만 paint에 저장
		if (height >= S)
			paint.push_back(pair<int, int>(height, price));
	}
	N = paint.size();	//resize N

	vector<int> prevPaint(N);		//prevPaint(i)는 i번째 그림 이전에 올 수 있는 가장 높은 그림의 인덱스
	vector<int> maxPrice(N);		//maxPrice(i)는 i번째까지 고려하였을 때의 최대 금액

	//paint 높이순 정렬
	sort(paint.begin(), paint.end());

	//LIS를 이용하여 prevPaint 채우기
	prevPaint[0] = -1;	//prevPaint[i]의 값이 -1이면 i번째 그림은 처음에 올 수밖에 없는 그림
	for (int i = 1; i < N; i++) {
		//처음에 올 수 밖에 없는 그림인지 확인
		if (paint[i].first - paint[0].first < S) {
			prevPaint[i] = -1;
			continue;
		}
		int prevIndex = prevPaint[i - 1]+1;
		for (; prevIndex < i; prevIndex++) {
			if (paint[i].first - paint[prevIndex].first < S)
				break;
		}
		prevPaint[i] = prevIndex-1;
	}

	//maxPrice[N-1] 구하기
	maxPrice[0] = paint[0].second;
	for (int i = 1; i < N; i++) {
		//첫번째 그림이라면
		if (prevPaint[i] == -1)
			maxPrice[i] = paint[i].second;
		//아닐 경우 자기 이전에 올 수 있는 가장 높은 그림(prevPaint[i])의 가격 + 현재 그림 가격
		else
			maxPrice[i] = maxPrice[prevPaint[i]] + paint[i].second;
		//최댓값 정하기
		maxPrice[i] = max(maxPrice[i], maxPrice[i - 1]);
	}

	printf("%d\n", maxPrice[N - 1]);

	return 0;
}
