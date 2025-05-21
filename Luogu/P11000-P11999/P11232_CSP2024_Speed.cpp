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
unsigned m, n, Len, Vmin, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Car {
  int Beg, Att, Ver;
  void Init() { Beg = RD(), Ver = RD(), Att = RDsg(); }
} Cr[100005];
unsigned a[100005];
unsigned Sq(const unsigned &x) { return x * x; }
unsigned Bina_Sear(unsigned SqD, unsigned Att, unsigned Sta) {
  unsigned L(1), R(m + 1), Mid;
  Att <<= 1;
  while (L < R) {
    Mid = ((L + R) >> 1);
    if (a[Mid] * Att <= Sta * Att + SqD)
      L = Mid + 1;
    else
      R = Mid;
  }
  return L;
}
inline void Clr() {}
signed main() {
  // freopen("detect2.in", "r", stdin);
  // freopen("duel.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    n = RD(), m = RD(), Len = RD(), Vmin = RD();
    for (unsigned i(1); i <= n; ++i) Cr[i].Init();
    for (unsigned i(1); i <= m; ++i) a[i] = RD();
    sort(a + 1, a + m + 1);
    vector<pair<unsigned, unsigned> > Rang;
    for (unsigned i(1), L, R; i <= n; ++i) {
      if (Cr[i].Ver <= Vmin && Cr[i].Att <= 0) continue;
      if (Cr[i].Ver > Vmin && Cr[i].Att >= 0) {
        L = lower_bound(a + 1, a + m + 1, Cr[i].Beg) - a;
        if (L <= m) Rang.push_back({L, m});
        continue;
      }
      if (Cr[i].Att > 0) {
        L = Bina_Sear(Sq(Vmin) - Sq(Cr[i].Ver), Cr[i].Att, Cr[i].Beg);
        if (L <= m) Rang.push_back({L, m});
        continue;
      }
      L = lower_bound(a + 1, a + m + 1, Cr[i].Beg) - a;
      R = Bina_Sear(Sq(Cr[i].Ver) - Sq(Vmin) - 1, -Cr[i].Att, Cr[i].Beg) - 1;
      if (L <= R) Rang.push_back({L, R});
    }
    printf("%u ", n = Rang.size());
    sort(Rang.begin(), Rang.end()), Ans = 0;
    for (unsigned i(n - 1), RL(1000000); ~i; --i)
      if (RL > Rang[i].second) RL = Rang[i].first, ++Ans;
    printf("%u\n", m - Ans);
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
((v + v0)/2)((v - v0)/a) = (v^2 - v0^2)/2a
g++ P11232_CSP2024_Speed.cpp -O3
*/