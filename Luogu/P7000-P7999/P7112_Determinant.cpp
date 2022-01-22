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
unsigned long long Gcd(unsigned long long x, unsigned long long y) {
  unsigned long long SwT;
  while (y) SwT = x, x = y, y = SwT % y;
  return x;
}
unsigned long long a[605][605], Mod, G, Tms(1), Ans(1);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
inline void Dec(unsigned long long* f, unsigned long long* g, unsigned x) {
  while (g[x]) {
    unsigned long long Tmp(Mod - (f[x] / g[x]));
    for (unsigned i(x); i <= n; ++i) f[i] = (f[i] + g[i] * Tmp) % Mod;
    for (unsigned i(x); i <= n; ++i) swap(f[i], g[i]);
    Tms = Mod - Tms;
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Mod = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) a[i][j] = RD() % Mod;
  if (n == 1) { printf("%llu\n", a[1][1]);return 0; }
  for (unsigned i(1); i <= n; ++i) {
    G = Gcd(a[i][1], a[i][2]);
    for (unsigned j(3); j <= n; ++j) G = Gcd(G, a[i][j]);
    if (G > 1) for (unsigned j(1); j <= n; ++j) a[i][j] /= G;
    Tms = Tms * G % Mod;
  }
  for (unsigned i(1); i <= n; ++i) {
    G = Gcd(a[1][i], a[2][i]);
    for (unsigned j(3); j <= n; ++j) G = Gcd(G, a[j][i]);
    if (G > 1) for (unsigned j(1); j <= n; ++j) a[j][i] /= G;
    Tms = Tms * G % Mod;
  }
  // printf("%llu\n", Tms);
  for (unsigned i(1); i <= n; ++i) for (unsigned j(n); j > i; --j) if (a[j][i]) Dec(a[j - 1], a[j], i);
  // for (unsigned i(1); i <= n; ++i) { for (unsigned j(1); j <= n; ++j) printf("%llu ", a[i][j]); putchar(0x0A); }
  for (unsigned i(1); i <= n; ++i) Ans = Ans * a[i][i] % Mod;
  printf("%llu\n", Ans * Tms % Mod);
  //  }
  // system("pause");
  return Wild_Donkey;
}