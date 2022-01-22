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
const unsigned long long Mod(998244353);
unsigned long long Ans(0), Fac[200005];
unsigned a[10005], m, n, nm;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Used[200005];
//  inline void Clr() {}
inline void DFS (unsigned Dep, unsigned Now) {
  if(!Now) {Ans += Fac[nm - Dep + 1]; if(Ans >= Mod) Ans -= Mod; return;}
  if(Dep > nm) return;
  for (unsigned i(1); i <= nm; ++i) if(!Used[i]) {
    Used[i] = 1;
    if(i <= n) DFS(Dep + 1, Now / a[i]);
    else DFS(Dep + 1, Now % a[i]);
    Used[i] = 0;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  A = RD(), n = RD(), m = RD(), nm = n + m, Fac[0] = 1;
  for (unsigned i(1); i <= nm; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  for (unsigned i(1); i <= nm; ++i) a[i] = RD();
  DFS(1, A);
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

