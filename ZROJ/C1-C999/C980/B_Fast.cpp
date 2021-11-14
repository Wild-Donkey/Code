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
unsigned a[20], b[20], M;
unsigned char Cnt(0), Ans(0xff);
unsigned char Tmp(0), Count[132000];
char InTmp[20], m, n;
void Shoot(unsigned x) {
  a[x] ^= (a[x - 1] << 1) ^ (a[x - 1] >> 1) ^ a[x - 1];
  a[x + 1] ^= a[x - 1], a[x] &= M;
}
signed main() {
  n = RD(), m = RD(), M = (1 << m) - 1;
  for (unsigned i(1), j(1); i <= M; ++i, j = i)
    while (j) { if (j & 1) ++Count[i]; j >>= 1; }
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", InTmp + 1);
    for (unsigned j(1); j <= m; ++j) b[i] <<= 1, b[i] |= ((InTmp[j] ^ 'X') ? 0 : 1);
  }
  for (unsigned i(0); i <= M; ++i) {
    memcpy(a, b, sizeof(b)), Cnt = 0;
    a[0] = i, Shoot(1), Cnt += Count[i];
    for (char j(2); j <= n; ++j) Shoot(j), Cnt += Count[a[j - 1]];
    if (!(a[n] & M)) Ans = min(Cnt, Ans);
  }
  printf("%u\n", Ans);
  // system("pause");
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