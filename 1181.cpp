#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    string s;
    vector<pair<int, string>> arr;
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        cin >> s;
        arr.push_back(pair<int, string>(s.length(), s));
    }
    
    sort(arr.begin(), arr.end());
    
    for(int i=0; i<N; i++) {
        if(i != 0) {
            if(s == arr[i].second)
                continue;
        }
        s = arr[i].second;
        cout << arr[i].second << '\n';
    }
    
    return 0;
}
