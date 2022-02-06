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
unsigned f[13005];
unsigned a[1005], Tms[1005], b[1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  memset(f, 0, (m + 1) << 2);
  n = RD(), m = RD(), A = Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  memset(Tms, 0x3f, sizeof(Tms));
  t = RD(), Tms[1] = 0;
  for (unsigned i(1); i <= 1000; ++i) {
    for (unsigned j(i), Des(i + (i / j)); j && ((Des = i + (i / j)) <= 1000); --j)
      Tms[Des] = min(Tms[Des], Tms[i] + 1);
    // printf("%u %u\n", i, Tms[i]);
  }
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD(), A += Tms[a[i]];
    for (unsigned i(1); i <= n; ++i) b[i] = RD();
    m = min(A, m);
    for (unsigned i(1); i <= n; ++i) {
      for (unsigned j(m); (~j) && (j >= Tms[a[i]]); --j) {
        f[j] = max(f[j], f[j - Tms[a[i]]] + b[i]);
      }
    }
    printf("%u\n", f[m]);
  }
  // system("pause");
  return Wild_Donkey;
}