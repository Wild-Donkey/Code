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
unsigned n;
long long a[1000005], K, B, Cnt(0), A, Ans(0), Tmp(0);
inline void Clr() {}
int main() {
  freopen("A.in", "r", stdin);
  freopen("A.ans", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), K = RDsg(), B = RDsg();
  Ans = B;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RDsg();
  }
  for (register unsigned i(1); i <= n; ++i) {
    for (register unsigned j(i); j <= n; ++j) {
      Tmp = B;
      for (register unsigned k(i); k <= j; ++k) {
        Tmp += a[k] * K;
      }
      Ans = max(Ans, Tmp);
    }
  }
  printf("%lld\n", Ans);
//  }
  return Wild_Donkey;
}
/*
2 -1 0
-2 2
*/
