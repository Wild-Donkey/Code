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
const unsigned long long MOD(1000000007);
unsigned a[1000005], m, n, Cnt(0), A, B, C, D, t, Tmp(0);
unsigned long long Fac[1000005], Inv[1000005], f[1000005], Ans(1);
unsigned long long Power(unsigned long long x, unsigned long long y) {
  register unsigned long long TmpAns(1);
  while (y) {
    if (y & 1) TmpAns = TmpAns * x % MOD;
    x = x * x % MOD, y >>= 1;
  }
  return TmpAns;
}
unsigned long long Binom(unsigned x, unsigned y) {
  if (x < y) return 0;
  return (Fac[x] * Inv[y] % MOD) * Inv[x - y] % MOD;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Fac[1] = 1, Fac[0] = 1, Inv[0] = 1;
  for (register unsigned i(2); i <= n + 1; ++i) Fac[i] = (Fac[i - 1] * i) % MOD;// printf("Fac[%u] %u\n", i, Fac[i]);
  // Inv[n + 1] = Power(Fac[n + 1], MOD - 2);
  // for (register unsigned i(n); i; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % MOD;// printf("Inv[%u] %u\n", i, Inv[i]);
  if (m == 0) { printf("%u\n", Fac[n]);return 0; }
  // f[1] = f[0] = 1;
  // for (register unsigned i(2); i <= n; ++i) {
  //   for (register unsigned j(0); j < i; ++j) {
  //     f[i] = (f[i] + (Binom(i - 1, j) * f[j] % MOD) * f[i - j - 1]) % MOD;
  //   }
  //   printf("f[%u] %u\n", i, f[i]);
  // }
  for (register unsigned i(1); i <= m; ++i) a[i] = RD();
  sort(a + 1, a + m + 1);
  for (register unsigned i(n), j(m), Now(1); i; --i, ++Now) {
    Ans = Ans * Now % MOD;
    if (i == a[j]) {
      Now -= 2, --j;
    }
  }
  printf("%u\n", Ans);
  // system("pause");
  return Wild_Donkey;
}