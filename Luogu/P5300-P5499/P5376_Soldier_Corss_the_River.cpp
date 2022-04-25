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
const unsigned Mod(59393);
unsigned Fac[60000], Inv[60000], m, n, K;
unsigned A, B, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Mdd(const unsigned x){return (x >= Mod) ? (x - Mod) : x;}
inline unsigned Inver(unsigned x) {
  unsigned y(59391), Rt(1);
  while (y) {if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1;}
  return Rt;
}
inline unsigned Lucas(unsigned x, unsigned y) {
  if(x < y) return 0;
  if(x < Mod) return (Fac[x] * Inv[y] % Mod) * Inv[x - y] % Mod;
  return Lucas(x / Mod, y / Mod) * Lucas(x % Mod, y % Mod) % Mod;
}
inline unsigned F(unsigned x, unsigned y) {
  if(x > y) swap(x, y);
  unsigned Rt(0);
  for (unsigned i(0); i <= x; ++i) Rt = (Rt + Lucas(x + y - i, x) * Lucas(x, i)) % Mod;
  return Rt;
}
inline unsigned G(unsigned x, unsigned y) {return F(y - 1, x);}
struct NotAva{
  unsigned X, Y, g;
  const inline char operator<(const NotAva& x) {return (X ^ x.X) ? (X < x.X) : (Y < x.Y);}
  inline unsigned F() {return ::F(X - 1, Y - 1); }
  inline unsigned F(const NotAva& x) const {return ::F(X - x.X, Y - x.Y);}
}a[21];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Fac[0] = 1;
  for (unsigned i(1); i < Mod; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[Mod - 1] = Inver(Fac[Mod - 1]);
  for (unsigned i(Mod - 1); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  n = RD(), m = RD(), K = RD();
  for (unsigned i(1); i <= K; ++i) a[i].X = RD(), a[i].Y = RD();
  sort(a + 1, a + K + 1);
  a[0] = {n, m, 0}, a[0].g = a[0].F();
//  printf("F0 %u\n", a[0].g);
  for (unsigned i(1); i <= K; ++i) {
    a[i].g = a[i].F();
    for (unsigned j(1); j < i; ++j) if(a[j].Y <= a[i].Y) a[i].g = (a[i].g + (Mod - a[i].F(a[j])) * a[j].g) % Mod;
    a[i].g %= Mod;
    a[0].g = (a[0].g + (Mod - a[0].F(a[i])) * a[i].g) % Mod;
  }
  Ans = (G(n, m) + G(m, n) + a[0].g) % Mod;
  for (unsigned i(1); i <= K; ++i) {
    A = n - a[i].X + 1, B = m - a[i].Y + 1;
    Ans = (Ans + Mdd(G(B, A) + G(A, B)) * (Mod - a[i].g)) % Mod;
  }
//  for (unsigned i(0); i <= K; ++i) printf("%u ", a[i].g); putchar(0x0A);
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

