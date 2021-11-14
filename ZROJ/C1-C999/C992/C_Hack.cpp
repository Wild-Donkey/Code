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
inline int RD() {
  int intmp(0);
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
int P(5), m, n;
int A, B, C, D, t;
int Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  freopen("C.in", "w", stdout);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (int T(1); T <= t; ++T){
//  Clr();
  n = (P + 1) * 7; m = ((n - 1) * n) >> 1;
  printf("%u %u\n", n, m);
  for (int j(1); j < n; ++j) {
    for (int k(j + 1); k <= n; ++k) {
      printf("%u %u\n", j, k);
    }
  }
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

