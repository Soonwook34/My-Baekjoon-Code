#include <iostream>
using namespace std;

int main() {
    int N, order[200]={0}, cnt=0;
    pair<int, int> info[200];
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d %d", &info[i].first, &info[i].second);
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(info[i].first < info[j].first && info[i].second < info[j].second)
                cnt++;
        }
        order[i] = cnt+1;
        cnt = 0;
    }
    
    for(int i=0; i<N; i++) {
        printf("%d ", order[i]);
    }
    
    return 0;
}
