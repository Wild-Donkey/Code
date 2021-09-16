#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
unsigned long long f[1000005], Ans(0x3f3f3f3f3f3f3f3f);
unsigned long long Left, Right;
unsigned m, n, Pos;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Range[1000005][2], End[1000005];
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Left = RD(), Right = RD();
  for (unsigned i(1); i <= n; ++i) {
    End[i] = End[i - 1] + RD();
    for (unsigned j(End[i - 1] + 1); j <= End[i]; ++j)
      Range[j][0] = RD(), Range[j][1] = RD();
    m = max(m, Range[End[i]][1]);
  }
  if (m <= 3000) {
    memset(f, 0x3f, sizeof(f));
    for (unsigned i(1); i <= End[1]; ++i)
      for (unsigned Pos(Range[i][0]); Pos <= Range[i][1]; ++Pos)
        f[Pos] = 0;
    for (unsigned i(2); i <= n; ++i) {
      for (unsigned j(1); j <= m; ++j)
        f[j] = min(f[j], f[j - 1] + Right);
      for (unsigned j(m); j; --j)
        f[j] = min(f[j], f[j + 1] + Left);
      for (unsigned j(Range[End[i - 1] + 1][0] - 1); j; --j) f[j] = 0x3f3f3f3f3f3f3f3f;
      for (unsigned j(End[i - 1] + 1); j < End[i]; ++j)
        for (unsigned k(Range[j][1] + 1); k < Range[j + 1][0]; ++k)
          f[k] = 0x3f3f3f3f3f3f3f3f;
      for (unsigned j(Range[End[i]][1] + 1); j <= m; ++j) f[j] = 0x3f3f3f3f3f3f3f3f;
    }
    for (unsigned i(1); i <= m;++i) {
      Ans = min(Ans, f[i]);
    }
    printf("%llu\n", Ans);
    system("pause");
    return Wild_Donkey;
  }
  m = 1, Ans = 0;
  for (unsigned i(2); i <= n;++i) {
    if ((Range[m][0] <= Range[i][1]) && (Range[m][1] >= Range[i][0]))
      Range[i][0] = max(Range[m][0], Range[i][0]), Range[i][1] = min(Range[m][1], Range[i][1]), ++m;
    else break;
  }
  if (m < n) {
    if (Range[m][1] < Range[m + 1][0])
      Ans += Right * (Range[m + 1][0] - Range[m][1]), Pos = Range[m + 1][0];
    else Ans += Left * (Range[m][0] - Range[m + 1][1]), Pos = Range[m + 1][1];
  }
  for (unsigned i(m + 2); i <= n; ++i) {
    if ((Range[i][0] <= Pos) && (Range[i][1] >= Pos)) continue;
    if (Range[i][0] > Pos) Ans += Right * (Range[i][0] - Pos), Pos = Range[i][0];
    else Ans += Left * (Pos - Range[i][1]), Pos = Range[i][1];
  }
  printf("%llu\n", Ans);
  return 0;
}
/*
*/