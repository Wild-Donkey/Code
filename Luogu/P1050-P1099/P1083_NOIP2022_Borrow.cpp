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
unsigned a[1000005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Order {
  unsigned l, r, v;
} b[1000005];
long long Div[1000005];
char Judge(unsigned x) {
  for (unsigned i(1); i <= n; ++i) Div[i] = 0;
  for (unsigned i(1); i <= x; ++i)
    Div[b[i].l] += b[i].v, Div[b[i].r + 1] -= b[i].v;
  for (unsigned i(1); i <= n; ++i) {
    Div[i] += Div[i - 1];
    if (Div[i] > a[i]) return 0;
  }
  return 1;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i)
    A = RD(), B = RD(), C = RD(), b[i] = {B, C, A};
  unsigned L(0), R(m), Mid;
  while (L < R) {
    Mid = ((L + R + 1) >> 1);
    if (Judge(Mid))
      L = Mid;
    else
      R = Mid - 1;
  }
  if (L == m)
    printf("0\n");
  else
    printf("-1\n%u\n", L + 1);
  //  }
  //  system("pause");
  return Wild_Donkey;
}