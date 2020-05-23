#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char address[5] = "";
	
	scanf("%s", address);
	while (atoi(address) != 0) {
		int length = 1;
		int addrLen = strlen(address);
		for (int i = 0; i < addrLen; i++) {
			switch (address[i] - '0') {
			case 1:
				length += 3;
				break;
			case 0:
				length += 5;
				break;
			default:
				length += 4;
			}
		}
		printf("%d\n", length);
		scanf("%s", address);
	}

	return 0;
}
