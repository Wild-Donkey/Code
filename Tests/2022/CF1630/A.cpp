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
#include <set>
#include <string>
#include <unordered_map>
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
inline void Clr() {
  n = RD(), m = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    if (m < n - 1) {
      printf("%u %u\n", m, n - 1);
      if (m)printf("%u %u\n", 0, ((n - 1) ^ m));
      for (unsigned j(n >> 1), i(j - 1); i; --i, ++j) if ((i ^ m) && (j ^ m)) printf("%u %u\n", i, j);
      continue;
    }
    if (n == 4) { printf("-1\n");continue; }
    printf("%u %u\n", n - 1, n - 2);
    printf("%u %u\n", n - 3, 0);
    printf("%u %u\n", n - 4, 2);
    printf("%u %u\n", 1, 3);
    for (unsigned j(n >> 1), i(j - 1); i > 3; --i, ++j) printf("%u %u\n", i, j);
  }
  // system("pause");
  return Wild_Donkey;
}