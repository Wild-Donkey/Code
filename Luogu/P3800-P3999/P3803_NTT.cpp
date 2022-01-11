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
#define Pi 3.141592653589793238462643383279502884197169399
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
unsigned long long W, a[2100000], b[2100000];
unsigned m, n, nn, Lgn(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(1);
char Inv(0);
//  inline void Clr() {}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long PR(1);
  while (y) {
    if (y & 1) PR = PR * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return PR;
}
inline void DIT(unsigned long long* f) {
  for (unsigned i(1), j(Lgn - 1); ~j; --j, i <<= 1) {
    unsigned long long Pri(Pow(Inv ? W : Pow(W, Mod - 2), 1 << j)), Po(1);
    for (unsigned k(0); k < n; ++k, Po = Po * Pri % Mod) if (!(k & i)) {
      unsigned long long Tma(f[k]), Tmb(f[k + i] * Po % Mod);
      f[k] = Tma + Tmb;
      f[k + i] = Mod + Tma - Tmb;
      if (f[k] >= Mod) f[k] -= Mod;
      if (f[k + i] >= Mod) f[k + i] -= Mod;
    }
  }
}
inline void DIF(unsigned long long* f) {
  for (unsigned i(n >> 1), j(0); i; ++j, i >>= 1) {
    unsigned long long Pri(Pow(Inv ? W : Pow(W, Mod - 2), 1 << j)), Po(1);
    for (unsigned k(0); k < n; ++k, Po = Po * Pri % Mod) if (!(k & i)) {
      unsigned long long Tma(f[k]), Tmb(f[k + i]);
      f[k] = Tma + Tmb;
      if (f[k] >= Mod) f[k] -= Mod;
      f[k + i] = (Mod + Tma - Tmb) * Po % Mod;
    }
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  nn = RD() + 1, m = RD() + 1, n = nn + m - 1;
  while (Tmp < n) Tmp <<= 1, ++Lgn; n = Tmp;
  W = Pow(3, (Mod - 1) / n);
  // for (unsigned i(0); i <= n; ++i) printf("%llu ", w[0][i]);putchar(0x0A);
  for (unsigned i(0); i < nn; ++i) a[i] = RD();
  for (unsigned i(0); i < m; ++i) b[i] = RD();
  DIF(a), DIF(b);
  for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) printf("%u ", b[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * b[i] % Mod;
  Inv = 1, DIT(a), W = Pow(n, Mod - 2);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * W % Mod;
  // for (unsigned i(0); i < n; ++i) printf("%llu ", a[i]);putchar(0x0A);
  for (unsigned i(0); i < m + nn - 1; ++i) printf("%llu ", a[i]); putchar(0x0A);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
1 1
2 1
1 2
2 2
1 2 0
1 2 1
2,1
3,0 1,-2 -1,0 1,2
4,0 0,-2 0,0 0,2

7 0
2 5 7 4 4 3 2 6
0
2,5,7,4,4,3,2,6
2 4 7 2 5 3 4 6
*/