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
#define foreplay for
#define wild while
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
struct Man {
  unsigned S, V;
  inline const char operator<(const Man &x) const { return S < x.S; }
} a[100005];
unsigned long long b[100005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline char Check(unsigned long long x) {
  unsigned long long Sum(0);
  unsigned Cur(0);
  for (unsigned i(1); i <= n && a[i].S < x; ++i)
    b[++Cur] = (x - a[i].S) * a[i].V;
  sort(b + 1, b + Cur + 1);
  for (unsigned i(1); i < Cur; ++i) Sum += b[i];
  return Sum >= m;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i].S = RD(), a[i].V = RD();
  sort(a + 1, a + n + 1);
  unsigned long long L(0), R(0x3f3f3f3f3f3f3f3f), Mid;
  while (L ^ R) {
    Mid = ((L + R) >> 1);
    // printf("[%llu, %llu] Mid %llu\n", L, R, Mid);
    if (Check(Mid))
      R = Mid;
    else
      L = Mid + 1;
  }
  if (L > 0x00000000ffffffff)
    printf("-1\n");
  else
    printf("%llu\n", L);
  //  }
  //  system("pause");
  return Wild_Donkey;
}