#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	int x = 0;
	char ps[51];
	for (int t = 0; t < T; t++) {
		scanf("%s", ps);
		bool isVPS = true;
		for (int i = 0; i < strlen(ps); i++) {
			//'('인 경우
			if (ps[i] == '(')
				x++;
			//')'인 경우
			else {
				if (x > 0)
					x--;
				//더 많은 괄호가 닫힌 경우
				else {
					isVPS = false;
					break;
				}
			}
		}
		//괄호가 열린 채로 끝난 경우
		if (isVPS && x != 0)
			isVPS = false;

		if (isVPS)
			printf("YES\n");
		else
			printf("NO\n");
		x = 0;
	}

	return 0;
}
