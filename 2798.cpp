#include <iostream>
using namespace std;

int main() {
    int N, M, best=-1, test;
    int card[100] = {0};
    scanf("%d %d", &N, &M);
    
    for(int i=0; i<N; i++) {
        scanf("%d", card + i);
    }
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            if(j != i)
                for(int k=0; k<N; k++)
                    if(k!=i && k!=j) {
                        test = card[i] + card[j] + card[k];
                        if(test <= M && test > best)
                            best = test;
                    }
    
    printf("%d\n", best);
    
    return 0;
}
