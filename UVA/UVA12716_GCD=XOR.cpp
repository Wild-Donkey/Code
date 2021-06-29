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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans[30000005], Tmp(0), Sq;
bool b[10005];
inline void Clr() {
  n = RD();
}
inline unsigned Gcd (unsigned x, unsigned y) {
  if(y) {
    return Gcd (y, x % y);
  } else {
    return x;
  }
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  for (register unsigned i(1); i <= 10000000; ++i) {
    for (register unsigned j(i + (i << 1)); j <= 30000000; j += i) {
      if(((j - i) ^ j) == i) {
        Ans[j]++;
      }
    }
  }
  for (register unsigned i(2); i <= 30000000; ++i) {
    Ans[i] += Ans[i - 1];
  }
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    printf("Case %u: %u\n", T, Ans[RD()]);
  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



