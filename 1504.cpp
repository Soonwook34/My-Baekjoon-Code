#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_COST 800000

int N, E;
vector<vector<pair<int, int>>> graph;	//a에서 b까지 거리c의 길의 집합 graph[a] (b, c)

vector<int> getShortestPath(int);		//x로부터 모든 정점들까지의 최단거리를 리턴하는 함수 getShortestPath(x)

int main() {
	//입력
	scanf("%d %d", &N, &E);
	graph.resize(N + 1);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	int v1, v2;
	scanf("%d %d", &v1, &v2);

	//v1, v2로부터의 모든 정점에 대한 최단 경로 구하기
	vector<int> fromV1 = getShortestPath(v1);
	vector<int> fromV2 = getShortestPath(v2);

	int startToV1 = fromV1[1];	//양방향 그래프이므로 1->v1 = v1->1
	int startToV2 = fromV2[1];	//양방향 그래프이므로 1->v2 = v2->1
	int v1toV2 = fromV1[v2];
	int v2toV1 = fromV2[v1];
	int v1ToN = fromV1[N];
	int v2ToN = fromV2[N];
	//v1, v2 중 먼저 방문하는 정점에 따른 최단 경로 중 최솟값 구하기
	int shortestPath = min(startToV1 + v1toV2 + v2ToN, startToV2 + v2toV1 + v1ToN);
	if (shortestPath > MAX_COST)
		printf("-1\n");
	else
		printf("%d\n", shortestPath);

	return 0;
}

//BellmanFord 알고리즘 이용
vector<int> getShortestPath(int from) {
	vector<int> distance(N + 1, MAX_COST + 1);
	distance[from] = 0;
	bool isUpdated;

	for (int it = 0; it < N; it++) {
		isUpdated = false;
		for (int curr = 1; curr <= N; curr++) {
			for (int j = 0; j < graph[curr].size(); j++) {
				int next = graph[curr][j].first;
				int cost = graph[curr][j].second;
				if (distance[curr] + cost < distance[next]) {
					distance[next] = distance[curr] + cost;
					isUpdated = true;
				}
			}
		}
		//더 이상 경로가 갱신이 안된다면 break
		if (!isUpdated)
			break;
	}
	return distance;
}
