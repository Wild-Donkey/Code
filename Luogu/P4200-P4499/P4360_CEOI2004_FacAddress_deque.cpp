#include <bits/stdc++.h>
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
unsigned w[20005], Pos[20005];
unsigned Sumw[20005], SumPosw[20005];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Ans(2000000000);
//  inline void Clr() {}
unsigned RangeToPos(unsigned L, unsigned R, unsigned P) {
  if (L > R) return 0;
  return SumPosw[R] - SumPosw[L - 1] - P * (Sumw[R] - Sumw[L - 1]);
}
unsigned Calc(unsigned Mid, unsigned Rig) {
  return RangeToPos(1, Mid - 1, 0) + RangeToPos(Mid, Rig - 1, Pos[Mid]) +
    RangeToPos(Rig, n, Pos[Rig]);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) w[n - i + 1] = RD(), Pos[n - i + 1] = RD();
  for (unsigned i(1); i <= n; ++i) Pos[i] += Pos[i - 1];
  for (unsigned i(1); i <= n; ++i) SumPosw[i] = SumPosw[i - 1] + Pos[i] * w[i];
  for (unsigned i(1); i <= n; ++i) Sumw[i] = Sumw[i - 1] + w[i];
  deque<pair<unsigned, unsigned> > Best;
  Best.push_back({ 1, 2 });
  for (unsigned i(2); i <= n; ++i) {
    // for (auto i : Best) printf("(%u,%u)", i.first, i.second);
    // putchar(0x0A);
    while (Best.size() > 1)
      if (Best[1].second <= i) Best.pop_front();
      else break;
    // for (auto i : Best) printf("(%u,%u)", i.first, i.second);
    // putchar(0x0A);
    Ans = min(Ans, Calc(Best.front().first, i));
    // printf("Here %u, %u = %u\n", Best.front().first, i, Ans);
    while (Best.size() && Best.back().second > i &&
      Calc(i, Best.back().second) <
      Calc(Best.back().first, Best.back().second))
      Best.pop_back();
    if (Best.size()) {
      unsigned L(i + 1), R(n), Mid;
      while (L < R) {
        Mid = ((L + R) >> 1);
        if (Calc(i, Mid) < Calc(Best.back().first, Mid))
          R = Mid;
        else
          L = Mid + 1;
      }
      Best.push_back({ i, L });
      // printf("%u as the best from %u\n", i, L);
    } else
      Best.push_back({ i, i + 1 });
  }
  printf("%u\n", Ans);
  //  }
  //  system("pause"); 
  return Wild_Donkey;
}
/*
g++ P4360_CEOI2004_FacAddress.cpp
  1  3  4 10 12 13 16 17 19
  1  1  2  1  3  1  3  2  1
*/