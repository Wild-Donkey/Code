#include<iostream>
#include<cstdio>
#include<cstring>
#define Lbt(x) ((x)&((~(x))+1))
using namespace std;
inline unsigned RD() {
  unsigned RTmp(0);
  char Rch(getchar());
  while (Rch < '0' || Rch > '9') Rch = getchar();
  while (Rch >= '0' && Rch <= '9') RTmp = (RTmp << 3) + (RTmp << 1) + Rch - '0', Rch = getchar();
  return RTmp;
}
const unsigned long long Mod(998244353);
unsigned n, m, t;
unsigned Log[1005];
unsigned long long f[1005][1005], g[20][1005][1005], Ans[1005][1005], Tmp[1005][1005];
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long TPow(1);
  while (y) {
    if(y & 1) TPow = TPow * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return TPow;
}
signed main() {
  t = RD();
//  for (unsigned i(1); i <= 10000000; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  for (unsigned i(1), j(0); i <= 1000; i <<= 1, ++j) Log[i] = j;
  for (unsigned i(1); i <= 1000; ++i) Log[i] = max(Log[i], Log[i - 1]);
  while (t--) {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    memset(Ans, 0, sizeof(Ans));
    n = RD(), m = 2;
    f[0][0] = 1;
    for (unsigned k(0); k < n; ++k) {
      for (unsigned i(n - 1); ~i; --i) {
        for (unsigned j(0); j < n; ++j) {
          unsigned long long &Des(f[i + 1][(j + k) % n]);
          Des += f[i][j];
          if(Des >= Mod) Des -= Mod;
        }
      }
    }
    memcpy(g[0], f, sizeof(f));
    for (unsigned i(2), j(1); i <= m; ++i) {
      for (unsigned k(0); k <= n; ++k) {
        for (unsigned kk(0); kk <= k; ++kk) {
          for (unsigned l1(0); l1 < n; ++l1) {
            for (unsigned l2(0); l2 < n; ++l2) {
              unsigned long long &Des(g[j][k][(l1 + l2) % n]);
              Des = (Des + g[j - 1][kk][l1] * g[j - 1][k - kk][l2]) % Mod;
            }
          }
        }
      }
    }
    Ans[0][0] = 1;
//    for (unsigned i(0); i < n; ++i) printf("%u %llu\n", i, g[1][n][i]);
    for (unsigned i(m); i; i -= Lbt(i)) {
      memcpy(Tmp, Ans, sizeof(Ans));
      for (unsigned k(n); ~k; --k) {
        for (unsigned kk(0); kk <= k; ++kk) {
          for (unsigned l1(0); l1 < n; ++l1) {
            for (unsigned l2(0); l2 < n; ++l2) {
              unsigned long long &Des(Ans[k][(l1 + l2) % n]);
              Des = (Des + Tmp[kk][l1] * g[Log[Lbt(i)]][k - kk][l2]) % Mod;
            }
          }
        }
      }
    }
    printf("%llu\n", Ans[n][0]);
  }
  return 0;
}
/*
*/
