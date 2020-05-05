#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> seq(n);	//주어진 수열
	stack<int> s;		//이용할 스택
	vector<char> order;	//push(+), pop(-) 정보를 저장하는 변수
	bool isValid = true;

	//입력받기
	for (int i = 0; i < n; i++)
		scanf("%d", &seq[i]);

	//수열 만들기
	for (int i = 1, j = 0; isValid && j < n; j++) {
		//현재 자리의 수열 수가 i보다 크거나 같을 때
		if (seq[j] >= i) {
			//현재 자리의 수열 수까지 push 후
			while (i <= seq[j]) {
				s.push(i);
				order.push_back('+');
				i++;
			}
			//현재 자리 pop
			s.pop();
			order.push_back('-');
		}
		//현재 자리의 수열 수가 i보다 작을 때
		else {
			//스택의 가장 마지막으로 들어간 수가 현재 자리의 수열 수일 때
			if (s.top() == seq[j]) {
				s.pop();
				order.push_back('-');
			}
			//아니면 NO
			else
				isValid = false;
		}
	}

	//정답 출력
	if (isValid) {
		for (int i = 0; i < order.size(); i++)
			printf("%c\n", order[i]);
	}
	else
		printf("NO\n");

	return 0;
}
