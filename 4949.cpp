#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main() {
	char string[101];

	scanf("%[^\n]", string);
	while (strcmp(string, ".") != 0) {
		stack<char> s;
		bool isVPS = true;
		for (int i = 0; i < strlen(string) && isVPS; i++) {
			switch (string[i]) {
			case '(':
			case '[':
				s.push(string[i]);
				break;
			case ')':
				//마지막 괄호가 '('이면 조건 만족
				if (s.size() > 0) {
					if (s.top() == '(')
						s.pop();
					else
						isVPS = false;
				}
				else
					isVPS = false;
				break;
			case ']':
				//마지막 괄호가 '['이면 조건 만족
				if (s.size() > 0) {
					if (s.top() == '[')
						s.pop();
					else
						isVPS = false;
				}
				else
					isVPS = false;
				break;
			default:
				break;
			}
		}
		//VPS이면
		if (isVPS && s.size() == 0)
			printf("yes\n");
		else
			printf("no\n");

		getchar();
		scanf("%[^\n]", string);
	}
	return 0;
}
