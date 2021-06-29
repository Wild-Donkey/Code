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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, f[5005][5005], Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), p;
bool b[10005];
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), p = RD();
  f[1][1] = 1;
  for (register unsigned i(1); i <= n; ++i) {
    f[0][i] = 1;
  }
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= i; ++j) {
      f[i][j] = f[i][j - 1] + f[i - j][j];
      if(f[i][j] >= p) f[i][j] -= p;
//      printf("%u %u %u\n", i, j, f[i][j]);
    }
    for (register unsigned j(i + 1); j <= n; ++j) {
      f[i][j] = f[i][j - 1];
    }
    if(f[i][i] >= p) f[i][i] -= p;
  }
  printf("%u\n", f[n][n]);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
