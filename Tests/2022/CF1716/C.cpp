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
unsigned a[2][200005], b[2][200005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  n = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[0][i] = RD() + 1;
    for (unsigned i(1); i <= n; ++i) a[1][i] = RD() + 1;
    a[0][1] = b[0][n + 1] = b[1][n + 1] = 0;
    for (unsigned i(n), j(1); i >= 1; --i, j += 2) {
      b[0][i] = max(a[0][i] + 1, b[0][i + 1]) - 1;
      b[0][i] = max(a[1][i], b[0][i] + j) - j;
      b[1][i] = max(a[1][i] + 1, b[1][i + 1]) - 1;
      b[1][i] = max(a[0][i], b[1][i] + j) - j;
    }
    // for (unsigned i(1); i <= n; ++i) printf("%u ", b[0][i]); putchar(0x0A);
    // for (unsigned i(1); i <= n; ++i) printf("%u ", b[1][i]); putchar(0x0A);
    Ans = b[0][1] + (n << 1) - 1;
    for (unsigned i(1), j((n << 1) - 3), Fst(0), Scd(1); i <= n; ++i, swap(Fst, Scd), j -= 2) {
      // printf("%u\n", Ans);
      a[Scd][i] = max(a[Scd][i], a[Fst][i] + 1);
      Ans = min(Ans, max(b[Scd][i + 1], a[Scd][i] + 1) + j);
      a[Scd][i + 1] = max(a[Scd][i + 1], a[Scd][i] + 1);
    }
    printf("%u\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}