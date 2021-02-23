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
unsigned int f[505][505], g[505], gg[505], m, n, Cnt(0), A, B, C, D, t, How[505][505][2], Ans, Prt[505][2];
int a[505], b[505];
bool flg;
char s[10005];
//inline void Clr() {
//  n = RD();
//  memset(a, 0, sizeof(a));
//}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RDsg();
  }
  m = RD();
  for (register unsigned int i(1); i <= m; ++i) {
    b[i] = RDsg();
  }
  memset(g, 0, sizeof(g));
  memset(f, 0, sizeof(f));
  memset(gg, 0, sizeof(gg));
  memset(How, 0, sizeof(How));
  memset(Prt, 0, sizeof(Prt));
  a[0] = -0X3f3f3f3f;
  b[0] = -0X3f3f3f3f;
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= m; ++j) {
      if(a[i] == b[j]) {
        for (register unsigned int k(0); k < j; ++k) {
          if(b[j] > b[k]) {
            if(f[i][j] < g[k] + 1) {
              f[i][j] = g[k] + 1;
              How[i][j][0] = gg[k];
              How[i][j][1] = k;
              gg[j] = i;//g[k]的值对应的f[i][j] 
            }
          }
//          printf("%u %u %u %u %u\n", i, j, k, f[i][k], g[k]);
        }
//        Ans = max(Ans, f[i][j]);
        if(f[i][j] > g[j]) {
          g[j] = f[i][j];
          gg[j] = i;
        }
        if(g[j] > Ans) {
          Ans = g[j];
          Prt[Ans][0] = i;
          Prt[Ans][1] = j;
        }
      }
    }
  }
//  if ()
//  while(1){}
  printf("%u\n", Ans);
  if(!Ans) {
    return 0;
  }
  for (register unsigned int i(Ans - 1); i >= 1; --i) {
//    if(Prt[i + 1][0] > 500 || Prt[i + 1][1] > 500) {
//      printf("%u %u\n", Prt[i + 1][0], Prt[i + 1][1]);
//    }else {
      Prt[i][0] = How[Prt[i + 1][0]][Prt[i + 1][1]][0];
//      printf("%u %u\n", Prt[i + 1][0], Prt[i + 1][1]);
      Prt[i][1] = How[Prt[i + 1][0]][Prt[i + 1][1]][1];
//    }
    
  }
  for (register unsigned int i(1); i <= Ans; ++i) {
    printf("%d ", b[Prt[i][1]]);
  }
  putchar('\n');
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
5
1 4 2 5 -12
4
-12 1 2 4

5
1 2 0 2 1
3
1 0 1

100
9060 2520 8100 4950 4950 6020 2360 2230 7100 7100 2360 8100 2520 2520 9060 2520 9065 2520 8100 9065 9065 2520 9065 4950 2520 9490 6020 2520 8100 2520 3400 1934 7100 9060 8100 2520 3400 1934 3400 1934 9490 9184 2230 2520 2360 9065 7100 2230 2520 2360 9065 2520 7100 1934 8100 2520 6020 5650 2520 5650 5650 9490 5650 1934 4950 4360 9060 6020 9184 2520 4950 9060 8100 1934 9184 2360 4950 6020 4360 7100 2360 8100 1934 9060 2520 3400 3400 4360 1934 8100 1934 2520 4360 5650 4360 6020 1934 2230 9065 2520
100
4950 8100 7100 9065 9060 7100 7100 6020 4950 2360 9184 2230 5650 4360 4950 5650 6020 7100 3400 7100 4360 9065 2230 2520 9065 3400 2360 3400 9490 4360 2230 4360 2520 8100 8100 2360 2230 8100 6020 5650 2230 4950 3400 3400 2360 4360 9065 9490 1934 2230 9060 5650 7100 2520 3400 2360 7100 2230 5650 8100 9184 9065 1934 7100 8100 1934 8100 2230 2230 7100 4950 5650 3400 5650 2360 2230 9065 9490 1934 9060 1934 5650 9184 9184 8100 6020 5650 1934 2230 4360 4360 2230 8100 4950 1934 2360 9060 2360 2230 4950

3
37 49 24
3
33 5 70
*/
