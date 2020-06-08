#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> road;
int totalTime[1001] = { 0, };

void getMinTime(int, int);

int main() {
	scanf("%d %d %d", &N, &M, &X);
	road.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int A, B, T;
		scanf("%d %d %d", &A, &B, &T);
		road[A].push_back(make_pair(B, T));
	}

	getMinTime(X, X);

	for (int i = 1; i <= N; i++) {
		if (i != X)
			getMinTime(i, X);
	}

	int maxTime = 0;
	for (int i = 1; i <= N; i++)
		maxTime = max(maxTime, totalTime[i]);

	printf("%d\n", maxTime);

	return 0;
}

void getMinTime(int from, int to) {
	//Dijkstra
	priority_queue<pair<int, int>> pq;
	bool visited[1001] = { false, };
	pq.push(make_pair(-0, from));
	int oneWay[1001] = { 0, };

	while (!pq.empty()) {
		int town = pq.top().second;
		int time = -pq.top().first;
		pq.pop();
		if (!visited[town]) {
			visited[town] = true;
			oneWay[town] = time;
		}
		for (int i = 0; i < road[town].size(); i++) {
			int nextTown = road[town][i].first;
			int nextTime = road[town][i].second;
			if (!visited[nextTown])
				pq.push(make_pair(-(time + nextTime), nextTown));
		}
	}

	if (from == to) {
		for (int i = 1; i <= N; i++) {
			totalTime[i] = oneWay[i];
		}
	}
	else
		totalTime[from] += oneWay[to];
}
