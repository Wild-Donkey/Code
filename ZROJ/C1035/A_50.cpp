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
const unsigned long long Mod(1000000007);
unsigned long long f[105][25], Ans(0), C[1005][1005];
unsigned m, n;
unsigned A, B, D, t;
unsigned Cnt(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  f[0][0] = 1;
  for (unsigned i(0); i <= 1000; ++i) {
    C[i][0] = 1;
    for (unsigned j(1); j <= i; ++j) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= Mod) C[i][j] -= Mod;
//      printf("C%u,%u = %llu\n", i, j, C[i][j]);
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD() % m;
    for (unsigned j(0); j < m; ++j) {
      for (unsigned k(0); k <= A; ++k) {
        unsigned From(m + j - (B * k % m));
        if(From >= m) From -= m;
//        printf("%u From %u\n", k, From);
        f[i][j] = (f[i][j] + f[i - 1][From] * C[A][k]) % Mod;
      }
//      printf("f%u, %u = %llu\n", i, j, f[i][j]);
    }
  }
  Ans = Mod + f[n][0] - 1;
  if(Ans >= Mod) Ans -= Mod; 
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/**/ 
