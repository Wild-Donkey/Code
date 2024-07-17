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
#define Mn(x) (x)-=(((x)>=Mod)?Mod:0)
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
unsigned long long a[131105], b[131105];
unsigned long long PriR[524300], *PR[20][2], W, Inv[20];
unsigned m(1), Lgm(0), n, CurLen, CurLg;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char Tp(0);
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;  
}
inline void DIT(unsigned long long* f) {
//  printf("DIT %u Lg %u\n", CurLen, CurLg);
  for (unsigned i(1), j(1), l(1); i < CurLen; i <<= 1, ++j, l = ((l << 1) | 1)) {
    for (unsigned k(0); k < CurLen; ++k) if(!(i & k)) {
//      printf("%u Sqrt %llu\n", k, PR[j][Tp][k & l]);
      unsigned long long TmA(f[k]), TmB(f[k ^ i] * PR[j][Tp][k & l] % Mod);
      f[k] = TmA + TmB, Mn(f[k]);
      f[k ^ i] = Mod + TmA - TmB, Mn(f[k ^ i]);
    }
  }
}
inline void DIF(unsigned long long* f) {
//  printf("DIF %u Lg %u\n", CurLen, CurLg);
  for (unsigned i(CurLen >> 1), j(CurLg), l((1 << CurLg) - 1); i; i >>= 1, --j, l >>= 1) {
    for (unsigned k(0); k < CurLen; ++k) if(!(i & k)) {
//      printf("%u Sqrt %llu\n", k, PR[j][Tp][k & l]);
      unsigned long long TmA(f[k]), TmB(f[k ^ i]);
      f[k] = TmA + TmB, Mn(f[k]);
      f[k ^ i] = PR[j][Tp][k & l] * (Mod + TmA - TmB) % Mod;
    }
  }
}
inline void Mul (unsigned long long* f, unsigned long long* g, unsigned long long* fg) {
  //Optimize: Small Block
  if(CurLen <= 32) {
    memset(fg + (CurLen >> 1), 0, CurLen << 2);
    for (unsigned i(CurLen >> 1); i < CurLen; ++i)
      for (unsigned j((CurLen >> 1) - 1); ~j; --j)
        fg[i] = (fg[i] + g[j] * f[i - j]) % Mod;
    return;
  }
  unsigned long long G[CurLen];
  memset(G, 0, CurLen << 3);
  memcpy(G, g, CurLen << 2);
  memcpy(fg, f, CurLen << 3);
//  printf("Mul Len %u Lg %u\n", CurLen, CurLg);
//  for (unsigned i(0); i < CurLen; ++i) printf("%llu ", G[i]); putchar(0x0A);
//  for (unsigned i(0); i < CurLen; ++i) printf("%llu ", fg[i]); putchar(0x0A);
  Tp = 0, DIF(G), DIF(fg);
  for (unsigned i(0); i < CurLen; ++i) fg[i] = fg[i] * G[i] % Mod;
  Tp = 1, DIT(fg);
  for (unsigned i(0); i < CurLen; ++i) fg[i] = fg[i] * Inv[CurLg] % Mod;
//  for (unsigned i(0); i < CurLen; ++i) printf("%llu ", fg[i]); putchar(0x0A);
}
inline void Solve(unsigned L, unsigned Len) {
  if(Len == 1) {CurLg = 1; return;}
  Len >>= 1, Solve(L, Len);
  unsigned long long STm[CurLen = (Len << 1)], *Rt(STm + Len), *G(b + L + Len);
  Mul(a, b + L, STm);
  for (unsigned i(0); i < Len; ++i) G[i] += Rt[i], Mn(G[i]);
  Solve(L + Len, Len);
  ++CurLg;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr(); 
  n = RD(), a[0] = 0, b[0] = 1;
  while (m < n) m <<= 1, ++Lgm;
  W = Pow(3, 998244352 / m);
  *(PR[Lgm][0] = PriR) = 1,  *(PR[Lgm][1] = PR[Lgm][0] + m) = 1;
  for (unsigned i(1), j(0); i <= m; i <<= 1, ++j) Inv[j] = Inv(i);
//  for (unsigned j(0); j <= Lgm; ++j) printf("%llu ", Inv[j]); putchar(0x0A);
  for (unsigned i(1); i < m; ++i) PriR[i] = PriR[i - 1] * W % Mod;
  for (unsigned i(1); i < m; ++i) PR[Lgm][1][i] = PriR[m - i] % Mod;
//  printf("Prime Root %u\n", m); for (unsigned i(0); i < m; ++i) printf("%u ", PriR[i]); putchar(0x0A);
  for (unsigned i(m >> 1), k(Lgm - 1); ~k; i >>= 1, --k) {
    PR[k][0] = PR[k + 1][1] + (i << 1);
    for (unsigned l(0); l < i; ++l) PR[k][0][l] = PR[k + 1][0][l << 1];
    PR[k][1] = PR[k][0] + i;
    for (unsigned l(0); l < i; ++l) PR[k][1][l] = PR[k + 1][1][l << 1];
  }
  for (unsigned i(1); i < n; ++i) a[i] = RD();
  CurLen = m, Solve(0, m);
  for (unsigned i(0); i < n; ++i) printf("%llu ", b[i]); putchar(0x0A);
//  }
  return Wild_Donkey;
}
/*
4
1 0 0 0
*/

