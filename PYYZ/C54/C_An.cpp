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
unsigned long long Fac[2000005], Inv[2000005], f[2000005][25];
unsigned m, n, A, B, C, D, t;
unsigned long long Ans(1);
inline unsigned long long Pow (unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return x;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i)
  for (unsigned i(1); i <= m; ++i) 
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j) {
      f[i][j] = 1, g[i][j] = 0;
      for (unsigned k(1); k <= j; ++k) {
        A = 0, B = Pow(k, i - 1), C = 1;
        for (unsigned l(1); l <= j; ++l) if(Gcd(l, k) == 1) {
          ++A, C = C * ((unsigned long long)B * l % Mod) % Mod;
        }
        printf("%u %u\n", A, C), C = Pow(C, g[i - 1][j / k]);
        g[i][j] = (g[i][j] + g[i - 1][j / k] * A) % Mod;
        f[i][j] = f[i][j] * (Pow(f[i - 1][j / k], A) * C % Mod) % Mod; 
      }
      printf("(%u, %u) f%llu g%llu\n", i, j, f[i][j], g[i][j]);
    }
  }
  for (unsigned i(1); i <= m; ++i) Ans = Ans * Pow(f[n][m / i] * Pow(i, g[n][m / i]) % Mod, i) % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

