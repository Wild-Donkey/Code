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
unsigned a[1000005];
char b[1000005], Flg(0);
unsigned m, n, nn, A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  nn = ((n = RD()) << 1);
  A = 1, B = nn, Flg = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= nn; ++i) {a[i] = RD();if(a[i] == a[1]) C = D = i;}
    b[1] = b[nn] = 'L', ++A, --C, ++D;
    for (unsigned i(2), j(nn - 1); i <= n; ++i, --j) {
//      printf("[1, %u] [%u, %u] [%u, %u]\n", A, C, D, B, nn);
      if((A < C) && (a[A] == a[C])) {b[i] = b[j] = 'L', ++A, --C; continue;}
      if((D <= B) && (a[A] == a[D])) {b[i] = 'L', b[j] = 'R', ++A, ++D; continue;}
      if((A <= C) && (a[B] == a[C])) {b[i] = 'R', b[j] = 'L', --B, --C; continue;}
      if((D < B) && (a[B] == a[D])) {b[i] = b[j] = 'R', --B, ++D; continue;}
      Flg = 1; break;
    }
    if(!Flg) {for (unsigned i(1); i <= nn; ++i) putchar(b[i]); putchar(0x0A); continue;}
    for (unsigned i(1); i < nn; ++i) if(a[i] == a[nn]) {C = D = i; break;}
//    printf("CD %u %u\n", C, D);
    Flg = 0, b[1] = 'R', b[nn] = 'L', --C, ++D, A = 1, B = nn - 1;
    for (unsigned i(2), j(nn - 1); i <= n; ++i, --j) {
//      printf("[1, %u] [%u, %u] [%u, %u]\n", A, C, D, B, nn);
      if((A < C) && (a[A] == a[C])) {b[i] = b[j] = 'L', ++A, --C; continue;}
      if((D <= B) && (a[A] == a[D])) {b[i] = 'L', b[j] = 'R', ++A, ++D; continue;}
      if((A <= C) && (a[B] == a[C])) {b[i] = 'R', b[j] = 'L', --B, --C; continue;}
      if((D < B) && (a[B] == a[D])) {b[i] = b[j] = 'R', --B, ++D; continue;}
      Flg = 1; break;
    }
    if(!Flg) {for (unsigned i(1); i <= nn; ++i) putchar(b[i]); putchar(0x0A); continue;}
    printf("-1\n");
  }
  return Wild_Donkey;
}
/*
1
4
3 1 2 3 4 4 2 1
*/
