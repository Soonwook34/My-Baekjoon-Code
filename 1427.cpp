#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void*, const void*);

int main() {
    int num, cnt=0;
    int arr[10];
    fill_n(arr, 10, 0);
    
    scanf("%d", &num);
    while(num >= 10) {
        arr[cnt++] = num % 10;
        num /= 10;
    }
    arr[cnt] = num % 10;
    
    qsort(arr, cnt+1, sizeof(int), compare);
    
    for(int i=cnt; i>-1; i--) {
        printf("%d", arr[i]);
    }
    
    return 0;
}

int compare(const void *a, const void *b) {
    int *n1 = (int *)a;
    int *n2 = (int *)b;
    
    if(*n1 > *n2)
        return 1;
    if(*n1 < *n2)
        return -1;
    return 0;
}
