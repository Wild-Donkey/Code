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
unsigned a[100005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Prime[10005], CntP(0);
unsigned Sum[100005][1005];
char Flg(0);
bitset<100005> Isnt;
bitset<10000> Have[100005];
bitset<1005> ExPr[1005];
inline void LiSh (unsigned Mx) {
  Isnt[1] = 1;
  for (unsigned i(2); i <= Mx; ++i) {
    if(!(Isnt[i])) Prime[++CntP] = i, Have[i][CntP] = 1;
    for (unsigned j(1); (Prime[j] * i <= Mx) && (j <= CntP); ++j) {
      Isnt[Prime[j] * i] = 1, Have[i * Prime[j]] = Have[Prime[j]] | Have[i];
      if(!(i % Prime[j])) break;
    }
  }
}
inline unsigned Gcd(unsigned x, unsigned y) {
  while (y) Tmp = x, x = y, y = Tmp % y;
  return x;
}
signed main() {
//  freopen("ex_B2.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  LiSh(100000);
//  printf("Cnt %u\n", CntP);
//  for (unsigned i(1); i <= 100; ++i) {
//    for (unsigned j(1); j <= 100; ++j)
//      printf("%u ", (unsigned)Have[i][j]);
//    putchar(0x0A);
//  }
  for (unsigned i(1); i <= n; ++i) {a[i] = RD(); if(a[i] > 1000) Flg = 1;}
  if(n <= 1000) {
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD(), C = RD(), Ans = 0;
      for (unsigned j(A); j <= B; ++j) if(Gcd(a[j], C) == 1) ++Ans;
      printf("%u\n", Ans);
    }
    return 0;
  }
  if(!Flg) {
    for (unsigned i(1); i <= n; ++i) Sum[i][a[i]] = 1;
    for (unsigned i(1); i <= n; ++i) 
      for (unsigned j(0); j <= 1000; ++j)
        Sum[i][j] += Sum[i - 1][j];
    for (unsigned i(0); i <= 1000; ++i) 
      for (unsigned j(i); j <= 1000; ++j)
        ExPr[i][j] = ExPr[j][i] = (Gcd(i, j) == 1);
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD(), C = RD(), Ans = 0;
      for (unsigned j(0); j <= 1000; ++j) if(ExPr[C][j]) Ans += Sum[B][j] - Sum[A - 1][j];
      printf("%u\n", Ans);
    }
    return 0;
  }
//  }
  return Wild_Donkey;
}

