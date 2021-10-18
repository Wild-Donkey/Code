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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned f[75][75], Sum[75];
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
  for (unsigned i(1); i <= n; ++i) N[i].Val = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Fre = RD();
  sort(N + 1, N + n + 1);
  for (unsigned i(1); i <= n; ++i) f[1][i] = N[i].Fre;
  for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + N[i].Fre;
  for (unsigned Len(2); Len <= n; ++Len) {
    for (unsigned i(n - Len + 1); i; --i) {
      unsigned Mx(i);
      for (unsigned j(i + Len - 1); j > i; --j) if(N[j].Val < N[Mx].Val) Mx = j;
      f[Len][i] = f[Mx - i][i] + f[i + Len - Mx - 1][Mx + 1];
      for (unsigned len(0); len < Len; ++len)
        f[Len][i] = min(f[Len][i], f[len][i] + f[Len - len - 1][i + len + 1] + m);
      f[Len][i] += Sum[i + Len - 1] - Sum[i - 1];
    }
  }
  printf("%u\n", f[n][1]);
//  }
  return Wild_Donkey;
}

