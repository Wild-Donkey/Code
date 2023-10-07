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
#define foreplay for
#define wild while
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
unsigned a[55], b[55], m, n, k, MinA(0x3f3f3f3f), MinB(0x3f3f3f3f), MaxA(0),
    MaxB(0);
unsigned long long SumA, SumB, Sum, A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  MinA = MinB = 0x3f3f3f3f;
  MaxA = MaxB = 0;
  SumA = SumB = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD(), m = RD(), k = RD();
    for (unsigned i(1); i <= n; ++i) SumA += (a[i] = RD());
    for (unsigned i(1); i <= m; ++i) SumB += (b[i] = RD());
    Sum = SumA + SumB;
    k = min(k, ((k & 7) + 8));
    unsigned *aa(a), *bb(b), *N(&n), *M(&m);
    unsigned long long *Suma(&SumA), *Sumb(&SumB);
    for (unsigned i(1); i <= k;
         ++i, swap(Suma, Sumb), swap(aa, bb), swap(N, M)) {
      sort(aa + 1, aa + (*N) + 1);
      sort(bb + 1, bb + (*M) + 1);
      if (aa[1] < bb[*M])
        *Suma -= aa[1], *Suma += bb[*M], *Sumb = Sum - *Suma,
                                         swap(aa[1], bb[*M]);
    }
    printf("%llu\n", SumA);
  }
  //  system("pause");
  return Wild_Donkey;
}