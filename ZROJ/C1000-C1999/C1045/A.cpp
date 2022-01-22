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
#include <string>
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
pair<unsigned, unsigned> Link[305];
unsigned a[305][305], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) a[i][j] = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) Link[j] = make_pair(a[i][j], j);
    sort(Link + 1, Link + n + 1);
    for (unsigned j(2); j <= n; ++j) if(Link[j].second > i) {
      unsigned To(Link[j].second);
      Flg = 0;
      for (unsigned k(2); k < j; ++k) if(a[i][Link[k].second] + a[To][Link[k].second] == a[i][To]) {Flg = 1;break;}
      if(!Flg) ++Ans;
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

