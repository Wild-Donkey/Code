#include <stdio.h>
int Max(int x, int y) { return (x > y) ? x : y; }
int Min(int x, int y) { return (x < y) ? x : y; }
void main() {
  int (*Fun[3])(int, int) = {NULL, &Max, &Min}, n, m, Op;
  scanf("%d%d%d", &n, &m, &Op);
  printf("%d\n", Fun[Op](n, m));
}
/*
gcc P166_7.c -o P166_7.exe && P166_7.exe

114 514 1
114 514 2
*/