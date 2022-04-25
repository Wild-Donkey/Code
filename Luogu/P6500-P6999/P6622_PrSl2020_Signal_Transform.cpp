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
#define Lbt(x) ((x)&((~(x))+1))
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
int K, g[4194304][23], f[8388608], Pre[23][23];
unsigned A, B, m, n, M, M2;
inline unsigned T(unsigned x, unsigned y) {return ((x & ((1 << y) - 1)) | ((x >> (y + 1)) << y));}
inline unsigned IT(unsigned x, unsigned y) {return ((x & ((1 << y) - 1)) | ((x >> y) << (y + 1)));}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), M2 = ((M = ((1 << (m = RD())) - 1)) >> 1), K = RD(), B = RD() - 1;
  for (unsigned i(1); i < n; ++i) ++Pre[A = RD() - 1][B], B = A;
  memset(f + 1, 0x3f, M << 2);
  for (unsigned i(0); i < m; ++i) for (unsigned j(0); j < m; ++j)
    if(j ^ i) g[0][i] += K * Pre[i][j] - Pre[j][i];
  for (unsigned i(1); i < M; ++i) {
    unsigned k, kk(0); 
    while (!((i >> kk) & 1)) ++kk; k = (i ^ (1 << kk));
    for (unsigned j(0); j < m; ++j) if(!((i >> j) & 1))
      g[T(i, j)][j] = g[T(k, j)][j] - (K - 1) * Pre[j][kk] + (K + 1) * Pre[kk][j];
  }
  for (unsigned i(0); i <= M2; ++i) {
    unsigned I(i);
    int Ppc(0);
    while (I) Ppc += (I & 1), I >>= 1;
    for (unsigned j(0), ji; j < m; ++j) {
      int &J(f[(ji = IT(i, j)) | (1 << j)]);
      J = min(J, f[ji] + g[i][j] * (Ppc + 1));
    }
//    printf("%u ", f[i]);
  }
  printf("%d\n", f[M]);
//  }
  return Wild_Donkey;
}

