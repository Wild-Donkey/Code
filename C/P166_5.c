#include <stdio.h>
int n;
void Plus(float *x, unsigned y) { *x += 1.0 / y; }
void main() {
  scanf("%d", &n);
  float Ans = 0;
  while (n > 0) Plus(&Ans, n), n -= 2;
  printf("%f\n", Ans);
}
/*
gcc P166_5.c -o P166_5.exe && P166_5.exe

100
99
*/