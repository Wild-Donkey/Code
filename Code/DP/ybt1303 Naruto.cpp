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
unsigned int f[15][25], m, n, Cnt(0), A, B, C, D, t;
bool b[10005];
char s[10005];
inline void Clr() {
  m = RD();
  n = RD();
  m += n;
  memset(f, 0, sizeof(f));
  f[0][0] = 1;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned int T(1); T <= t; ++T) {
    Clr();
//    for (register unsigned int i(1); i <= m; ++i) {
//      f[0][i] = 1;
//    }
    for (register unsigned int i(1); i <= n; ++i) {
      f[i][i] = 1;
      for (register unsigned int j(i + 1); j <= m; ++j) {
        f[i][j] = f[i - 1][j - 1] + f[i][j - i];
//        printf("%u %u %u    ",i, j, f[i][j]);
      }
//      putchar('\n');
    }
    printf("%u\n", f[n][m]);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


