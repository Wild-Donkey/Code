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
unsigned long long a[2005][2005], Up[2005][2005], Down[2005], m, n, A, B, C, D, t, Ans(0), Tmp(0);
char Ch(0);
inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      while (Ch ^ '0' && Ch ^ '1') Ch = getchar();
      a[i][j] = (Ch - '0') ^ 1;
      Ch = 0;
    }
  }
  for (register unsigned j(1); j <= m; ++j) {
    for (register unsigned i(1); i <= n; ++i) {
      if(!a[i - 1][j]) Up[i][j] = 0;
      else Up[i][j] = Up[i - 1][j] + 1;
    }
  }
  for (register unsigned j(1); j <= m; ++j) {
    for (register unsigned i(n); i; --i) {
      if(!a[i + 1][j]) Down[i] = 0;
      else Down[i]= Down[i + 1] + 1;
      Up[i][j] = min(Up[i][j], Down[i]);
    }
  }
  for (register unsigned i(2); i < n; ++i) {
    for (register unsigned j(1), Cnt(0); j <= m; ) {
      while (a[i][j] == 0 && j <= m) ++j;
      while (a[i][j]) ++Cnt, ++j;
      if(Cnt) {
        sort(Up[i] + j - Cnt, Up[i] + j);
        for (register unsigned k(j - Cnt); k < j; ++k) {
          Ans += Up[i][k] * (j - k - 1);
        }
        Cnt = 0;
      }
    }
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

