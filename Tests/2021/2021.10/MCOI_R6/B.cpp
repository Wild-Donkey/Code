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
  unsigned intmp = 0;
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
unsigned a[10005], m, n, Cnt(0);
unsigned A, B, C, D, t, Tmp(0), Ans[1000005];
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Cnt = 1, Tmp = 0;
    n = RD(), m = RD(), C = RD();
    if(n * m % C) {printf("NO\n");continue;}
    printf("YES\n");
    for (unsigned i(1); i <= n; ++i) {
      if(i & 1) {
        for (unsigned j(1); j <= m; ++j) {
          ++Tmp;
          if(Tmp > C) Tmp = 1, ++Cnt;
          printf("%u ", Cnt);
        }
        putchar('\n');
      } else {
        for (unsigned j(m); j; --j) {
          ++Tmp;
          if(Tmp > C) Tmp = 1, ++Cnt;
          Ans[j] = Cnt;
        }
        for (unsigned j(1); j <= m; ++j) printf("%u ", Ans[j]);
        putchar('\n');
      }
    }
  }
  return Wild_Donkey;
}


