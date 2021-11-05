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
const unsigned long long Mod(998244353);
unsigned long long Ans(0), Inv[1000005], Pro[1000005], SumInvPro[1000005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline unsigned long long Pow(unsigned long long x) {
  unsigned long long TmpP(1);
  unsigned y(Mod - 2);
  while (y) {
    if(y & 1) TmpP = TmpP * x % Mod;
    y >>= 1, x = x * x % Mod;
  }
  return TmpP;
}
//  inline void Clr() {}
signed main() {
//  freopen("A2.in", "r", stdin);
//  freopen("A.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Pro[0] = 1, SumInvPro[1] = 1;
  for (unsigned i(1); i <= n; ++i) Pro[i] = Pro[i - 1] * Pow(RD()) % Mod;
  for (unsigned i(1); i <= n; ++i) {SumInvPro[i + 1] = SumInvPro[i] + Pow(Pro[i]); if(SumInvPro[i + 1] >= Mod) SumInvPro[i + 1] -= Mod;}
//  for (unsigned i(1); i <= n; ++i) {
//    printf("%u %llu %llu\n", i, Pro[i], SumInvPro[i]);
//  }
  for (unsigned i(1); i <= m; ++i) {
    A = RD() - 1, B = RD();
    printf("%llu\n", Pro[B] * (Mod + SumInvPro[B] - SumInvPro[A]) % Mod);
  }
//  }
  return Wild_Donkey;
}
/*
3 3
1 499122177 499122177
2 1
2 2
2 3
*/
