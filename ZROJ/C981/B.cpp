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
unsigned a[10005], m, n;
unsigned A, B, C, D, t, Left, Right;
unsigned Cnt(0), Tmp(0);
unsigned Range[1000005][2], End[1000005];
unsigned long long f[3005][3005], Ans(0x3f3f3f3f3f3f3f3f);
//  inline void Clr() {}
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
  memset(f, 0x3f, sizeof(f));
  for (unsigned i(1); i <= End[1]; ++i)
    for (unsigned Pos(Range[i][0]); Pos <= Range[i][1]; ++Pos)
      f[1][Pos] = 0;
  if (n <= 1000 && m <= 1000) {
    for (unsigned i(2); i <= n; ++i) {
      for (unsigned j(End[i - 1] + 1); j <= End[i]; ++j) {
        for (unsigned Pos(Range[j][0]); Pos <= Range[j][1]; ++Pos) {
          for (unsigned k(1); k <= Pos; ++k)
            f[i][Pos] = min(f[i][Pos], f[i - 1][k] + Right * (Pos - k));
          for (unsigned k(m); k > Pos; --k)
            f[i][Pos] = min(f[i][Pos], f[i - 1][k] + Left * (k - Pos));
        }
      }
      // for (unsigned j(1); j <= m; ++j) {
      //   printf("%u ", f[i][j]);
      // }
      // putchar('\n');
    }
    for (unsigned i(1); i <= m;++i) {
      Ans = min(Ans, f[n][i]);
    }
    printf("%llu\n", Ans);
    // system("pause");
    return Wild_Donkey;
  }
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(End[i - 1] + 1), k(End[i - 2] + 1), Pos2(Range[k][0]); j <= End[i]; ++j) {
      for (Pos2 = max(Range[k][0], Range[j - 1][1] + 1); k <= End[i - 1] && Pos2 <= Range[j][0]; ++Pos2) {
        if (Pos2 > Range[k][1]) { Pos2 = Range[++k][0] - 1; continue; }
        f[i][Range[j][0]] = min(f[i][Range[j][0]], f[i - 1][Pos2] + Right * (Range[j][0] - Pos2));
        if (j - 1 > End[i - 1]) f[i][Range[j - 1][1]] = min(f[i][Range[j - 1][1]], f[i - 1][Pos2] + Left * (Pos2 - Range[j - 1][1]));
      }
      for (unsigned Pos(Range[j][0]); Pos <= Range[j][1]; ++Pos) {
        f[i][Pos] = min(f[i][Pos], f[i - 1][Pos]);
      }
    }
    for (unsigned k(End[i - 1]), l(Range[k][1]); l > Range[End[i]][1]; --l) {
      if (l < Range[k][0]) { l = Range[--k][1] + 1;continue; }
      f[i][Range[End[i]][1]] = min(f[i][Range[End[i]][1]], f[i - 1][l] + Left * (l - Range[End[i]][1]));
    }
    // for (unsigned j(1); j <= m; ++j) {
    //   printf("%u ", f[i][j]);
    // }
    // putchar('\n');
  }
  for (unsigned i(1); i <= m;++i) {
    Ans = min(Ans, f[n][i]);
  }
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}