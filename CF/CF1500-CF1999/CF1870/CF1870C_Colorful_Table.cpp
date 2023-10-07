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
struct Node {
  unsigned Val, Pos;
  inline const char operator<(const Node& x) const { return Val < x.Val; }
} a[100005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() { n = RD(), m = RD(); }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i].Val = RD(), a[i].Pos = i;
    sort(a + 1, a + n + 1);
    set<unsigned> S;
    for (unsigned i(1); i <= n; ++i) S.insert(i);
    for (unsigned i(1), j(1); j <= n;) {  // Val i, Pos j
      while (a[j].Val > i) printf("0 "), ++i;
      unsigned Mn(*S.begin()), Mx(*S.rbegin());
      while (j <= n && a[j].Val == i) S.erase(a[j].Pos), ++j;
      printf("%u ", (Mx - Mn + 1) << 1), ++i;
    }
    for (unsigned i(a[n].Val + 1); i <= m; ++i) printf("0 ");
    putchar(0x0A);
  }
  //  system("pause");
  return Wild_Donkey;
}