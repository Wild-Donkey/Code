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
unsigned Fa[5005], Stack[5005], Top(0), m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Find (unsigned x) {
  while (x ^ Fa[x]) Stack[++Top] = x, x = Fa[x];
  while (Top) Fa[Stack[Top--]] = x;
  return x;
}
struct Edge {
  unsigned Frm, To, Val;
  const inline char operator <(const Edge& x) const {return Val < x.Val;}
}E[200005];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (unsigned i(1); i <= m; ++i) E[i].Frm = RD(), E[i].To = RD(), E[i].Val = RD();
  sort(E + 1, E + m + 1);
  for (unsigned i(1); i <= m; ++i) {
    A = Find(E[i].Frm), B = Find(E[i].To);
    if(A ^ B) ++Cnt, Ans += E[i].Val, Fa[A] = B;
  }
  if(Cnt < n - 1) printf("orz\n");
  else printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

