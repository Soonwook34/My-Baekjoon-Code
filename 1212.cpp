#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[333335] = "";
	scanf("%s", s);

	char first[][4] = { "", "1", "10", "11", "100", "101", "110", "111" };
	char rest[][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };
	
	int len = strlen(s);

	if (atoi(s) == 0) {
		printf("0");
		return 0;
	}

	printf("%s", first[s[0] - '0']);
	for (int i = 1; i < len; i++)
		printf("%s", rest[s[i] - '0']);

	return 0;
}
