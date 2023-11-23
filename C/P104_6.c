#include <stdio.h>
int a[10], n, Rank;
void main() {
  scanf("%d%d", &n, &Rank);
  for (unsigned i = 0; i < n; ++i) scanf("%d", a + i);
  if (Rank)
    for (unsigned i = 0; i < n; ++i) a[i] = -a[i];
  for (unsigned i = 0; i < n; ++i)
    for (unsigned j = i; j < n; ++j)
      if (a[i] > a[j]) a[i] ^= a[j], a[j] ^= a[i], a[i] ^= a[j];
  if (Rank)
    for (unsigned i = 0; i < n; ++i) a[i] = -a[i];
  for (unsigned i = 0; i < n; ++i) printf("%d ", a[i]);
}