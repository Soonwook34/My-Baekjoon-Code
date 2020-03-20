#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    for(int t=0; t<T; t++) {
        vector<pair<string, int>> fashion;
        string name, category;
        int N;
        cin >> N;
        if(N == 0) {
            cout << 0 << '\n';
            continue;
        }
        cin >> name >> category;
        fashion.push_back(pair<string, int>(category, 1));
        for(int n=1; n<N; n++) {
            cin >> name >> category;
            
            bool isAdded = false;
            for(int i=0; i<fashion.size(); i++) {
                if(fashion[i].first.compare(category) == 0) {
                    fashion[i].second++;
                    isAdded = true;
                    break;
                }
            }
            if(isAdded == false)
                fashion.push_back(pair<string, int>(category, 1));
        }
        
        int totalCase = 1;
        for(int i=0; i<fashion.size(); i++) {
            totalCase *= (fashion[i].second + 1);
        }
        cout << totalCase - 1 << '\n';
    }
    
    return 0;
}
