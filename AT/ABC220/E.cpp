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
unsigned long long Ans(0), Tmp(0), Bin[2000005], Sum[2000005];
unsigned m, n, M;
unsigned A, B, C, D, t;
unsigned Cnt(0);
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), M = max(n, m), Bin[0] = 1;
  for (unsigned i(1); i <= M; ++i) {
    Bin[i] = Bin[i - 1] << 1;
    if(Bin[i] >= Mod) Bin[i] -= Mod;
  }
  for (unsigned i(0); i <= m; ++i) Sum[i] = Bin[i] * Bin[m - i] % Mod;
  for (unsigned i(1); i <= m; ++i) {Sum[i] += Sum[i - 1]; if(Sum[i] >= Mod) Sum[i] -= Mod;}
  for (unsigned i((m + 1) >> 1); i < n; ++i) {
    A = (m - 1) >> 1, B = m - min(i, m);
    if(B == 0) B = 1;
//    printf("%u %u\n", A, B);
    if(A >= B) Tmp = Mod + Sum[A] - Sum[B - 1];
    else Tmp = 0;
//    printf("Tmp %llu\n", Tmp);
    while(Tmp >= Mod) Tmp -= Mod;
    if(m <= i) {Tmp += Bin[m + 1]; if(Tmp >= Mod) Tmp -= Mod;}
    if(!(m & 1)) Tmp = (Tmp + Bin[m >> 1] * Bin[(m >> 1) - 1]) % Mod;
    Ans = (Ans + Bin[n - i - 1] * Tmp) % Mod;
//    printf("Ans %llu\n", Ans);
  }
  printf("%llu\n", Ans);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

