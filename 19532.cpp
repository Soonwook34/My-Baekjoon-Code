#include <iostream>
using namespace std;

int main() {
   int a, b, c, d, e, f;
   scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

   int X, Y;
   bool isFound = false;
   for (int x = -999; x < 1000; x++) {
      for (int y = -999; y < 1000; y++) {
         int ans1 = a * x + b * y - c;
         int ans2 = d * x + e * y - f;
         if (ans1 == 0 && ans2 == 0) {
            X = x;
            Y = y;
            isFound = true;
            break;
         }
      }
      if (isFound)
         break;
   }
   printf("%d %d\n", X, Y);

   return 0;
}