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
#include <string>
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
int f[10005], Ans(0);
unsigned m, n; 
unsigned Ca, Cb, a[10005], b[10005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Bel[10005];
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(Ca = RD()); i; --i) Bel[a[i] = RD()] = 1;
  for (unsigned i(Cb = RD()); i; --i) Bel[b[i] = RD()] = 2;
  sort(a + 1, a + Ca + 1);
  sort(b + 1, b + Cb + 1);
  f[1] = 0;
  for (unsigned i(2); i <= m; ++i) {
    if(!Bel[i]) {f[i] = 0; continue;}
    if(Bel[i] & 1) for (unsigned j(1); j <= i - j; ++j) f[i] = max(f[i], 1 + f[j] + f[i - j]);
    else for (unsigned j(1); j <= i - j; ++j) f[i] = min(f[i], f[j] + f[i - j] - 1);
  }
//  for (unsigned i(1); i <= m; ++i) printf("%d ", f[i]); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) Ans += f[RD()];
  printf(Ans > 0 ? "Pomegranate\n" : "Orange\n");
//  }
  return Wild_Donkey;
}
