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
inline unsigned int RD() {
  unsigned int intmp = 0;
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
unsigned int a[105][105], f[105][105], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
//  memset(a, 0, sizeof(a));
  memset(f, 0x3f, sizeof(f));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  Clr();
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= n; ++j) {
      a[i][j] = RD();
    }
  }
  f[0][1] = 0;
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= n; ++j) {
      f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];
    }
  }
  printf("%u\n", f[n][n]);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
5
1  4  6  8  10 
2  5  7  15 17 
6  8  9  18 20 
10 11 12 19 21 
20 23 25 29 33
*/

