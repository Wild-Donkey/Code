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
double C[1005][1005], Pre[1005], P[1005], Cur;
unsigned m, n;
unsigned A, B, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned Ceil(double x) { return (unsigned)(x + 0.99999999); }
inline double Pow(double x, unsigned y, double z) { while (y) { if (y & 1) z *= x; x *= x, y >>= 1; }return z; }
inline double Calc(double x, unsigned y, double pre, double p) {
  double pp(pre / (1 - p));
  return pp - Pow(p, y, pp - x);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  C[0][0] = 1;
  for (unsigned i(1); i < n; ++i) {
    C[i][i] = C[i][0] = C[i - 1][0] / 2;
    for (unsigned j(1); j < i; ++j) {
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) / 2;
    }
  }
  // for (unsigned i(1); i <= n; ++i) printf("%lf ", C[n - 1][i - 1]); putchar(0x0A);
  for (unsigned i(n); i; --i) Pre[i] = Pre[i + 1] + C[n - 1][i - 1] * i;
  for (unsigned i(1); i <= n; ++i) P[i] = P[i - 1] + C[n - 1][i - 1];
  // for (unsigned i(1); i <= n; ++i) printf("%lf ", Pre[i]); putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%lf ", P[i]); putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%lf ", Calc(Pre[1], i - 1, Pre[2], P[1])); putchar(0x0A);
  Cur = Pre[1];
  for (unsigned i(Ceil(Cur)), j(1); j <= m; ) {
    // printf("Cur %lf i %u j %u\n", Cur, i, j);
    unsigned L(1), R(m - j + 1), Mid;
    while (L ^ R) {
      Mid = ((L + R) >> 1);
      if (Calc(Cur, Mid, Pre[i], P[i - 1]) > i) R = Mid;
      else L = Mid + 1;
    }
    if (L == m - j + 1) { printf("%.10lf\n", Calc(Cur, L - 1, Pre[i], P[i - 1])); return 0; }
    Cur = Calc(Cur, L, Pre[i], P[i - 1]), i = Ceil(Cur), j += L;
  }
  //  }
//  system("pause");
  return Wild_Donkey;
}
/*
5 3
3.6328125000

5 4
3.8100585938

5 10
4.2396453126

10 1000
9.8121223473
*/