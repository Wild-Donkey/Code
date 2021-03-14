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
unsigned int a[105][105], f[105][105], m, n, Cnt(0), A, B, C, D, t, How[105][105][105];
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= m; ++j) {
      a[i][j] = RDsg() + 50;
    }
  }
  for (register unsigned int i(1); i <= n; ++i) {
    f[i][i] = f[i - 1][i - 1] + a[i][i];
    for (register unsigned int j(1); j < i; ++j) {
      How[i][i][j] = How[i - 1][i - 1][j];
    }
    How[i][i][i] = i;
    for (register unsigned int j(i + 1); j <= m; ++j) {
      if (f[i][j - 1] < f[i - 1][j - 1] + a[i][j]) {
        f[i][j] = f[i - 1][j - 1] + a[i][j];
        for (register unsigned int k(1); k < i; ++k) {
          How[i][j][k] = How[i - 1][j - 1][k];
        }
        How[i][j][i] = j;
      }
      else {
        f[i][j] = f[i][j - 1];
        for (register unsigned int k(1); k <= i; ++k) {
          How[i][j][k] = How[i][j - 1][k];
        }
      }
    }
  }
  printf("%u\n", f[n][m] - 50 * n);
  for (register unsigned int i(1); i <= n; ++i) {
    printf("%u ", How[n][m][i]);
  }
  putchar('\n');
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


