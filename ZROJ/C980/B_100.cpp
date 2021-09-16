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
unsigned a[20], b[20], m, n, M;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
char InTmp[20];
void Shoot(unsigned x, unsigned y) {
  a[x - 1] ^= (1 << y), a[x + 1] ^= (1 << y);
  a[x] ^= (1 << y) ^ (1 << (y + 1));
  if (y) a[x] ^= (1 << (y - 1));
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), M = (1 << m) - 1;
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", InTmp + 1);
    for (unsigned j(1); j <= m; ++j) b[i] <<= 1, b[i] |= ((InTmp[j] ^ 'X') ? 0 : 1);
  }
  for (unsigned i(0); i <= M; ++i) {
    memcpy(a, b, sizeof(b)), Cnt = 0;
    for (unsigned j(0); j < m; ++j) if (i & (1 << j)) Shoot(1, j), ++Cnt;
    for (unsigned j(2); j <= n; ++j) {
      for (unsigned k(0); k < m; ++k) {
        if (a[j - 1] & (1 << k)) Shoot(j, k), ++Cnt;
      }
    }
    if (!(a[n] & M)) Ans = min(Cnt, Ans);
  }
  printf("%u\n", Ans);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
5 5
XX.XX
X.X.X
.XXX.
X.X.X
XX.XX
*/