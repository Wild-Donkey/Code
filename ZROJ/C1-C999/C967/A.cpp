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
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
const unsigned long long MOD(1000000007);
unsigned m, n, Cnt(0);
unsigned long long P, Phi[10000005], Inv[10000005], Prime[1000005], Pow[10000005], Ans(0);
bool NotPrime[10000005];
unsigned long long Power(unsigned long long x) {
  unsigned long long Tmpy(P), TmpAns(1);
  while (Tmpy) {
    if (Tmpy & 1) TmpAns = TmpAns * x % MOD;
    x = x * x % MOD, Tmpy >>= 1;
  }
  return TmpAns;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), Ans = P = RD(), Inv[1] = 1, Phi[1] = 1;
  for (register unsigned i(2); i <= n; ++i) {
    Inv[i] = Inv[MOD % i] * (MOD - MOD / i) % MOD;
  }
  for (register unsigned i(2); i <= n; ++i) {
    if (!NotPrime[i]) {
      Prime[++Cnt] = i, Phi[i] = i - 1, Pow[i] = Power(i);
    }
    for (register unsigned j(1), k; ((k = Prime[j] * i) <= n) && (j <= Cnt); ++j) {
      NotPrime[k] = 1, Phi[k] = Phi[Prime[j]] * Phi[i], Pow[k] = Pow[Prime[j]] * Pow[i] % MOD;
      if (!(i % Prime[j])) {
        Phi[k] /= Prime[j] - 1;
        Phi[k] *= Prime[j];
        break;
      }
    }
  }
  // printf("Cnt %u\n", Cnt);
  for (register unsigned i(2), TmpIP; i <= n; ++i) {
    Ans = (Ans + Phi[i] * (((MOD + Pow[i] - 1) * Inv[i - 1]) % MOD)) % MOD;
  }
  // for (register unsigned i(1); i <= Cnt; ++i) {
  //   printf("%u ", Prime[i]);
  // }
  // putchar('\n');
  // for (register unsigned i(1); i <= n; ++i) {
  //   printf("[%u] %u ", i, Phi[i]);
  // }
  // putchar('\n');
  // for (register unsigned i(1); i <= n; ++i) {
  //   printf("[%u] %u ", i, Inv[i]);
  // }
  // putchar('\n');
  printf("%u\n", Ans);
  // system("pause");
  return Wild_Donkey;
}
/*
100 1000000007
10000000 1000000000
*/