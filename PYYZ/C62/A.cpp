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
inline void Mn(unsigned& x) {x -= ((x >= Mod) ? Mod : 0);}
unsigned Two[1000005], f[1000005], Sum[1000005], m, n;
unsigned long long Ans(0);
unsigned A, B, C, D, t;
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Sum[0] = f[0] = Two[0] = 1;
  for (unsigned i(1); i <= n; ++i) Two[i] = (Two[i - 1] << 1), Mn(Two[i]);
  Ans = (Ans + (unsigned long long)Two[n >> 1] * n) % Mod;
  for (unsigned i(1); i <= ((n - 1) >> 1); ++i) f[i] = Two[i], Sum[i] = Sum[i - 1] + f[i], Mn(Sum[i]);
  for (unsigned i((n + 1) >> 1); i <= n; ++i)
    f[i] = Mod + Sum[i - 1] - Sum[(i << 1) - n], Mn(f[i]), Sum[i] = Sum[i - 1] + f[i], Mn(Sum[i]);
  for (unsigned i(1); i <= n; ++i)
    Ans = (Ans + i * ((unsigned long long)Two[i >> 1] * f[n - i] % Mod)) % Mod;
//  for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, (unsigned long long)Two[i >> 1] * f[n - i] % Mod);
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

