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
unsigned long long C1[160005], IFac[160005], MFac[160005], A[530000], B[530000];
unsigned long long Tmp(1), w;
unsigned m, n, N(1);
unsigned D, t;
unsigned Cnt(0), Ans(0);
inline void Mn(unsigned long long& x) { x -= ((x >= Mod) ? Mod : 0); }
inline unsigned long long W(unsigned x) {
  unsigned long long Now(3), Rt(1);
  while (x) { if (x & 1) Rt = Rt * Now % Mod;  Now = Now * Now % Mod, x >>= 1; }
  return Rt;
}
inline unsigned long long Inv(unsigned long long x) {
  unsigned long long Rt(1);
  unsigned y(998244351);
  while (y) { if (y & 1) Rt = Rt * x % Mod;y >>= 1, x = x * x % Mod; }
  return Rt;
}
inline void DIT(unsigned long long* f) {
  unsigned long long Now(1), Tmpw[20];
  unsigned Lg(0);
  Tmpw[0] = w;
  for (unsigned i(1); i < N; i <<= 1, ++Lg) Tmpw[Lg + 1] = Tmpw[Lg] * Tmpw[Lg] % Mod; --Lg;
  for (unsigned i(1); i < N; i <<= 1, --Lg) {
    for (unsigned j(0); j < N; ++j, Now = Now * Tmpw[Lg] % Mod) if (!(i & j)) {
      // printf("(%u, %u) %llu\n", i, j, Now);
      unsigned long long TmpA(f[j]), TmpB(f[j ^ i] * Now % Mod);
      f[j] = TmpA + TmpB, Mn(f[j]);
      f[j ^ i] = Mod + TmpA - TmpB, Mn(f[j ^ i]);
    }
  }
}
inline void DIF(unsigned long long* f) {
  unsigned long long Now(1);
  for (unsigned i(N >> 1); i; i >>= 1, w = w * w % Mod) {
    for (unsigned j(0); j < N; ++j, Now = Now * w % Mod) if (!(i & j)) {
      unsigned long long TmpA(f[j]), TmpB(f[j ^ i]);
      f[j] = TmpA + TmpB, Mn(f[j]);
      f[j ^ i] = (Mod + TmpA - TmpB) * Now % Mod;
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
  n = RD(), m = RD();
  while (N <= n) { N <<= 1; } N <<= 1;
  for (unsigned i(0); i <= n; ++i) A[i] = RD();
  for (unsigned i(1); i <= n; ++i) Tmp = Tmp * i % Mod;
  IFac[n] = Inv(Tmp);
  for (unsigned i(n - 1); ~i; --i) IFac[i] = IFac[i + 1] * (i + 1) % Mod;
  for (unsigned i(0); i <= n; ++i)
    A[i] = ((((n - i) & 1) ? (Mod - A[i]) : A[i]) * IFac[n - i] % Mod) * IFac[i] % Mod;
  C1[0] = 1;
  for (unsigned i(m - n); i <= m; ++i) C1[0] = C1[0] * i % Mod;
  for (unsigned i(1); i <= n; ++i) C1[i] = (C1[i - 1] * Inv(m - n + i - 1) % Mod) * (m + i) % Mod;
  for (unsigned i(n << 1); ~i; --i) B[i] = Inv(m + i - n);
  // for (unsigned i(0); i < N; ++i) printf("%llu ", A[i]); putchar(0x0A);
  // for (unsigned i(0); i < N; ++i) printf("%llu ", B[i]); putchar(0x0A);
  // N = 8, memset(A, 0, 64), memset(B, 0, 64), A[0] = 2, B[0] = 3;
  w = W(998244352 / N), DIF(A), w = W(998244352 / N), DIF(B);
  for (unsigned i(0); i < N; ++i) A[i] = A[i] * B[i] % Mod;
  w = Inv(W(998244352 / N)), DIT(A), w = Inv(N), N = (n << 1);
  // for (unsigned i(0); i < N; ++i) printf("%llu ", A[i] * w % Mod); putchar(0x0A);
  // printf("%u\n", N);
  // for (unsigned i(0); i <= N; ++i) printf("%llu ", A[i] * w % Mod); putchar(0x0A);
  for (unsigned i(n); i <= N; ++i) printf("%llu ", (C1[i - n] * A[i] % Mod) * w % Mod); putchar(0x0A);
  //  }
//  system("pause");
  return Wild_Donkey;
}