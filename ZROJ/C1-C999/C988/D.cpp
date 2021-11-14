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
#define C(x,y) (((Fac[x]*Inv[(x)-(y)]%MOD)*Inv[y])%MOD)
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
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
const unsigned long long MOD(1000000007);
unsigned long long Fac[400], Inv[400], PowerTmp;
unsigned long long f[355][355][2];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(1000000005);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Fac[0] = Inv[n] = 1;
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % MOD;
  PowerTmp = Fac[n]; while (Tmp) { if (Tmp & 1) Inv[n] = Inv[n] * PowerTmp % MOD; Tmp >>= 1, PowerTmp = PowerTmp * PowerTmp % MOD; }
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % MOD;
  // for (unsigned i(1); i <= n; ++i) printf("FI%u = %llu %llu\n", i, Fac[i], Inv[i]);
  f[0][0][0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j <= n;++j) {
      for (unsigned k(0); k <= j; ++k) {
        if (k ^ i) f[i][j][0] = (f[i][j][0] + (f[i - 1][j - k][0] * C(j, k))) % MOD;
        f[i][j][1] = (f[i][j][1] + (f[i - 1][j - k][1] * C(j, k))) % MOD;
      }
      if (j >= i) f[i][j][1] = (f[i][j][1] + (f[i - 1][j - i][0] * C(j, i))) % MOD;
      printf("f[%u][%u] %llu %llu\n", i, j, f[i][j][0], f[i][j][1]);
    }
  }
  printf("%llu\n", f[n][n][1]);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
0 0 123
0 123 0
123 0 0

0 1 23
0 2 13
0 3 12

0 12 3
0 13 2
0 23 1

1 23 0
2 13 0
3 12 0

1 23 0
2 13 0
3 12 0

1 0 23
2 0 13
3 0 12

23 0 1
13 0 2
12 0 3

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
```
0 0 123

0 12 3
0 13 2
0 23 1

1 23 0
2 13 0
3 12 0

1 23 0
2 13 0
3 12 0

1 0 23
2 0 13
3 0 12

1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/