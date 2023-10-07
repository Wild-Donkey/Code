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
struct Prb {
  unsigned Num, Scr;
  inline const char operator<(const Prb &x) const { return Scr > x.Scr; }
} a[105], b[105];
unsigned Ans[105];
char List[105][105];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) a[i].Scr = RD(), a[i].Num = i;
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", List[i] + 1);
    b[i] = {i, i};
    for (unsigned j(1); j <= m; ++j)
      if (List[i][j] == 'o') b[i].Scr += a[j].Scr;
  }
  sort(b + 1, b + n + 1);
  sort(a + 1, a + m + 1);
  for (unsigned i(2); i <= n; ++i) {
    unsigned Delt(b[1].Scr - b[i].Scr);
    Cnt = 0;
    for (unsigned j(1); Delt < 0x3f3f3f3f; ++j)
      if (List[b[i].Num][a[j].Num] == 'x') Delt -= a[j].Scr, ++Cnt;
    Ans[b[i].Num] = Cnt;
  }
  for (unsigned i(1); i <= n; ++i) printf("%u\n", Ans[i]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}