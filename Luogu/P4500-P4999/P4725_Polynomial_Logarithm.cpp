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
#define Inv(x) Pow(x,998244351)
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
const unsigned long long Mod(998244353);
unsigned long long MulIn[262145], WPool[1048576], * W[2][19], * PTp(WPool);
unsigned a[262144], n, Lgn(0), m(1);
inline void Mn(unsigned& x) { x -= (x >= Mod ? Mod : 0); }
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline void CalcW(unsigned long long** x, unsigned long long w) {
  (x[Lgn] = PTp)[0] = 1, PTp += m;
  for (unsigned i(1); i < m; ++i) x[Lgn][i] = x[Lgn][i - 1] * w % Mod;
  for (unsigned i(Lgn - 1), j(m >> 1); ~i; --i, j >>= 1) {
    x[i] = PTp, PTp += j;
    for (unsigned k(0); k < j; ++k) x[i][k] = x[i + 1][k << 1];
  }
}
inline void Init() {
  n = RD();
  for (unsigned i(0);i < n; ++i) a[i] = RD();
  while (m < n) { m <<= 1, ++Lgn; }
  unsigned long long w(Pow(3, 998244352 / (m <<= 1)));
  ++Lgn, CalcW(W[0], w), CalcW(W[1], Inv(w)), --Lgn, MulIn[0] = MulIn[1] = 1;
  for (unsigned i(2); i <= m; ++i) MulIn[i] = (Mod - MulIn[Mod % i]) * (Mod / i) % Mod;
}
inline void DIT(unsigned* f, unsigned Lg) {
  unsigned Len(1 << Lg);
  for (unsigned i(1), j(1), k(Len >> 1); i <= Lg; ++i, j <<= 1, k >>= 1) {
    for (unsigned Ot(0); Ot < k; ++Ot) {
      unsigned long long* w(W[1][i]);
      unsigned* F(f + (Ot << i));
      for (unsigned In(0); In < j; ++In, ++w) {
        unsigned long long TmpA(F[In]), TmpB(F[In ^ j] * (*w) % Mod);
        Mn(F[In] = TmpA + TmpB);
        Mn(F[In ^ j] = Mod + TmpA - TmpB);
      }
    }
  }
}
inline void DIF(unsigned* f, unsigned Lg) {
  unsigned Len(1 << Lg);
  for (unsigned i(Lg), j(1), k(Len >> 1); i; --i, j <<= 1, k >>= 1) {
    for (unsigned Ot(0); Ot < j; ++Ot) {
      unsigned long long* w(W[0][i]);
      unsigned* F(f + (Ot << i));
      for (unsigned In(0); In < k; ++In, ++w) {
        // printf("%u, %u, %u, %u, %u\n", i, j, k, Ot, In);
        unsigned long long TmpA(F[In]), TmpB(F[In ^ k]);
        Mn(F[In] = TmpA + TmpB);
        F[In ^ k] = (Mod + TmpA - TmpB) * (*w) % Mod;
      }
    }
  }
}
unsigned InvPool[786432], * Inva(InvPool);
inline void Inver(unsigned* f, unsigned Lg) {
  unsigned* g(InvPool), * Dbg(InvPool + m), * F(InvPool + (m << 1));
  // printf("Faq\n");
  memset(F, 0, m << 2), memset(g, 0, m << 2), g[0] = Inv(f[0]);
  for (unsigned i(1), j(2); i <= Lg; ++i, j <<= 1) {
    unsigned Len(j << 1);
    unsigned long long IvL(Mod - MulIn[Len]);
    for (unsigned k(0); k < j; ++k) Mn(Dbg[k] = g[k] << 1);
    memcpy(F, f, j << 2), memset(F + j, 0, j << 2);
    DIF(g, i + 1), DIF(F, i + 1);
    for (unsigned k((j << 1) - 1); ~k; --k) F[k] = F[k] * ((unsigned long long)g[k] * g[k] % Mod) % Mod;
    DIT(F, i + 1);
    for (unsigned k(0); k < j; ++k) g[k] = (Dbg[k] + F[k] * IvL) % Mod;
    memset(g + j, 0, j << 2);
  }
  // for (unsigned i(0); i < n; ++i) printf("%u ", g[i]); putchar(0x0A);
}
inline void Derivative(unsigned* f, unsigned Len) {
  for (unsigned long long i(1); i < Len; ++i) f[i - 1] = f[i] * i % Mod;
}
inline void Integral(unsigned* f, unsigned Len) {
  for (unsigned i(Len); i; --i) f[i] = (unsigned long long)f[i - 1] * MulIn[i] % Mod;
  f[0] = 0;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Init();
  Inver(a, Lgn), Derivative(a, n), a[n - 1] = 0;
  DIF(a, Lgn + 1), DIF(Inva, Lgn + 1);
  for (unsigned i(0); i < m; ++i) a[i] = (unsigned long long)a[i] * Inva[i] % Mod;
  DIT(a, Lgn + 1);
  unsigned long long InvM(MulIn[m]);
  for (unsigned i(0); i < m; ++i) a[i] = a[i] * InvM % Mod;
  Integral(a, n);
  for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  // unsigned b[100];
  // for (unsigned i(0); i < n; ++i) b[i] = RD();
  // DIF(a, Lgn), DIF(b, Lgn);
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  // for (unsigned i(0); i < n; ++i) printf("%u ", b[i]); putchar(0x0A);
  // for (unsigned i(0); i < n; ++i) a[i] = (unsigned long long)a[i] * b[i] % Mod;
  // DIT(a, Lgn);
  // for (unsigned i(0); i < n; ++i) a[i] = a[i] * Inv(n >> 1) % Mod;
  // for (unsigned i(0); i < n; ++i) printf("%u ", a[i]); putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
8
1 2 3 4 0 0 0 0
5 6 7 8 0 0 0 0
5 16 34 60 61 52 32 0
*/