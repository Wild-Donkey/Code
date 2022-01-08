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
double p[2005], f[2005][2], g[2], Ans(1000000000);
unsigned m, n, Cn, Ce;
unsigned Dis[305][305];
unsigned a[2005], b[2005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Cn = RD(), Ce = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = RD();
  for (unsigned i(1); i <= n; ++i) scanf("%lf", p + i);
  memset(Dis, 0x3f, sizeof(Dis));
  for (unsigned i(1); i <= Ce; ++i) {
    A = RD(), B = RD();
    Dis[A][B] = Dis[B][A] = min(Dis[A][B], RD());
  }
  for (unsigned i(1); i <= Cn; ++i) Dis[i][i] = 0;
  for (unsigned i(1); i <= Cn; ++i) for (unsigned j(1); j <= Cn; ++j)
    for (unsigned k(1); k <= Cn; ++k) Dis[j][k] = min(Dis[j][i] + Dis[i][k], Dis[j][k]);
  for (unsigned i(0); i <= m; ++i) f[i][0] = f[i][1] = 1000000000;
  f[0][0] = 0, f[1][1] = 0;
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(min(m, i)); j; --j) {
      // printf("Dis (%u, %u): %u\n", Dis[a[i]][a[i - 1]]);
      g[0] = min(f[j][0] + Dis[a[i]][a[i - 1]],
        f[j][1] + Dis[a[i]][b[i - 1]] * p[i - 1] + Dis[a[i]][a[i - 1]] * (1 - p[i - 1]));
      g[1] = min(f[j - 1][0] + Dis[b[i]][a[i - 1]] * p[i] + Dis[a[i]][a[i - 1]] * (1 - p[i]),
        f[j - 1][1] + Dis[b[i]][b[i - 1]] * p[i] * p[i - 1] + Dis[a[i]][b[i - 1]] * (1 - p[i]) * p[i - 1] +
        Dis[b[i]][a[i - 1]] * p[i] * (1 - p[i - 1]) + Dis[a[i]][a[i - 1]] * (1 - p[i]) * (1 - p[i - 1]));
      f[j][0] = g[0], f[j][1] = g[1];
    }
    f[0][0] = f[0][0] + Dis[a[i]][a[i - 1]];
  }
  for (unsigned i(0); i <= m; ++i) {
    Ans = min(Ans, min(f[i][0], f[i][1]));
  }
  printf("%.2lf", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}