#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <string>
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
unsigned int a[25], f[25], m, n, Cnt(0), A, B, C, D, len(0), Ans(0), Tmp, How[25], Prt[25];
bool b[25][25];
//string s;
string s;
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  for (register unsigned int i(1); i < n; ++i) {
    for (register unsigned int j(i + 1); j <= n; ++j) {
      if(RD()) {
        b[i][j] = 1;
      }
    }
  }
  memset(f, 0, sizeof(f));
//  f[1] = a[1];
//  Ans = a[1];
  for (register unsigned int i(1); i <= n; ++i) {
    f[i] = a[i];
    How[i] = 0;
    for (register unsigned int j(1); j < i; ++j) {
      if (b[j][i]) {
        if (f[j] + a[i] > f[i]) {
          f[i] = f[j] + a[i];
          How[i] = j; 
        }
      }
    }
    if(f[i] > Ans) {
      Ans = f[i];
      How[0] = i;
    }
  }
  Tmp = 0;
  Prt[0] = How[0];
  while (How[Prt[Cnt]]) {
    Prt[Cnt + 1] = How[Prt[Cnt]];
    ++Cnt;
  }
  for (register unsigned int i(Cnt); i < 0x3f3f3f3f; --i) {
    printf("%u ", Prt[i]);
  }
  putchar('\n');
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
