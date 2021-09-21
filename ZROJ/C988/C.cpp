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
long double TmpL, TmpR(1e20);
long long P, Q, G;
unsigned Ans(0);
unsigned A, C, D, t;
unsigned m, n;
struct Pnt {
  long long X, Y, ComA, ComB;
  double B;
  inline const char operator<(const Pnt& x) const { return this->B < x.B; }
}b[1000005];
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
    b[i].X = RD(), b[i].B = b[i].Y = RD(), b[i].B -= (double)(b[i].X * P) / Q;
    b[i].ComB = Q * b[i].Y, b[i].ComA = (Q * b[i].Y) - (b[i].X * P);
  }
  sort(b + 1, b + n + 1);
  for (unsigned i(2); i <= n; ++i) {
    if (b[i].ComB == b[i - 1].ComB) continue;
    TmpL = abs((long double)(b[i].ComA - b[i - 1].ComA) / (b[i].ComB - b[i - 1].ComB));
    if (TmpL < TmpR) Ans = i, TmpR = TmpL;
  }
  P = abs(b[Ans].Y - b[Ans - 1].Y), Q = abs(b[Ans].X - b[Ans - 1].X), G = Gcd(P, Q);
  printf("%llu/%llu\n", P / G, Q / G);
  //  }
  // system("pause");
  return Wild_Donkey;
}