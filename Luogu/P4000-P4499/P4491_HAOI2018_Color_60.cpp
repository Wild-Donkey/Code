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
const unsigned long long Mod(1004535809);
unsigned long long Tmp, Fac[10000005], Inv[10000005];
unsigned long long f[100005], g[100005], Bi[100005], Ans(0);
unsigned m, n, Mx, S, mn;
unsigned A, B, C, D, t;
unsigned Cnt(0);
unsigned long long Pow(unsigned long long x, unsigned long long y) {
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
  n = RD(), m = RD(), S = RD(), Mx = min(n / S, m), mn = max(n, m);
  Bi[0] = Fac[0] = 1;
  for (unsigned i(1); i <= mn; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[mn] = Pow(Fac[mn], Mod - 2);
  for (unsigned i(mn - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  // for (unsigned i(1); i <= n; ++i) printf("%u %llu\n", i, Inv[i])
  for (unsigned i(1); i <= Mx; ++i)
    Bi[i] = ((Bi[i - 1] * Fac[n - S * (i - 1)] % Mod) * Inv[S] % Mod) * Inv[n - S * i] % Mod;
  for (unsigned i(0); i <= Mx; ++i)
    f[i] = (((Bi[i] * Fac[m] % Mod) * Inv[i] % Mod) * Inv[m - i] % Mod) * Pow(m - i, n - i * S) % Mod;
  for (unsigned i(0); i <= Mx; ++i) for (unsigned j(i); j <= Mx; ++j) {
    if ((j - i) & 1) g[i] = (Mod + g[i] - ((f[j] * Fac[j] % Mod) * Inv[i] % Mod) * Inv[j - i] % Mod) % Mod;
    else  g[i] = (g[i] + ((f[j] * Fac[j] % Mod) * Inv[i] % Mod) * Inv[j - i]) % Mod;
  }
  // for (unsigned i(0); i <= Mx; ++i) printf("%u, Bi: %llu, f: %llu, g: %llu\n", i, Bi[i], f[i], g[i]);
  for (unsigned i(0); i <= m; ++i) Ans = (Ans + g[i] * RD()) % Mod;
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
8 3 3
9388800 + 7247296 + 564480
*/