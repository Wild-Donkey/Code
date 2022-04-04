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
const unsigned Mod(998244353);
unsigned a[132005], b[132005], m, n;
unsigned long long Iv;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Type(0);
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
inline unsigned long long Inv(unsigned long long x) {
  unsigned long long Rt(1);
  unsigned y(998244351);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline void DIF (unsigned *f) {
  for (unsigned i(n >> 1); i; i >>= 1) {
    for (unsigned j(0); j < n; ++j) if(!(j & i)) {
      unsigned Tma(f[j]), Tmb(f[j ^ i]);
      if(Type == 1) { Mn(f[j ^ i] += Tma); continue;}
      if(Type == 2) { Mn(f[j] += Tmb); continue;}
      Mn(f[j] += Tmb);
      Mn(f[j ^ i] = Mod + Tma - Tmb);
    }
  }
}
inline void DIT (unsigned *f) {
  for (unsigned i(1); i < n; i <<= 1) {
    for (unsigned j(0); j < n; ++j) if(!(j & i)) {
      unsigned Tma(f[j]), Tmb(f[j ^ i]);
      if(Type == 1) { Mn(f[j ^ i] += Mod - Tma); continue;}
      if(Type == 2) { Mn(f[j] += Mod - Tmb); continue;}
      Mn(f[j] += Tmb);
      Mn(f[j ^ i] = Mod + Tma - Tmb);
    }
  }
}
inline void Calc () {
  unsigned Ta[n], Tb[n];
  memcpy(Ta, a, n << 2);
  memcpy(Tb, b, n << 2);
  DIF(Ta), DIF(Tb);
//  for (unsigned i(0); i < n; ++i) printf("%u ", Ta[i]); putchar(0x0A);
//  for (unsigned i(0); i < n; ++i) printf("%u ", Tb[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) Ta[i] = (unsigned long long)Ta[i] * Tb[i] % Mod;
  DIT(Ta);
  if(Type == 3) for (unsigned i(0); i < n; ++i) Ta[i] = Ta[i] * Iv % Mod;
  for (unsigned i(0); i < n; ++i) printf("%u ", Ta[i]); putchar(0x0A);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Iv = Inv(n = (1 << (m = RD())));
  for (unsigned i(0); i < n; ++i) a[i] = RD();
  for (unsigned i(0); i < n; ++i) b[i] = RD();
  Type = 1, Calc();
  Type = 2, Calc();
  Type = 3, Calc();
//  }
  return Wild_Donkey;
}

