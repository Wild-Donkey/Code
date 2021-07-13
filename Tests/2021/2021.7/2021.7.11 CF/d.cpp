#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
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
const unsigned MOD(998244353);
unsigned Factorial[100005], Inverse[100005], Sum(0), m, n, Cnt0(0), Cnt1(0), A, B, C, D, t, Ans(0), Tmp(0);
char a[100005], Ch;
inline void Clr() {
  n = RD(), Sum = Cnt0 = Cnt1 = Ch = 0;
}
inline unsigned Power (unsigned x, unsigned y){
  unsigned PowerTmp(1);
  while (y){
    if (y & 1) PowerTmp = ((unsigned long long)PowerTmp * x) % MOD;
    x = ((unsigned long long)x * x) % MOD;
    y >>= 1;
  }
  return PowerTmp;
}
int main() {
  Factorial[0] = 1;
  for (register unsigned i(1); i <= 100000; i++) {
    Factorial[i] = ((unsigned long long)Factorial[i - 1] * i) % MOD;
  }
  Inverse[100000] = Power(Factorial[100000], MOD - 2);
  for (register unsigned i(99999); i; i--) {
    Inverse[i] = ((unsigned long long)Inverse[i + 1] * (i + 1)) % MOD;
  }
  Inverse[0] = Inverse[1];
  t = RD();
  for (register unsigned T(1); T <= t; ++T){
    Clr();
    while ((Ch ^ '1') && (Ch ^ '0')) Ch = getchar();
    for (register unsigned i(1); i <= n; ++i) {
      a[i] = Ch - '0';
      if(!a[i]) ++Cnt0;
      Ch = getchar();
    }
    for (register unsigned i(2); i <= n; ++i) {
      if((a[i] == 1) && (a[i - 1] == 1)) {
        a[i] = a[i - 1] = 0;
        ++Cnt1;
      }
    }
    Cnt1 += Cnt0 + 1, Cnt1 -= 1, swap(Cnt1, Cnt0);
    printf("%u\n", ((((unsigned long long)Factorial[Cnt0] * Inverse[Cnt1]) % MOD) * (unsigned long long)Inverse[Cnt0 - Cnt1]) % MOD);
  }
  return Wild_Donkey;
}

