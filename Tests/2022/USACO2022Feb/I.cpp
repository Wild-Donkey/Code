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
vector <pair<unsigned, unsigned> > a[11];
vector <pair<unsigned long long, pair<unsigned, unsigned> > > E;
unsigned Fa[1000005], Stack[1000005], STop(0), m, n;
unsigned long long Ans(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned long long Sq(unsigned x) { return (unsigned long long)x * x; }
unsigned Find(unsigned x) {
  while (x ^ Fa[x]) Stack[++STop] = x, x = Fa[x];
  while (STop) Fa[Stack[STop--]] = x;
  return x;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) A = RD(), B = RD(), a[B].push_back({ A, ++Cnt });
  // printf("Done\n");
  for (unsigned i(0); i <= 10; ++i) if (a[i].size()) {
    sort(a[i].begin(), a[i].end());
    for (unsigned j(a[i].size() - 1); j; --j)
      E.push_back({ Sq(a[i][j].first - a[i][j - 1].first) ,{a[i][j].second, a[i][j - 1].second} });
  }
  for (unsigned i(0); i < 10; ++i) if (a[i].size()) for (unsigned j(i + 1); j <= 10; ++j) if (a[j].size()) {
    unsigned Pls(Sq(j - i));
    for (unsigned fi(a[i].size() - 1), fj(a[j].size() - 1); (~fi) && (~fj); ) {
      if (a[i][fi].first >= a[j][fj].first)
        E.push_back({ Pls + Sq(a[i][fi].first - a[j][fj].first) ,{a[i][fi].second, a[j][fj].second} }), --fi;
      else
        E.push_back({ Pls + Sq(a[j][fj].first - a[i][fi].first) ,{a[j][fj].second, a[i][fi].second} }), --fj;
    }
  }
  sort(E.begin(), E.end()), Cnt = 0;
  for (unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (auto i : E) {
    A = Find(i.second.first), B = Find(i.second.second);
    if (A ^ B) {
      Fa[A] = B;
      ++Cnt, Ans += i.first;
      if (Cnt == n - 1) break;
    }
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
10
83 10
77 2
93 4
86 6
49 1
62 7
90 3
63 4
40 10
72 0
*/