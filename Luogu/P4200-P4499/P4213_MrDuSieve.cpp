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
int Mu[10000005];
unsigned Pri[1000005], CntP(0);
unsigned n, A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unordered_map<unsigned, int> SMu;
bitset<10000005> Ava;
inline int CalcM(unsigned x) {
  if (x <= 10000000) return Mu[x];
  if (SMu.find(x) != SMu.end()) return SMu[x];
  // printf("Clac Mu %u\n", x);
  int TmpS(1);
  for (unsigned L, R(1), Now; R < x; ) {
    L = R + 1, Now = x / L, R = x / Now;
    TmpS -= CalcM(Now) * (R - L + 1);
  }
  return SMu[x] = TmpS;
}
inline long long CalcP() {
  long long TmpS(0), Now(0);
  for (unsigned L, R(0); R < n; ) {
    L = R + 1, Now = n / L, R = n / Now;
    TmpS += Now * Now * (CalcM(R) - CalcM(L - 1));
  }
  return (TmpS + 1) >> 1;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (unsigned i(2); i <= 10000000; ++i) {
    if (!Ava[i]) Pri[++CntP] = i, Mu[i] = -1;
    for (unsigned j(1); (i * Pri[j] <= 10000000) && (j <= CntP); ++j) {
      unsigned Cur(i * Pri[j]);
      Ava[Cur] = 1, Mu[Cur] = Mu[i] * Mu[Pri[j]];
      if (!(i % Pri[j])) { Mu[Cur] = 0; break; }
    }
  }
  t = RD(), Mu[1] = 1;
  // for (unsigned i(1); i <= 100; ++i) printf("%u ", Pri[i]); putchar(0x0A);
  // for (unsigned i(1); i <= 100; ++i) printf("%d ", Mu[i]); putchar(0x0A);
  for (unsigned i(2); i <= 10000000; ++i) Mu[i] += Mu[i - 1];
  // for (unsigned i(9999900); i <= 10000000; ++i) printf("%d ", Mu[i]); putchar(0x0A);
  for (unsigned T(1); T <= t; ++T) {
    n = RD(), printf("%lld %d\n", CalcP(), CalcM(n));
  }
  //  system("pause");
  return Wild_Donkey;
}