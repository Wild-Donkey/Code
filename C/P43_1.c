#include <stdio.h>
void main() {
  int a = 1, b = 1;
  a += b += 1;
  {
    int a = 10, b = 10;
    a += b += 10;
    printf("b = %d\t", b);
  }
  a *= a *= b * 10;
  printf("a = %2d\n", a);
}