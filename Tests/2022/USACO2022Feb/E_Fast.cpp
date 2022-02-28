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
vector<pair<int, int> > f[21], g[21];
int a[21][2], b[21][2], A, B, DA, DB;
unsigned long long Ans(0);
unsigned m, n;
unsigned C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = (n >> 1), n -= m;
  DA = RDsg(), DB = RDsg();
  for (unsigned i(0); i < n; ++i) a[i][0] = RDsg(), a[i][1] = RDsg();
  // printf("nm %u %u\n", n, m);
  for (unsigned i((1 << n) - 1); ~i; --i) {
    Cnt = 0, A = B = 0;
    for (unsigned j(0); j < n; ++j) if ((i >> j) & 1) A += a[j][0], B += a[j][1], ++Cnt;
    // printf("%u (%d, %d)\n", i, A, B);
    f[Cnt].push_back({ A, B });
  }
  for (unsigned i(0); i < m; ++i) b[i][0] = -RDsg(), b[i][1] = -RDsg();
  for (unsigned i((1 << m) - 1); ~i; --i) {
    Cnt = 0, A = DA, B = DB;
    for (unsigned j(0); j < m; ++j) if ((i >> j) & 1) A += b[j][0], B += b[j][1], ++Cnt;
    g[Cnt].push_back({ A, B });
  }
  for (unsigned i(0); i <= n; ++i) sort(f[i].begin(), f[i].end());
  for (unsigned i(0); i <= m; ++i) sort(g[i].begin(), g[i].end());
  // for (unsigned i(0); i <= n; ++i) for (auto j : f[i]) printf("%u (%d, %d)\n", i, j.first, j.second);
  // for (unsigned i(0); i <= m; ++i) for (auto j : g[i]) printf("%u (%d, %d)\n", i, j.first, j.second);
  for (unsigned i(1); i <= n + m; ++i) {
    Ans = 0, Tmp = 0;
    for (unsigned j(min(i, n)); (~j) && (i - j) <= m; --j) {
      for (unsigned k(f[j].size() - 1), l(g[i - j].size() - 1); (~k) && (~l); --k) {
        while ((~l) && (g[i - j][l] > f[j][k])) --l;
        while ((~l) && (g[i - j][l] == f[j][k])) ++Tmp, --l;
        while ((k) && (f[j][k] == f[j][k - 1])) Ans += Tmp, --k; Ans += Tmp;
        Tmp = 0;
      }
    }
    printf("%llu\n", Ans + Tmp);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}