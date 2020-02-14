#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool compare(pair<int, string>, pair<int, string>);

int main() {
    int N, age;
    string s;
    vector<pair<int, string>> arr;
    scanf("%d", &N);
    
    arr.resize(N);
    
    for(int i=0; i<N; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    
    stable_sort(arr.begin(), arr.end(), compare);
    
    for(int i=0; i<N; i++) {
        printf("%d %s\n", arr[i].first, arr[i].second.c_str());
        //cout << arr[i].first << ' ' << arr[i].second << '\n';
    }
    
    return 0;
}

bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}
