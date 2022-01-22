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
unsigned long long a[305][305], Tms(1);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(1);
char Opt;
inline unsigned long long Pow(unsigned long long x, unsigned y) {
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
  n = RD() - 1, m = RD(), Opt = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD() - 1, B = RD() - 1, C = RD();
    if (A ^ B) {
      a[B][B] += C, a[A][B] += Mod - C;
      if (!Opt) a[A][A] += C, a[B][A] += Mod - C;
    }
  }
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) a[i][j] %= Mod;
  // for (unsigned i(1); i <= n; ++i) { for (unsigned j(1); j <= n; ++j) printf("%llu ", a[i][j]); putchar(0x0A); }
  // system("pause");
  for (unsigned i(1); i <= n; ++i) {
    unsigned No(i);
    while ((No <= n) && (!a[No][i])) ++No;
    if (No > n) { printf("0\n"); return 0; }
    if (No ^ i) { for (unsigned j(i); j <= n; ++j) swap(a[No][j], a[i][j]); Tms = Mod - Tms; }
    for (unsigned j(i + 1); j <= n; ++j) {
      unsigned long long Tmp(a[j][i] * (Mod - Pow(a[i][i], Mod - 2)) % Mod);
      for (unsigned k(i); k <= n; ++k) a[j][k] = (a[j][k] + a[i][k] * Tmp) % Mod;
    }
  }
  for (unsigned i(1); i <= n; ++i) Ans = Ans * a[i][i] % Mod;
  printf("%llu\n", Ans * Tms % Mod);
  //  }
  system("pause");
  return Wild_Donkey;
}