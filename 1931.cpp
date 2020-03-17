#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> time;

bool compare(pair<int, int>, pair<int, int>);

int main() {
    int N;
    scanf("%d", &N);
    
    int start, end;
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start, &end);
        time.push_back(pair<int, int>(start, end));
    }

    sort(time.begin(), time.end(), compare);

    int count = 0, presentTime = 0, minCount = 100000;
    for (int i = 0; i < N; i++) {
        if (time[i].first >= presentTime) {
            presentTime = time[i].second;
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}
