#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAX 1000

char s1[MAX + 2], s2[MAX + 2];
int dp[MAX + 1][MAX + 1] = { 0, };

int main() {
	scanf("%s %s", s1 + 1, s2 + 1);
	int len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i] == s2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max({ dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j] });
		}
	}
	printf("%d\n", dp[len1][len2]);

	return 0;
}
