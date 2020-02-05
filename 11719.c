#include <stdio.h>

int main() {
    char s[101];

    s[0] = '\0';
    while(fgets(s, 100, stdin)) {
        printf("%s", s);
        s[0] = '\0';
    }

    return 0;
}
