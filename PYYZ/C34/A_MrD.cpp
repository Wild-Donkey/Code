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
inline unsigned long long RD() {
  unsigned long long intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
bitset<22000005> Ava;
unsigned Pri[1400005], CntP(0);
unsigned char Cp[22000005];
int Mu[22000005], D[22000005];
long long PM[5005], PD[5005];
unsigned long long n;
long long Ans(0), H(1);
unsigned m, A, B, C, t;
unsigned Cnt(0), Tmp(0);
inline void GM() {
  for (unsigned long long xx(n / (m + 1)); xx; --xx) {
    unsigned long long x(n / xx);
    long long Rt(1);
    for (unsigned long long L, R(1), Cur; R < x;) {
      L = R + 1, Cur = x / L, R = x / Cur;
      Rt -= (R - L + 1) * ((Cur <= m) ? Mu[Cur] : PM[n / Cur]);
    }
    PM[xx] = Rt;
  }
}
inline void GD() {
  for (unsigned long long xx(n / (m + 1)); xx; --xx) {
    unsigned long long x(n / xx);
    long long Rt(x), LM(1), NM(1);
    for (unsigned long long L, R(1), Cur; R < x;) {
      L = R + 1, Cur = x / L, R = x / Cur, NM = ((R <= m) ? Mu[R] : PM[n / R]);
      Rt -= (NM - LM) * ((Cur <= m) ? D[Cur] : PD[n / Cur]), LM = NM;
    }
    PD[xx] = Rt;
  }
}
signed main() {
  n = RD(), m = pow(n, (double)2 / 3) + 1, D[1] = Mu[1] = 1;
  for (unsigned i(2); i <= m; ++i) {
    if (!Ava[i]) Pri[++CntP] = i, Mu[i] = -1, D[i] = 2, Cp[i] = 1;
    for (unsigned j(1); (Pri[j] * i <= m) && (j <= CntP); ++j) {
      unsigned Cur(Pri[j] * i);
      Ava[Cur] = 1;
      if (!(i % Pri[j])) { Mu[Cur] = 0, D[Cur] = D[i] / (Cp[i] + 1) * ((Cp[Cur] = Cp[i] + 1) + 1); break; }
      Mu[Cur] = -Mu[i], D[Cur] = D[i] * 2, Cp[Cur] = 1;
    }
  }
  for (unsigned i(2); i <= m; ++i) D[i] += D[i - 1];
  for (unsigned i(2); i <= m; ++i) Mu[i] += Mu[i - 1];
  GM(), GD();
  for (unsigned long long L, R(0), Cur; R < n;) {
    L = R + 1, Cur = n / L, R = n / Cur;
    Ans += (R - L + 1) * ((Cur <= m) ? D[Cur] : PD[R]);
  }
  printf("%lld\n", Ans);
  return Wild_Donkey;
}