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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
inline void Clr() {}
int main() {
  freopen("A.in", "w", stdout);
  srand(0);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = 5;
  m = (rand() % 10) + 1;
  printf("%u %u\n", n, m);
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(1); j <= m; ++j) {
      putchar('a' + (rand() % 26)); 
    }
    putchar('\n'); 
  }
//  }
  return Wild_Donkey;
}

