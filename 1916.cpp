#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
vector<vector<pair<int, int>>> town;

int solve(int, int);

int main() {
	scanf("%d %d", &N, &M);
	town.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		town[a].push_back(make_pair(b, c));
	}
	int A, B;
	scanf("%d %d", &A, &B);

	printf("%d\n", solve(A, B));

	return 0;
}

//다익스트라
int solve(int from, int to) {

	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(-0, from));
	int totalTime[1001];
	memset(totalTime, -1, sizeof(totalTime));
	totalTime[from] = 0;

	while (!pq.empty()) {
		int curr = pq.top().second;
		int time = -pq.top().first;
		pq.pop();
		for (int i = 0; i < town[curr].size(); i++) {
			int next = town[curr][i].first;
			int nextTime = town[curr][i].second;
			if (totalTime[next] == -1 || totalTime[next] > time + nextTime) {
				totalTime[next] = time + nextTime;
				pq.push(make_pair(-(time + nextTime), next));
			}
		}
	}
	return totalTime[to];
}
