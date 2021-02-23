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
unsigned int a[20][20], m, n, Cnt(0), A, B, C, D, f[20], How[20][20];
bool b[20];
char s[20];
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
  memset(a, 0, sizeof(a));
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(1); j <= m; ++j) {
      a[i][j] = RD();
    }
  }
  memset(f, 0, sizeof(f));
  memset(How, 0, sizeof(How));
  for (register unsigned int i(1); i <= n; ++i) {
    for (register unsigned int j(m); j > 0; --j) {//all used
      for (register unsigned int k(0); k <= j; ++k) {//now used
//          printf("%u %u %u\n", i, j, k); 
        if(f[j] < f[j - k] + a[i][k]) {
          f[j] = f[j - k] + a[i][k];
          for(register unsigned int l(1); l < i; ++l) {
            How[j][l] = How[j - k][l];
          }
          How[j][i] = k;
        }
        if(f[j] == f[j - k] + a[i][k]) {
          bool flg(0);
          for(register unsigned int l(1); l < i; ++l) {
            if(How[j][l] > How[j - k][l]) {
              flg = 1;
              break;
            }
          }
          if(flg) {
            for(register unsigned int l(1); l < i; ++l) {
              How[j][l] = How[j - k][l];
            }
            How[j][i] = k;
          }
        }
      }
    }
  }
  printf("%u\n", f[m]);
  for (register unsigned int i(1); i <= n; ++i) {
    printf("%u %u\n", i, How[m][i]);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
3 3
30 40 50
20 30 50
20 25 30
*/
