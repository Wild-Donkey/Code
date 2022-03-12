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
unsigned int a[105], f[105][65][65], List[65], m, n, N, Cnt(0), A, B, C, D, Ans(0);
bool b[10005];
char s;
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
inline unsigned int Gtnm(unsigned int x) {
  unsigned int tmp(0); 
  while (x) {
    if(x & 1) {
      ++tmp;
    }
    x = x >> 1;
  }
  return tmp;
}
inline bool Judge (unsigned int x) {
  unsigned int tmp(0x3f);
  while (x) {
    if(x & 1) {
      if(tmp < 2) {
        return 0;
      }
      tmp = 0;
    }
    else {
      ++tmp;
    }
    x = x >> 1;
  }
  return 1;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P2704_3.in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  N = (1 << m) - 1;
  memset(a, 0, sizeof(a));
  memset(f, 0, sizeof(f));
  memset(List, 0, sizeof(List));
  for (register int i(0); i <= N; ++i) {
    if (Judge(i)) {
      List[++List[0]] = i;
    }
  }
//  printf("List[0]%u\n", List[0]);
  for (register int i(1); i <= n; ++i) {
    for (register int j(1); j <= m; ++j) {//init
      while (s != 'H' && s != 'P') {
        s = getchar();
      }
      a[i] = a[i] << 1;
      if (s == 'H') {
        ++a[i];
      }
      s = '0';
    }
//    printf("%u %u\n", i, a[i]);
  }
  for (register unsigned int i(1); i <= List[0]; ++i) {//1st line
    if (List[i] & a[1]) {//land
      continue;
    }
    Cnt = Gtnm(List[i]);
    f[1][i][1] = Cnt;
//    printf("f[1][%u][0] %u\n", List[i], f[1][i][0]);
  }
  for (register unsigned int i(2); i <= n; ++i) {
    for (register unsigned int j(1); j <= List[0]; ++j) {//this line
      if (List[j] & a[i]) {//land
        continue;
      }
      Cnt = Gtnm(List[j]);
      for (register unsigned int k(1); k <= List[0]; ++k) {//last line
        if(List[j] & List[k] || List[k] & a[i - 1]) {//Gun
          continue;
        }
        for (register unsigned int l(1); l <= List[0]; ++l) {//last of last 
          if(List[j] & List[l] || List[k] & List[l] || List[l] & a[i - 2]) {
            continue;
          }
          f[i][j][k] = max(f[i - 1][k][l] + Cnt, f[i][j][k]); 
        }
//        printf("f[%u][%u][%u]%u ", i, List[j], List[k], f[i][j][k]);
      }
//      putchar('\n');
    }
//    putchar('\n');
//    putchar('\n');
  }
  for (register unsigned int i(1); i <= List[0]; ++i) {
    for (register unsigned int j(1); j <= List[0]; ++j) {
      Ans = max(f[n][i][j], Ans);
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
5 4
PHPP
PPHH
PPPP
PHPP
PHHP


*/
