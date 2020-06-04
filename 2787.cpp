#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;	//i번째 수가 될 수 있는 수 j의 집합 graph[i] (j)
vector<bool> visited;		//i번째 수의 방문 여부 vistied[i]
vector<int> Match;			//숫자 j와 매칭된 수열의 위치 Match[j]
vector<int> sequence;		//i번째 수와 매칭된 숫자(구하려는 수열) sequence[i]

bool DFS(int);				//DFS 기반 Maximum Bipartite Matching 알고리즘을 위한 DFS 함수

int main() {
	scanf("%d %d", &N, &M);
	graph.resize(N + 1);
	visited.resize(N + 1);
	Match.resize(N + 1, -1);
	sequence.resize(N + 1, -1);

	//수열의 정보 입력
	vector<vector<int>> check(N + 1, vector<int>(N + 1, 1));	//i번째 수가 j가 될 수 있는지 여부 check[i][j] 
	for (int m = 0; m < M; m++) {
		//조건 입력
		int condition, x, y, v;
		scanf("%d %d %d %d", &condition, &x, &y, &v);
		
		switch (condition) {
		case 1:
			//[x, y]는 (v, N]이 될 수 없다
			for (int i = x; i <= y; i++) {
				for (int num = v + 1; num <= N; num++)
					check[i][num] = 0;
			}
			break;
		case 2:
			//[x, y]는 [1, v)가 될 수 없다
			for (int i = x; i <= y; i++) {
				for (int num = 1; num < v; num++)
					check[i][num] = 0;
			}
			break;
		}
		//[x, y]가 아닌 수들은 v가 될 수 없다
		for (int i = 1; i <= N; i++) {
			if (i >= x && i <= y)
				continue;
			check[i][v] = 0;
		}
	}
	//graph 정보 입력
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (check[i][j] == 1)
				graph[i].push_back(j);
		}
	}

	//DFS 기반 Maximum Bipartite Matching 알고리즘
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		fill(visited.begin(), visited.end(), false);
		if (DFS(i))
			ans++;
	}

	//수열이 완성되었으면
	if (ans == N) {
		for (int i = 1; i <= N; i++)
			printf("%d ", sequence[i]);
		printf("\n");
	}
	//아니면
	else
		printf("-1\n");
	
	return 0;
}

//DFS 기반 Maximum Bipartite Matching 알고리즘을 위한 DFS 함수
bool DFS(int a) {
	if (visited[a])
		return false;
	visited[a] = true;

	for (int i = 0; i < graph[a].size(); i++) {
		int b = graph[a][i];
		if (Match[b] == -1) {
			Match[b] = a;
			sequence[a] = b;		//수열 정보 업데이트
			return true;
		}
	}

	for (int i = 0; i < graph[a].size(); i++) {
		int b = graph[a][i];
		if (DFS(Match[b])) {
			Match[b] = a;
			sequence[a] = b;		//수열 정보 업데이트
			return true;
		}
	}

	return false;
}
