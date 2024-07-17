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
unsigned a[50005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Judge(unsigned x) {
  unsigned Rt(0), j(0);
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] - j < x)
      ++Rt;
    else
      j = a[i];
  }
  if (t - j < x) ++Rt;
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  t = RD(), n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) { a[i] = RD(); }
  unsigned L(0), R(1000000000), Mid;
  while (L < R) {
    Mid = (L + R + 1) >> 1;
    if (Judge(Mid) <= m)
      L = Mid;
    else
      R = Mid - 1;
  }
  printf("%u\n", L);
  //  }
  //  system("pause");
  return Wild_Donkey;
}