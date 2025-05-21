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
const unsigned long long Mod(1000000007);
unsigned long long a[405][805];
unsigned A, B, C, D, t, m, n;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1);
  while (y) { if (y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1; }
  return Rt;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  m = ((n = RD()) << 1);
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) a[i][j] = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(n + 1); j <= m; ++j) a[i][j] = 0;
  for (unsigned i(1); i <= n; ++i) a[i][n + i] = 1;
  for (unsigned i(1); i <= n; ++i) {
    unsigned No(i);
    while ((!a[No][i]) && (No <= n)) ++No;
    if (No > n) { printf("No Solution\n");return 0; }
    if (No ^ i) for (unsigned j(i); j <= m; ++j) swap(a[No][j], a[i][j]);
    for (unsigned j(i + 1); j <= n; ++j) {
      unsigned long long Tms(a[j][i] * (Mod - Pow(a[i][i], Mod - 2)) % Mod);
      for (unsigned k(i); k <= m; ++k) a[j][k] = (a[j][k] + a[i][k] * Tms) % Mod;
    }
  }
  for (unsigned i(n); i; --i) {
    if (!a[i][i]) { printf("No Solution\n");return 0; }
    unsigned long long Chg(Pow(a[i][i], Mod - 2));
    if (Chg != 1) for (unsigned j(i); j <= m; ++j) a[i][j] = a[i][j] * Chg % Mod;
    for (unsigned j(i - 1); j; --j) {
      for (unsigned k(n + 1); k <= m; ++k) a[j][k] = (a[j][k] + a[i][k] * (Mod - a[j][i])) % Mod;
      a[j][i] = 0;
    }
  }
  for (unsigned i(1); i <= n; ++i) { for (unsigned j(n + 1); j <= m; ++j) printf("%llu ", a[i][j]); putchar(0x0A); }
  //  }
  // system("pause");
  return Wild_Donkey;
}