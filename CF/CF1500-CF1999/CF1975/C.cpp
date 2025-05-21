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
unsigned a[100005], b[100005], m, n;
int Cur[100005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(); }
char Judge(unsigned x) {
  int Mn(0);
  Cur[0] = 0;
  Cur[1] = (a[1] < x) ? -1 : 1;
  for (unsigned i(2); i <= n; ++i) {
    Mn = min(Cur[i - 2], Mn);
    if (a[i] < x)
      Cur[i] = Cur[i - 1] - 1;
    else
      Cur[i] = Cur[i - 1] + 1;
    if (Cur[i] > Mn) return 1;
  }
  return 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) { b[i] = a[i] = RD(); }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - b - 1;
    for (unsigned i(1); i <= n; ++i)
      a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
    unsigned L(1), R(m), Mid;
    while (L < R) {
      Mid = ((L + R + 1) >> 1);
      if (Judge(Mid))
        L = Mid;
      else
        R = Mid - 1;
    }
    printf("%u\n", b[L]);
  }
  //  system("pause");
  return Wild_Donkey;
}