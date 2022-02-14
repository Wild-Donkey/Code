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
#define Lbt(x) ((x)&((~(x))+1))
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
unsigned List[1000005], Val[1000005], a[505][505], b[250005], T[505];
unsigned m, n, Csq(0), LsC(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
unsigned Pls(0);
vector<pair<unsigned, unsigned> >V[250005];
struct Qry {
  unsigned Ans, Now, K;
}Q[60005];
struct SubQ {
  unsigned Bel, X, Y;
  char Type;
  inline const char operator < (SubQ& x) { return X < x.X; }
}Sq[240005];
inline void Chg(unsigned x) { for (;x <= n; x += Lbt(x)) if (Pls) ++T[x]; else --T[x]; }
inline void Ask(unsigned x) { for (;x; x -= Lbt(x)) Tmp += T[x]; }
inline void Solve(unsigned L, unsigned R, unsigned Ql, unsigned Qr) {
  // printf("Ans [%u, %u] SubQry [%u, %u] LsC %u\n", L, R, Ql, Qr, LsC);
  if (L == R) { for (unsigned i(Ql); i <= Qr; ++i) Q[Sq[i].Bel].Ans = L; return; }
  if (Ql > Qr) return;
  unsigned Mid((L + R) >> 1), Bot(Ql), LastT(LsC), J(0);
  sort(Sq + Ql, Sq + Qr + 1);
  vector <pair <unsigned, unsigned> > Edit;
  for (unsigned i(Ql); i <= Qr; ++i) List[++LsC] = Sq[i].Bel;
  sort(List + LastT + 1, List + LsC + 1), LsC = unique(List + LastT + 1, List + LsC + 1) - List - 1;
  for (unsigned i(LastT + 1); i <= LsC; ++i) Val[i] = Q[List[i]].Now;
  for (unsigned i(L); i <= Mid; ++i) for (auto j : V[i]) Edit.push_back(j);
  sort(Edit.begin(), Edit.end()), Pls = 1;
  // for (auto i : Edit) printf("(%u, %u) ", i.first, i.second); putchar(0x0A);
  for (unsigned i(Ql); i <= Qr; ++i) {
    while ((J < Edit.size()) && (Edit[J].first <= Sq[i].X)) Chg(Edit[J++].second);
    Tmp = 0, Ask(Sq[i].Y), Tmp = (Sq[i].Type) ? (-Tmp) : Tmp, Q[Sq[i].Bel].Now += Tmp;
    // printf("Found %u on (%u, %u) Type %u\n", Tmp, Sq[i].X, Sq[i].Y, Sq[i].Type);
  }
  // for (unsigned i(1); i <= m; ++i) printf("%u ", Q[i].Now); putchar(0x0A);
  for (unsigned i(Ql); i <= Qr; ++i) if (Q[Sq[i].Bel].Now >= Q[Sq[i].Bel].K) swap(Sq[Bot++], Sq[i]);
  Pls = 0; while (J) Chg(Edit[--J].second);
  Solve(Mid + 1, R, Bot, Qr);
  for (; LsC > LastT;--LsC) Q[List[LsC]].Now = Val[LsC];
  Solve(L, Mid, Ql, Bot - 1);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) b[++Cnt] = a[i][j] = RD();
  sort(b + 1, b + Cnt + 1), Cnt = unique(b + 1, b + Cnt + 1) - b;
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j)
    V[lower_bound(b + 1, b + Cnt, a[i][j]) - b].push_back(make_pair(i, j));
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD(), D = RD();
    Sq[++Csq] = SubQ{ i, A - 1, B - 1 ,0 };
    Sq[++Csq] = SubQ{ i, C, B - 1 ,1 };
    Sq[++Csq] = SubQ{ i, A - 1, D ,1 };
    Sq[++Csq] = SubQ{ i, C, D ,0 };
    Q[i].K = RD();
  }
  Solve(1, Cnt - 1, 1, Csq);
  for (unsigned i(1); i <= m; ++i) printf("%u\n", b[Q[i].Ans]);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
2 2
2 2
2 2
1 1 1 2 2
1 1 2 2 3
*/