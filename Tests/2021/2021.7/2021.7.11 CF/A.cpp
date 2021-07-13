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
unsigned a[10005], b[10005], Suma, Sumb, m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Stack[10005][2], Hd0(0), Hd1(0);
inline void Clr() {
  n = RD(), Hd0 = Hd1 = Suma = Sumb = 0;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    for (register unsigned i(1); i <= n; ++i) {
      Suma += (a[i] = RD());
    }
    for (register unsigned i(1); i <= n; ++i) {
      Sumb += (b[i] = RD());
    }
    if(Suma ^ Sumb) {printf("-1\n"); continue;}
    for (register unsigned i(1); i <= n; ++i) {
      while (a[i] > b[i]) {
        --a[i], Stack[++Hd0][0] = i;
      }
      while (a[i] < b[i]) {
        ++a[i], Stack[++Hd1][1] = i;
      }
    }
    printf("%u\n", Hd0);
    for (register unsigned i(1); i <= Hd0; ++i) {
      printf("%u %u\n", Stack[i][0], Stack[i][1]);
    }
  }
  return Wild_Donkey;
}

