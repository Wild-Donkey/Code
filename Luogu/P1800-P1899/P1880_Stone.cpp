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
#define foreplay for
#define wild while
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
unsigned f[105][205], g[105][205], a[205], m, n;
unsigned A, B, C, D, t;
unsigned Ansl(0x3f3f3f3f), Ansr(0);
unsigned Sum(unsigned L, unsigned R) { return a[R] - a[L - 1]; }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = (n << 1) - 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  memcpy(a + (n + 1), a + 1, ((n - 1) << 2));
  for (unsigned i(1); i <= m; ++i) a[i] += a[i - 1];
  for (unsigned Len(2); Len <= n; ++Len) {
    memset(f[Len], 0x3f, (m + 1) << 2);
    for (unsigned l(m - Len + 1), r(m); l; --l, --r) {
      for (unsigned k(1); k < Len; ++k) {
        f[Len][l] = min(f[k][l] + f[Len - k][l + k], f[Len][l]);
        g[Len][l] = max(g[k][l] + g[Len - k][l + k], g[Len][l]);
      }
      f[Len][l] += Sum(l, r);
      g[Len][l] += Sum(l, r);
      // printf("(%u, %u) %u %u\n", l, r, f[Len][l], g[Len][l]);
    }
  }
  for (unsigned i(1); i <= n; ++i)
    Ansl = min(Ansl, f[n][i]), Ansr = max(Ansr, g[n][i]);
  printf("%u\n%u\n", Ansl, Ansr);
  //  }
  //  system("pause");
  return Wild_Donkey;
}