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
unsigned f[2505][5005];
unsigned m(0), n(0), Pos1[2505], Pos0[5005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char a[5005];
inline unsigned Dif(unsigned x, unsigned y) { return (x > y) ? (x - y) : (y - x); }
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  A = RD();
  for (unsigned i(1); i <= A; ++i) if (RD()) Pos1[++n] = i; else Pos0[++m] = i;
  for (unsigned i(1); i <= n; ++i) f[i][i - 1] = 0x3f3f3f3f;
  for (unsigned i(1); i <= n; ++i) for (unsigned j(i); j <= m; ++j)
    f[i][j] = min(f[i - 1][j - 1] + Dif(Pos1[i], Pos0[j]), f[i][j - 1]);
  // for (unsigned i(1); i <= n; ++i) { for (unsigned j(i); j <= m; ++j) printf("%u ", f[i][j]); putchar(0x0A); }
  printf("%u\n", f[n][m]);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
12
0 0 0 1 1 0 1 0 0 1 1 1
8
1 0 0 0 1 1 0 1
9
0 1 0 0 0 1 1 0 1
8
0 0 1 0 1 0 1 1
*/