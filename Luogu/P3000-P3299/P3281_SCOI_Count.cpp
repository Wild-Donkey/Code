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
const unsigned long long Mod(20130427);
unsigned L[100005], R[100005], n, m;
unsigned long long f[100005][2], g[100005][2], Pow[100005];
unsigned long long Tmp[100005], LtR[100005], Ans(0);
unsigned A, B, C, D, t;
unsigned Cnt(0);
//  inline void Clr() {}'
inline unsigned Calc(unsigned x) {
  return (((unsigned long long)(x) * (x - 1)) >> 1) % Mod;
}
inline int Do(unsigned* Md, unsigned Len) {
  f[Len + 1][1] = f[Len + 1][0] = g[Len + 1][1] = 0;
  g[Len + 1][0] = 0;
  unsigned long long DRt(0);
  LtR[Len + 1] = 0, Tmp[0] = 1;
  for (unsigned i(1); i <= Len; ++i) Tmp[i] = (Tmp[i - 1] + Md[i] * Pow[i - 1]) % Mod;
  for (unsigned i(Len); i; --i) LtR[i] = (LtR[i + 1] * B + Md[i]) % Mod;
  for (unsigned i(Len); i; --i) {
    f[i][0] = (((f[i + 1][0] * B % Mod) * B) + Calc(B) * (g[i + 1][0] + LtR[i + 1])) % Mod;
    if (Md[i]) f[i][0] = (f[i][0] + (f[i + 1][1] * Md[i] % Mod) * B + Calc(Md[i]) * (g[i + 1][1] + 1)) % Mod;
    g[i][0] = (g[i + 1][0] * B + g[i + 1][1] * Md[i] + LtR[i + 1] * B + Md[i] - 1) % Mod;
    f[i][1] = (f[i + 1][1] * B + Md[i] * (g[i + 1][1] + 1)) % Mod;
    g[i][1] = g[i + 1][1] + 1;
    DRt = (DRt + f[i][0] * Pow[i - 1] + f[i][1] * Tmp[i - 1]) % Mod;
    // printf("%u : %llu * %llu + %llu * %llu\n", i, f[i][0], Pow[i - 1], f[i][1], Tmp[i - 1]);
    // printf("%u : %llu %llu\n", i, g[i][0], g[i][1]);
  }
  return DRt % Mod;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  B = RD(), n = RD(), Pow[0] = 1;
  for (unsigned i(1); i <= 100000; ++i) Pow[i] = Pow[i - 1] * B % Mod;
  for (unsigned i(n); i; --i) L[i] = RD();
  if ((n == 1) && (!(L[1]))) Ans = 0;
  else {
    for (unsigned i(1); i <= n; ++i) {
      if (L[i]) { --L[i];break; }
      L[i] = B - 1;
    }
    if (!L[n]) --n;
    Ans = Do(L, n);
  }
  m = RD();
  for (unsigned i(m); i; --i) R[i] = RD();
  Ans = Mod + Do(R, m) - Ans;
  printf("%llu\n", Ans % Mod);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
10
3 1 0 0
3 1 0 0
*/