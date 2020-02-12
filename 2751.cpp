#include <iostream>
#include <cstdlib>

int compare(const void*, const void*);

int main() {
    int N, temp;
    int num[1000000] = {0};
    scanf("%d", &N);
    
    for(int i=0; i<N; i++) {
        scanf("%d", num+i);
    }
    
    qsort(num, N, sizeof(int), compare);
    
    for(int i=0; i<N; i++) {
        printf("%d\n", num[i]);
    }
    
    return 0;
}

int compare(const void* a, const void* b) {
	const int* x = (int*) a;
	const int* y = (int*) b;
    
	if (*x > *y)
		return 1;
	else if (*x < *y)
		return -1;
    
	return 0;
}
