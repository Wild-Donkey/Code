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
unsigned a[4005][4005], f[4005][4005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = (n * n) >> 2;
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(i + 1); j <= n; j += 2)
      a[i][j] = RD();
  for (unsigned Len(2); Len <= n; Len += 2)
    for (unsigned i(n - Len + 1); i; --i) {
      f[Len][i] = max(f[Len - 2][i + 1], a[i][i + Len - 1]);
      for (unsigned j(2); j < Len; j += 2)
        f[Len][i] = min(f[Len][i], max(f[j][i], f[Len - j][i + j]));
    }
  printf("%u\n", f[n][1]);
  //  }
  // system("pause");
  return Wild_Donkey;
}