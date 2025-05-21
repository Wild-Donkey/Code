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
unsigned a[10005], m, n;
unsigned f[10005][2][2];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), f[0][0][0] = f[0][0][1] = 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) {
    if (a[i] > 3) {
      printf("0\n");
      return 0;
    }
    if (a[i] == 0) {
      f[i][1][0] = f[i][1][1] = f[i][0][1] = 0;
      f[i][0][0] = f[i - 1][0][0];
      continue;
    }
    if (a[i] == 1) {
      f[i][1][1] = 0;
      f[i][1][0] = f[i - 1][0][1];
      f[i][0][1] = f[i - 1][0][0];
      f[i][0][0] = f[i - 1][1][0];
      continue;
    }
    if (a[i] == 2) {
      f[i][0][0] = 0;
      f[i][0][1] = f[i - 1][1][0];
      f[i][1][0] = f[i - 1][1][1];
      f[i][1][1] = f[i - 1][0][1];
      continue;
    }
    f[i][1][0] = f[i][0][0] = f[i][0][1] = 0;
    f[i][1][1] = f[i - 1][1][1];
  }
  printf("%u\n", f[n][1][0] + f[n][0][0]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}