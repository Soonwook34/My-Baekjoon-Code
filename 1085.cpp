#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int x, y, w, h, ans;
    
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    printf("%d\n", min(w-x > x? x : w-x, h-y > y? y : h-y));
    
    return 0;
}
