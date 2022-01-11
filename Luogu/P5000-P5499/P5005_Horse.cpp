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
const unsigned long long Mod(1000000007);
unsigned long long Ans(0);
unsigned f[65][65], g[65][65];
unsigned m, n, M;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), M = 1 << (m = RD());
  g[0][0] = 1;
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(0); j < M; ++j) {
      for (unsigned k(0); k < M; ++k) {
        unsigned Verjk(j & k);
        if(!((((j << 2) & ((M - 1) ^ (Verjk << 1))) | ((j >> 2) & ((M - 1) ^ (Verjk >> 1)))) & k & (M - 1))) {
          for (unsigned l(0); l < M; ++l) {
            unsigned Ver(k & l), No(0), Hor(k & (k << 1));
            No |= (((j >> 1) & ((M - 1) ^ (Hor >> 1))) | ((j << 1) & ((M - 1) ^ Hor)));
            No |= (((k >> 2) & ((M - 1) ^ (Ver >> 1))) | ((k << 2) & ((M - 1) ^ (Ver << 1))));
            if(!(No & l & (M - 1))) {
              f[k][l] += g[j][k];
              if(f[k][l] >= Mod) f[k][l] -= Mod;
            }
          }
        }
      }
    }
    memcpy(g, f, sizeof(f));
    memset(f, 0, sizeof(f));
  }
//  for (unsigned i(1); i <= n; ++i) {
//    for (unsigned j(0); j < M; ++j) {
//      printf("f %u %u:\n", i, j);
//      for (unsigned k(0); k < M; ++k) {
//        printf("%u ", f[i][j][k]);
//      }
//      putchar(0x0A);
//    }
//  }
  for (unsigned i(0); i < M; ++i) {
    for (unsigned j(0); j < M; ++j) {
      Ans += g[i][j];
    }
  }
  printf("%llu\n", Ans % Mod);
//  }
  return Wild_Donkey;
}

