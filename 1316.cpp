#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cin >> n;
    int isGroup=1, cnt=0;
    
    for(int i=0; i<n; i++) {
        int count[26] = {0};
        char s[100];
        cin >> s;
        count[s[0]-97]++;
        for(int j=1, m=strlen(s); j<m; j++) {
            if(s[j] != s[j-1] && count[s[j]-97] != 0) {
                isGroup = 0;
                break;
            }
            else
                count[s[j]-97]++;
        }
        if(isGroup != 0)
            cnt++;
        isGroup = 1;
    }
    
    cout << cnt << endl;
    
    return 0;
}
