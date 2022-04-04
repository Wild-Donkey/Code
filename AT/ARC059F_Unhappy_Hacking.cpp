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
unsigned long long Fac[5005], Inv[5005], Two[5005], g[5005], f[5005], Ans(0);
unsigned m, n;
inline unsigned long long Inver(unsigned long long x) {
  unsigned long long Rt(1);
  unsigned y(1000000005);
  while (y) { if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1;}
  return Rt;
}
inline unsigned long long Solve(unsigned x) {
  unsigned Typ((x + m) >> 1);
  unsigned long long A(Two[Typ - m]), B(Inv[Typ] * Inv[x - Typ] % Mod);
  A = A * Fac[x] % Mod;
  B = B * A % Mod, Typ = x - Typ;
  if(Typ) --Typ, A = A * Inv[Typ] % Mod, A = A * Inv[x - Typ] % Mod;
  else A = 0;
//  printf("%u: %llu\n", x, (Mod + B - A) % Mod);
  return Mod + B - A;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  n = RD(), f[0] = g[0] = Fac[0] = Two[0] = 1;
  while (getchar() >= '0') ++m;
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[n] = Inver(Fac[n]);
  for (unsigned i(n); i; --i) Inv[i - 1] = Inv[i] * i % Mod;
  for (unsigned i(1); i <= n; ++i) Two[i] = (Two[i - 1] << 1), Two[i] -= (Two[i] >= Mod) ? Mod : 0;
  for (unsigned i(n >> 1); i; --i)
    g[i] = (((Fac[i << 1] * Inv[i + 1] % Mod) * Inv[i] % Mod) * Two[i]) % Mod;
  for (unsigned i(1); i <= n; ++i) for (unsigned j((i - 1) >> 1); ~j; --j)
    f[i] = (f[i] + f[i - 1 - (j << 1)] * g[j]) % Mod;
  for (unsigned i(n - m); ~i; --i) if(!(((n - i) ^ m) & 1))
    Ans = (Ans + f[i] * Solve(n - i)) % Mod;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
//10 00000
