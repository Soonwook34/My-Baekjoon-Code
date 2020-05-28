#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 1000

int N, E, A, B;
vector<vector<pair<int, int>>> capacity;	//u에서 v까지 capacity w의 집합 capacity[u] (v, w)
vector<vector<pair<int, int>>> flow;		//u에서 v까지 flow w의 집합 flow[u] (v, w)
vector<bool> visited(MAX_N);				//정점의 방문 여부

int findMaxFlow();							//Edmons-Karp 알고리즘을 이용하여 U부터 V까지 Max Flow를 구하는 함수 findMaxFlow(U, V)
int findMaxSingleFlow(int, int, int);		//DFS를 이용하여 U부터 V까지 한 경로의 Max Flow를 구하는 함수 findMaxSingleFlow(U, V, W)
												//W는 flow(U->V)로 시작부터 U까지 경로의 최솟값


int main() {
	int T;
	scanf("%d", &T);

	for (int t = 0; t < T; t++) {
		//입력
		scanf("%d %d %d %d", &N, &E, &A, &B);
		capacity.resize(N);
		flow.resize(N);

		for (int i = 0; i < E; i++) {
			int U, V, W;
			scanf("%d %d %d", &U, &V, &W);
			//capacity 입력(V-U는 flow를 위해 0으로 추가)
			capacity[U].push_back({ V, W });
			capacity[V].push_back({ U, 0 });
			//flow 입력(capacity 정보에 따른 초기화)
			flow[U].push_back({ V, 0 });
			flow[V].push_back({ U, 0 });
		}

		//Max Flow 구하기
		int maxFlow = findMaxFlow();
		//한 경로의 Max Flow 구하기
		fill(visited.begin(), visited.end(), false);
		int maxSingleFlow = findMaxSingleFlow(A, B, INT_MAX);

		//최소 중복 비율 출력
		printf("%.3lf\n", (double)maxFlow / (double)maxSingleFlow);

		//다음 TC를 위해 초기화
		for (int j = 0; j < N; j++) {
			capacity[j].clear();
			flow[j].clear();
		}
	}

	return 0;
}

//Edmons-Karp 알고리즘을 이용하여 U부터 V까지 Max Flow를 구하는 함수 findMaxFlow(U, V)
int findMaxFlow() {
	vector<pair<int, int>> prevRoad;	//정점 v의 이전 정점 u와 capacity(u->v)를 저장하는 변수
	int maxFlow = 0;
	//Augmenting Path가 없을 때까지 반복
	while(1) {
		//BFS를 이용하여 Augmenting Path 찾기
		prevRoad.clear();
		prevRoad.resize(N, { -1, -1 });
		queue<int> q;
		prevRoad[A] = { A, 0 };
		q.push(A);
		
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			for (int i = 0; i < capacity[curr].size(); i++) {
				int next = capacity[curr][i].first;
				//도로가 유효하려면 curr부터 다음까지의 Residual Capacity가 0보다 커야한다
				int nextResidualCap = capacity[curr][i].second;
				for (int j = 0; j < flow[curr].size(); j++) {
					if (flow[curr][j].first == next) {
						nextResidualCap -= flow[curr][j].second;
						break;
					}
				}
				//도로가 유효하면 정보 저장 및 q에 추가
				if (prevRoad[next].first == -1 && nextResidualCap > 0) {
					prevRoad[next].first = curr;
					prevRoad[next].second = nextResidualCap;
					//가장 먼저 B에 다다르면 BFS break
					if (next == B)
						break;
					q.push(next);
				}
			}
		}
		//더 이상 Augmenting Path가 없으면 break
		if (prevRoad[B].first == -1)
			break;

		//Augmenting Path의 전체 Residual Capacity 구하기
		int residualCap = prevRoad[B].second;
		for (int i = prevRoad[B].first; i != A; i = prevRoad[i].first)
			residualCap = min(residualCap, prevRoad[i].second);

		//Residual Capacity 반영하기
		for (int i = B; i != A; i = prevRoad[i].first) {
			int prev = prevRoad[i].first;
			//정방향 Path의 flow에 반영
			for (int j = 0; j < flow[prev].size(); j++) {
				if (flow[prev][j].first == i) {
					flow[prev][j].second += residualCap;
					break;
				}
			}
			//역방향 Path의 flow에 반영
			for (int k = 0; k < flow[i].size(); k++) {
				if (flow[i][k].first == prev) {
					flow[i][k].second -= residualCap;
					break;
				}
			}
		}
		//Max Flow 계산
		maxFlow += residualCap;
	}

	return maxFlow;
}

//DFS를 이용하여 U부터 V까지 한 경로의 Max Flow를 구하는 함수 findMaxSingleFlow(U, V, W)
int findMaxSingleFlow(int from, int to, int maxF) {
	//도착했으면
	if (from == to)
		return maxF;

	int maxSingle = 0;
	//모든 경로를 DFS로 탐색
	for (int i = 0; i < flow[from].size(); i++) {
		if (!visited[flow[from][i].first] && flow[from][i].second > 0) {
			int next = flow[from][i].first;
			visited[next] = true;
			//maxF 자리에 시작부터 현재까지 경로의 최소 flow 값 넣어주기
			maxSingle = max(maxSingle, findMaxSingleFlow(next, to, min(maxF, flow[from][i].second)));
			visited[next] = false;
		}
	}

	return maxSingle;
}
