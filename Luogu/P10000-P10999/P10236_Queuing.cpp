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
  if (!x) return 0;
  unsigned long long Rt(1);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
unsigned a[1002];
unsigned long long f[1001][1001],
    Ans;  //[l + 1, r]: [l][r] Cut l, [r][l] Cur r + 1
unsigned m, n, t;
unsigned Tmp(0);
inline void Clr() {
  for (unsigned i(0); i <= n; ++i) memset(f[i], 0, (n + 1) << 3);
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  a[0] = a[n + 1] = 0, Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    f[0][n] = f[n][0] = 0;
    for (unsigned i(n - 1); ~i; --i) {
      for (unsigned l(0), r(l + i); r <= n; ++l, ++r) {
        if (l) {  // Consider f[l - 1][r], f[r][l - 1], Del a[l]
          Tmp = Pow(a[l - 1], a[l]);
          f[l][r] = max(f[l][r], f[l - 1][r] + Tmp);
          if (r < n) {
            Tmp = Pow(a[r + 1], a[l]);
            f[l][r] = max(f[l][r], f[r][l - 1] + Tmp);
          }
        }
        if (r < n) {  // Consider f[l][r + 1], f[r + 1][l], Del a[r + 1]
          if (l) {
            Tmp = Pow(a[l], a[r + 1]);
            f[r][l] = max(f[r][l], f[l][r + 1] + Tmp);
          }
          Tmp = Pow(a[r + 2], a[r + 1]);
          f[r][l] = max(f[r][l], f[r + 1][l] + Tmp);
        }
      }
    }
    // for (unsigned i(0); i <= n; ++i) {
    //   for (unsigned j(0); j <= n; ++j) printf("%6u", f[i][j]);
    //   putchar(0x0A);
    // }
    for (unsigned i(1); i <= n; ++i) Ans = max(Ans, f[i][i]);
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
3
5
5 3 1 4 2
6
6 5 1 4 2 3
6
1 1 1 1 1 0
*/