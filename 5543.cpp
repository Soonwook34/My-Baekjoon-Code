#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int burger = 10000, drink = 10000;

    for (int i = 0; i < 3; i++) {
        int price;
        scanf("%d", &price);
        burger = min(burger, price);
    }
    for (int i = 0; i < 2; i++) {
        int price;
        scanf("%d", &price);
        drink = min(drink, price);
    }

    printf("%d\n", burger + drink - 50);

    return 0;
}
