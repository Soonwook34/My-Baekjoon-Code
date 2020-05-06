#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	queue<int> card;
	//초기 상태
	for (int i = 1; i <= N; i++)
		card.push(i);

	int i = 1;
	int x;
	while(card.size() > 1) {
		//홀수번째
		if (i % 2 == 1) {
			card.pop();
		}
		//짝수번째
		else {
			x = card.front();
			card.pop();
			card.push(x);
		}
		i++;
	}

	printf("%d\n", card.front());

	return 0;
}
