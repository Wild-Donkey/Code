#include <cstdio>
#include <iostream>
#define Wild_Donkey 0
#define C(x,y) (((((unsigned long long)Fac[x]*Inv[y])%MOD)*(unsigned long long)Inv[(x)-(y)])%MOD)
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')  intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
unsigned long long MOD, Ans, Tmp, A;
unsigned m, n, n2, Cnt(0), Fac[20000005], Inv[20000005], h[3005], g[3005], f[3005];
signed main() {
  n = RD(), MOD = RD(), n2 = n << 1, m = n * n2, Fac[0] = 1;
  for (unsigned long long i(1); i <= m; ++i) Fac[i] = (Fac[i - 1] * i) % MOD;
  f[0] = 1, g[n] = 1, Tmp = MOD - 2, Inv[m] = 1, A = Fac[m];
  while (Tmp) { if (Tmp & 1) Inv[m] = (Inv[m] * A) % MOD; A = (A * A) % MOD, Tmp >>= 1; }
  for (unsigned long long i(m - 1); ~i; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % MOD;
  for (unsigned i(n); ~i; --i) {
    for (unsigned j(i - 1); ~j; --j) { g[j] += g[j + 1]; if (g[j] >= MOD) g[j] -= MOD; }
    h[i] = g[0];
  }
  for (unsigned i(2), Size(m); i <= n; ++i) {
    Size = m - (i - 2) * (n2 + 2) - 3, Tmp = 0;
    for (unsigned j(0); j <= n; ++j) Tmp = (Tmp + ((unsigned long long)h[j] * C(Size - j, n2 - j))) % MOD;
    f[i - 1] = (f[i - 2] * Tmp) % MOD, Size = m - i - 1;
    for (unsigned j(1); j < i; ++j, Size -= n2 + 1)
      f[j] = ((f[j] + (((unsigned long long)f[j - 1] * h[0]) % MOD) * C(Size, n2)) % MOD);
  }
  printf("%u\n", f[n - 1]);
  return Wild_Donkey;
}