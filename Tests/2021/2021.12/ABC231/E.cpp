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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long Ans(0), f[105][2], List[105][2], m, a[105];
unsigned n, A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), List[1][0] = RD(), f[1][0] = f[1][1] = 0;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  Ans = List[1][0] / a[n], List[1][0] %= a[n], List[1][1] = List[1][0];
  for (unsigned i(1); i < n; ++i) {
    List[i + 1][0] = List[i][0] - (List[i][0] % a[i + 1]);
    List[i + 1][1] = a[i + 1] * ((List[i][1] + a[i + 1] - 1) / a[i + 1]);
    f[i + 1][0] = min(f[i][0] + (List[i][0] - List[i + 1][0]) / a[i], f[i][1] + (List[i][1] - List[i + 1][0]) / a[i]);
    f[i + 1][1] = min(f[i][0] + (List[i + 1][1] - List[i][0]) / a[i], f[i][1] + (List[i + 1][1] - List[i][1]) / a[i]);
  }
  printf("%llu\n", min(f[n][0] + List[n][0] / a[n], f[n][1] + List[n][1] / a[n]) + Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}