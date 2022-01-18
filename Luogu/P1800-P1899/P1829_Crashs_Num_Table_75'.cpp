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
const long long Mod(20101009), Inv(15075757);
long long Ans(0), Tmp(0);
int Mu[10000005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Prime[1000005], Cnt(0);
bitset<10000005> No;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Mu[1] = 1; if (n > m) swap(n, m);
  for (unsigned i(2); i <= m; ++i) {
    if (!No[i]) Prime[++Cnt] = i, Mu[i] = -1;
    for (unsigned j(1), Des(i << 1); (j <= Cnt) && (Des <= m); ++j, Des = Prime[j] * i) {
      No[Des] = 1, Mu[Des] = Mu[i] * Mu[Prime[j]];
      if (!(i % Prime[j])) { Mu[Des] = 0; break; }
    }
  }
  for (unsigned i(1); i <= n; ++i, Tmp = 0) {
    long long Nd(n / i), Md(m / i);
    for (long long j(Nd), Sq(Nd* Nd% Mod), Nk, Mk; j; --j, Sq = j * j % Mod)
      Nk = Nd / j, Mk = Md / j, Tmp = (Tmp + (((((Mu[j] * Sq % Mod) * (Nk + 1) % Mod) * (Mk + 1) % Mod) * Nk % Mod) * Mk % Mod) * Inv) % Mod;
    Ans = (Ans + i * Tmp) % Mod;
  }
  printf("%lld\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}