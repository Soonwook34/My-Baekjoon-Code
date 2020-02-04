#include <stdio.h>
#include <string.h>

int main() {
    char s[1000000] = "";
    int cnt=0;
    while(scanf("%s", s) != EOF) {
        cnt++;
    }
    
    printf("%d\n", cnt);
    return 0;
}
