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
unsigned int f[1005][1005], m, n, Cnt(0), A, B, C, D, t, Ans(0);
string a[100005], b[100005];
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
    cin >> a[i];
  }
  for (register unsigned int i(1); i <= m; ++i) {
    cin >> b[i];
  }
  memset(f, 0, sizeof(f));
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= m; ++j) {
//      f[i][j] = max(f[i - 1][j], f[i][j - 1]);
      if (a[i] == b[j]) {
        f[i][j] = max(f[i - 1][j - 1] + 1, f[i][j]);
        Ans = max(Ans, f[i][j]);
      }
    }
  }
  printf("%u\n", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*

*/
