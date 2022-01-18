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
long long Ks, Wh, a, b, c, d;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
long long Gcd(long long x, long long y) {
  long long STm;
  while (y) { STm = x, x = y, y = STm % y; }
  return x;
}
inline void Exgcd(long long x, long long y) {
  long long STm, Stack[105];
  unsigned STop(0);
  while (y) Stack[++STop] = x / y, STm = x, x = y, y = STm % y;
  Ks = x, Wh = 0;
  for (;STop;--STop) STm = Wh, Wh = Ks - Wh * Stack[STop], Ks = STm;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  c = RD(), c = RD() - c, a = RD(), a -= RD(), b = RD(), b = -b;
  d = Gcd((a > 0) ? a : -a, (b > 0) ? b : -b); if (d < 0) d = -d;
  if (c % d) { printf("Impossible\n"); return 0; }
  a /= d, b /= d, c /= d;
  // printf("Exgcd %lld %lld\n", a, b);
  Exgcd(a, b);
  if (b < 0) b = -b;
  // printf("Done %lld %lld %lld\n", Ks, Wh, c);
  Ks *= c, Ks %= b, Ks += b;
  if (Ks >= b) Ks -= b;
  printf("%lld\n", Ks);
  //  }
  system("pause");
  return Wild_Donkey;
}