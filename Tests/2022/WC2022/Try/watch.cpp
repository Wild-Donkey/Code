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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
bitset<500005> OK, No;
//  inline void Clr() {}
signed main() {
  freopen("watch.in", "r", stdin);
  freopen("watch.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), OK[0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD(), No = 0;
    for (unsigned j(500000); j >= A; --j) {
      unsigned Lim(j - A * B);
      if (!OK[j]) {
        if ((No[j]) && (Lim <= 0x3f3f3f3f)) {
          No[Lim] = 1;
          if (OK[Lim]) { while (Lim <= j) OK[Lim] = 1, Lim += A; break; }
        }
        else {
          if (Lim > 0x3f3f3f3f) Lim = 0;
          for (unsigned k(j - A); (k >= Lim) && (k < 0x3f3f3f3f); k -= A) {
            No[k] = 1;
            if (OK[k]) { while (k <= j) OK[k] = 1, k += A; break; }
          }
        }
      }
    }
    // for (unsigned j(0); j <= 100; ++j) putchar(OK[j] ? '1' : '0'); putchar(0x0A);
  }
  for (unsigned i(1); i <= m; ++i) printf(OK[RD()] ? "YES\n" : "NO\n");
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
3 5
1 2
5 1
6 3
3 19 21 1 7
*/