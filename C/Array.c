#include <stdio.h>
void Test(unsigned a[]) { return; }
void main() {
  unsigned *x;
  Test(x);
}