#include <iostream>
#include <vector>
using namespace std;

#define MAX_TC 5		//최대 TC
#define MAX_N 500		//최대 N
#define MAX_D 5000000	//시작점으로부터 최대 거리는 (최대 N - 1) * 최대 T < 5000000

int TC, tc;
int N, M, W;
int S, E, T;
vector<pair<int, int>> graph[MAX_TC + 1][MAX_N + 1];	//지점 S와 연결된 지점의 번호 E와 흘러간 시간 T를 나타내는 graph[tc][S](E, T)
vector<int> time;										//지점 S에서 지점 1로 돌아가는데 걸리는 최소 시간 time[S]

bool BellmanFord();

int main() {
	scanf("%d", &TC);

	for (tc = 0; tc < TC; tc++) {
		//입력
		scanf("%d %d %d", &N, &M, &W);
		//도로 정보
		for (int j = 0; j < M; j++) {
			scanf("%d %d %d", &S, &E, &T);
			graph[tc][S].push_back(make_pair(E, T));
			graph[tc][E].push_back(make_pair(S, T));
		}
		//웜홀 정보
		for (int k = 0; k < W; k++) {
			scanf("%d %d %d", &S, &E, &T);
			graph[tc][S].push_back(make_pair(E, -T));
		}

		//초기화
		time.resize(N + 1);
		fill(time.begin(), time.end(), MAX_D);
		time[1] = 0;

		//BellmanFord 알고리즘 수행
		if (BellmanFord())
			printf("YES\n");
		else
			printf("NO\n");
	}
}

//BellmanFord 알고리즘
bool BellmanFord() {
	for (int i = 0; i < N; i++) {
		for (int u = 1; u <= N; u++) {
			for (int k = 0; k < graph[tc][u].size(); k++) {
				int v = graph[tc][u][k].first;
				int w = graph[tc][u][k].second;
				if (time[u] + w < time[v])
					time[v] = time[u] + w;
			}
		}
	}
	//negative-weight cycle이 있으면 true, 없으면 false
	for (int u = 1; u <= N; u++) {
		for (int k = 0; k < graph[tc][u].size(); k++) {
			int v = graph[tc][u][k].first;
			int w = graph[tc][u][k].second;
			if (time[u] + w < time[v])
				return true;
		}
	}
	return false;
}
