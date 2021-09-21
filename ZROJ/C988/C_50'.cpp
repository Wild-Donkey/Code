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
long long a[10005][2], Prt[10005][2], P, Q, G;
unsigned Ans1(0), Ans2(0);
unsigned A, B, C, D, t;
unsigned m, n;
long double TmpL, TmpR(1e20);
long long Gcd(long long x, long long y) {
  long long TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return x;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), P = RD(), Q = RD();
  for (unsigned i(1); i <= n; ++i) {
    Prt[i][0] = RD(), Prt[i][1] = RD();
    a[i][1] = Q * Prt[i][0], a[i][0] = (Q * Prt[i][1]) - (Prt[i][0] * P);
    for (unsigned j(1); j < i; ++j) {
      if (a[i][1] == a[j][1]) continue;
      TmpL = abs((long double)(a[i][0] - a[j][0]) / (a[i][1] - a[j][1]));
      if (TmpL < TmpR) Ans1 = i, Ans2 = j, TmpR = TmpL;
    }
  }
  P = abs(Prt[Ans1][1] - Prt[Ans2][1]), Q = abs(Prt[Ans1][0] - Prt[Ans2][0]), G = Gcd(P, Q);
  printf("%llu/%llu\n", P / G, Q / G);
  //  }
  // system("pause");
  return Wild_Donkey;
}