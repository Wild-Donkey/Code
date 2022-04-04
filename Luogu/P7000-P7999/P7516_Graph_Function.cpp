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
unsigned a[1005][1005], Prt[200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i][i] = m + 1;
  for (unsigned i(1); i <= m; ++i) A = RD(), B = RD(), a[A][B] = max(a[A][B], i);
  for (unsigned i(n); i; --i) {
    for (unsigned j(1), *J(a[j]); j <= i; J = a[++j]) for (unsigned k(1); k <= n; ++k)
      J[k] = max(J[k], min(J[i], a[i][k]));
    for (unsigned j(i + 1), *J(a[j]); j <= n; J = a[++j]) for (unsigned k(1); k <= i; ++k)
      J[k] = max(J[k], min(J[i], a[i][k]));
  }
//  for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= n; ++j) printf("%u ", a[i][j]); putchar(0x0A);}
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= i; ++j) ++Prt[min(a[i][j], a[j][i])];
  for (unsigned i(m); i; --i) Prt[i] += Prt[i + 1];
  for (unsigned i(0); i <= m; ++i) printf("%u ", Prt[i + 1]);
  putchar(0x0A);
//  }
  return Wild_Donkey;
}
