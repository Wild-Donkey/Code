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
unsigned int m, n, t;
int a[50005], b[50005], Min[50005][2], Max[50005][2], Ans(-0x3f3f3f3f);
inline void Clr() {
  Ans = -0x3f3f3f3f;
  n = RD();
//  b[0] = RDsg();
  a[0] = 0;
  Min[0][0] = 0;
  Max[0][0] = -0x3f3f3f3f;
  Min[n + 1][1] = -0x3f3f3f3f;
  Max[n + 1][1] = 0x3f3f3f3f;
//  memset(f, 0, sizeof(f));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned int T(1); T <= t; ++T) {
    Clr();
    for (register unsigned int i(1); i <= n; ++i) {
      b[i] = RDsg();
      a[i] = b[i] + a[i - 1];
//      printf("%d ", a[i]);
    }
//    putchar('\n');
    Min[n][2] = -0x3f3f3f3f;
    for (register unsigned int i(1); i < n; ++i) {
      Min[i][0] = min(a[i], Min[i - 1][0]);
      Max[i][0] = max(a[i] - Min[i - 1][0], Max[i - 1][0]);
//      printf("%u %d\n", i, Max[i][0]);
    }
    for (register unsigned int i(n); i >= 1; --i) {
      Min[i][1] = max(a[i], Min[i + 1][1]);
      Max[i][1] = min(a[i] - Min[i + 1][1], Max[i + 1][1]);
//      printf("%u %d %d\n", i, Max[i][1], Min[i][1]);
    }
//    printf("%d\n", Max[1][1]);
    for (register unsigned int i(1); i < n; ++i) {
      Ans = max(Max[i][0] - Max[i][1], Ans);
    }
    printf("%d\n", Ans);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
1
10
-1 -1 -2 -2 -3 -3 -4 -4 -5 -5
1
10
1 -1 2 2 3 -3 4 -4 5 -5
*/
