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
unsigned long long f[35][25], g[105][25], Tmp[2][25], Ans(0);
unsigned m, n;
unsigned A, B;
char Lg;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  g[0][0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD() % m, Lg = 0;
    memset(f, 0, sizeof(f)), ++f[0][0], ++f[0][B];
    for (unsigned Size(2), j(1); Size <= A; Size <<= 1, ++j, Lg ^= 1) {
      for (unsigned k(0); k < m; ++k) for (unsigned l(0); l < m; ++l) {
        unsigned From(m + k - l); if(From >= m) From -= m;
        f[j][k] = (f[j][k] + f[j - 1][l] * f[j - 1][From]) % Mod;
      }
    }
    memset(Tmp[1], 0, m << 3), Tmp[1][0] = 1;
    for (unsigned Size(1), j(0); Size <= A; Size <<= 1, ++j) if(Size & A) {
      memset(Tmp[j & 1], 0, m << 3);
      for (unsigned k(0); k < m; ++k) for (unsigned l(0); l < m; ++l) {
        unsigned From(m + k - l); if(From >= m) From -= m;
        Tmp[j & 1][k] = (Tmp[j & 1][k] + Tmp[(j ^ 1) & 1][l] * f[j][From]) % Mod;
      }
    } else memcpy(Tmp[j & 1], Tmp[(j ^ 1) & 1], m << 3);
//    for (unsigned j(0); j < m; ++j) printf("%llu ", Tmp[Lg][j]);
//    putchar(0x0A);
//    for (unsigned j(0); j < m; ++j) printf("%llu ", Tmp[Lg ^ 1][j]);
//    putchar(0x0A);
    for (unsigned j(0); j < m; ++j) for (unsigned k(0); k < m; ++k) {
      unsigned From(m + j - k); if(From >= m) From -= m;
      g[i][j] = (g[i][j] + g[i - 1][From] * Tmp[Lg][k]) % Mod;
    }
  }
  Ans = Mod + g[n][0] - 1; if(Ans >= Mod) Ans -= Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
22 15
1 3
2 6
2 6
8 12
6 8
10 2
3 9
4 9
4 13
1 4
6 14
6 12
5 4
5 6
4 2
2 11
9 5
3 8
5 9
4 7
1 5
8 5

375072397
*/ 
