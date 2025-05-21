#include <stdio.h>
int Pls(double a, double b) { return a + b; }
void main() {
  int a[5][2] = {{0, 1}, {2, 3}, {4, 5}, {6, 7}, {8, 9}};
  int *p[] = {a[0], a[1], a[2], a[3], a[4]};
  int **pp[] = {p + 4, p + 3, p + 2, p + 1, p};
  int ***ppp = pp;
  printf("%d---", ***++ppp);
  printf("---%d---", **pp[2]);
  printf("---%d", **--*++ppp + 1);
  printf("%d\n", (int)12.84);
}