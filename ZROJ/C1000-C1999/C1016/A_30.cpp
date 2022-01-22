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
unsigned long long Fac[300005], Inv[300005], Sum[300005];
unsigned a[300005], Fall[300005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(1), Tmp(0);
unsigned long long Pow(unsigned long long x) {
  unsigned long long PTm(1);
  unsigned y(Mod - 2);
  while (y) {
    if(y & 1) PTm = PTm * x % Mod;
    x = x * x % Mod, y >>= 1;
  }
  return PTm;
}
signed main() {
    freopen("ex_a3.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), a[n + 1] = 0x3f3f3f3f, Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (unsigned i(1); i <= n; ++i) Fac[i] = Fac[i - 1] * i % Mod;
  Inv[n] = Pow(Fac[n]);
  for (unsigned i(n - 1); ~i; --i) Inv[i] = Inv[i + 1] * (i + 1) % Mod;
  for (unsigned i(1), j(1); i <= n; ++i)
    if(a[i] < a[i + 1]) Fall[++Cnt] = i + 1 - j, j = i + 1;
//  for (unsigned i(1); i <= n; ++i) printf("%llu %llu\n", Inv[i], Fac[i]);
  for (unsigned i(Cnt); i; --i) Sum[i] = Sum[i + 1] + Fall[i];
  Ans = Inv[n - 1];
  for (unsigned i(Cnt); i > 1; --i) Ans = Ans * Sum[i] % Mod;
  for (unsigned i(Cnt); i; --i) Ans = Ans * Fac[Fall[i] - 1] % Mod;
  printf("%llu\n", Pow(Ans));
  //  }
  //  system("pause");
  return Wild_Donkey;
}
 
