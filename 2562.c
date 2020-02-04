#include <stdio.h>

int main() {
    int num[9] = {0};
    int index=0, max=0;
    
    for(int i=0; i<9; i++) {
        scanf("%d", &num[i]);
    }
    
    for(int i=0; i<9; i++) {
        if(num[i] > max) {
            index = i+1;
            max = num[i];
        }
    }
    
    printf("%d\n%d\n", max, index);
    
    return 0;
}
