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
int f[35][1005], Ans;
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Orb {
  int Val;
  unsigned Wei, Bi;
  const inline char operator < (const Orb& x) const {
    return (Bi ^ x.Bi) ? (Bi > x.Bi) : (Val < x.Val);
  }
}O[105];
inline void Clr() {
  memset(f, 0xaf, sizeof(f)), Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  // t = RD();
  for (;; ) {
    Clr();
    n = RDsg(), m = RD();
    if (n > 0x3f3f3f3f) break;
    for (unsigned i(1); i <= n; ++i) {
      O[i].Wei = RD(), O[i].Val = RD(), O[i].Bi = 0;
      if (!O[i].Wei) A += O[i].Val, O[i].Bi = O[i].Val = 0;
      while (!(O[i].Wei & 1)) O[i].Wei >>= 1, ++(O[i].Bi);
    }
    sort(O + 1, O + n + 1), f[30][m & (1 << 30)] = f[30][0] = 0;
    for (unsigned i(30), j(1); j <= n; ++j) {
      while (i > O[j].Bi) {
        // printf("%u %u:\n", i, (m >> i) & 1);
        // for (unsigned k(0); k <= 20; ++k) printf("%d ", f[i][k]);
        // putchar(0x0A);
        for (unsigned k(1000); ~k; --k) {
          unsigned Des((k << 1) + ((m >> (i - 1)) & 1));
          if (Des > 1000) f[i - 1][1000] = max(f[i - 1][1000], f[i][k]);
          else f[i - 1][Des] = max(f[i - 1][Des], f[i][k]);
        }
        --i;
        for (unsigned k(1000); ~k; --k) f[i][k] = max(f[i][k], f[i][k + 1]);
      }
      for (unsigned k(0); k + O[j].Wei <= 1000; ++k) {
        if (f[i][k + O[j].Wei] >= 0)
          f[i][k] = max(f[i][k], f[i][k + O[j].Wei] + O[j].Val);
      }
      Ans = max(Ans, f[i][0]);
      // printf("B: %u W %u V %u:\n", i, O[j].Wei, O[j].Val);
      // for (unsigned k(0); k <= 20; ++k) printf("%d ", f[i][k]);
      // putchar(0x0A);
    }
    printf("%d\n", Ans + A);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
4 10
8 9
5 8
4 6
2 5
4 13
8 9
5 8
4 6
2 5
16 75594681
393216 5533
2 77
32768 467
29360128 407840
112 68
24576 372
768 60
33554432 466099
16384 318
33554432 466090
2048 111
24576 350
9216 216
12582912 174768
16384 295
1024 76
*/