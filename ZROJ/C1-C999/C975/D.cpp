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
#define C(x,y) (((((unsigned long long)Fac[x]*Inv[y])%MOD)*(unsigned long long)Inv[(x)-(y)])%MOD)
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
unsigned m, n, n2, Cnt(0);
unsigned long long MOD;
unsigned long long Ans, Tmp, A, B, C, D;
unsigned Fac[20000005], Inv[20000005], g[3005][3005], f[3005][3005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //   Clr();
  n = RD(), MOD = RD(), n2 = n << 1, m = n * n2, Fac[0] = 1;
  for (unsigned long long i(1); i <= m; ++i) Fac[i] = (Fac[i - 1] * i) % MOD;
  Tmp = MOD - 2, Inv[m] = 1, A = Fac[m];
  while (Tmp) { if (Tmp & 1) Inv[m] = (Inv[m] * A) % MOD; A = (A * A) % MOD, Tmp >>= 1; }
  for (unsigned long long i(m - 1); ~i; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % MOD;
  // for (unsigned i(0); i <= m; ++i) printf("%u: %u * %u = %llu\n", i, Fac[i], Inv[i], ((unsigned long long)(Fac[i]) * Inv[i]) % MOD);
  for (unsigned i(0); i <= n; ++i) f[i][0] = g[n][i] = 1;
  for (unsigned i(n - 1); ~i; --i) {
    g[i][i] = g[i + 1][i];//printf("g[%u][%u] = %u\n", i, i, g[i][i]);
    for (unsigned j(i - 1); ~j; --j) {
      g[i][j] = g[i + 1][j] + g[i][j + 1];
      if (g[i][j] >= MOD) g[i][j] -= MOD;
      // printf("g[%u][%u] = %u\n", i, j, g[i][j]);
    }
  }
  // printf("C52 %u", C(5000, 2000));
  for (unsigned i(2), Size(m); i <= n; ++i) {
    Size = m - i;
    for (unsigned j(1); j < i; ++j, Size -= n2) {
      f[i][j] = ((f[i - 1][j] + (((unsigned long long)f[i][j - 1] * g[0][0]) % MOD) * C(Size - j, n2)) % MOD);
      // printf("f[%u][%u] = %u\n", i, j, f[i][j]);
    }
    Tmp = 0, Size += n2 - i + 1;
    for (unsigned j(0); j <= n; ++j) Tmp = (Tmp + ((unsigned long long)g[j][0] * C(Size - j, n2 - j))) % MOD;// printf("C(%u,%u) = %u\n", Size - j, n2 - j, C(Size - j, n2 - j));
    f[i][i - 1] = (f[i][i - 1] + (f[i - 1][i - 2] * Tmp)) % MOD; //printf("f[%u][%u] = %u\n", i, i - 1, f[i][i - 1]);
  }
  printf("%u\n", f[n][n - 1]);
  system("pause");
  return Wild_Donkey;
}
/*
谁帮我算一下 binom{5000}{2000} % 1e9 + 7 (666470189)
300 1000000007
*/