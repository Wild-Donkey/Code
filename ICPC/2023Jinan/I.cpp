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
#define foreplay for
#define wild while
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
unsigned a[105], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Stk[105][2];
inline void Clr() { n = RD(), Ans = 0; }
void Calc(unsigned x, unsigned y) {
  // printf("[%u, %u]\n", x, y);
  if (x >= y || y > 0x3f3f3f3f) return;
  unsigned Mn(n + 1), Mx(0);
  for (unsigned i(x); i <= y; ++i) {
    if (a[i] < a[Mn]) Mn = i;
    if (a[i] > a[Mx]) Mx = i;
  }
  unsigned Curx(x), Cury(y);
  if (Mn == x) {
    ++Curx;
    while (a[Curx] == a[Curx - 1] + 1) ++Curx;
  }
  if (Mx == y) {
    --Cury;
    while (a[Cury] == a[Cury + 1] - 1) --Cury;
  }
  if (Curx != x || Cury != y) return Calc(Curx, Cury);
  if (Mn - x + 1 > y - Mx + 1) {
    Stk[++Ans][0] = x, Stk[Ans][1] = Mn;
    sort(a + x, a + Mn + 1);
    return Calc(x + 1, y);
  }
  Stk[++Ans][0] = Mx, Stk[Ans][1] = y;
  sort(a + Mx, a + y + 1);
  return Calc(x, y - 1);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    a[0] = 0, a[n + 1] = n + 1;
    Calc(1, n);
    printf("%u\n", Ans);
    for (unsigned i(1); i <= Ans; ++i) printf("%u %u\n", Stk[i][0], Stk[i][1]);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1
5
1 5 2 3 4
 */