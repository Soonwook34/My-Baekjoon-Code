#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//MST 계산에 활용할 노드
struct island {
	int height;
	struct island* parent;
};
typedef struct island island;

int N, M, maxWeight;
bool isVisited[100001] = { false, };				//각 섬의 방문 여부
priority_queue<pair<int, pair<int, int>>> bridge;	//각 다리의 중량제한 내림차순으로 정렬될 다리 정보(중량제한, (섬1, 섬2))
vector<island*> set;								//MST 계산을 위한 집합

vector<pair<int, int>> map[100001];					//섬 i와 연결되는 다리의 (목적지, 중량제한)의 집합 map[i]

void makeMST();						//Kruskal 알고리즘을 활용한 MST 구해 map에 저장하는 함수
void createSet(island*);			//초기 집합을 초기화 하는 함수
island* findSet(island*);			//x의 최상위 노드를 찾는 findSet(x)
void unionSet(island*, island*);	//두 집합을 합치는 함수

int findMaxWeight2(int, int);		//X부터 Y까지 최대중량제한을 찾는 함수 findMaxWeight(X, Y)

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		isVisited[A] = isVisited[B] = true;			//연결 여부 체크
		bridge.push(make_pair(C, make_pair(A, B)));
	}
	//MST 계산
	makeMST();

	int X, Y;
	scanf("%d %d", &X, &Y);

	memset(isVisited, false, sizeof(isVisited));
	printf("%d\n", findMaxWeight2(X, Y));

	return 0;
}

void makeMST() {
	int connected = 0;	//연결될 노드의 수
	set.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		set[i] = (island*)malloc(sizeof(island));
		createSet(set[i]);
		if (isVisited[i])
			connected++;
	}
	maxWeight = bridge.top().first;
	int num = 0;
	//최소 다리의 개수만큼 연결하여 MST 완성하기(Kruskal 알고리즘)
	while (num < connected - 1) {
		pair<int, int> b = bridge.top().second;
		island* p = findSet(set[b.first]);
		island* q = findSet(set[b.second]);
		//p와 q의 최상위 노드가 다르면 다리를 추가
		if (p != q) {
			unionSet(p, q);
			num++;
			map[b.first].push_back(make_pair(b.second, bridge.top().first));
			map[b.second].push_back(make_pair(b.first, bridge.top().first));
		}
		bridge.pop();
	}

}

void createSet(island* x) {
	x->height = 0;
	x->parent = x;
}

island* findSet(island* x) {
	while (x != x->parent)
		x = x->parent;
	return x;
}

void unionSet(island* a, island* b) {
	if (a->height <= b->height) {
		if (a->height == b->height)
			b->height++;
		a->parent = b;
	}
	else
		b->parent = a;
}

int findMaxWeight2(int start, int end) {
	//DFS 이용
	queue<pair<int, int>> q;	//(현재 위치, 현재까지의 중량제한)
	q.push(make_pair(start, maxWeight));
	isVisited[start] = true;

	while (q.empty() != true) {
		int island = q.front().first;
		int weight = q.front().second;
		q.pop();
		//도착했으면 중량제한 값 리턴
		if (island == end)
			return weight;
		//연결된 섬 방문
		for (int i = 0; i < map[island].size(); i++) {
			int nextIsland = map[island][i].first;
			int nextWeight = map[island][i].second;
			if (isVisited[nextIsland] == false) {
				isVisited[nextIsland] = true;
				//중량제한에 유의하여 push
				q.push(make_pair(nextIsland, min(weight, nextWeight)));
			}
		}
	}

	return 0;
}
