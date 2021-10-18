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
unsigned a[75], m, n, v;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned f[75][75][75], Sum[75];
struct Node{
  unsigned Key, Val, Fre;
  inline const char operator< (const Node& x) const{return Key < x.Key;}
}N[75];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Key = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Val = a[i] = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Fre = RD();
  sort(N + 1, N + n + 1), sort(a + 1, a + n + 1), v = unique(a + 1, a + n + 1) - a;
  for (unsigned i(1); i <= n; ++i) N[i].Val = lower_bound(a + 1, a + v, N[i].Val) - a;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j <= N[i].Val; ++j) f[1][i][j] = N[i].Fre;
    for (unsigned j(N[i].Val + 1); j <= v; ++j) f[1][i][j] = N[i].Fre + m;
//    for (unsigned j(1); j <= v; ++j) printf("[%u] V %u = %u\n", i, j, f[1][i][j]);
  }
  for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + N[i].Fre;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      for (unsigned j(1); j <= v; ++j) f[Len][i][j] = 0x3f3f3f3f;
      for (unsigned Mid(i + Len - 1); Mid >= i; --Mid) {
        for (unsigned j(1); j <= N[Mid].Val; ++j)
          f[Len][i][j] = min(f[Len][i][j], f[Mid - i][i][N[Mid].Val] + f[i + Len - Mid - 1][Mid + 1][N[Mid].Val]);
        for (unsigned j(1); j <= v; ++j)
          f[Len][i][j] = min(f[Len][i][j], f[Mid - i][i][j] + f[i + Len - Mid - 1][Mid + 1][j] + m);
      }
      for (unsigned j(1); j <= v; ++j) f[Len][i][j] += Sum[i + Len - 1] - Sum[i - 1];
//      for (unsigned j(1); j <= v; ++j) printf("[%u, %u] V %u = %u\n", i, i + Len - 1, j, f[Len][i][j]);
    }
  }
  printf("%u\n", f[n][1][1]);
//  }
  return Wild_Donkey;
}

