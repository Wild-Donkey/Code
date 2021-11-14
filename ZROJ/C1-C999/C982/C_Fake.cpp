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
unsigned f[150][550005], g[550005], m, n, a[150];
unsigned A, B, C, D, t, Hor[150], Ver[150];
unsigned Cnt(0), Ans(0), Tmp(0);
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = (1 << (n - 1)) - 1;
  if (n <= 1) { printf("0\n");return 0; }
  for (unsigned i(1); i < n; ++i)
    for (unsigned j(i + 1); j <= n; ++j)
      if (gcd(i, j) == 1) Hor[++Cnt] = i, Ver[Cnt] = j;
  for (unsigned i(1); i <= Cnt; ++i)
    for (unsigned j(Hor[i] + 1); j <= Ver[i]; ++j)
      a[i] |= (1 << (j - 2));
  f[0][0] = 1;
  for (unsigned i(1); i <= Cnt; ++i) {
    memcpy(g, f[i - 1], sizeof(g));
    for (unsigned j(1); j <= m; j <<= 1)
      for (unsigned k(0); k <= m; ++k)
        if (k & j) { g[k] += g[k ^ j]; if (g[k] >= 1000000000) g[k] -= 1000000000; }
    for (unsigned j(0), k; j <= m; ++j) {
      if ((j & a[i]) == a[i]) {
        k = j ^ a[i], printf("%u %u %u %u %u %u\n", i, j, k, g[k], g[j], f[i - 1][k]);
        f[i][j] += g[j] - g[a[i]];
        while (f[i][j] >= 1000000000) f[i][j] -= 1000000000;
      }
      f[i][j] += f[i - 1][j]; if (f[i][j] >= 1000000000) f[i][j] -= 1000000000;
      printf("f[%u][%u] %u\n", i, j, f[i][j]);
    }
  }
  //  }
  printf("%u\n", f[Cnt][m]);
  system("pause");
  return Wild_Donkey;
}