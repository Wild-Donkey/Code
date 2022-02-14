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
#define INFi 0x3f3f3f3f3f3f3f3f
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
unsigned long long Ans(INFi);
unsigned a[2005], m, n, K, Mn(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  vector <pair<Node*, unsigned> > E;
  unsigned long long Dis;
  unsigned Recd, Tot;
  char NAva;
}N[1005], * S, * T;
vector <pair<Node*, unsigned> > List[2005];
inline void Calc() {
  for (unsigned i(1); i <= n; ++i) N[i].Recd = N[i].Tot = N[i].NAva = 0, N[i].Dis = INFi;
  priority_queue<pair<unsigned long long, Node*> > Q;
  Q.push(make_pair(INFi, S)), S->Dis = 0;
  while (Q.size()) {
    Node* Cur(Q.top().second);
    Q.pop();
    if (Cur->NAva) continue;
    Cur->NAva = 1;
    for (auto i : Cur->E) {
      Node* Des(i.first);
      char Gr(Mn <= i.second);
      unsigned long long Dist(Cur->Dis + (Gr ? (i.second) : 0));
      if (Des->Dis > Dist) {
        Des->Dis = Dist, Des->Recd = Cur->Recd + Gr, Des->Tot = Cur->Tot + 1;
        Q.push(make_pair(INFi - Dist, Des));
      }
    }
  }
  // printf("Rec %u Recd %u, Tot %u Dis %llu\n", Mn, T->Recd, T->Tot, T->Dis);
}
//  inline void Clr() {}
signed main() {
  // freopen("C.in", "r", stdin);
  // freopen("C.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), K = RD(), S = N + RD(), T = N + RD();
  for (unsigned i(1); i <= m; ++i) A = RD(), B = RD(), N[A].E.push_back(make_pair(N + B, a[i] = RD()));
  sort(a + 1, a + n + 1), Cnt = unique(a + 1, a + n + 1) - a - 1, Calc(), Ans = min(Ans, T->Dis);
  // for (unsigned i(1); i <= m; ++i) printf("Ed %u: %u -> %u Val %u\n", i, E[i].Fr - N, E[i].To - N, E[i].Val);
  for (unsigned i(1); i <= Cnt; ++i) {
    Mn = a[i], Calc(); if (T->Recd < K) break;
    Ans = min(Ans, T->Dis - (T->Recd - K) * a[i]);
  }
  printf("%llu\n", Ans);
  //  }
    //  system("pause");
  return Wild_Donkey;
}