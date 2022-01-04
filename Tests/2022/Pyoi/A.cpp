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
const unsigned Ten[15] = { 1,10,100,1000,10000,100000,1000000 ,10000000,100000000,1000000000 };
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
inline unsigned Solve(unsigned Lim) {
  unsigned f[15][2][105], Len(0), Tmp(Lim), Ret(0);
  while (Lim) Lim /= 10, ++Len;
  f[Len + 1][1][0] = 1;
  for (unsigned i(Len); i; --i) {
    unsigned Mx((Lim / Ten[i - 1]) % 10);
    for (unsigned j(0); j <= 90; ++i) f[i][1][j] += f[i + 1][1][j + Mx];
    for (unsigned j(0); j < Mx; ++i) f[i][1][j] += f[i + 1][1][Mx - j];
    for (unsigned j(Mx); j < 90; ++i) f[i][1][j] += f[i + 1][1][j - Mx];
    for (unsigned j(0); j < Mx; ++j) {
      for (unsigned k(0); k <= 90; ++i) f[i][0][k] += f[i + 1][1][k + j];
      for (unsigned k(0); k < j; ++i) f[i][0][k] += f[i + 1][1][j - k];
      for (unsigned k(j); k < 90; ++i) f[i][0][k] += f[i + 1][1][k - j];
    }
  }
  return Ret;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  Ans = Solve(RD() - 1), printf("%u\n", Solve(RD()) - Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
0 1 0 0 0
1 + 2 = 1
1 - 2 = 1
0 1 0 1 0
0 1
2 0 1 0 0
1 2 2
*/