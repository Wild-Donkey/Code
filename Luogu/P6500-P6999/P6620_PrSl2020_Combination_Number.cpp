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
unsigned Str[1005][1005], a[1005], b[1005], C1P[1005], m, n;
unsigned long long C, Mod, Fac(1), CP(1), Ans(0);
inline unsigned long long Pow(unsigned long long x, unsigned y) {
  unsigned long long Rt(1); 
  while (y) {if(y & 1) Rt = Rt * x % Mod; x = x * x % Mod, y >>= 1;}
  return Rt;
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), C = RD(), Mod = RD(), m = RD(), Str[0][0] = 1;
  for (unsigned i(0); i <= m; ++i) a[i] = RD();
  for (unsigned i(1); i <= m; ++i) {
    Str[i][0] = 0;
    for (unsigned long long j(1); j <= i; ++j)
      Str[i][j] = (j * Str[i - 1][j] + Str[i - 1][j - 1]) % Mod;
  }
//  for (unsigned i(0); i <= m; ++i) {
//    for (unsigned long long j(0); j <= m; ++j) printf("%u ", Str[i][j]); putchar(0x0A); 
//  }
  memset(b, 0, (m + 1) << 2);
  for (unsigned i(0); i <= m; ++i) for (unsigned j(i); j <= m; ++j)
    b[i] = (b[i] + (unsigned long long)a[j] * Str[j][i]) % Mod;
  C1P[m] = Pow(C + 1, n - m);
//  printf("Done");
  for (unsigned i(m); i; --i) C1P[i - 1] = C1P[i] * (C + 1) % Mod;
//  for (unsigned i(0); i <= m; ++i) printf("%u ", C1P[i]); putchar(0x0A);
  for (unsigned i(0); i <= m; ++i) {
    Ans = (Ans + (((CP * C1P[i] % Mod) * b[i] % Mod) * Fac)) % Mod;
    CP = CP * C % Mod, Fac = Fac * (n - i) % Mod;
  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

