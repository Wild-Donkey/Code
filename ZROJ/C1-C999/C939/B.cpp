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
unsigned a[10005], m, n, Cnt(0), Sum(0);
unsigned long long Ans(0x3f3f3f3f3f3f3f3f), Tmp, A;
char b[10005];
inline void Clr() {}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    Sum += (a[i] = RDsg() + 4000);
  }
  Sum /= n;
//  printf("Sum/n %u\n", Sum);
  for (register unsigned i(1000); i <= 7000; ++i) {
    Tmp = 0;
    for (register unsigned j(1); j <= n; ++j) {
      A = max(a[j], i) - min(a[j], i);
      Tmp += A * A;
    }
//    printf("%u -> %llu\n", i, Tmp);
    Ans = min(Ans, Tmp);
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
5
5 -2 5 -1 -2

6
-4 -2 6 1 -5 -6

8
8 6 5 -8 -1 -1 -8 5
*/
