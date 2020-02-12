#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int compare(const void*, const void*);

int main() {
    int N, x, y;
    vector<pair<int, int>> v;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d %d", &x, &y);
        v.push_back(pair<int, int>(x, y));
    }
    qsort(&v[0], N, sizeof(pair<int,int>), compare);
    
    for(int i=0; i<N; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    
    return 0;
}

int compare(const void *a, const void *b) {
    pair<int, int> *p1 = (pair<int, int> *)a;
    pair<int, int> *p2 = (pair<int, int> *)b;
    
    if(p1->second > p2->second)
        return 1;
    if(p1->second < p2->second)
        return -1;
    if(p1->first > p2->first)
        return 1;
    else
        return -1;
}
