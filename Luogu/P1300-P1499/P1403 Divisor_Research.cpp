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
unsigned a[1000005], Pri[79005], Fac, m, n, Cnt(0), A, B, C, D, t, Ans(1), Tmp(0);
bool b[1000005];
inline void Clr() {}
unsigned Get(unsigned x) {
  if(!b[x]) {
    return 2;
  }
  unsigned tmp(1), Sq(x);
  for (register unsigned i(1); Pri[i] <= x, i <= Cnt; ++i) {
//    printf("Pri[%u] = %u, x = %u\n", i, Pri[i], x);
    if(!(x % Pri[i])) {
      Fac = 0;
      while(!(x % Pri[i])) {
        ++Fac;
        x /= Pri[i];
      }
      return a[x] * (Fac + 1);
    }
  }
  return tmp;
}
int main() {
  // double Ti(clock()), Mti(0);
//   freopen("P1403_0.in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  a[1] = 1;
  n = RD();
  for (register unsigned i(2); i <= n; ++i) {
    if(!b[i]) {
      Pri[++Cnt] = i;
    }
    for (register unsigned j(1); j <= Cnt, Pri[j] * i <= n; ++j) {
      b[Pri[j] * i] = 1;
      if (!(i % Pri[j])) {
        break;
      }
    }
  }
//  for (register unsigned i(1); i <= Cnt; ++i) {
//    printf("%u -> %u\n", i, Pri[i]);
//  }
  for (register unsigned i(2); i <= n; ++i) {
    a[i] = Get(i);
    Ans += a[i];
//    printf("%u %u\n", i, a[i]);
  }
  printf("%u\n", Ans);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}


