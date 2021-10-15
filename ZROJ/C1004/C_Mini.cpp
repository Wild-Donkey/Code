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
unsigned long long Fac[405], Inv[405], Pow, Poi(Mod - 2);
unsigned long long Cnt(0), Ans(0);
unsigned long long C[405][405];// Binom
unsigned long long DP[405]; // chosed i pairs to <= x 
unsigned long long f[405];  // x = x - 1, h
unsigned long long g[405];  // at least i pairs <= x
unsigned long long h[405];  // i pairs  <= x
unsigned a[405], b[405], Pos[805], m, n;
unsigned MA(0), MB(0), A, B;
char Flg (0);
signed main() {
  n = RD(), m = RD(), Inv[n] = Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) MA = max(a[i] = RD(), MA);
  for (unsigned i(1); i <= n; ++i) MB = max(b[i] = RD(), MB);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  MA += MB;
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Pow = Fac[n]; while (Poi) {if(Poi & 1) Inv[n] = Inv[n] * Pow % Mod; Poi >>= 1, Pow = Pow * Pow % Mod;}
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  b[n + 1] = 0x3f3f3f3f;
  for (unsigned i(1), j(1); i <= n; ++i)
    while (j < b[i]) Pos[j++] = i - 1;
  for (unsigned i(MA); !(Pos[i]); --i) Pos[i] = n;
  for (unsigned i(1); i <= n; ++i) {
    C[i][0] = C[i][i] = 1;
    for (unsigned j(1); j < i; ++j){
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
      if(C[i][j] >= Mod) C[i][j] -= Mod;
    }
  }
  m = n - m + 1;
  for (unsigned x(1); x <= MA; ++x) {
    memset(DP, 0, sizeof(DP));
    memcpy(f, h, sizeof(h));
    Cnt = 0, DP[0] = 1;
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(i); j; --j)
        if((x > a[n - i + 1]) && (Pos[x - a[n - i + 1]] >= j))
          DP[j] = (DP[j] + DP[j - 1] * (Pos[x - a[n - i + 1]] - j + 1)) % Mod;
    for (unsigned i(1); i <= n; ++i) g[i] = DP[i] * Fac[n - i] % Mod;
    memset(h, 0, sizeof(h));
    for (unsigned i(1); i <= n; ++i)
      for (unsigned j(i); j <= n; ++j)
        if((j + i) & 1) {h[i] = (h[i] + Mod - ((C[j][i] * g[j]) % Mod)); if(h[i] >= Mod) h[i] -= Mod;}
        else h[i] = (h[i] + C[j][i] * g[j]) % Mod;
    for (unsigned i(m); i <= n; ++i) {
      Cnt += Mod + h[i] - f[i];
      while(Cnt >= Mod) Cnt -= Mod;
    }
    Ans = (Ans + Cnt * x) % Mod;
  }
  Ans = Ans * Inv[n] % Mod;
  printf("%llu\n", Ans);
  return Wild_Donkey;
}

