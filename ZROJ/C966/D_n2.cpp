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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned long long MOD(2148473647);
unsigned Cnt[10005], Sol[10005], m, n, A, B, C, D, t, Ans(0), Tmp(0);
unsigned long long Power(unsigned long long x) {
  register unsigned Tmpy(MOD - 2);
  register unsigned long long TmpA(1);
  while (Tmpy) {
    if (Tmpy & 1) {
      TmpA = TmpA * x % MOD;
    }
    Tmpy >>= 1, x = x * x % MOD;
  }
  return TmpA;
}
signed main() {
  // freopen("D.in", "r", stdin);
  // freopen("D.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Cnt[1] = Sol[1] = 1, Cnt[0] = 0, Sol[0] = 1;
  for (register unsigned i(2); i <= n; ++i) {
    for (register unsigned j(0); j < i; ++j) {
      Sol[i] = (Sol[i] + (unsigned long long)Sol[j] * Sol[i - j - 1]) % MOD;
    }
    // printf("Sol[%u] = %u\n", i, Sol[i]);
  }
  for (register unsigned i(2); i <= n; ++i) {
    for (register unsigned j(0); j < i; ++j) {
      Cnt[i] = (Cnt[i] + (unsigned long long)Cnt[j] * Sol[i - j - 1] + (unsigned long long)Sol[j] * Cnt[i - j - 1]) % MOD;
    }
  }
  printf("%u %u\n", Sol[n], Cnt[n]);
  printf("%u\n", (Cnt[n] * Power(Sol[n])) % MOD);
  system("pause");
  return Wild_Donkey;
}
