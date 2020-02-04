#include <stdio.h>
#include <string.h>

int main() {
    char s[1000000];
    scanf("%s", s);
    
    int total[26];
    
    for(int i=0, n = strlen(s); i<n; i++) {
    	if(s[i] >= 'a' && s[i] <= 'z')
    		total[s[i]-97]++;
    	else
        	total[s[i]-65]++;
    }
    int max=0, index=-1;
    for(int i=0; i<26; i++) {
        if(total[i] > max) {
            max = total[i];
            index = i;
        }
    }
    for(int i=0; i<26; i++) {
        if(total[i] == max && index != i) {
            printf("?\n");
            return 0;
        }
    }
    printf("%c\n", index + 65);
    
    return 0;
}
