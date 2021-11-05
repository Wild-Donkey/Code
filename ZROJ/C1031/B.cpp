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
unsigned long long f[70000][2], g[70000][2], PCnt[70000], Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Link[20][20];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) A = RD(), B = RD(), Link[A][B] = Link[B][A] = 1;
  for (unsigned i(0); i < n; ++i) f[1 << i][0] = 1;
  for (unsigned i((1 << n) - 1), Cnti(0); ~i; --i) {
    for (unsigned j(0); j < n; ++j) if((1 << j) & i) {
      ++Cnti;
      unsigned From(i ^ (1 << j)), CntBi(0);
      for (unsigned k(0); k < n; ++k) if(((1 << k) & From) && (Link[j + 1][k + 1])) ++CntBi;
      f[i][0] = (f[i][0] + f[From][0] * CntBi) % Mod;
      f[i][1] = (f[i][1] + ((f[From][0] * CntBi * (CntBi - 1)) >> 1)) % Mod;
      f[i][1] = (f[i][1] + f[From][1] * CntBi) % Mod;
    }
    PCnt[i] = Cnti;
  }
  m = 1 << n;
  g[0][0] = 1;
  for (unsigned i(1); i < m; ++i) {
    for (unsigned j(i); j; j = (i & (j - 1))) {
      g[i][0] = (g[i][0] + (g[i ^ j][0] * f[j][0] % Mod) * PCnt[j]) % Mod;
      g[i][1] = (g[i][1] + (g[i ^ j][1] * f[j][0] % Mod) * PCnt[j]) % Mod;
      g[i][1] = (g[i][1] + (g[i ^ j][0] * f[j][1] % Mod) * PCnt[j]) % Mod;
    }
  }
  Ans = g[(1 << n) - 1][0] + g[(1 << n) - 1][1];
  if(Ans >= Mod) Ans -= Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

