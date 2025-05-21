#include<bits/stdc++.h>
using namespace std;
unsigned RD() {
  unsigned RTm = 0;
  char Rchr = getchar();
  while (Rchr < '0' || Rchr > '9') Rchr = getchar();
  while (Rchr >= '0' && Rchr <= '9') RTm = (RTm * 10) + Rchr - '0', Rchr = getchar();
  return RTm;
}
unsigned long long n, m, V[1000005], W[1000005];
unsigned long long EqD(unsigned long long x, unsigned long long y) {
  if (!y) return 0;
  return (x * 2 + y - 1) * y / 2;
}
unsigned long long SqEqD(unsigned long long x) {
  return (x + 3 * x * x + 2 * x * x * x) / 6;
}
unsigned long long Sq(unsigned long long x, unsigned long long y) {
  if (x > y) swap(x, y);
  if (!x) return 0;
  unsigned long long Ret = x * EqD(x + 1, y - x);
  Ret += 2 * SqEqD(x);
  Ret -= EqD(1, x);
  return Ret;
}
signed main() {
  n = RD(), m = RD();
  for (unsigned i = 0; i < n * m; ++i) W[i] = RD();
  for (unsigned i = 0; i < n; ++i) {
    for (unsigned j = 0, J = i * m; j < m; ++j, ++J) {
      V[J] = EqD(1, n - i - 1) + EqD(1, i) + EqD(1, j) + EqD(1, m - j - 1);
      V[J] += Sq(i, j) + Sq(n - i - 1, j) + Sq(i, m - j - 1) + Sq(n - i - 1, m - j - 1);
      printf("%llu", V[J] * W[J]);
      if (j == m - 1) putchar(0x0A);
      else putchar(' ');
    }
  }
  return 0;
}