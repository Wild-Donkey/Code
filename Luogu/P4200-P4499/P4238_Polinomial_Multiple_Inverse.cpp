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
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) {if(y & 1)Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1;}
  return Rt;
}
unsigned long long W[20], IW[20];
unsigned a[262150], b[262150], Two[20], m(1), n, Lgn(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void DIT(unsigned* f, unsigned Lg, unsigned long long* Curw) {
  unsigned Len(Two[Lg]);
  unsigned long long W_i(1);
  for (unsigned i(1), j(1); i <= Lg; ++i, j <<= 1, W_i = 1) {
    for (unsigned k(0); k < Len; ++k, W_i = W_i * Curw[i] % Mod) if (!(k & j)) {
      unsigned long long TmA(f[k]), TmB(f[k | j] * W_i % Mod);
//      printf("%u %u %u %llu\n", i, j, k, W_i);
      f[k] = TmA + TmB, Mn(f[k]);
      f[k | j] = Mod + TmA - TmB, Mn(f[k | j]);
    }
  }
}
inline void DIF(unsigned* f, unsigned Lg, unsigned long long* Curw) {
  unsigned Len(Two[Lg]);
  unsigned long long W_i(1);
  for (unsigned i(Lg), j(1 << (Lg - 1)); i; --i, j >>= 1, W_i = 1) {
    for (unsigned k(0); k < Len; ++k, W_i = W_i * Curw[i] % Mod) if (!(k & j)) {
      unsigned long long TmA(f[k]), TmB(f[k | j]);
      f[k] = TmA + TmB, Mn(f[k]);
      f[k | j] = (Mod + TmA - TmB) * W_i % Mod;
    }
  }
}
inline void Multi(unsigned* f, unsigned* g, unsigned* Rt, unsigned Lg) {
  unsigned Len(Two[Lg]);
//  printf("fg^2:\n");
//  for (unsigned i(0); i < Len; ++i) printf("%u ", f[i]); putchar(0x0A);
//  for (unsigned i(0); i < Len; ++i) printf("%u ", g[i]); putchar(0x0A);
  DIF(f, Lg, W), DIF(g, Lg, W);
  for (unsigned i(0); i < Len; ++i) 
    Rt[i] = ((unsigned long long)f[i] * g[i] % Mod) * g[i] % Mod;
//    Rt[i] = (unsigned long long)f[i] * g[i] % Mod;
  DIT(Rt, Lg, IW);
  unsigned long long InvLen(Pow(Len, 998244351));
  for (unsigned i(0); i < Len; ++i) Rt[i] = Rt[i] * InvLen % Mod;
//  for (unsigned i(0); i < Len; ++i) printf("%u ", Rt[i]); putchar(0x0A);
}
inline void Inv(unsigned* f, unsigned* Rt, unsigned Lg) {
  if(Lg == 0) {Rt[0] = Pow(f[0], 998244351); return;}
  unsigned Len(1 << Lg);
//  for(unsigned i(0); i < Len; ++i) printf("%u ", f[i]); putchar(0x0A);
  unsigned g[Len << 1];
  Inv(f, g, Lg - 1), memset(g + (Len >> 1), 0, (Len + (Len << 1)) << 1);
  memcpy(Rt, f, Len << 2), memset(Rt + Len, 0, Len << 2);
  Multi(Rt, g, Rt, Lg + 1);
  unsigned long long InvLen(Pow(1 << (Lg + 1), 998244351));
  DIT(g, Lg + 1, IW);
  for (unsigned i(0); i < Len; ++i) g[i] = g[i] * InvLen % Mod;
  for (unsigned i(0); i < Len; ++i) Rt[i] = ((g[i] << 1) + Mod - Rt[i]) % Mod;
//  for(unsigned i(0); i < (1 << Lg); ++i) printf("%u ", Rt[i]); putchar(0x0A);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Two[0] = 1;
  for (unsigned i(1); i < 20; ++i) Two[i] = (Two[i - 1] << 1);
  while (m < n) m <<= 1, ++Lgn;
  W[19] = Pow(3, 998244352 >> 19), IW[19] = Pow(W[19], 998244351);
  for (unsigned i(19); i; --i) W[i - 1] = W[i] * W[i] % Mod;
  for (unsigned i(19); i; --i) IW[i - 1] = IW[i] * IW[i] % Mod;
//  for (unsigned i(0); i <= 19; ++i) printf("%u ", W[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) a[i] = RD();
  for (unsigned i(n); i < m; ++i) a[i] = 0;
  Inv(a, b, Lgn);
  for (unsigned i(0); i < n; ++i) printf("%u ", b[i]); putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

