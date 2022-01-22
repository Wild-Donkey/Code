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
long long f[50005], Mu[50005], Ans(0), Tmp(0);
unsigned Prime[50005], Cnt(0), m, n;
unsigned A, B, C, D, t;
bitset<50005> No;
inline void Clr() {
  n = RD(), m = RD(), Ans = 0; if (m < n) swap(n, m);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (unsigned i(1); i <= 50000; ++i) for (unsigned L(0), R(0), Div(0); R < i;)
    L = R + 1, Div = i / L, R = i / Div, f[i] += (R - L + 1) * Div;// printf("%u [%u, %u]\n", i, L, R);
  for (unsigned i(2); i <= 50000; ++i) {
    if (!No[i]) Prime[++Cnt] = i, Mu[i] = -1;
    for (unsigned j(1), Des(i* Prime[j]); (j <= Cnt) && (Des <= 50000); ++j, Des = i * Prime[j]) {
      No[Des] = 1, Mu[Des] = Mu[i] * Mu[Prime[j]];
      if (!(i % Prime[j])) { Mu[Des] = 0; break; }
    }
  }
  t = RD(), Mu[1] = 1;
  for (unsigned i(2); i <= 50000; ++i) Mu[i] += Mu[i - 1];
  // for (unsigned i(1); i <= 100; ++i) printf("%lld ", f[i]); putchar('\n');
  // for (unsigned i(1); i <= 100; ++i) printf("%lld ", Mu[i]); putchar('\n');
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned L(0), R(0); R < n;)
      L = R + 1, A = n / L, B = m / L, R = min(n / A, m / B), Ans += (Mu[R] - Mu[L - 1]) * f[A] * f[B];
    printf("%lld\n", Ans);
  }
  // system("pause");
  return Wild_Donkey;
}