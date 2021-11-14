#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
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
const unsigned long long MOD(1000000007);
unsigned long long Fact[200005], Inv[200005], a[200005], b[200005], Ans(1);
unsigned m, n, Max(0), Cnt[200005], A, B, C, D, t, Tmp(0);
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  Fact[0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    Fact[i] = Fact[i - 1] * i % MOD;
//    printf("Fact[%u] = %u\n", i, Fact[i]);
  }
  Tmp = MOD - 2, A = Fact[n], Inv[n] = 1, B = 1;
  while (B <= Tmp) {
    if(B & Tmp) {
      Inv[n] = Inv[n] * A % MOD;
    }
    A = (unsigned long long)A * A % MOD;
    B <<= 1;
  }
//  printf("Inv[%u] = %u\n", n, Inv[n]);
  for (register unsigned i(n - 1); i; --i) {
    Inv[i] = Inv[i + 1] * (i + 1) % MOD;
//    printf("Inv[%u] = %u\n", i, Inv[i]);
  }
  Inv[0] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  memcpy(b, a, ((n + 1) << 3));
  sort(b + 1, b + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if(b[i] ^ b[i - 1]) {
      b[++Max] = b[i];
    }
    ++Cnt[Max];
  }
  for (register unsigned i(1); i <= Max; ++i) {
    Ans = Ans * Cnt[i] % MOD;
  }
  Ans = Ans * Fact[n - Max] % MOD;
  Ans = Ans * (((Fact[n] * Inv[Max]) % MOD) * Inv[n - Max] % MOD) % MOD;
  printf("%u %u\n", Max, Ans);
//  }
  return Wild_Donkey;
}
/*
1 1 2 2: 4 * 2 * 2
1 2 1 2: 3 * 2 * 2
1 2 2 1: 2 * 2 * 2
2 1 1 2: 2 * 2 * 2
2 1 2 1: 1 * 2 * 2
2 2 1 1: 0
Ans = 48
1 2 3
1 3 2
3 1 2
2 1 3
2 3 1
3 2 1
*/
