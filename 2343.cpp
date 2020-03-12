#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> lessonTime;

bool isPossible(int);

int main() {
	scanf("%d %d", &N, &M);

	int maxlessonTime = 0;
	for (int i = 0; i < N; i++) {
		int time;
		scanf("%d", &time);
		lessonTime.push_back(time);
		maxlessonTime = max(maxlessonTime, time);
	}

	int left = maxlessonTime, right = 1000000000;
	int mid, blurayTime;

	while (left <= right) {
		mid = (left + right) / 2;
		if (isPossible(mid)) {
			blurayTime = min(blurayTime, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	printf("%d\n", blurayTime);

	return 0;
}

bool isPossible(int blurayTime) {
	int timeSpent = 0;
	int newBlurayCnt = 1;
	for (int i = 0; i < lessonTime.size(); i++) {
		if (timeSpent + lessonTime[i] > blurayTime) {
			timeSpent = lessonTime[i];
			newBlurayCnt++;
		}
		else {
			timeSpent += lessonTime[i];
		}
	}
	if (newBlurayCnt <= M)
		return true;
	else
		return false;
}
