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
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[100005], b[100005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
inline void Clr() {}
int main() {
  // double Ti(clock()), Mti(0);
  freopen("my.out", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  freopen("std.out", "r", stdin);
  for (register unsigned i(1); i <= n; ++i) {
    b[i] = RD();
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(a[i] == 0) {
      printf("-!-!-%u-!-!-\n", i);
    }
    if(a[i] ^ b[i]) {
      printf("%u!!!%u!!!%u\n", a[i], i, b[i]);
    }
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



