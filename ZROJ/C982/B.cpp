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
const unsigned long long MOD(1000000007);
unsigned long long Fac[100005], Inv[100005], Tmp, Ans(0), a[100005];
unsigned m, n, A;
//  inline void Clr() {}
signed main() {
  // freopen("B.in", "r", stdin);
  // freopen("B.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Fac[0] = 1;
  for (unsigned i(1); i <= n; ++i) Fac[i] = (Fac[i - 1] * i) % MOD;
  Inv[n] = 1, Tmp = Fac[n], A = MOD - 2;
  while (A) { if (A & 1) Inv[n] = Inv[n] * Tmp % MOD; Tmp = Tmp * Tmp % MOD, A >>= 1; }
  for (unsigned i(n - 1); ~i; --i) Inv[i] = (Inv[i + 1] * (i + 1)) % MOD;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  sort(a + 1, a + n + 1);
  for (unsigned i(m); i <= n; ++i)
    Ans = (Ans + ((((Fac[i - 1] * Inv[m - 1] % MOD) * Inv[i - m]) % MOD) * a[i])) % MOD;
  printf("%llu\n", Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}