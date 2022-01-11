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
unsigned a[10005], b[10005], f[1005][1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
  sort(b + 1, b + n + 1);
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j <= n; ++j) f[i][j] = f[i - 1][j];
    for (unsigned j(0); j < a[i]; ++j) {
      f[i][a[i]] = max(f[i][a[i]], f[i - 1][j] + 1);
    }
    for (unsigned j(0); j <= n; ++j) printf("%u ", f[i][j]);
    putchar(0x0A);
  }
  for (unsigned i(1); i <= n; ++i) Ans = max(f[n][i], Ans);
  printf("%u\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
5
1 7 5 6 8
5
1 9 5 6 8
*/