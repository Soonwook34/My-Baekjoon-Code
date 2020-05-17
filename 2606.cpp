#include <iostream>
#include <vector>
using namespace std;

#define MAX 100

vector<int> graph[MAX + 1];
bool visited[MAX + 1] = { false, };
int cnt = 0;

void countDFS(int);

int main() {
	int N, M;
	scanf("%d\n%d", &N, &M);

	for (int i = 0; i < M; i++) {
		int from, to;
		scanf("%d %d", &from, &to);
		//양방향 연결
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	countDFS(1);
	printf("%d\n", cnt - 1);

	return 0;
}

//DFS 출력
void countDFS(int V) {
	cnt++;
	visited[V] = true;
	for (int i = 0; i < graph[V].size(); i++) {
		if (!visited[graph[V][i]])
			countDFS(graph[V][i]);
	}
	return;
}
