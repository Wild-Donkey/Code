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
//unordered_map <unsigned, unsigned> f[8200][13];
unsigned f[8200][13][501];
unsigned Pop[8200], Cost[13][13], a[13], m, n, N, Mx(0);
unsigned long long Ans(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  N = (1 << (n = RD())) - 1, m = RD(); 
  for (unsigned i(0); i < n; ++i) {a[i] = RD(); if(a[i] > a[Mx]) Mx = i;}
//  printf("%u %u\n", Mx, m);
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j < n; ++j) {
    Cost[i][j] = a[i] - a[j] + (i < j);
    Cost[i][j] = (Cost[i][j] > 0x3f3f3f3f) ? 0 : Cost[i][j];
//    printf("%u %u : %u\n", i, j, Cost[i][j]);
  }
  for (unsigned i(0), j; i < n; ++i) if((j = n * Cost[Mx][i]) <= m) f[1 << i][i][m - j] = 1;
  for (unsigned i(0); i < N; ++i) {
    unsigned Pi(n - (Pop[i] = Pop[i >> 1] + (i & 1)));
    for (unsigned j(0); j < n; ++j) if((i >> j) & 1) {
      for (unsigned k(0); k < n; ++k) if(!((i >> k) & 1)) {
        unsigned Use(Pi * Cost[j][k]);
//        printf("%u %u -> %u: %u\n", i, j, k, Use);
//        for (auto l:f[i][j]) if(l.first >= Use) f[i + (1 << k)][k][l.first - Use] += l.second;
        for (unsigned l(Use); l <= m; ++l) f[i + (1 << k)][k][l - Use] += f[i][j][l];
      }
    }
  }
//  for (unsigned i(0); i < N; ++i) for (unsigned j(0); j < n; ++j) 
//    for (auto k:f[i][j]) printf("f %u %u %u: %u\n", i, j, k.first, k.second);
//  for (unsigned i(0); i < n; ++i) for (auto j:f[N][i]) Ans += j.second;
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j <= m; ++j) Ans += f[N][i][j];
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

