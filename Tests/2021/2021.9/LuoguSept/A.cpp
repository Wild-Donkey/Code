#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[100005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline void Clr() {
  n = RD(), m = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T) {
    Clr();
    if (m == 0 || m >= n - 1) { for (register unsigned i(n); i; --i) printf("%u ", i); putchar('\n'); continue; }
    for (unsigned i(1); i <= m; ++i) a[i] = i;
    for (unsigned i(m + 1); i <= n; ++i) a[i] = n + m - i + 1;
    if (m <= (n >> 1)) for (unsigned i(1); (i <= m) && (i + m <= n); ++i) swap(a[m + i], a[i]);
    else for (unsigned i(1); i <= m; ++i) swap(a[i], a[i + n - m]);
    for (register unsigned i(1); i <= n; ++i) printf("%u ", a[i]); putchar('\n');
  }
  system("pause");
  return Wild_Donkey;
}