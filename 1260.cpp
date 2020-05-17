#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 1000

vector<int> graph[MAX + 1];
bool visited[MAX + 1] = { false, };

void printDFS(int);
void printBFS(int);

int main() {
	int N, M, V;
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		//양방향 연결
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	//연결되어있는 정점 오름차순 정렬
	for (int i = 0; i < N; i++)
		sort(graph[i].begin(), graph[i].end());

	printDFS(V);
	printf("\n");
	memset(visited, false, sizeof(visited));	//visited 초기화
	printBFS(V);

	return 0;
}

//DFS 출력
void printDFS(int V) {
	printf("%d ", V);
	visited[V] = true;
	for (int i = 0; i < graph[V].size(); i++) {
		if (!visited[graph[V][i]])
			printDFS(graph[V][i]);
	}
	return;
}

//BFS 출력
void printBFS(int V) {
	queue<int> q;
	q.push(V);
	visited[V] = true;

	while (!q.empty()) {
		V = q.front();
		q.pop();
		printf("%d ", V);
		for (int i = 0; i < graph[V].size(); i++) {
			if (!visited[graph[V][i]]) {
				visited[graph[V][i]] = true;
				q.push(graph[V][i]);
			}
		}
	}
	printf("\n");
	return;
}
