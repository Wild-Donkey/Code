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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Prime[20005], CntP(0);
bitset<210005> Isnt;
inline void Clr() {
  n = RD();
}
inline void Cho() {
  for (unsigned i(2); i <= 210000; ++i) {
//    printf("Do %u\n", i);
    if(!Isnt[i]) Prime[++CntP] = i;
    for (unsigned j(1); (Prime[j] * i <= 210000) && (j <= CntP); ++j) {
      Isnt[i * Prime[j]] = 1;
      if(!(i % Prime[j])) break;
    }
  }
//  printf("P %u\n", CntP);
//  for (unsigned i(1); i <= CntP; ++i) printf("%u ", Prime[i]);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  Cho();
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    A = *lower_bound(Prime + 1, Prime + CntP + 1, n + 1);
    B = *lower_bound(Prime + 1, Prime + CntP + 1, n + A);
    printf("%llu\n", (unsigned long long)A * B);
  }
  return Wild_Donkey;
}
/*
8
1
2
3
10
100
1000
10000
100000
*/
