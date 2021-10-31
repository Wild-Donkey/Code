#include <algorithm>
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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long Ans(0), m, n;
unsigned long long A, B, C, D;
unsigned t;
unsigned Cnt(0), Tmp(0);
inline void Clr() {
  n = RD(), A = m = RD(), B = Ans = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
    t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    --n;
    if(!n) {printf("0\n");continue;}
    while (A) ++B, A >>= 1;
//    printf("Times %u\n", B);
    for (unsigned long long i(1), j(1); i <= B; ++i, j <<= 1) {
      if(n <= j) break;
      n -= j, ++Ans;
    }
    if(n) Ans += (n + m - 1) / m;
    printf("%llu\n", Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}

