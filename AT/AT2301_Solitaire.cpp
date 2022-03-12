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
const unsigned long long Mod(1000000007);
inline void Mn (unsigned& x) {x -= (x >= Mod) ? Mod : 0;}
unsigned f[2005][2005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) {
    f[i][1] = 1;
//    printf("Now %u\n", i);
    for (unsigned j(min(m, i)); j > 1; --j) {
      for (unsigned k(j - 1); k < i; ++k) {
        for (unsigned l(1); l < j; ++l) {
          f[i][j] += f[k][l], Mn(f[i][j]);
        }
      }
    }
  }
  for (unsigned i(1); i < n - m; ++i) f[n][m] <<= 1, Mn(f[n][m]);
  printf("%u\n", f[n][m]);
//  }
//  system("pause");
  return Wild_Donkey;
}

