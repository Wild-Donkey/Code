#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
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
long long a[10005], f[10005], Ans(0);
unsigned  m, n, Cnt(0), A, B, C, D, t, Tmp(0);
char Cs[10005];
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RDsg(), f[i] = 0xafafafafafafafaf;
  }
  f[0] = 0;
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(i); j; --j) {
      if (f[j] < f[j - 1] + j * a[i]) f[j] = f[j - 1] + j * a[i], Cs[j] = 1;
      else Cs[j] = 0;
    }
    printf("\nF_%3u\n", i);
    // for (register unsigned j(1); j <= i; ++j) {
    //   printf("f[%u][%u] = %d ", i, j, f[j]), printf("Dif = %d ", f[j] - f[j - 1]);
    // }
    for (register unsigned j(1); j <= i; ++j) {
      printf("%5d ", f[j]);
    }
    // for (register unsigned j(1); j <= i; ++j) {
    //   printf("%u Cs ?%u \n", j, Cs[j]);
    // }
    putchar('\n');
  }
  for (register unsigned i(1); i <= n; ++i) Ans = max(Ans, f[i]);
  printf("%d\n", Ans);
  system("pause");
  return Wild_Donkey;
}
/*
5
-2 -8 0 5 -3
5
8 2 10 15 7
*/