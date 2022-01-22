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
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
signed main() {
  freopen("C.in", "w", stdout);
//  freopen(".out", "w", stdout);
  srand(time(0));
  t = 10;
  printf("%u\n", t);
  for (unsigned T(1); T <= t; ++T) {
    n = rand() + 1, m = (rand() % n) + 1; 
    printf("%u %u\n", n, m);
    for (unsigned i(1); i < n; ++i) printf("%u %u\n", i + 1, (rand() % i) + 1);
    for (unsigned i(1); i <= n; ++i) printf("%u ", (rand() * rand()) % 11);
    putchar(0x0A);
  }
  return Wild_Donkey;
}

