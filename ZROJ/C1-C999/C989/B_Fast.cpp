#include <algorithm>
#include <bitset> 
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
unsigned a[4005][2005];
unsigned m, n, Sz(1000000), Now(Sz);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char RB[1000005];
inline char GC() {
  if (Now == Sz) Now = 0, fread(RB, 1, Sz, stdin);
  return RB[Now++];
}
inline unsigned RD() {
  register unsigned intmp(0);
  register char rdch(GC());
  while (rdch < '0') rdch = GC();
  while (rdch >= '0') intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = GC();
  return intmp;
}
char Check (unsigned x) {
  bitset<4005> BS[n + 5];
//  printf("Check %u\n", x);
  for (unsigned Le(n - 1); Le; --Le) {
    BS[Le].reset();
    if(a[Le][1] <= x) BS[Le][Le + 1] = 1;
    for (unsigned i((n - Le - 1) >> 1); i; --i)
      BS[Le][Le + (i << 1) + 1] = (BS[Le + 1][Le + (i << 1)] && (a[Le][i + 1] <= x));
    for (unsigned i(Le + 1); i <= n; i += 2)
      if(BS[Le][i]) BS[Le] |= BS[i + 1];  
  }
  return BS[1][n];
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = n >> 1;
  for (register unsigned i(1); i <= n; ++i)
    for (register unsigned j(1), Len((n - i + 1) >> 1); j <= Len; ++j)
      a[i][j] = RD();
  unsigned L(1), R((m + 1) * (m - 1));
  for (unsigned Mid((L + R) >> 1); L ^ R; Mid = (L + R) >> 1)
    if(Check(Mid)) R = Mid; else L = Mid + 1;
  printf("%u\n", L);
  //  }
  return Wild_Donkey;
}
