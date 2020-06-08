#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct computer {
	int height;
	struct computer* parent;
};
typedef struct computer computer;

int N, M;
priority_queue<pair<int, pair<int, int>>> network;
vector<computer*> set;

int makeMST();
void createSet(computer*);
computer* findSet(computer*);
void unionSet(computer*, computer*);

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		network.push(make_pair(-C, make_pair(A, B)));
	}

	printf("%d\n", makeMST());
}

//MST
int makeMST() {
	set.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		set[i] = (computer*)malloc(sizeof(computer));
		createSet(set[i]);
	}
	int num = 0;
	int ret = 0;
	while (num < N - 1) {
		int cost = -network.top().first;
		pair<int, int> n = network.top().second;
		network.pop();

		computer* p = findSet(set[n.first]);
		computer* q = findSet(set[n.second]);
		if (p != q) {
			unionSet(p, q);
			num++;
			ret += cost;
		}
	}

	return ret;
}

void createSet(computer* x) {
	x->height = 0;
	x->parent = x;
}

computer* findSet(computer* x) {
	while (x != x->parent)
		x = x->parent;
	return x;
}

void unionSet(computer* a, computer* b) {
	if (a->height <= b->height) {
		if (a->height == b->height)
			b->height++;
		a->parent = b;
	}
	else
		b->parent = a;
}
