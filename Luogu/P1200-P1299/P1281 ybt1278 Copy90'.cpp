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
unsigned int b[505], a[505], f[505][505], sum[505], m, n, Cnt(0), A, B, C, D, t, How[505][505], Prt[505];
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
   freopen("P1281_8.in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  sum[0] = 0;
  for (register unsigned int i(1); i <= n; ++i) {
    b[i] = RD();
  }
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = b[n + 1 - i];
    sum[i] = sum[i - 1] + a[i];
  }
  memset(f, 0x3f, sizeof(f));
  memset(How, 0x3f, sizeof(How));
  for (register unsigned int i(0); i <= m; ++i) {
    f[i][0] = 0;
    How[i][0] = 0;
  }
  for (register unsigned int i(1); i <= m; ++i) {
    for (register unsigned int j(1); j <= n; ++j) {
      for (register unsigned int k(j); k <= n; ++k) {
        if (f[i][k] >= max(f[i - 1][j - 1], sum[k] - sum[j - 1])) {
          f[i][k] = max(f[i - 1][j - 1], sum[k] - sum[j - 1]);
          How[i][k] = j;
//          continue;
        }
//        if (How[i][k] < j) {
//          if (f[i][k] >= max(f[i - 1][j - 1], sum[k] - sum[j - 1])) {
//            f[i][k] = max(f[i - 1][j - 1], sum[k] - sum[j - 1]);
//            How[i][k] = j;
//            continue;
//          }
//        }
        if(i == 7 && j >= 43 && j <= 44 && k == 51)
        printf("%u %u %u f%uh%u Ot%u   ", i, j, k, f[i][k], How[i][k], f[i - 1][j - 1]);
      }
      if(i == 7 && j >= 43 && j <= 44)
      putchar('\n');
    }
    f[i][n + 1] = f[i - 1][n];
    How[i][n + 1] = n + 1;
  }
//  printf("%u\n", f[m][n]);
  for (register unsigned int i(m); i >= 1; --i) {
//    printf("%u %u %u\n", i, f[i][n + 1], f[i - 1][n + 1]);
    if (f[i][n] >= f[i][n + 1]) {
      printf("0 0\n");
      --m;
      continue;
    }
    break;
  }
  unsigned int Tmp(n);//上一个抄完了，这个人从这里开始
  for (register unsigned int i(m); i >= 1; --i) {
    if (f[i][Tmp]) {
      
    }
    printf("%u %u\n", n - Tmp + 1, n - How[i][Tmp] + 1);
    Tmp = How[i][Tmp] - 1;
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
9 3			
1 2 3 4 5 6 7 8 9
//17
1 5
6 7
8 9

5 5
1 1 1 5 5
//5
0 0
0 0
1 3
4 4
5 5

1 10
10
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
0 0
1 1
*/
