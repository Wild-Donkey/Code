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
const unsigned long long Mod(1004535809);
unsigned long long Tmp, Fac[10000005], Inv[10000005];
unsigned long long f[100005], g[100005], Bi[100005], Ans(0);
unsigned long long a[270000], b[270000], IW, W, Len, l(1);
unsigned m, n, Mx, S, mn;
unsigned A, B, C, D, t, Cnt(0);
char Ive(0);
unsigned long long Pow(unsigned long long x, unsigned long long y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline void DIT(unsigned long long* c) {
  for (unsigned i(1), j(l >> 1); j; j >>= 1, i <<= 1) {
    unsigned long long Alp(Pow(Ive ? IW : W, j)), Nw(1);
    for (unsigned k(0); k < l; ++k, Nw = Nw * Alp % Mod) if (!(k & i)) {
      unsigned long long Tma(c[k]), Tmb(c[k + i] * Nw % Mod);
      c[k] = Tma + Tmb;
      c[k + i] = Mod + Tma - Tmb;
      if (c[k] >= Mod) c[k] -= Mod;
      if (c[k + i] >= Mod) c[k + i] -= Mod;
    }
  }
}
inline void DIF(unsigned long long* c) {
  for (unsigned i(l >> 1), j(1); i; i >>= 1, j <<= 1) {
    unsigned long long Alp(Pow(Ive ? IW : W, j)), Nw(1);
    for (unsigned k(0); k < l; ++k, Nw = Nw * Alp % Mod) if (!(k & i)) {
      unsigned long long Tma(c[k]), Tmb(c[k + i]);
      c[k] = Tma + Tmb;
      c[k + i] = (Mod + Tma - Tmb) * Nw % Mod;
      if (c[k] >= Mod) c[k] -= Mod;
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
  n = RD(), m = RD(), S = RD(), Mx = min(n / S, m), mn = max(n, m);
  Bi[0] = Fac[0] = 1;
  for (unsigned i(1); i <= mn; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[mn] = Pow(Fac[mn], Mod - 2);
  for (unsigned i(mn - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  // for (unsigned i(1); i <= n; ++i) printf("%u %llu\n", i, Inv[i])
  for (unsigned i(1); i <= Mx; ++i)
    Bi[i] = ((Bi[i - 1] * Fac[n - S * (i - 1)] % Mod) * Inv[S] % Mod) * Inv[n - S * i] % Mod;
  for (unsigned i(0); i <= Mx; ++i)
    f[i] = (((Bi[i] * Fac[m] % Mod) * Inv[i] % Mod) * Inv[m - i] % Mod) * Pow(m - i, n - i * S) % Mod;
  for (unsigned i(0); i <= Mx; ++i) a[i] = (i & 1) ? (Mod - Inv[i]) : Inv[i];
  for (unsigned i(0); i <= Mx; ++i) b[Mx - i] = Fac[i] * f[i] % Mod;
  Len = Mx + Mx + 1;
  // Len = 4;
  // a[0] = 1, a[1] = 2, b[0] = 2, b[1] = 1;
  while (l < Len) l <<= 1;
  W = Pow(3, (Mod - 1) / l), IW = Pow(W, Mod - 2), DIF(a), DIF(b);
  for (unsigned i(0); i < l; ++i) a[i] = a[i] * b[i] % Mod;
  Ive = 1, DIT(a), W = Pow(l, Mod - 2);
  for (unsigned i(0); i <= Mx; ++i) b[Mx - i] = (a[i] * W % Mod) * Inv[Mx - i] % Mod;
  // for (unsigned i(0); i < l; ++i) b[i] = a[i] * W % Mod;
  // for (unsigned i(0); i <= Mx; ++i) printf("%llu ", b[i]); putchar(0x0A);
  for (unsigned i(0); i <= Mx; ++i) Ans = (Ans + b[i] * RD()) % Mod;
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
8 3 3
9388800 + 7247296 + 564480
*/