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
unsigned W, Tmp(0);
unsigned long long a[2100005], b[2100005];
unsigned A(0), B(0), C, D, t, m, n(1), Lgn(0);
unsigned Cnt(0), Ans(0);
char Inv(0), OK(0), IO[2100005];
inline unsigned long long Pow(unsigned long long x, unsigned long long y) {
  unsigned long long Rt(1);
  // printf("Pow %u\n", y);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
inline void DIT(unsigned long long* f) {
  for (unsigned i(n >> 1), j(1); i; i >>= 1, j <<= 1) {
    unsigned long long Pr(Pow(Inv ? Pow(W, Mod - 2) : W, i)), Alp(1);
    for (unsigned k(0); k < n; ++k, Alp = Alp * Pr % Mod) if (!(k & j)) {
      unsigned long long Tma(f[k]), Tmb(f[k + j] * Alp % Mod);
      f[k] = Tma + Tmb;
      f[k + j] = Mod + Tma - Tmb;
      if (f[k] >= Mod) f[k] -= Mod;
      if (f[k + j] >= Mod) f[k + j] -= Mod;
    }
  }
}
inline void DIF(unsigned long long* f) {
  for (unsigned i(1), j(n >> 1); j; i <<= 1, j >>= 1) {
    unsigned long long Pr(Pow(Inv ? Pow(W, Mod - 2) : W, i)), Alp(1);
    for (unsigned k(0); k < n; ++k, Alp = Alp * Pr % Mod) if (!(k & j)) {
      unsigned long long Tma(f[k]), Tmb(f[k + j]);
      f[k] = Tma + Tmb;
      f[k + j] = (Mod + Tma - Tmb) * Alp % Mod;
      if (f[k] >= Mod) f[k] -= Mod;
    }
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  scanf("%s", &IO);
  for (unsigned i(strlen(IO) - 1); ~i; --i) a[A++] = IO[i] - '0';
  memset(IO, 0, A + 2), scanf("%s", &IO);
  for (unsigned i(strlen(IO) - 1); ~i; --i) b[B++] = IO[i] - '0';
  m = A + B - 1;
  // printf("%u %u %u\n", A, B, m);
  while (n < m) n <<= 1, ++Lgn;
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  // for (unsigned i(0); i < n; ++i) printf("%u ", b[i]); putchar(0x0A);
  Inv = 1, W = Pow(3, (Mod - 1) / n), DIF(a), DIF(b);
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  // for (unsigned i(0); i < n; ++i) printf("%u ", b[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * b[i] % Mod;
  Inv = 0, DIT(a), W = Pow(n, Mod - 2);
  for (unsigned i(0); i < n; ++i) a[i] = a[i] * W % Mod;
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) IO[i] = (a[i] + Tmp) % 10, Tmp = (a[i] + Tmp) / 10;
  while (Tmp) IO[n++] = Tmp % 10, Tmp /= 10;
  while ((!IO[n - 1]) && (n > 1)) --n;
  for (unsigned i(n - 1); ~i; --i) putchar(IO[i] + '0'); putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
5 6
4 1 5 4 1 1
0 1 8 9 1 9 1
*/