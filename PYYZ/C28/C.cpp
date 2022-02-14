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
  char NAva;
}N[1005], * S, * T;
inline void Calc() {
  for (unsigned i(1); i <= n; ++i) N[i].NAva = 0, N[i].Dis = INFi;
  priority_queue<pair<unsigned long long, Node*> > Q;
  Q.push(make_pair(INFi, S)), S->Dis = 0;
  while (Q.size()) {
    Node* Cur(Q.top().second);
    Q.pop();
    if (Cur->NAva) continue;
    Cur->NAva = 1;
    for (auto i : Cur->E) {
      Node* Des(i.first);
      unsigned long long Dist(Cur->Dis + ((Mn <= i.second) ? (i.second - Mn) : 0));
      if (Des->Dis > Dist) Des->Dis = Dist, Q.push(make_pair(INFi - Dist, Des));
    }
  }
  // printf("Rec %u Recd %u, Tot %u Dis %llu\n", Mn, T->CntE, T->Dis);
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
  sort(a + 1, a + m + 1), Cnt = unique(a + 1, a + m + 1) - a - 1, Calc(), Ans = min(Ans, T->Dis);
  // for (unsigned i(1); i <= m; ++i) printf("Ed %u: %u -> %u Val %u\n", i, E[i].Fr - N, E[i].To - N, E[i].Val);
  for (unsigned i(1); i <= Cnt; ++i) {
    Mn = a[i], Calc(), Ans = min(Ans, T->Dis + (unsigned long long)K * Mn);
  }
  printf("%llu\n", Ans);
  //  }
    //  system("pause");
  return Wild_Donkey;
}
/*
5 7 4 1 5
1 4 80
2 1 71
2 3 1
3 4 57
4 1 61
4 3 79
4 5 35
*/