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
unsigned a[10005], m, n, M;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
char InTmp[20];
unsigned DFS(char x, char y, unsigned Puted) {
  // printf("(%u, %u)Now Situation:\n", x, y);
  // for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, a[i]);
  if (y > m) y = 1, ++x;
  if (x > n) {
    // printf("Judge:\n");
    // for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, a[i]);
    for (char i(1); i <= n; ++i) if (a[i]) return 0x3f3f3f3f;
    return Puted;
  }
  a[x - 1] ^= 1 << (y - 1), a[x + 1] ^= 1 << (y - 1);
  a[x] ^= (1 << (y - 1)) ^ (1 << (y));
  if (y > 1) a[x] ^= (1 << (y - 2));
  a[x] &= M;
  unsigned TmpD(DFS(x, y + 1, Puted + 1));
  a[x - 1] ^= 1 << (y - 1), a[x + 1] ^= 1 << (y - 1);
  a[x] ^= (1 << (y - 1)) ^ (1 << (y));
  if (y > 1) a[x] ^= (1 << (y - 2));
  a[x] &= M;
  return min(TmpD, DFS(x, y + 1, Puted));
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
    for (unsigned j(1); j <= m; ++j) a[i] <<= 1, a[i] |= ((InTmp[j] ^ 'X') ? 0 : 1);
    // printf("%u %u\n", i, a[i]);
  }
  printf("%u\n", DFS(1, 1, 0));
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
2 2
XX
X.
5 5
XX.XX
X.X.X
.XXX.
X.X.X
XX.XX
*/