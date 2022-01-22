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
double Plk(0.000001), Le(0), Ri(100), Ans(0), a[200005], Sum[200005], f[200005];
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
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  while (Le + Plk <= Ri) {
    Ans = (Le + Ri) / 2, f[0] = 0;
//    printf("[%lf, %lf], %lf\n", Le, Ri, Ans);
    for (unsigned i(1); i <= n; ++i) f[i] = 1000000000;
    for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + a[i] - Ans;
    for (unsigned i(1); i < n; ++i) {
      unsigned Pos(upper_bound(f, f + n + 1, Sum[i]) - f);
      if(Pos) f[Pos] = min(f[Pos], Sum[i]);
    }
    if((upper_bound(f, f + n + 1, Sum[n]) - f) < m) Ri = Ans;
    else Le = Ans;
//    for (unsigned i(1); i <= n; ++i) printf("%lf ", Sum[i]);
//    putchar(0x0A);
//    for (unsigned i(1); i <= n; ++i) printf("%lf ", f[i]);
//    putchar(0x0A);
  }
  printf("%lf\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

