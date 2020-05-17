#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000

int V, K, groupCnt = 0;
vector<vector<int>> graph;				//graph[A]는 A가 가면 갈 수 있는 사람들의 모임
vector<vector<int>> rGraph;				//rGraph[A]는 A가 가려면 가야하는 사람들의 모임
bool visited[MAX + 1] = { false, };
stack<int> fTime;						//DFS를 수행할 때 해당 노드의 방문이 종료되는 시점 순으로 push
vector<vector<int>> groupList;			//MT를 가기 위한 그룹과 그 그룹에 속한 사람들의 모임
vector<pair<int, int>> groupRange;		//각 그룹에서 갈 수 있는 최소 인원과 최대 인원
int knapsack[MAX + 1][MAX + 1];			//i번째 그룹까지 고려했을 때 정원이 j인 버스에 탈 수 있는 최대 인원 knapsack[i][j]

void DFS(int);				//DFS를 통해 fTime을 채우는 함수
void findGroup(int);		//그룹을 만들어 groupList에 저장하는 함수
int findMinCnt(int);		//각 그룹에서 갈 수 있는 최소 인원을 구하는 함수
int getKnapsack(int, int);	//0-1 knapsack을 구하는 함수

int main() {
	scanf("%d %d", &V, &K);
	graph.resize(V + 1);
	rGraph.resize(V + 1);
	
	//입력
	for (int A = 1; A <= V; A++) {
		int B;
		scanf("%d", &B);

		graph[B].push_back(A);
		rGraph[A].push_back(B);
	}

	//DFS 수행
	for (int v = 1; v <= V; v++) {
		if (!visited[v])
			DFS(v);
	}

	//그룹 찾기(fTime 순)
	groupList.resize(V);
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < V; i++) {
		int v = fTime.top();
		fTime.pop();
		if (!visited[v]) {
			findGroup(v);
			groupCnt++;
		}
	}
	groupList.resize(groupCnt);

	//각 그룹의 인원 범위 구하기
	for (int i = 0; i < groupCnt; i++) {
		memset(visited, false, sizeof(visited));
		int minV = findMinCnt(groupList[i][0]);	//그룹의 첫번째 노드의 findMinCnt() 값이 최소
		int maxV = groupList[i].size();			//그룹의 전체 명수가 최대
		groupRange.push_back(make_pair(minV, maxV));
	}

	//버스에 태울 수 있는 최대 인원 구하기
	memset(knapsack, -1, sizeof(knapsack));
	printf("%d\n", getKnapsack(groupCnt, K));

	return 0;
}

//graph에 대한 DFS를 통해 fTime을 채우는 함수
void DFS(int v) {
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]])
			DFS(graph[v][i]);
	}
	//노드의 탐색 종료 시점에 fTime에 push
	fTime.push(v);
}

//fTime 순으로 graph에 대한 DFS를 통해 그룹을 만들어 groupList에 저장하는 함수
void findGroup(int v) {
	visited[v] = true;
	groupList[groupCnt].push_back(v);

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]])
			findGroup(graph[v][i]);
	}
}

//rGraph에 대한 DFS를 통해 각 그룹에서 갈 수 있는 최소 인원을 구하는 함수
int findMinCnt(int v) {
	visited[v] = true;
	int cnt = 1;

	for (int i = 0; i < rGraph[v].size(); i++) {
		if (!visited[rGraph[v][i]])
			cnt += findMinCnt(rGraph[v][i]);
	}

	return cnt;
}

//0-1 knapsack 알고리즘을 이용하여 knapsack[groupNum][k]를 구하는 함수
int getKnapsack(int groupNum, int k) {
	if (groupNum == 0)
		return 0;

	//이미 저장되어 있는 정보라면 리턴
	if (knapsack[groupNum][k] != -1)
		return knapsack[groupNum][k];

	//이전 그룹까지 정보 가져오기
	knapsack[groupNum][k] = getKnapsack(groupNum - 1, k);

	if (k >= groupRange[groupNum - 1].first) {
		//그룹의 최소 인원부터 최대 인원까지 고려
		for (int i = groupRange[groupNum - 1].first; i <= groupRange[groupNum - 1].second; i++) {
			//최대값이 범위를 넘어가면 stop
			if (i > k)
				break;
			//P[n][W] = max(P[n-1][W], P[n-1][W-wi] + wi)
			knapsack[groupNum][k] = max(knapsack[groupNum][k], getKnapsack(groupNum - 1, k - i) + i);
		}
	}

	return knapsack[groupNum][k];
}
