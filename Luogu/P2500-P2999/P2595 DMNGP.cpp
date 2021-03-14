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
unsigned int f[16][33000], m, n, Cnt(0), A, B, C, D, t;
bool a[16][16];
char s[17];
int main() {
  // freopen(".in","r",stdin);
  // freopen(".out","w",stdout);
  n = RD();
  m = RD();
  for (register int i(1); i <= n; ++i) {
    cin.getline(s, 16);
    for (register int j(1); j <= m; ++j) {//init
      if (s[j - 1] == '.') {
        a[i][j] = 0;
      } else {
        a[i][j] = 1;
      }
    }
  }
  for (register int i(1); i <= n; ++i) {//line
    for (register int j(1); j <= m; ++j) {
      printf("%u", int(a[i][j]));
    }
    putchar('\n');
  }
  for (register int i(1); i <= n; ++i) {
    for (register int j(0); j < 1 << m; ++j) {
      for (register int k(1); k <= m; ++k) {
      }
    }
  }
  system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return 0;
}
