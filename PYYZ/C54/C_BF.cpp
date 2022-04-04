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
unsigned long long f[10005], g[10005];
unsigned long long Ans(1), Tmp(0);
unsigned A, B, C, D, t, m, n;
inline unsigned long long Pow (unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
inline unsigned Gcd(unsigned x, unsigned y) {
  unsigned TmpG;
  while (y) TmpG = x, x = y, y = TmpG % y;
  return x;
}
inline void DFS(unsigned Dep, unsigned G, unsigned long long Pi, unsigned Mx) {
  if(Dep == n) {
//    Ans = Ans * Pow(Pi, G) % Mod;
//    printf("%u %llu %u, F %llu\n", G, Pi, Mx, f[Mx]);
    if(G == 1) f[Mx] = f[Mx] * Pi % Mod, ++g[Mx];
    return;
  }
  for (unsigned i(1); i <= m; ++i) DFS(Dep + 1, Gcd(G, i), Pi * (i / Gcd(Pi, i)) % Mod, max(Mx, i));
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(0); i <= m; ++i) f[i] = 1;
  DFS(0, 0, 1, 0);
  for (unsigned i(1); i <= m; ++i) f[i] = f[i] * f[i - 1] % Mod, g[i] += g[i - 1];
  for (unsigned i(1); i <= m; ++i) printf("%u f %llu g %llu\n", i, f[i], g[i]);
  for (unsigned i(1); i <= m; ++i) Ans = Ans * Pow(f[m / i] * Pow(i, g[m / i]) % Mod, i) % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

