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
unsigned a[100005], m, n, Sum;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), Sum = 0, Ans = 0x3f3f3f3f;
}
inline void Calc(unsigned x) {
  unsigned Left(x);
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] <= Left) Left -= a[i];
    else return;
    if (!Left) Left = x;
  }
  Ans = min(Ans, x);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD(), Sum += a[i];
    if (!Sum) { printf("0\n"); continue; }
    for (unsigned i(sqrt(Sum)); i; --i) if (!(Sum % i)) {
      Calc(i);
      if ((Sum / i) ^ i) Calc(Sum / i);
    }
    printf("%u\n", n - (Sum / Ans));
  }
  //  system("pause");
  return Wild_Donkey;
}