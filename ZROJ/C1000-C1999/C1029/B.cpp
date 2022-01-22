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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Ans[1005][1005][2], Top[1005];
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    for (unsigned i(1); i <= n; ++i) Top[i] = 0;
    m = (n = RD()) >> 1;
    printf("Case #%u: %u\n", T, m);
    for (unsigned i(1); i <= m; ++i) {
      for (unsigned j(1); j < i; ++j) {
        Ans[i][++Top[i]][0] = i << 1, Ans[i][Top[i]][1] = (j << 1) - 1;
        Ans[i][++Top[i]][0] = (i << 1) - 1, Ans[i][Top[i]][1] = j << 1;
      }
      Ans[i][++Top[i]][0] = i << 1, Ans[i][Top[i]][1] = (i << 1) - 1;
      for (unsigned j(1); j < i; ++j) {
        Ans[j][++Top[j]][0] = i << 1, Ans[j][Top[j]][1] = j << 1;
        Ans[j][++Top[j]][0] = (i << 1) - 1, Ans[j][Top[j]][1] = (j << 1) - 1;
      }
    }
    for (unsigned i(1); i <= m; ++i) {
      for (unsigned j((m << 1) - 1); j; --j) printf("%u %u\n", Ans[i][j][0], Ans[i][j][1]);
      if (n & 1) printf("%u %u\n", n, i);
    }
  }
  return Wild_Donkey;
}
/*

*/

