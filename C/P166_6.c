#include <stdio.h>
int a[10005], *b[10005];
unsigned n;
void SWAP(int **x, int **y) {
  *x = (int *)((unsigned long long)(*x) ^ (unsigned long long)(*y));
  *y = (int *)((unsigned long long)(*y) ^ (unsigned long long)(*x));
  *x = (int *)((unsigned long long)(*x) ^ (unsigned long long)(*y));
}
void Sort(int **x, unsigned len) {
  unsigned i, j;
  for (i = len - 1; ~i; --i)
    for (j = 0; j < i; ++j)
      if (*x[j] > *x[j + 1]) SWAP(x + j, x + j + 1);
}
void main() {
  scanf("%u", &n);
  int i;
  for (i = 0; i < n; ++i) scanf("%d", a + i);
  for (i = 0; i < n; ++i) b[i] = a + i;
  Sort(b, n);
  for (i = 0; i < n; ++i) printf("%d ", *b[i]);
  putchar(0x0A);
}
/*
gcc P166_6.c -o P166_6.exe && P166_6.exe

10
8 76 76 5 6 8 7 5 4 8
*/