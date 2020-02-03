#include <stdio.h>

int main() {
    int hour, min, alm_hour, alm_min;
    scanf("%d %d", &hour, &min);
    
    alm_hour = hour;
    alm_min = min - 45;
    if(alm_min < 0) {
        alm_min += 60;
        alm_hour -= 1;
        if(alm_hour < 0)
            alm_hour += 24;
    }
    
    printf("%d %d\n", alm_hour, alm_min);
    
    return 0;
}
