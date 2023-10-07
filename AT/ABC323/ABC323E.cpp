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
#define foreplay for
#define wild while
const unsigned long long Mod(998244353);
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
inline unsigned long long Inv(unsigned long long x) {
  unsigned long long Rt(1), y(998244351);
  while (y) {
    if (y & 1) Rt = Rt * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return Rt;
}
inline void Mns(unsigned &x) { x -= (x >= Mod) ? Mod : 0; }
unsigned long long N;
unsigned f[10005], t[1005], m, n;
unsigned A, B, C, D;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), f[0] = 1, N = Inv(n);
  for (unsigned i(1); i <= n; ++i) t[i] = RD();
  for (unsigned i(1); i <= m; ++i) {
    for (unsigned j(1); j <= n; ++j)
      if (i >= t[j]) Mns(f[i] += f[i - t[j]]);
    f[i] = f[i] * N % Mod;
  }
  for (unsigned i(0); i < t[1]; ++i)
    if (m >= i) Mns(Ans += f[m - i]);
  printf("%llu\n", Ans * N % Mod);
  //  }
  //  system("pause");
  return Wild_Donkey;
}