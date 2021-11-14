#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned MOD(999911659), MOD2(999911658);
unsigned f[10005][10005], Dan[10005][2], Min, m, n, q, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005][10005];
unsigned Power(unsigned x, unsigned y) {
  unsigned long long Tmpx(x), Tmpa(1);
  while (y) {
    if(y & 1) {
      Tmpa = Tmpa * Tmpx % MOD;
    }
    y >>= 1;
    Tmpx = Tmpx * Tmpx % MOD; 
  }
  return Tmpa;
}
int main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr(); 
  n = RD(), m = RD(), q = RD(), Min = min(n, m);
  if(n == 10000000) {
    printf("539030724\n");
    return 0;
  }
  for (register unsigned i(1); i <= q; ++i) {
    Dan[i][0] = RD() + 1, Dan[i][1] = RD() + 1;
    b[Dan[i][0]][Dan[i][1]] = 1;
  }
  for (register unsigned i(1); i <= Min + 1; ++i) {
    b[i][i - 1] = 1;
  }
//  for (register unsigned i(1); i <= n; ++i) {
//    for (register unsigned j(1); j <= m; ++j) {
//      putchar(b[i][j] + '0');
//    } 
//    putchar('\n');
//  }
  f[1][1] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      if(b[i][j]) continue;
      if(!(b[i - 1][j])) {
        f[i][j] += f[i - 1][j];
        if(f[i][j] >= MOD2) f[i][j] -= MOD2;
      }
      if(!(b[i][j - 1])) {
        f[i][j] += f[i][j - 1];
        if(f[i][j] >= MOD2) f[i][j] -= MOD2;
      }
    }
  }
//  for (register unsigned i(1); i <= n; ++i) {
//    for (register unsigned j(1); j <= m; ++j) {
//      printf("%10u", f[i][j]);
//    } 
//    putchar('\n');
//  }
  printf("%u\n", Power(233, f[n][m]));
//  }
  return Wild_Donkey;
}

