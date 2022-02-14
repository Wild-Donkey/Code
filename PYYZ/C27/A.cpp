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
unsigned Fa[100005], Stack[100005], STop(0);
unsigned Ned[100005], Siz[100005], Id[100005], Od[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Find(unsigned x) {
  while (Fa[x] ^ x) Stack[++STop] = x, x = Fa[x];
  while (STop) Fa[Stack[STop--]] = x;
  return x;
}
inline unsigned Dif(unsigned& x, unsigned& y) { return (x > y) ? (x - y) : (y - x); }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (unsigned i(1); i <= m; ++i) {
    C = Find(A = RD()), D = Find(B = RD());
    ++Od[A], ++Id[B];
    if (C ^ D) Fa[Fa[C]] = Fa[D];
  }
  for (unsigned i(1); i <= n; ++i) Ned[Find(i)] += Dif(Id[i], Od[i]), ++Siz[Fa[i]];
  for (unsigned i(1); i <= n; ++i) if ((Siz[i] > 1)) Ans += (Ned[++Cnt] = (Ned[i] >> 1));
  for (unsigned i(1); i <= Cnt; ++i) if (!Ned[i]) ++Ans;
  printf("%u\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
9 5
1 2
1 2
3 4
5 6
7 8
*/