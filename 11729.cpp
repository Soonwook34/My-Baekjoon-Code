#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> order;

void makeHanoi(int, int, int, int);

int main() {
    int n;
    scanf("%d", &n);
    
    makeHanoi(n, 1, 2, 3);
    
    printf("%d\n", order.size());
    for(int i=0; i<order.size(); i++)
        printf("%d %d\n", order[i].first, order[i].second);
    
    return 0;
}

void makeHanoi(int n, int from, int via, int to) {
    if(n == 1) {
        order.push_back({from, to});
        return;
    }
    else {
        makeHanoi(n-1, from, to, via);
        order.push_back({from, to});
        makeHanoi(n-1, via, from, to);
    }
}
