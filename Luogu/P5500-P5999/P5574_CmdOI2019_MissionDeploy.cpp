#include <bits/stdc++.h>
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
unsigned a[25005], f[25005], g[25005], m, n;
unsigned A, B, C, D, t;
unsigned Ans(0);
unsigned DP(long long x) {
  long long TmpDp;
  for (unsigned i(1); i <= n; ++i) {
    TmpDp = f[j] + 


      Calc(j + 1, i) - x;
    if (f[i] < TmpDp)
      f[i] = TmpDp, g[i] = g[j] + 1;
  }
  return g[n];
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  long long L(0), R(312487500), Mid;
  while (L < R) {
    Mid = ((L + R) >> 1);
    DP()
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P5574_CmdOI2019_MissionDeploy.cpp
*/