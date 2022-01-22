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
double a[105][105];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline char Zer(double& x) { return (x <= 0.00000001) && (x >= -0.00000001); }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n + 1; ++j) a[i][j] = RDsg();
  for (unsigned i(1); i <= n; ++i) {
    unsigned Do(i);
    while ((Zer(a[Do][i])) && (Do <= n)) ++Do;
    if (Do > n) { printf("No Solution\n");return 0; }
    if (Do ^ i) for (unsigned j(i); j <= n + 1; ++j) swap(a[i][j], a[Do][j]);
    for (unsigned j(i + 1); j <= n; ++j) {
      double Tms(-a[j][i] / a[i][i]);
      // printf("%u -> %u %lf\n", i, j, Tms);
      for (unsigned k(i); k <= n + 1; ++k) a[j][k] += a[i][k] * Tms;
    }
  }
  for (unsigned i(n); i; --i) {
    if (Zer(a[i][i])) { printf("No Solution\n");return 0; }
    for (unsigned j(i - 1); j; --j)
      a[j][n + 1] -= (a[j][i] / a[i][i]) * a[i][n + 1], a[j][i] = 0;
  }
  // for (unsigned i(1); i <= n; ++i) {
  //   for (unsigned j(1); j <= n + 1; ++j) printf("%lf ", a[i][j]); putchar(0x0A);
  // }
  for (unsigned i(1); i <= n; ++i) printf("%.2lf\n", a[i][n + 1] / a[i][i]);
  //  }
  // system("pause");
  return Wild_Donkey;
}