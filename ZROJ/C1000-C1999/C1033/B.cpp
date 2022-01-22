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
const unsigned long long Mod(258280327);
unsigned long long m, n, Q[2005], f[2005][2005], Ans[2005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
inline unsigned long long Pow(unsigned long long x) {
  unsigned long long PTmp(1);
  unsigned y(Mod - 2);
  while (y) {
    if(y & 1) PTmp = PTmp * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return PTmp;
}
inline void Clr() {
  memset(Ans, 0, (n + 1) << 3);
  n = RD(), Q[1] = RD(), Q[1] = Mod + 1 - (Q[1] * Pow(RD()) % Mod);
  if(Q[1] >= Mod) Q[1] -= Mod;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD(), Q[0] = 1;
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(2); i <= n; ++i) Q[i] = Q[i - 1] * Q[1] % Mod;
    f[0][0] = 1;
    for (unsigned i(1); i < n; ++i) {
      for (unsigned j(1); j <= i; ++j) {
        f[i][j] = (f[i - 1][j] * (Mod + 1 - Q[j])) % Mod;
        f[i][j] = (f[i][j] + f[i - 1][j - 1] * Q[j - 1]) % Mod;
      }
    }
    for (unsigned i(0); i < n; ++i) {
      for (unsigned j(0); j <= i; ++j) {
        Ans[j] = (Ans[j] + f[i][j] * Q[j]) % Mod;
      }
    }
    for (unsigned i(0); i < n; ++i) printf("%u ", Ans[i] * Pow(n) % Mod);
    putchar(0x0A);
  }
  return Wild_Donkey;
}
/*
2
3 40 100
9 32 1049
*/
