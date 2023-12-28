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
#define foreplay for
#define wild while
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
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
    // printf("%u %u\n", x, )
  }
  return Rt;
}
unsigned long long f[200005], Fac[200005], Inv[200005];
unsigned a[200005], b[200005];
unsigned m, n;
int A;
unsigned t;
char Flg;
inline unsigned long long C(unsigned x, unsigned y) {
  return (Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
}
inline unsigned long long Calc(unsigned Pos, unsigned Val, unsigned Chos) {
  // printf("Calc(%u, %u, %u)\n", Pos, Val, Chos);
  return (C(Pos, Chos) * C(Val, Chos) % Mod) * Fac[Chos] % Mod;
}
inline void Clr() { n = RD(), m = 0, Flg = 0; }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  Fac[0] = 1;
  for (unsigned i(1); i <= 200000; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[200000] = Pow(Fac[200000], 998244351);
  for (unsigned i(200000); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  // for (unsigned i(0); i < 5; ++i) printf("%u %llu %llu\n", i, Fac[i],
  // Inv[i]);
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) {
      A = RDsg();
      if (A >= 0) a[++m] = A, b[m] = i;
    }
    a[0] = b[0] = 0;
    if (b[m] < n)
      b[++m] = n, a[m] = n;
    else {
      if (a[m] != n) {
        printf("0\n");
        continue;
      }
    }
    for (unsigned i(1); i < m; ++i)
      if (a[i] > a[i + 1] || a[i + 1] - a[i] > ((b[i + 1] - b[i]) << 1) ||
          a[i] > b[i]) {
        Flg = 1;
        break;
      }
    if (Flg) {
      printf("0\n");
      continue;
    }
    f[0] = 1;
    for (unsigned i(m); i; --i) a[i] -= a[i - 1];
    for (unsigned i(1), j(0); i <= m; j += a[i++]) {
      f[i] = 0;
      for (unsigned k(0); k <= a[i]; ++k) {
        // printf("%u k\n", k);
        if (k + b[i - 1] > b[i]) continue;
        if (k + j > b[i - 1]) continue;
        if (a[i] + b[i - 1] > b[i] + k) continue;
        if (a[i] + j > b[i]) continue;
        f[i] =
            (f[i] +
             f[i - 1] * (Calc(b[i - 1] - j, b[i] - b[i - 1], k) *
                         Calc(b[i] - b[i - 1], b[i] - j - k, a[i] - k) % Mod)) %
            Mod;
      }
    }
    printf("%llu\n", f[m]);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
x -> a b (a + b = x)
*/