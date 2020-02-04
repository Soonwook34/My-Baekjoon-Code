#include <stdio.h>
#include <string.h>

int main() {
    int num, cnt=1, score=0;
    scanf("%d", &num);
    
    for(int i=0; i<num; i++) {
        char ox[80] = "";
        scanf("%s", ox);
        for(int j=0; j<strlen(ox); j++) {
            if(ox[j] == 'O') {
                score += cnt;
                cnt++;
            }
            else 
                cnt = 1;
        }
        printf("%d\n", score);
        score = 0;
        cnt = 1;
    }
}
