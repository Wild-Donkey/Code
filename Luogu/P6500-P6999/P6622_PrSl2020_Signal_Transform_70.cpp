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
unsigned f[8400000], Pre[25][25], Suf[25][25], m, n, K, M(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), M = ((1 << (m = RD())) - 1), K = RD(), B = RD() - 1;
  for (unsigned i(1); i < n; ++i) A = RD() - 1, ++Pre[A][B], ++Suf[B][A], B = A;
  memset(f + 1, 0x3f, M << 2);
  for (unsigned i(0); i < M; ++i) {
    unsigned Ppc(0), I(i);
    while (I) Ppc += (I & 1), I >>= 1;
    for (unsigned j(0); j < m; ++j) if(!((i >> j) & 1)) {
      unsigned &J(f[i | (1 << j)]), Add(0);
      for (unsigned k(0); k < m; ++k) if(k ^ j) {
        if((i >> k) & 1) Add += Suf[j][k] * K + Pre[j][k];
        else Add += Pre[j][k] * K - Suf[j][k];
      }
//      printf("%u %u %u\n", i, j, Add);
      J = min(J, f[i] + Add * (Ppc + 1));
    }
//    printf("%u ", f[i]);
  }
  printf("%u\n", f[M]);
//  }
  return Wild_Donkey;
}
