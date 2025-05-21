#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#define Wild_Donkey 0
#define foreplay for
#define wild while
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline unsigned long long RDll() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long a[1000005], c[1000005];
unsigned b[1000005], d[1000005], *D[1000005];
unsigned n, m, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD();
  unsigned J(0), K(0);
  for (unsigned i(1); i <= n; ++i) {
    b[i] = RD();
    for (unsigned j(0); j < b[i]; ++j, ++J) a[J] = RDll();
  }
  memcpy(c + 1, a, J << 3);
  sort(c + 1, c + J + 1);
  J = unique(c + 1, c + J + 1) - c - 1;
  D[1] = d;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < b[i]; ++j, ++K)
      D[i][j] = lower_bound(c + 1, c + J + 1, a[K]) - c;
    sort(D[i], D[i] + b[i]);
    D[i + 1] = D[i] + b[i];
  }
}
unsigned Judge(unsigned x, unsigned *f, unsigned Len) {
  return upper_bound(f, f + Len, x) - f;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= m; ++i) {
      unsigned Fs, Sc, Lf, Ls, M;
      unsigned *Af, *As;
      Lf = b[Fs = RD()], Ls = b[Sc = RD()];
      Af = D[Fs], As = D[Sc], M = (Lf + Ls + 1) >> 1;
      unsigned L(min(Af[0], As[0])), R(max(Af[Lf - 1], As[Ls - 1])), Mid;
      while (L < R) {
        Mid = (L + R) >> 1;
        if (Judge(Mid, Af, Lf) + Judge(Mid, As, Ls) >= M)
          R = Mid;
        else
          L = Mid + 1;
      }
      printf("%llu\n", c[L]);
    }
  }
  //  system("pause");
  return Wild_Donkey;
}