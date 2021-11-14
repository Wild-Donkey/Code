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
unsigned a[205][205], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1); j <= m; ++j)
      a[i][j] = RD();
  if ((n % 3) & 1) {
    if ((m % 3) & 1) {
      for (unsigned i(1); i <= n; i += 3)
        for (unsigned j(1); j <= m; j += 3)
          Ans += a[i][j];
    }
    else {
      for (unsigned i(1); i <= n; i += 3)
        for (unsigned j(2); j <= m; j += 3)
          Ans += a[i][j];
    }
  }
  else {
    if ((m % 3) & 1) {
      for (unsigned i(2); i <= n; i += 3)
        for (unsigned j(1); j <= m; j += 3)
          Ans += a[i][j];
    }
    else {
      for (unsigned i(2); i <= n; i += 3)
        for (unsigned j(2); j <= m; j += 3)
          Ans += a[i][j];
    }
  }
  printf("%u\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
3 3
2 3 3
2 3 3
1 1 1
*/