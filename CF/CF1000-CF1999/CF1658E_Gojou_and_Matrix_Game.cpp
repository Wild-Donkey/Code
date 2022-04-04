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
long long a[2005][2005], b[2005][2005], f[2][2005][2005];
int m, n, Times(100);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Cur, Pre;
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Times = 1001;
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) f[1][i][j] = a[i][j] = RD();
//  while (Times--) {
//    printf("%u:\n", Times);
    Cur = 0, Pre = 1;
    for (int i(1); i <= n; ++i) for(int j(1); j <= n; ++j) {
      f[Cur][i][j] = 0xafafafafafafafaf;
      for (int i1(1); i1 <= n; ++i1) for (int j1(1); j1 <= n; ++j1)
        if(abs(i1 - i) + abs(j1 - j) > m) f[Cur][i][j] = max(f[Cur][i][j], f[Pre][i1][j1]);
      f[Cur][i][j] = a[i][j] - f[Cur][i][j];
    }
//    for (int i(1); i <= n; ++i) {for(int j(1); j <= n; ++j) printf("%lld ", f[Cur][i][j]); putchar(0x0A); }
    memcpy(b, f[Cur], sizeof(b));
    Cur = 1, Pre = 0;
    for (int i(1); i <= n; ++i) for(int j(1); j <= n; ++j) {
      f[Cur][i][j] = 0xafafafafafafafaf;
      for (int i1(1); i1 <= n; ++i1) for (int j1(1); j1 <= n; ++j1)
        if(abs(i1 - i) + abs(j1 - j) > m) f[Cur][i][j] = max(f[Cur][i][j], f[Pre][i1][j1]);
      f[Cur][i][j] = a[i][j] - f[Cur][i][j];
    }
//    for (int i(1); i <= n; ++i) {for(int j(1); j <= n; ++j) printf("%lld ", f[Cur][i][j]); putchar(0x0A); }
    Cur = 0, Pre = 1;
    for (int i(1); i <= n; ++i) for(int j(1); j <= n; ++j) {
      f[Cur][i][j] = 0xafafafafafafafaf;
      for (int i1(1); i1 <= n; ++i1) for (int j1(1); j1 <= n; ++j1)
        if(abs(i1 - i) + abs(j1 - j) > m) f[Cur][i][j] = max(f[Cur][i][j], f[Pre][i1][j1]);
      f[Cur][i][j] = a[i][j] - f[Cur][i][j];
    }
//    for (int i(1); i <= n; ++i) {for(int j(1); j <= n; ++j) printf("%lld ", f[Cur][i][j]); putchar(0x0A); }
//  }
  for (int i(1); i <= n; ++i) {for(int j(1); j <= n; ++j) putchar((f[0][i][j] - b[i][j] > 0) ? 'M' : 'G'); putchar(0x0A); }
//  }
  return Wild_Donkey;
}
/*
3 1
1 2 4
6 8 3
9 5 7
*/
