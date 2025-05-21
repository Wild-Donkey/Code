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
const unsigned long long Mod(1000000007);
inline void Mn(unsigned long long &x) { x -= (x >= Mod) ? Mod : 0; }
inline void Mn(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned long long Fac[105], Inv[105];
unsigned long long f[101][101][101];
unsigned long long Ans(0);
unsigned A, Cnt[105], m, n;
inline unsigned long long C(unsigned x, unsigned y) {
  // printf("%u, %u\n", x, y);
  return (Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
}
inline unsigned long long Calc(unsigned x, unsigned y) {
  // printf("Here\n");
  return Fac[x] * C(x + y - 1, y - 1) % Mod;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Fac[0] = 1;
  for (unsigned i(1); i <= 100; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[100] = Pow(Fac[100], Mod - 2);
  for (unsigned i(100); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  n = RD();
  for (unsigned i(1); i <= n; ++i) A = RD() + 1, ++Cnt[A];
  memset(f, 0, sizeof(f));
  if (Cnt[1])
    f[1][0][1] = 1;
  else
    f[1][1][1] = 1;
  for (unsigned i(1), I(Cnt[1]); i <= n; ++i, I += Cnt[i]) {
    for (unsigned j(0); j <= n - I; ++j) {
      for (unsigned k(1); k <= j + Cnt[i]; ++k)
        if (f[i][j][k]) {  // k of nodes in layer i
          // printf("%u %u %u %u\n", i, j, k, f[i][j][k]);
          if (j + I == n) {
            Ans = (Ans + f[i][j][k] * Fac[j]) % Mod;
            continue;
          }
          for (unsigned K(1), J(j + 1 - Cnt[i + 1]); K <= n - I - j; ++K, ++J)
            if (J < 0x3f3f3f3f) {
              unsigned long long Li(Calc(K, k));
              for (unsigned l(min(K, Cnt[i + 1])); ~l;
                   --l) {  // l of i in Layer i
                if (j + l < Cnt[i + 1]) continue;
                // printf("%u %u %u %u %u %u\n", i, j, k, K, l, J);
                unsigned long long *Cur(f[i + 1][J] + K);
                *Cur = (*Cur +
                        (f[i][j][k] * (Li * Inv[K - l] % Mod * Inv[l] % Mod) %
                         Mod) *
                            (Fac[Cnt[i + 1]] * C(j, Cnt[i + 1] - l) % Mod)) %
                       Mod;
              }
            }
        }
    }
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}