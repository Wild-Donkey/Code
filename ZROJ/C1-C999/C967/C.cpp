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
unsigned MOD;
unsigned f[105][105], a[10005], Sum[105][105], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), MOD = RD(), m = n * (n - 1);
  memset(f, 0, sizeof(f));
}
unsigned Count(unsigned x, unsigned y) {
  register unsigned Ret(0);
  y = n - y + 1;
  Ret += y * (y - 1);
  Ret += y * (x - 1);
  Ret += (((x - 1) * (x - 2)) >> 1);
  return Ret;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    f[1][n] = 1;
    for (register unsigned i(1); i <= m; ++i) {
      Ans = 0;
      for (register unsigned k(0); k < n; ++k) {
        Sum[k][n] = f[n - k][n];
        for (register unsigned j(n - 1); (j >= k) && (j < 0x3f3f3f3f); --j) {
          Sum[k][j] = Sum[k][j + 1] + f[j - k][j];
          if (Sum[k][j] >= MOD) Sum[k][j] -= MOD;
        }
      }
      for (register unsigned k(n); k; --k) {
        for (register unsigned j(k); j; --j) {
          if (i <= Count(j, k)) { if (j ^ k) f[j][k] = 0; }
          else f[j][k] = 0;
          f[j][k] += f[j - 1][k];
          if (f[j][k] >= MOD) f[j][k] -= MOD;
          f[j][k] += Sum[k - j][k + 1];
          if (f[j][k] >= MOD) f[j][k] -= MOD;
          Ans += f[j][k];
          if (Ans >= MOD) Ans -= MOD;
        }
      }
      printf("%u ", Ans);
    }
    putchar('\n');
  }
  // system("pause");
  return Wild_Donkey;
}