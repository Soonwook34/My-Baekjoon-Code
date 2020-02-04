#include <stdio.h>
#include <stdlib.h>

int main() {
    int c, n, i, j;
    int total=0, over=0;
    int *score = NULL;
    float avg=0.0;
    
    scanf("%d", &c);
    
    for(i=0; i<c; i++) {
        scanf("%d", &n);
        score = (int *)calloc(n, sizeof(int));
        for(j=0; j<n; j++) {
            scanf("%d", score + j);
            total += *(score + j);
        }
        avg = (float)total/n;
        for(j=0; j<n; j++) {
            if(score[j] > avg)
                over++;
        }
        printf("%.3f%%\n", (float)over/n*100);
        total = over = 0;
        free(score);
    }
    
    return 0;
}
