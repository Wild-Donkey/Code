#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <bitset>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <vector>
#define Wild_Donkey 0
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned long long a[105], Sum, f[105][2];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) Sum += (a[i] = RD());
  sort(a + 1, a + n + 1);
  for (unsigned i(n); i; --i) {
    if(a[i] <= 3) f[i][0] = f[i + 1][1], f[i][1] = f[i + 1][0] + a[i];
    else {
      f[i][0] = min(f[i + 1][1], f[i + 1][0] + 4);
      f[i][1] = max(f[i + 1][0] + a[i], f[i + 1][1] + a[i] - 4);
    }
  }
  printf("%llu %llu\n", f[1][0], Sum - f[1][0]);
  return Wild_Donkey;
}
/*
2 5
1 2
01
10
100

*/
