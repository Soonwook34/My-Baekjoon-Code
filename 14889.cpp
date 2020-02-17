#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int N;
int minimum = INT_MAX;
int stat[20][20];
int startTeam[10]={0, }, linkTeam[10];

void getStat(int);

int main() {
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d", &stat[i][j]);
        }
    }
    
    getStat(0);
    printf("%d\n", minimum);
    
    return 0;
}

void getStat(int step) {
    if(step == N/2) {
        int startStat=0, linkStat=0;
        int cnt=0;
        bool isInStart = false;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N/2; j++) {
            	if(i == startTeam[j]) {
            		isInStart = true;
            		break;
            	}
            }
            if(!isInStart) {
                linkTeam[cnt] = i;
                cnt++;
            }
            isInStart = false;
        }
        
        for(int i=0; i<N/2; i++) {
            for(int j=0; j<N/2; j++) {
                startStat += stat[startTeam[i]][startTeam[j]];
                linkStat += stat[linkTeam[i]][linkTeam[j]];
            }
        }
        if(abs(startStat-linkStat) < minimum)
            minimum = abs(startStat-linkStat);
        return;
    }
    
    for(int i=0; i<N; i++) {
        if(step==0 || i>startTeam[step-1]) {
            startTeam[step] = i;
            getStat(step + 1);
        }
    }
}
