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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
//  inline void Clr() {}
priority_queue<unsigned> Manba, Out;
signed main() {
  // freopen("duel3.in", "r", stdin);
  // freopen("duel.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) Manba.push(100000000 - RD());
  while (Manba.size()) {
    A = 100000000 - Manba.top(), Manba.pop();
    B = Out.size() ? 100000000 - Out.top() : 100000000;
    if (B < A) ++Ans, Out.pop();
    Out.push(100000000 - A);
  }
  printf("%u\n", n - Ans);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P11231_CSP2024_Fight.cpp -O3
*/