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
long long Sum[50005];
unsigned g[50005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Calc() {
  long long f[10005];
  f[0] = 0xafafafafafafafaf;
  for (unsigned i(1); i <= n; ++i) {
    f[i] = 0x3f3f3f3f3f3f3f3f;
    for (unsigned j(0); j < i; ++j) if (f[i] > max(f[j], Sum[i] - Sum[j]))
      f[i] = max(f[j], Sum[i] - Sum[j]), g[i] = j;
    // printf("%u ", g[i]);
  }
  // putchar(0x0A);
  // for (unsigned i(1); i <= n; ++i) printf("%lld ", f[i]); putchar(0x0A);
}
inline char Judge1(const long long& x) {
  bitset<105> f[105];
  f[0][0] = 1;
  for (unsigned i(1); i <= m; ++i) for (unsigned j(1); j <= n; ++j)
    for (unsigned k(0); k < j; ++k) if ((Sum[j] - Sum[k] <= x) && (f[i - 1][k])) { f[i][j] = 1; break; }
  return f[m][n];
}
inline void Sub1() {
  long long L(-3000005), R(3000005), Mid;
  while (L ^ R) {
    Mid = ((L + R) >> 1);
    // printf("[%lld, %lld] %lld\n", L, R, Mid);
    if (Judge1(Mid)) R = Mid;
    else L = Mid + 1;
  }
  printf("%lld\n", L);
  // system("pause");
}
inline char JudgeP(long long x) {
  unsigned Tmp(0);
  for (unsigned i(0), j(0); i <= n;) {
    while ((Sum[j + 1] - Sum[i] <= x) && (j <= n)) ++j;
    // printf("(%u, %u]\n", i, j);
    ++Tmp, i = (j++);
  }
  return Tmp <= m;
}
inline void SubP() {
  long long L(0), R(1500000005), Mid;
  while (L ^ R) {
    Mid = ((L + R) >> 1);
    // printf("[%lld, %lld] %lld\n", L, R, Mid);
    if (JudgeP(Mid)) R = Mid;
    else L = Mid + 1;
  }
  printf("%lld\n", L);
  // system("pause");
}
inline char JudgeN(long long x) {
  unsigned Tmp(0);
  for (unsigned i(0), j(0); i <= n;) {
    while ((Sum[j] - Sum[i] > x) && (j <= n)) ++j;
    // printf("(%u, %u]\n", i, j);
    Tmp += (Sum[j] - Sum[i] <= x), i = j;
  }
  return Tmp >= m;
}
inline void SubN() {
  long long L(-1500000005), R(0), Mid;
  while (L ^ R) {
    Mid = ((L + R) >> 1);
    // printf("[%lld, %lld] %lld\n", L, R, Mid);
    if (JudgeN(Mid)) R = Mid;
    else L = Mid + 1;
  }
  printf("%lld\n", L);
  // system("pause");
}
//  inline void Clr() {}
signed main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + RDsg();
  if (n <= 100) { Sub1(); return 0; }
  if (Sum[n] > 0) { SubP(); return 0; }
  if (Sum[n] < 0) { SubN(); return 0; }
  // Calc();
  SubP();
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
9 4
-1 -1 -1 -3 -2 -2 -1 -3 -1
*/