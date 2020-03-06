#include <iostream>
#include <cstring>
using namespace std;

int N;
int treeIndex = 1;            //왼쪽부터 채워나가는 인덱스
pair<int, int> tree[10001];   //인덱스는 부모 노드, pair의 왼쪽과 오른쪽은 각각 왼쪽 자식과 오른쪽 자식
int minMax[10001][2] = {0, }; //각 레벨 별 최솟값과 최댓값

void findMinMax(int, int);  //깊이우선탐색 중위순회를 통해 minMax를 채우는 함수

int main() {
    scanf("%d", &N);
    
    //minMax의 최솟값 초기화
    for(int i=1; i<=N; i++)
        minMax[i][0] = N+1;
    
    //노드 정보 입력 받기
    int parent, leftChild, rightChild;
    bool rootIndex[N+1];    //rootIndex[n]이 true면 n는 루트 노드 
    memset(rootIndex, true, sizeof(rootIndex));
    for(int i=0; i<N; i++) {
        scanf("%d %d %d", &parent, &leftChild, &rightChild);
        tree[parent].first = leftChild;
        tree[parent].second = rightChild;
        
        if(leftChild != -1)
            rootIndex[leftChild] = false;
        if(rightChild != -1)
            rootIndex[rightChild] = false;
    }
    
    //루트 노드 찾기
    int root;
    for(int i=1; i<=N; i++) {
        if(rootIndex[i]) {
            root = i;
            break;
        }
    }
    
    findMinMax(root, 1);
    
    //너비가 가장 넓은 레벨과 그 레벨의 너비 구하기
    int maxLevel=0, maxWidth=0, temp;
    for(int i=1; i<=N; i++) {
        if(minMax[i][0] == N+1)
            break;
        temp = minMax[i][1] - minMax[i][0] + 1;
        if(temp > maxWidth) {
            maxLevel = i;
            maxWidth = temp;
        }
    }
    
    //답 출력
    printf("%d %d\n", maxLevel, maxWidth);
    
    return 0;
}

void findMinMax(int node, int level) {
    //왼쪽 자식 노드 방문
    if(tree[node].first != -1) {
        findMinMax(tree[node].first, level+1);
    }
    //중위 순회로 방문, 해당 노드의 treeIndex 값이 정해진다
    minMax[level][0] = min(minMax[level][0], treeIndex);
    minMax[level][1] = max(minMax[level][1], treeIndex);
    treeIndex++;
    //오른쪽 자식 노드 방문
    if(tree[node].second != -1) {
        findMinMax(tree[node].second, level+1);
    }
}
