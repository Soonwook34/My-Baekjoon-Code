#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MAX_V 20000

int V, E, K;
vector<pair<int, int>> graph[MAX_V + 1];	//u로부터 w의 값으로 이어진 v의 집합 graph[u] (v, w)
int length[MAX_V + 1];						//K부터 i까지의 거리 length[i]

void dijkstra();		//dikstra 알고리즘

int main() {
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	//입력
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		graph[u].push_back(make_pair(v, w));
	}
	
	//dikstra 알고리즘 수행
	dijkstra();

	//정답 출력
	for (int i = 1; i <= V; i++) {
		if (length[i] == INT_MAX)
			printf("INF\n");
		else
			printf("%d\n", length[i]);
	}
}

void dijkstra() {
	//lengh 초기화
	for (int i = 1; i <= V; i++)
		length[i] = INT_MAX;
	length[K] = 0;		//K부터 K의 거리는 0
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;	//이어진 집합에서 거리 w로 정점 v에 가는 간선의 오름차순 정렬
	pq.push(make_pair(0, K));		//K 넣기

	while (!pq.empty()) {
		//꺼내기
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[now].size(); i++) {
			int next = graph[now][i].first;
			int nextCost = graph[now][i].second;
			//이어진 노드가 훨씬 가깝다면 추가
			if (length[next] > cost + nextCost) {
				length[next] = cost + nextCost;
				pq.push(make_pair(length[next], next));
			}
		}
	}
}
