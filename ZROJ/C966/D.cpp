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
unsigned long long MOD(2148473647), n;
unsigned long long Power(unsigned long long x) {
  register unsigned Tmpy(MOD - 2);
  x %= MOD;
  register unsigned long long TmpA(1);
  while (Tmpy) {
    if (Tmpy & 1) {
      TmpA = TmpA * x % MOD;
    }
    Tmpy >>= 1, x = x * x % MOD;
  }
  return TmpA;
}
signed main() {
  n = RD();
  printf("%u\n", (((((unsigned long long)n * n) + n) % MOD) * Power((n << 2) - 2)) % MOD);
  return Wild_Donkey;
}
