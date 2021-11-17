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
const unsigned long long Mod(9999973);
unsigned long long Ans(0), f[105][105][105], C2[105];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  C2[0] = 0, f[0][0][0] = 1;
  for (unsigned i(1); i <= n; ++i) C2[i] = (i * (i - 1)) >> 1;
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(0); j <= n; ++j) {
      for (unsigned k(0); k + j <= n; ++k) {
        f[i][j][k] = f[i - 1][j][k];
        if(j) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 1][k] * (n - k - j + 1)) % Mod;
        if(k) f[i][j][k] = (f[i][j][k] + f[i - 1][j + 1][k - 1] * (j + 1)) % Mod;
        if(j > 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j - 2][k] * C2[n - k - j + 2]) % Mod;
        if(k > 1) f[i][j][k] = (f[i][j][k] + f[i - 1][j + 2][k - 2] * C2[j + 2]) % Mod;
        if(k) f[i][j][k] = (f[i][j][k] + f[i - 1][j][k - 1] * j * (n - k - j + 1)) % Mod;
//        printf("f %u %u %u = %u\n", i, j, k, f[i][j][k]);
      }
    }
  }
  for (unsigned i(0); i <= n; ++i) for (unsigned j(0); j + i <= n; ++j) Ans += f[m][i][j];
  printf("%llu\n", Ans % Mod);
//  }
  return Wild_Donkey;
}
