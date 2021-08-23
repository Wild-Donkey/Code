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
unsigned a[10005], m, n, Cnt(0), q, A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
inline void Clr() {}
int main() {
  freopen("C.in", "w", stdout);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  srand(time(0));
  n = 5 + rand() % 10, m = 5 + rand() % 10, q = 1000;
  printf("%u %u %u\n", n, m, q);
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = (rand() % 5) + 1;
  }
  sort(a + 1, a + n + 1);
  for (register unsigned i(1); i <= m; ++i) {
    b[i] = (rand() % 5) + 1;
  }
  sort(b + 1, b + m + 1);
  for (register unsigned i(1); i <= n; ++i) {
    printf("%u ", a[i]);
  }
  putchar('\n');
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u ", b[i]);
  }
  putchar('\n');
  for (register unsigned i(1); i <= q; ++i) {
    printf("%u %d\n", 1 + (rand() & 1), (rand() % 100) - 50);
  }
//  }
  return Wild_Donkey;
}

