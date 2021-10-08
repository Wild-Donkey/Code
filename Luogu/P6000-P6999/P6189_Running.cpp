#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned n, f[100005], g[330][100005], Sq, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), p;
inline void Clr() {}
int main() {
  n = RD(), p = RD(), Sq = sqrt(n) + 1;
  f[0] = 1;
  for (register unsigned j(1); j <= Sq; ++j) {
    for (register unsigned i(j); i <= n; ++i) {
      f[i] += f[i - j];
      if(f[i] >= p) f[i] -= p;
    }
  }
  g[0][0] = 1;
  for (register unsigned i(1); i <= Sq; ++i) {
    for (register unsigned j(i); j <= n; ++j) {
      g[i][j] = g[i - 1][j - 1] + g[i][j - i];
      if(g[i][j] >= p) g[i][j] -= p;
    }
  }
  for (register unsigned i(0); i * (Sq + 1) <= n; ++i) {
    for (register unsigned j(i * (Sq + 1)); j <= n; ++j) {
      Ans = ((unsigned long long)g[i][j - Sq * i] * f[n - j] + Ans) % p;
    }
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
