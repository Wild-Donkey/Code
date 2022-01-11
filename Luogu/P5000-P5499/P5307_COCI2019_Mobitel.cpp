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
const unsigned long long Mod(1000000007);
unsigned List[1000005], Back[2005], f[2][305][2005];
unsigned long long C[605][605], Ans(0);
unsigned a[305][305], m, n;
unsigned A, B, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD() - 1;
  for (unsigned i(1); i <= t; ++i) if (!List[t / i]) Back[List[t / i] = ++Cnt] = t / i;
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] = RD();
  for (unsigned i(0); i <= 600; ++i) {
    C[i][0] = 1;
    for (unsigned j(1); j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if (C[i][j] >= Mod) C[i][j] -= Mod;
    }
  }
  if (a[1][1] > t) { printf("%llu\n", C[n + m - 2][n - 1]); return 0; }
  else f[1][1][List[t / a[1][1]]] = 1;
  for (unsigned i(1); i < n; ++i) {
    // printf("i=%u\n", i);
    for (unsigned j(1); j < m; ++j) {
      // printf("j=%u\n", j);
      for (unsigned k(1); k <= Cnt; ++k) if (f[i & 1][j][k]) {
        unsigned Nu(Back[k]), Cas(f[i & 1][j][k]);
        if (a[i + 1][j] > Nu)
          Ans = (Ans + Cas * C[n + m - i - j - 1][n - i - 1]) % Mod;
        else {
          unsigned Des(List[Nu / a[i + 1][j]]);
          f[(i & 1) ^ 1][j][Des] += Cas;
          if (f[(i & 1) ^ 1][j][Des] >= Mod) f[(i & 1) ^ 1][j][Des] -= Mod;
        }
        if (a[i][j + 1] > Nu)
          Ans = (Ans + Cas * C[n + m - i - j - 1][n - i]) % Mod;
        else {
          unsigned Des(List[Nu / a[i][j + 1]]);
          f[i & 1][j + 1][Des] += Cas;
          if (f[i & 1][j + 1][Des] >= Mod) f[i & 1][j + 1][Des] -= Mod;
        }
      }
      memset(f[i & 1][j], 0, (Cnt + 1) << 2);
      // printf("Ans = %u\n", Ans);
    }
    for (unsigned k(1); k <= Cnt; ++k) if (f[i & 1][m][k]) {
      unsigned Nu(Back[k]), Cas(f[i & 1][m][k]);
      if (a[i + 1][m] > Nu) { Ans += Cas;if (Ans >= Mod) Ans -= Mod; }
      else {
        unsigned Des(List[Nu / a[i + 1][m]]);
        f[(i & 1) ^ 1][m][Des] += Cas;
        if (f[(i & 1) ^ 1][m][Des] >= Mod) f[(i & 1) ^ 1][m][Des] -= Mod;
      }
    }
    memset(f[i & 1][m], 0, (Cnt + 1) << 2);
  }
  for (unsigned j(1); j < m; ++j)for (unsigned k(1); k <= Cnt; ++k) if (f[n & 1][j][k]) {
    unsigned Nu(Back[k]), Cas(f[n & 1][j][k]);
    if (a[n][j + 1] > Nu) {
      Ans += Cas;
      if (Ans >= Mod) Ans -= Mod;
    }
    else {
      unsigned Des(List[Nu / a[n][j + 1]]);
      f[n & 1][j + 1][Des] += Cas;
      if (f[n & 1][j + 1][Des] >= Mod) f[n & 1][j + 1][Des] -= Mod;
    }
  }
  printf("%llu\n", Ans);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
6 3 200
2 3 4
5 6 7
2 3 4
5 6 7
2 3 4
5 6 7
*/