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
unsigned a[10005], m, n, f[5005][5005], Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), p;
bool b[10005];
inline void Clr() {}
int main() {
  n = RD(), p = RD();
  for (register unsigned i(1); i <= n; ++i) {
    f[i][i] = 1;
  }
  for (register unsigned i(2); i <= n; ++i) {
    for (register unsigned j(1); j < i; ++j) {
      for (register unsigned k(1); k <= j; ++k) {
        f[i][j] += f[i - j][k];
        if(f[i][j] >= p) f[i][j] -= p;
      }
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    Ans += f[n][i];
    if(Ans >= p) Ans -= p;
  }
  printf("%u\n", Ans);
  return Wild_Donkey;
}
