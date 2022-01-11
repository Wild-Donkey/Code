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
unsigned long long Mod(998244353);
unsigned long long Ans(1), f[105][105];
unsigned a[105][2005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j) {
      a[i][0] += (a[i][j] = RD());
      if (a[i][0] >= Mod) a[i][0] -= Mod;
    }
    Ans = Ans * (a[i][0] + 1) % Mod;
  }
  for (unsigned i(1); i <= m; ++i) {
    memset(f, 0, sizeof(f)), f[0][0] = 1;
    for (unsigned Po(1); Po <= n; ++Po) {
      for (unsigned Me(Po); Me; --Me) for (unsigned Ot(Po - Me); Ot; --Ot)
        f[Me][Ot] = (f[Me][Ot] + f[Me - 1][Ot] * a[Po][i] + f[Me][Ot - 1] * (Mod + a[Po][0] - a[Po][i])) % Mod;
      for (unsigned Me(Po); Me; --Me) f[Me][0] = (f[Me][0] + f[Me - 1][0] * a[Po][i]) % Mod;
      for (unsigned Ot(Po); Ot; --Ot) f[0][Ot] = (f[0][Ot] + f[0][Ot - 1] * (Mod + a[Po][0] - a[Po][i])) % Mod;
    }
    // printf("Chose %u:\n", i);
    // for (unsigned Me(0); Me <= n; ++Me) {
    //   for (unsigned Ot(0); Ot <= n; ++Ot) printf("%llu ", f[Me][Ot]);
    //   putchar(0x0A);
    // }
    for (unsigned Me(1); Me <= n; ++Me) for (unsigned Ot(0); Ot < Me; ++Ot) Ans = Mod + Ans - f[Me][Ot];
  }
  --Ans, Ans %= Mod;
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*

*/