#include <stdio.h>
int i, n, m, a[10005];
void main() {
  scanf("%d%d\n", &n, &m);
  for (i = 1; i <= n; ++i) scanf("%d", a + i + m - ((i + m > n) ? n : 0));
  for (i = 1; i <= n; ++i) printf("%d ", a[i]);
  putchar(0x0A);
}
/*
gcc P166_2.c -o P166_2.exe && P166_2.exe

10 4
1 2 3 4 5 6 7 8 9 10
*/