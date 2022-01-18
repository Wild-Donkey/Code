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
unordered_map<unsigned, unsigned> f[100005];
unsigned g[100005];
unsigned a[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  for (unsigned i = 0; i <= n; ++i) f[i].clear();
  memset(g, 0, (n + 1) << 2);
  n = RD(), Ans = 0x3f3f3f3f;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    for (unsigned i(0); i < n; ++i) {
      unsigned Mx(g[i]);
      for (auto j : f[i]) {
        Mx = min(Mx, j.second);
        if (a[i + 1] > j.first) {
          if (f[i + 1].find(a[i + 1] - j.first) != f[i + 1].end())
            f[i + 1][a[i + 1] - j.first] = min(f[i + 1][a[i + 1] - j.first], j.second + 1);
          else f[i + 1][a[i + 1] - j.first] = j.second + 1;
        }
      }
      if (!(a[i + 1] & 1)) {
        if (f[i + 1].find(a[i + 1] >> 1) != f[i + 1].end()) f[i + 1][a[i + 1] >> 1] -= 1;
        else f[i + 1][a[i + 1] >> 1] = g[i] + 1;
      }
      for (auto j : f[i + 1]) if (a[i + 1] - j.first < a[i]) f[i + 1][j.first] = min(j.second, g[i] + 1);
      g[i + 1] = Mx + 2;
      if ()
    }
    for (auto i : f[n])Ans = min(Ans, i.second);
    Ans = min(Ans, g[n]);
    printf("%u\n", Ans);
  }
  system("pause");
  return Wild_Donkey;
}