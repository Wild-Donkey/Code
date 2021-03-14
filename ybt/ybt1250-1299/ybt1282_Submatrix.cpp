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
unsigned int m, n, Cnt(0), A, B, C, D;
int a[105][105], sum[105][105], Min[105], Max[105], Su[105], Ans(-0x3f3f3f3f);
bool b[10005];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
inline int Sum (const unsigned int &x, const unsigned int &y, const unsigned int &_x, const unsigned int &_y) {
  return sum[_x][_y] - sum[x - 1][_y] - sum[_x][y - 1] + sum[x - 1][y - 1];
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("1282.in", "r", stdin);
   freopen("1282.out", "w", stdout);
  n = RD();
  memset(sum, 0, sizeof(sum));
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= n; ++j) {
      a[i][j] = RDsg();
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
    }
  }
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(i); j <= n; ++j) {
      Min[0] = 0;
      Max[0] = -0x3f3f3f3f;
      for (register unsigned int k(1); k <= n; ++k) {
        Su[k] = Sum(1, i, k, j);
        Min[k] = min(Min[k - 1], Su[k]);
        Max[k] = max(Max[k - 1], Su[k] - Min[k - 1]);
      }
      Ans = max(Ans, Max[n]);
    }
  }
  printf("%d\n", Ans);
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}

