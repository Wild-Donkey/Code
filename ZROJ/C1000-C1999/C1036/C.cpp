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
unsigned long long f[1000005][2], Ans(1), Tmp(500000004); 
unsigned Deg[1000005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0);
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD() - 1;
  for (unsigned i(1); i <= n; ++i) ++Deg[RD()], ++Deg[RD()];
  for (unsigned i(1); i <= n; i <<= 1) {
  	if(i & n) Ans = Ans * Tmp % Mod;
  	Tmp = Tmp * Tmp % Mod;
  }
  f[0][0] = f[0][1] = f[1][0] = 1, f[1][1] = 3;
  for (unsigned i(2); i <= n; ++i) {
  	f[i][0] = (f[i - 1][1] + (((f[i - 2][0] + f[i - 1][0]) * (i - 1)) << 1)) % Mod;
  	f[i][1] = (f[i][0] + ((f[i - 1][1] * i) << 1)) % Mod;
  }
  for (unsigned i(n + 1); i; --i) Ans = Ans * f[Deg[i]][0] % Mod;
  printf("%llu\n", Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}

