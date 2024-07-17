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
const unsigned long long Mod(998244353);
unsigned long long Pnt[2005][2], La[2005], L[2005], Ans(0), m, Now(1);
unsigned n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
inline unsigned long long Inv(unsigned long long x) {
  unsigned long long Rt(1);
  unsigned y(998244351);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(0); i < n; ++i) Pnt[i][0] = RD(), Pnt[i][1] = RD();
  La[1] = 1, La[0] = Mod - Pnt[0][0];
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(i + 1); j; --j)
      La[j] = (La[j] * (Mod - Pnt[i][0]) + La[j - 1]) % Mod;
    La[0] = La[0] * (Mod - Pnt[i][0]) % Mod;
  }
  // for (unsigned i(0); i <= n; ++i) printf("%llu ", La[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) {
    unsigned long long Mul(1), Tmp(La[n]);
    for (unsigned j(0); j < n; ++j) if (j ^ i) Mul = Mul * (Mod + Pnt[i][0] - Pnt[j][0]) % Mod;
    Mul = Inv(Mul) * Pnt[i][1] % Mod;
    for (unsigned j(n - 1); ~j; --j) {
      L[j] = (L[j] + Mul * Tmp) % Mod;
      Tmp = (La[j] + Tmp * Pnt[i][0]) % Mod;
    }
  }
  // for (unsigned i(0); i < n; ++i) printf("%llux^%u + ", L[i], i); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) {
    Ans = (Ans + L[i] * Now) % Mod;
    Now = Now * m % Mod;
  }
  printf("%llu\n", Ans);
  //  }
    //  system("pause");
  return Wild_Donkey;
}