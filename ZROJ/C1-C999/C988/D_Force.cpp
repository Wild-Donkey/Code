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
#define C(x,y) (((Fac[x]*Inv[(x)-(y)]%MOD)*Inv[y])%MOD)
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
const unsigned long long MOD(1000000007);
unsigned long long Fac[400], Inv[400], PowerTmp;
unsigned long long f[355][355][2];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt[355], Ans(0), Tmp(1000000005);
void DFS(unsigned Dep) {
  if (Dep == n + 1) {
    for (unsigned i(1); i <= n; ++i) if (Cnt[i] == i) { ++Ans; return; }
    return;
  }
  if (Dep == 5) Ans %= MOD;
  for (unsigned i(1); i <= n; ++i) ++Cnt[i], DFS(Dep + 1), --Cnt[i];
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), DFS(1);
  printf("%u\n", Ans % MOD);
  //  }
  system("pause");
  return Wild_Donkey;
}