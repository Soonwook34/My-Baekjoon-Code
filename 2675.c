#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int repeat;
    for(int i=0; i<n; i++) {
        char s[20] = "";
        scanf("%d %s", &repeat, s);
        for(int j=0; j<strlen(s); j++) {
            for(int k=0; k<repeat; k++) {
                printf("%c", s[j]);
            }
        }
        printf("\n");
    }
}
