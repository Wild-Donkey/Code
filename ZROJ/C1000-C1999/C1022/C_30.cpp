#include <algorithm>
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
unsigned long long Sum[10005][10005], SSum[10005], Sj[10005][10005], Si[10005][10005];
unsigned long long Ans(0); 
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline unsigned GCD(unsigned x, unsigned y) {
  unsigned TmG;
  while(y) TmG = x, x = y, y = TmG % y;
  return x;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j < i; ++j) {
      Sum[i][j] = GCD(a[i], a[j]) + Sum[i][j - 1];
    }
  }
  for (unsigned i(1); i <= n; ++i) SSum[i] = SSum[i - 1] + Sum[i][i - 1];
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) {
      Si[i][j] = Si[i][j - 1] + Sum[j][i];
    }
  }
  for (unsigned j(1); j <= n; ++j) {
    for (unsigned i(1); i <= n; ++i) {
      Sj[j][i] = Sj[j][i - 1] + Sum[i][j];
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= i; ++j) {
      Ans += SSum[j - 1] - SSum[i] + SSum[n] + Sj[j - 1][n] - Sj[j - 1][i] - Si[i][n] + Si[i][i];
    }
  }
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

