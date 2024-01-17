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
unsigned a[10005], m, n;
unsigned A, B, C, D, t, Blc(0);
unsigned Cnt(0), Ans[200005], Tmp(0);
unordered_set<unsigned> Apr[200005], Contain[200005];
vector<pair<unsigned, unsigned> > Qry[200005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    C += (A = RD());
    for (unsigned j(1); j <= A; ++j)
      B = RD(), Contain[i].insert(B), Apr[B].insert(i);
  }
  Blc = sqrt(C) + 1;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    if (Apr[A].size() < Blc) {
      for (auto j : Apr[A])
        if (Contain[j].find(B) != Contain[j].end()) ++Ans[i];
      continue;
    }
    if (Apr[B].size() < Blc) {
      for (auto j : Apr[B])
        if (Contain[j].find(A) != Contain[j].end()) ++Ans[i];
      continue;
    }
    Qry[A].push_back({B, i});
  }
  for (unsigned i(1); i <= n; ++i)
    if (Qry[i].size()) {
      for (auto j : Apr[A]) { for (unsigned) }
    }
  //  }
  //  system("pause");
  return Wild_Donkey;
}