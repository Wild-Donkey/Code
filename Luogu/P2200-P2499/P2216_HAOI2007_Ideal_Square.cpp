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
unsigned a[1005][1005], b[1005][1005], c[1005][1005];
unsigned m, n, t;
unsigned A, B, C, D;
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
pair<unsigned, unsigned> Q1[1005], * Hd1(Q1 + 1), * Tl1(Q1);
pair<unsigned, unsigned> Q2[1005], * Hd2(Q2 + 1), * Tl2(Q2);
void Insert1(unsigned x, unsigned y) {
  while (Hd1 <= Tl1 && (*Tl1).first <= x) --Tl1;
  *(++Tl1) = { x, y };
}
void Insert2(unsigned x, unsigned y) {
  while (Hd2 <= Tl2 && (*Tl2).first >= x) --Tl2;
  *(++Tl2) = { x, y };
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD();
  for (unsigned i(1); i <= n; ++i)
    for (unsigned j(1); j <= m; ++j)
      a[i][j] = RD();
  for (unsigned i(1); i <= n; ++i) {
    Hd1 = Q1 + 1, Tl1 = Q1;
    Hd2 = Q2 + 1, Tl2 = Q2;
    for (unsigned j(1); j <= t; ++j) {
      Insert1(a[i][j], j);
      Insert2(a[i][j], j);
    }
    b[i][1] = (*Hd1).first;
    c[i][1] = (*Hd2).first;
    for (unsigned j(t + 1); j <= m; ++j) {
      if ((*Hd1).second == j - t) ++Hd1;
      if ((*Hd2).second == j - t) ++Hd2;
      Insert1(a[i][j], j);
      Insert2(a[i][j], j);
      b[i][j - t + 1] = (*Hd1).first;
      c[i][j - t + 1] = (*Hd2).first;
    }
  }
  m -= t - 1;
  /*
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j)
      printf("%u ", b[i][j]);
    putchar(0x0A);
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j)
      printf("%u ", c[i][j]);
    putchar(0x0A);
  }*/
  for (unsigned i(1); i <= m; ++i) {
    Hd1 = Q1 + 1, Tl1 = Q1;
    Hd2 = Q2 + 1, Tl2 = Q2;
    for (unsigned j(1); j <= t; ++j) {
      Insert1(b[j][i], j);
      Insert2(c[j][i], j);
    }
    Ans = min(Ans, (*Hd1).first - (*Hd2).first);
    for (unsigned j(t + 1); j <= n; ++j) {
      if ((*Hd1).second == j - t) ++Hd1;
      if ((*Hd2).second == j - t) ++Hd2;
      Insert1(b[j][i], j);
      Insert2(c[j][i], j);
      Ans = min(Ans, (*Hd1).first - (*Hd2).first);
    }
  }
  printf("%u\n", Ans);
  //  }
//  system("pause");
  return Wild_Donkey;
}