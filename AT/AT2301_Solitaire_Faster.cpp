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
  for (unsigned i(1), l; i <= n; ++i) {
    f[i][1] = 1, l = min(m, i);
//    printf("Now %u\n", i);
    for (unsigned j(2); j <= l; ++j)
      f[i][j] = f[i][j - 1] + f[i - 1][j - 1] - f[j - 2][j - 1] + Mod, Mn(f[i][j]), Mn(f[i][j]);
    for (unsigned j(1); j <= l; ++j) f[i][j] += f[i - 1][j], Mn(f[i][j]); 
  }
  Ans = (Mod + Mod + f[n][m] - f[n][m - 1] - f[n - 1][m] + f[n - 1][m - 1]) % Mod;
  for (unsigned i(m + 1); i < n; ++i) Ans <<= 1, Mn(Ans);
  printf("%u\n", Ans);
//  }
//  system("pause");
  return Wild_Donkey;
}

