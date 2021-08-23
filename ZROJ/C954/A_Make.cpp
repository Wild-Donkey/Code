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
long long a[10005], m, n, q, Cnt(0), A, B, C, D, E, t, Ans(0), Tmp(0);
char b[2005][2005];
long long Rand(long long L, long long R) {
  return (((long long)rand() * rand()) % (R - L + 1)) + L;
}
int main() {
  freopen("A.in", "w", stdout);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  n = Rand(1, 2000);
  m = Rand(-1000000, 1000000);
  q = Rand(-1000000, 1000000);
  printf("%d %d %d\n", n, m, q);
  for (register unsigned i(1); i <= n; ++i) {
    printf("%d ", Rand(-1000000, 1000000));
  }
  putchar('\n');
//  }
  return Wild_Donkey;
}

