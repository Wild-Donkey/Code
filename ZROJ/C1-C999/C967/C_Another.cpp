#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned f[105][105], Sum[105], MOD, m, n, JM(0), Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), MOD = RD(), m = n * (n - 1), JM = (n - 1) << 1;
  memset(f, 0, sizeof(f));
}
unsigned Limit(unsigned x) {
  register unsigned TmpLim(0);
  TmpLim += x * (x - 1);
  TmpLim += x * (n - x);
  TmpLim += ((n - x) * (n - x - 1)) >> 1;
  return TmpLim;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr(), f[0][1] = 1;
    for (register unsigned i(1); i <= m; ++i) {
      Ans = 0;
      for (register unsigned j(min(i, n)); j; --j) {
        Sum[0] = 0;
        for (register unsigned k(1); k <= n; ++k) { Sum[k] = Sum[k - 1] + f[j - 1][k]; if (Sum[k] >= MOD) Sum[k] -= MOD; }
        for (register unsigned k(j + 1); (k + j <= i + 1) && (k + j <= JM + 1) && (k <= n); ++k) {
          if (i <= Limit(k)) {
            // printf("Before %u\n", f[j][k]);
            f[j][k] += Sum[k - 1];
            if (f[j][k] >= MOD) f[j][k] -= MOD;
            Ans += f[j][k];
            if (Ans >= MOD) Ans -= MOD;
            // printf("%u %u %u Ans %u\n", i, j, k, f[j][k]);
          }
          else f[j][k] = 0;
        }
      }
      if (i <= Limit(1)) {
        Ans += f[0][1];
        if (Ans >= MOD) Ans -= MOD;
      }
      else f[0][1] = 0;
      printf("%u ", Ans);
    }
    putchar('\n');
  }
  system("pause");
  return Wild_Donkey;
}
/*
2
5 1000000007
3 1000000007
*/