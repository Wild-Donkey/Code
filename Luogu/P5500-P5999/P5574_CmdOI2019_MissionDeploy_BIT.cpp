#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <unordered_map>
#define Wild_Donkey 0
#define LowBit(x) ((x) & ((~(x)) + 1))
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
unsigned a[25005];
unsigned Tre[25005], Rl, Rr;
unsigned f[2][25005], *Lf(f[0]), *Cf(f[1]);
unsigned m, n, Ans;
void Add(unsigned x) {
  while (x <= n) ++Tre[x], x += LowBit(x);
}
void Sub(unsigned x) {
  while (x <= n) --Tre[x], x += LowBit(x);
}
unsigned Sum(unsigned x) {
  if (!x) return 0;
  unsigned Rt = 0;
  while (x) Rt += Tre[x], x -= LowBit(x);
  return Rt;
}
void SrL() {
  // printf("[%u, %u) %u SrL\n", Rl, Rr, Ans);
  Sub(a[Rl++]);
  Ans -= Rr - Rl - Sum(a[Rl - 1]);
}
void SrR() {
  // printf("[%u, %u) %u SrR\n", Rl, Rr, Ans);
  Sub(a[--Rr]);
  Ans -= Sum(a[Rr]);
}
void ExL() {
  // printf("[%u, %u) %u ExL\n", Rl, Rr, Ans);
  Ans += Rr - Rl - Sum(a[Rl - 1]);
  Add(a[--Rl]);
}
void ExR() {
  // printf("[%u, %u) %u ExR\n", Rl, Rr, Ans);
  Ans += Sum(a[Rr]);
  Add(a[Rr++]);
}
void DP(unsigned l, unsigned r, unsigned Ol, unsigned Or) {
  if (l > r) return;
  unsigned Mid((l + r) >> 1), TOr(min(Or, Mid - 1));
  unsigned Chs(0x3f3f3f3f), Cur(0x3f3f3f3f), Tmp;
  // printf("[%u,%u] with [%u,%u] (%u)\n", l, r, Ol, Or, TOr);
  while (Rr > Mid + 1 && Rl < Rr) SrR();
  while (Rl <= Ol && Rl < Rr) SrL();
  if (Rl == Rr) Rl = Rr = TOr + 1;
  if (Mid + 1 - Rr + min(min(TOr + 1 - Rl, Rl - TOr - 1), Rl - Ol - 1) <
      Mid - TOr + Rr - Rl) {
    while (Rl > TOr + 1) ExL();
    if (TOr + 1 - Rl < Rl - Ol - 1)
      while (Rl <= TOr) SrL();
    else
      while (Rl > Ol + 1) ExL();
  } else {
    while (Rl < Rr) SrL();
    Rl = Rr = TOr + 1;
  }
  while (Rr <= Mid) ExR();
  if (Rl == Ol + 1) {
    while (Rl <= TOr + 1) {
      Tmp = Lf[Rl - 1] + Ans;
      if (Tmp < Cur) Cur = Tmp, Chs = Rl - 1;
      SrL();
    }
    Cf[Mid] = Cur;
    DP(Mid + 1, r, Chs, Or);
    DP(l, Mid - 1, Ol, Chs);
    return;
  }
  while (Rl > Ol) {
    Tmp = Lf[Rl - 1] + Ans;
    if (Tmp <= Cur) Cur = Tmp, Chs = Rl - 1;
    ExL();
  }
  Cf[Mid] = Cur;
  DP(l, Mid - 1, Ol, Chs);
  DP(Mid + 1, r, Chs, Or);
  return;
}
signed main() {
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  Lf[0] = 0, Ans = 0, Rl = Rr = 1;
  for (unsigned i(1); i <= n; ++i) ExR(), Lf[i] = Ans;
  for (unsigned i(2); i <= m; ++i, swap(Lf, Cf)) DP(i, n, i - 1, n - 1);
  printf("%u\n", Lf[n]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P5574_CmdOI2019_MissionDeploy.cpp -static-libstdc++
clang P5574_CmdOI2019_MissionDeploy.cpp -std=c++17 -lstdc++
(------)
(--)(--)
()()()()
*/