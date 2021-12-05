#include<iostream>
#include<cstdio>
using namespace std;
inline unsigned RD() {
  unsigned RTmp(0);
  char Rch(getchar());
  while (Rch < '0' || Rch > '9') Rch = getchar();
  while (Rch >= '0' && Rch <= '9') RTmp = (RTmp << 3) + (RTmp << 1) + Rch - '0', Rch = getchar();
  return RTmp;
}
const unsigned long long Mod(998244353);
unsigned n, m, t, Ans(1);
unsigned His[1000005][2], HTop(0);
unsigned long long Fac[1000005];
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long TPow(1);
  while (y) {
    if(y & 1) TPow = TPow * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return TPow;
}
signed main() {
  t = RD(), Fac[0] = 1;
  for (unsigned i(1); i <= 1000000; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  while (t--) {
    n = RD(), m = RD();
    if(n == m) printf("%llu\n", Fac[m - 1]);
    else printf("%llu\n", (Fac[m - 1] * Pow(n, n - m - 1) % Mod) * m % Mod);
  }
  return 0;
}
/*
*/
