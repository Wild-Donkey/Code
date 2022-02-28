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
map<pair<int, int>, unsigned> f[21], g[21];
long long A, B;
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
  n = RD(), m = (n >> 1), n -= m, f[0][{0, 0}] = 1;
  A = RDsg(), B = RDsg(), g[0][{A, B}] = 1;
  for (unsigned i(1); i <= n; ++i) {
    A = RDsg(), B = RDsg();
    for (unsigned k(i - 1); ~k; --k) for (auto j : f[k]) {
      f[k + 1][{j.first.first + A, j.first.second + B}] += j.second;
    }
  }
  for (unsigned i(1); i <= m; ++i) {
    A = -RDsg(), B = -RDsg();
    for (unsigned k(i - 1); ~k; --k) for (auto j : g[k]) {
      g[k + 1][{j.first.first + A, j.first.second + B}] += j.second;
    }
  }
  // for (unsigned i(0); i <= n; ++i) for (auto j : f[i]) printf("%u (%lld, %lld) = %u\n", i, j.first.first, j.first.second, j.second);
  // for (unsigned i(0); i <= m; ++i) for (auto j : g[i]) printf("%u (%lld, %lld) = %u\n", i, j.first.first, j.first.second, j.second);
  for (unsigned i(1); i <= n + m; ++i) {
    Ans = 0;
    for (unsigned j(min(i, n)); (~j) && (i - j) <= m; --j) {
      for (auto k : f[j]) {
        Ans += (unsigned long long)k.second * g[i - j][k.first];
      }
    }
    printf("%llu\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}