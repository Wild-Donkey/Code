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
unsigned long long Fac[100005], Inv[100005], Pow, Poi(Mod - 2);
unsigned long long Cnt(0), Ans(0);
unsigned a[100005], b[100005], Pos[200005], m, n;
unsigned MA(0), MB(0);
unsigned A, B, C, D, t;
unsigned List[15], Tmp[15];
char Ava[15], Flg (0);
inline void DFS (unsigned Dep) {
  if(Dep > n) {
    memcpy(Tmp, List, 44);
    sort(Tmp + 1, Tmp + n + 1);
//    for (unsigned i(1); i <= n; ++i) printf("%u ", Tmp[i]);
//    putchar(0x0A);
    Ans += Tmp[n - m + 1];
  }
  for (unsigned i(1); i <= n; ++i) if(!Ava[i]){
    Ava[i] = 1, List[Dep] = a[Dep] + b[i], DFS(Dep + 1), Ava[i] = 0;
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Inv[n] = Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) MA = max(a[i] = RD(), MA);
  for (unsigned i(1); i <= n; ++i) MB = max(b[i] = RD(), MB);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Pow = Fac[n]; while (Poi) {if(Poi & 1) Inv[n] = Inv[n] * Pow % Mod; Poi >>= 1, Pow = Pow * Pow % Mod;}
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  DFS(1);
  Ans = Ans * Inv[n] % Mod;
  printf("%llu\n", Ans);
  return 0;
//  }
  return Wild_Donkey;
}

