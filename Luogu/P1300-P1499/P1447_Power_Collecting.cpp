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
long long Mu[100005], Ans(0), Tmp(0);
unsigned Prime[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
bitset<100005> Isnt;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Mu[1] = 1;
  if (n < m) swap(n, m);
  for (unsigned i(2); i <= n; ++i) {
    if (!Isnt[i]) Prime[++Cnt] = i, Mu[i] = -1;
    for (unsigned j(1); (j <= Cnt) && (Prime[j] * i <= n); ++j) {
      unsigned Des(Prime[j] * i);
      Isnt[Des] = 1, Mu[Des] = Mu[Prime[j]] * Mu[i];
      if (!(i % Prime[j])) { Mu[Des] = 0; break; }
    }
  }
  for (unsigned i(1); i <= m; ++i, Tmp = 0) {
    for (unsigned j(m / i), Nd(n / i), Md(m / i); j; --j) Tmp += Mu[j] * (Nd / j) * (Md / j);
    Ans += i * Tmp;
  }
  // printf("%llu\n", Ans);
  printf("%llu\n", (Ans << 1) - ((unsigned long long)n * m));
  //  }
  // system("pause");
  return Wild_Donkey;
}