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
const unsigned long long Mod(998244353);
unsigned long long Ans(0);
unsigned Log[150005], Bin[20];
unsigned a[150005][20][2], m, n;
unsigned b[3005][3005], Sum[3005][3005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Min(unsigned L, unsigned R) {
  unsigned LgLen(Log[R - L + 1]);
//  printf("Find [%u %u]\n", L, R);
  return min(a[L][LgLen][0], a[R - Bin[LgLen] + 1][LgLen][0]);
}
unsigned Max(unsigned L, unsigned R) {
  unsigned LgLen(Log[R - L + 1]);
//  printf("Find [%u %u]\n", L, R);
  return max(a[L][LgLen][1], a[R - Bin[LgLen] + 1][LgLen][1]);
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i][0][0] = a[i][0][1] = RD();
  for (unsigned i(1), j(0); i <= n; i <<= 1, ++j) Log[i] = j, Bin[j] = i;
  for (unsigned i(1); i <= n; ++i) Log[i] = max(Log[i - 1], Log[i]);
  for (unsigned i(1), j(0); (i << 1) <= n; i <<= 1, ++j) {
    for (unsigned k(n - (i << 1) + 1); k; --k) {
      a[k][j + 1][0] = min(a[k][j][0], a[k + i][j][0]);
      a[k][j + 1][1] = max(a[k][j][1], a[k + i][j][1]);
//      printf("[%u %u] %u\n", k, k + (i << 1) - 1, a[k][j + 1][0]);
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(i); j <= n; ++j) {
      b[i][j] = (b[i][j - 1] + (unsigned long long)Min(i, j) * Max(i, j)) % Mod;
    }
  }
//  printf("Done\n");
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) {
      b[i][j] += b[i - 1][j];
      if(b[i][j] >= Mod) b[i][j] -= Mod;
//      printf("[%u, %u] %u\n", i, j, b[i][j]);
    }
  }
  for (unsigned i(1); i <= m; ++i) {
    A = RD() - 1, B = RD(), C = RD() - 1, D = RD();
    Ans = (Mod << 1) + b[B][D] - b[A][D] - b[B][C] + b[A][C];
    printf("%llu\n", Ans % Mod);
  }
//  }
  return Wild_Donkey;
}

