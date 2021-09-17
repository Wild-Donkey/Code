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
unsigned int a[505], f[505][505], sum[505], m, n, Cnt(0), A, B, C, D, t, How[505], l(0), r(1000000000), Mid((l + r) >> 1);
char s[10005];
inline void Clr() {
  n = RD();
  memset(a, 0, sizeof(a));
}
bool Chk (const unsigned int &x) {
  register unsigned int j(n), Tmp(0);
  for (register unsigned int i(1); i <= m; ++i) {
    Tmp = 0;
    while (Tmp + a[j] <= x && j) {
      Tmp +=a[j];
      --j;
    }
    if(!j) {
      return 1;
    }
  }
  if(j) {
    return 0;
  }
}
inline void Prt(const unsigned int &x) {
  memset(How, 0, sizeof(How));
  How[m + 1] = 0;
  register unsigned int j(n), Tmp(0);
  for (register unsigned int i(1); i <= m; ++i) {
    Tmp = 0;
    How[i] = j;
    while (Tmp + a[j] <= x && j) {
      Tmp +=a[j];
      --j;
    }
    if(!j) {
      break;
    }
  }
  for (register unsigned int i(m); i >= 1; --i) {
    printf("%u %u\n", min(How[i + 1] + 1, How[i]), How[i]);
  }
  return;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P1281_8.in", "r", stdin);
  // freopen(".out", "w", stdout);
  n = RD();
  m = RD();
  for (register unsigned int i(1); i <= n; ++i) {
    a[i] = RD();
  }
  while (l < r) {
    Mid = (l + r) >> 1;
//    printf("%u %u %u\n", l, Mid, r);
    if (Chk(Mid)) {
      r = Mid;
    }
    else {
      l = Mid + 1;
    }
  }
  Prt(l);
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
