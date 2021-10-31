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
const unsigned long long Mod(998244353);
unsigned long long f[505][505], C[505][505], Pow[505][505];
unsigned A, B, D, t, m, n;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
} 
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(0); i <= n; ++i) C[i][0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= Mod) C[i][j] -= Mod;
//      printf("Bi %u %u = %llu\n", i, j, C[i][j]);
    }
  }
  for (unsigned i(1); i <= m; ++i) {
    Pow[i][0] = 1;
    for (unsigned j(1); j <= n; ++j)
      Pow[i][j] = Pow[i][j - 1] * i % Mod;
  }
  for (unsigned i(1); i <= m; ++i) f[1][i] = i;
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j) {
      if(i > j) continue;
      for (unsigned k(1); k <= i; ++k) {
        f[i][j] = (f[i][j] + (f[k][j - i + 1] * Pow[i - 1][i - k] % Mod) * C[i][k]) % Mod;
      }
    }
  }
  printf("%llu\n", (Pow[m][n] + Mod - f[n][m]) % Mod);
  //  system("pause");
  return Wild_Donkey;
}

