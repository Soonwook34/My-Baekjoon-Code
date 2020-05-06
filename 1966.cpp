#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int T, N, M;
	scanf("%d", &T);
	
	int x;
	for (int t = 0; t < T; t++) {
		scanf("%d %d", &N, &M);

		queue<pair<int, int>> doc;	//(중요도, 인덱스)
		vector<int> pdoc(N);		//중요도 순으로 정렬될 배열
		for (int i = 0; i < N; i++) {
			scanf("%d", &x);
			doc.push(pair<int, int>(x, i));
			pdoc[i] = x;
		}
		//중요도순 정렬
		sort(pdoc.begin(), pdoc.end());

		int i;
		for (i = 0; i < N; i++) {
			//중요도가 가장 높은 문서를 찾을때까지 순환
			while (doc.front().first != pdoc[N - i - 1]) {
				doc.push(doc.front());
				doc.pop();
			}
			//M번째 문서이면 break
			if (doc.front().second == M)
				break;
			//아니면 pass
			doc.pop();
		}
		//답 출력
		printf("%d\n", i + 1);
	}

	return 0;
}
