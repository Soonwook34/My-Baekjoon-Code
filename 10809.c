#include <stdio.h>
#include <string.h>

int main() {
    char s[100] = "";
    int first[26] = {0};
    for(int i=0; i<26; i++) {
        first[i] = -1;
    }
    scanf("%s", s);
    
    for(int i=0; i<strlen(s); i++) {
        if(first[*(s+i)-97] == -1)
            first[*(s+i)-97] = i;
    }
    
    for(int i=0; i<26; i++) {
        printf("%d ", first[i]);
    }
    
    return 0;
}
