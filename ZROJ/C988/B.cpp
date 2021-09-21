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
unsigned Cnt[2][1005], Fa[1005], Stack[1005];
unsigned m, n, A, B, C, D, t, Top(0);
unsigned Ans(0), Tmp(0), Last, Link(0);
char a[1005][1005];
unsigned Find(unsigned x) {
  while (x ^ Fa[x]) Stack[++Top] = x, x = Fa[x];
  while (Top) Fa[Stack[Top--]] = x;
  return x;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) Fa[i] = i;
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", a[i] + 1);
    for (unsigned j(1); j <= m; ++j)
      Cnt[0][i] += (a[i][j] -= '0'), Cnt[1][j] += a[i][j];
    Ans += (m - Cnt[0][i]) * 3, Last = 0;
    for (unsigned j(1); j <= m; ++j) {
      if (a[i][j]) { if (Last) A = Find(j), B = Find(Last), Fa[A] = B;  Last = j; }
    }
  }
  for (unsigned i(1); i <= m; ++i) if (Fa[i] == i) ++Link;
  // for (unsigned i(1); i <= m; ++i) printf("Fa[%u] %u\n", i, Fa[i]);
  for (unsigned i(1); i <= n; ++i) if (!(Cnt[0][i])) ++Link;
  --Link, printf("%u\n", Link + Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
3 3
101
010
101
13
3 3
100
010
001
*/