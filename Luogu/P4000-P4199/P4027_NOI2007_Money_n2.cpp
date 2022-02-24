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
double f[100005], a[100005], b[100005], Co[100005], Ra[100005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), f[1] = m = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%lf%lf%lf", a + i, b + i, Ra + i);
    Co[i] = Ra[i] * a[i] + b[i];
  }
  for (unsigned i(2); i <= n; ++i) {
    f[i] = f[i - 1];
    for (unsigned j(1); j < i; ++j)
      f[i] = max(f[i], f[j] * (a[i] * Ra[j] + b[i]) / Co[j]);
  }
  for (unsigned i(1); i <= n; ++i) printf("%u %lf\n", i, f[i]);
  printf("%lf\n", f[n]);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
10 100
5.226 5.381 1.73
5.273 5.899 1.35
5.275 5.236 1.93
5.769 5.863 1.78
5.888 5.064 1.91
5.464 5.894 1.95
5.565 5.731 1.97
5.568 5.305 1.31
5.639 5.501 1.85
5.751 5.925 1.14
123.072
*/