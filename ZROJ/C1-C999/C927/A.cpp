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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), A, B, C, D, t;
char a[2005][2005], b[2005][2005], Ans[4005], Min;
inline void Clr() {}
int main() {
//  freopen("A.in", "r", stdin);
//  freopen("A.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= n; ++i) {
    scanf("%s", a[i] + 1);
  }
  b[1][1] = 1;
  Ans[0] = a[1][1];
  for (register unsigned i(2), Tmp; i <= n; ++i) {
    Tmp = min(i, m), Min = 0x7f;
    for (register unsigned j(1); j <= Tmp; ++j) {
//      c[i - j + 1][j] = i;
      if(b[i - j + 1][j - 1] | b[i - j][j]) {
//        printf("Caoni %u %u %u\n", i, i - j + 1, j);
        Min = min(a[i - j + 1][j], Min);
      }
    }
    Ans[i - 1] = Min;
    for (register unsigned j(1); j <= Tmp; ++j) {
      if(a[i - j + 1][j] == Min && (b[i - j + 1][j - 1] | b[i - j][j])) {
        b[i - j + 1][j] = 1;
      }
    }
  }
  for (register unsigned i(2), Tmp; i <= m; ++i) {
    Tmp = (n + i > m) ? (n - m + i) : 1, Min = 0x7f;
    for (register unsigned j(n); j >= Tmp; --j) {
//      printf("%u %u %u\n", i, j, i - j + n);
//      c[j][i - j + n] = i;
      if(b[j - 1][i - j + n] | b[j][i - j + n - 1]) {
        Min = min(Min, a[j][i - j + n]);
      }
    }
    Ans[n + i - 2] = Min;
    for (register unsigned j(n); j >= Tmp; --j) {
      if(a[j][i - j + n] == Min && (b[j - 1][i - j + n] | b[j][i - j + n - 1])) {
        b[j][i - j + n] = 1;
      }
    }
  }
//  for (register unsigned i(1); i <= n; ++i) {
//    for (register unsigned j(1); j <= m; ++j)
//      printf("%d ", c[i][j]);
//    putchar('\n');
//  }
  printf("%s\n", Ans);
//  }
  return Wild_Donkey;
}
/*
5 2
as
th
ds
vc
ds
6 6
asdifj
dsfkjh
skdjhd
weoiuh
iwehcw
erkjfb
*/
