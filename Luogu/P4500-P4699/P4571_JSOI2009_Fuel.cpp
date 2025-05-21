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
#include <unordered_set>
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
unsigned a[1005], m, n;
unsigned A, B, C, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unordered_set<unsigned> D;
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(sqrt(a[i])); j > 1; --j) {
      if (!(a[i] % j)) D.insert(j), D.insert(a[i] / j);
    }
    D.insert(a[i]);
  }
  D.insert(1);
  for (auto i : D) {
    Cnt = 0;
    for (unsigned j(1); j <= n; ++j)
      if (!(a[j] % i)) ++Cnt;
    if (Cnt >= m) Ans = max(Ans, i);
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}