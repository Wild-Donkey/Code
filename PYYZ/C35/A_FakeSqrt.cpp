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
unsigned long long t;
unsigned Pool[90000005], Mx[455];
unsigned a[200505], b[200005], m, n;
unsigned A, B, C, D, BC, BD;
unsigned Cnt(0), Ans(0), Tmp(0);
inline unsigned* Get(const unsigned& x, const unsigned& y) { return Pool + (x * Cnt) + y; }
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD() % n, B = sqrt(n), A = n / B;
  printf("BlockLen %u BlockCnt %u\n", B, A);
  for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
  sort(b + 1, b + n + 1), Cnt = unique(b + 1, b + n + 1) - b;
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + Cnt, a[i]) - b;
  for (unsigned i(1); i <= n; ++i) printf("%u ", a[i]); putchar(0x0A);
  for (unsigned i(0); i < A; ++i) {
    unsigned* Pos(Get(i, Cnt - 1)), * Cur(a + i * B + 1);
    unsigned CMx[B + 1], Rise(0), Val(Cnt - 1);
    CMx[0] = 0;
    for (unsigned j(1); j <= B; ++j, ++Cur) CMx[j] = max(CMx[j - 1], *Cur);
    Mx[i] = CMx[B];
    while (Val >= Mx[i]) (*Pos) = Rise, --Pos, --Val; ++Rise;
    for (unsigned j(B); j; --j, ++Rise) {
      while (CMx[j] == CMx[j - 1]) --j;
      if (!(j - 1)) break;
      while (Val >= CMx[j - 1]) (*Pos) = Rise, --Pos, --Val;
    }
    while (~Val) (*Pos) = Rise, --Val, --Pos;
  }
  for (unsigned i(0); i < A; ++i) {
    for (unsigned j(0); j < Cnt; ++j) printf("%u ", *Get(i, j)); putchar(0x0A);
  }
  for (unsigned i(1); i <= m; ++i) {
    Ans = t * Ans % n, C = (RD() + Ans + n - 1) % n + 1, D = (RD() + Ans + n - 1) % n + 1;
    if (C > D) swap(C, D);
    BC = (C + B - 2) / B, BD = (D / B) - 1, Ans = 0;
    printf("Qry [%u, %u] Block [%u, %u]\n", C, D, BC, BD);
    unsigned Cur(0), L(BC * B + 1), R(BD * B + B);
    for (unsigned i(C); i < L; ++i) if (Cur < a[i]) Cur = a[i], ++Ans;
    for (unsigned i(BC); i <= BD; ++i) Ans += (*Get(i, Cur)), Cur = max(Mx[i], Cur);
    for (unsigned i(R + 1); i <= D; ++i) if (Cur < a[i]) Cur = a[i], ++Ans;
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}