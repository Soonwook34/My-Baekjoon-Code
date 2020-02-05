#include <stdio.h>

int main() {
    char s[101] = "\0";
    int cnt = 0;

    scanf("%s", s);

    for(int i=0; i<101; i++) {
        if(s[i] == '\0') {
            return 0;
        }
        if(cnt == 10) {
            cnt = 0;
            putchar('\n');
        }
        putchar(s[i]);
        cnt++;
    }

}
