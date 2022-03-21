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
double Pnt[2005][2], La[2005], L[2005], Ans(0), m, Now(1);
unsigned n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  n = RD();
  for (unsigned i(0); i < n; ++i) scanf("%lf%lf", Pnt[i], Pnt[i] + 1);
  La[1] = 1, La[0] = -Pnt[0][0];
  for (unsigned i(1); i < n; ++i) {
    for (unsigned j(i + 1); j; --j) La[j] = La[j - 1] - La[j] * Pnt[i][0];
    La[0] = - La[0] * Pnt[i][0];
  }
  // for (unsigned i(0); i <= n; ++i) printf("%llu ", La[i]); putchar(0x0A);
  for (unsigned i(0); i < n; ++i) {
    double Mul(1), Tmp(La[n]);
    for (unsigned j(0); j < n; ++j) if (j ^ i) Mul *= (Pnt[i][0] - Pnt[j][0]);
    Mul = Pnt[i][1] / Mul;
    for (unsigned j(n - 1); ~j; --j) {
      L[j] += Mul * Tmp;
      Tmp = La[j] + Tmp * Pnt[i][0];
    }
  }
  for (unsigned i(n - 1); ~i; --i) printf("%lfx^%u + ", L[i], i); putchar(0x0A);
  printf("Qrys:"), t = RD();
  for (unsigned T(1); T <= t; ++T){
    Ans = 0, Now = 1, scanf("%lf", &m);
    for (unsigned i(0); i < n; ++i) {
      Ans += L[i] * Now;
      Now *= m;
    }
    printf("%lf\n", Ans);
  }
    //  system("pause");
  return Wild_Donkey;
}
/*
4
0 0
1 1
2 5
3 14
5
0 0
1 1
2 9
3 36
4 100
*/
