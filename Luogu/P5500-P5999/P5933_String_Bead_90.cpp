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
unsigned long long Mod(1000000007);
unsigned long long f[20][66000], Inv[20];
unsigned N, a[20][20], m, n, PopCnt[66000];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  N = 1 << (n = RD()), Inv[0] = Inv[1] = 1;
  for (unsigned i(0); i < n; ++i) for (unsigned j(0); j < n; ++j) a[i][j] = RD() + 1;
  for (unsigned i(0); i < N; ++i) {
    f[0][i] = 1;
    for (unsigned j(0); j < n; ++j) if (i & (1 << j))
      for (unsigned k(0); k < j; ++k) if (i & (1 << k))
        f[0][i] = f[0][i] * a[j][k] % Mod;
  }
  for (unsigned i(0); i < N; ++i) PopCnt[i] = PopCnt[i >> 1] + (i & 1);
  for (unsigned i(2); i <= n; ++i) {
    Inv[i] = Mod - (Inv[Mod % i] * (Mod / i) % Mod); if (Inv[i] >= Mod) Inv[i] -= Mod;
  }
  f[0][1] = f[1][0] = 1;
  for (unsigned i(1); i < N; ++i) {
    f[1][i] = f[0][i];
    for (unsigned k(PopCnt[i]); k > 1; --k) {
      for (unsigned j((i - 1)& i); j; j = i & (j - 1)) if (PopCnt[j] >= k - 1)
        f[k][i] = (f[k][i] + f[k - 1][j] * f[1][i ^ j]) % Mod;
      f[k][i] = f[k][i] * Inv[k] % Mod;
      f[1][i] += Mod - f[k][i];
      if (f[1][i] >= Mod) f[1][i] -= Mod;
    }
    // printf("%u: ", i);
    // for (unsigned j(0); j <= PopCnt[i]; ++j) printf("%llu ", f[j][i]); putchar(0x0A);
  }
  printf("%llu\n", f[1][N - 1]);
  //  }
  // system("pause");
  return Wild_Donkey;
}