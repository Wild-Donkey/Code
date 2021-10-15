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
#include <string>
#include <vector>
#define Wild_Donkey 0
#define INF 0x3f3f3f3f3f3f3f3f
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
unsigned long long Cnt(0), Ans[1000005], Tmp(0);
unsigned long long NoFa[1000005];
priority_queue<pair<unsigned long long, unsigned> > Q;
struct Node;
struct Edge {
  Node* To;
  unsigned long long Val;
}E[4000005], * PFa[1000005];
struct Node {
  vector<Edge*> Ed;
  Edge* Fa;
  unsigned long long Dis;
  char Poped;
}N[1000005], * S;
inline void Dij () {
  for (unsigned i(1); i <= n; ++i) N[i].Dis = INF, N[i].Poped = 0;
  Q.push(make_pair(INF, S - N)), S->Dis = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Poped) continue;
    Cur->Poped = 1;
//    printf("Cur %u Dis %llu\n", Cur - N, Cur->Dis);
    for (auto i:(Cur->Ed)) if(i->To->Dis > Cur->Dis + i->Val) {
      i->To->Fa = i, i->To->Dis = Cur->Dis + i->Val;
      Q.push(make_pair(INF - i->To->Dis, i->To - N));
    }
  }
}
inline void DP () {
  for (unsigned i(1); i <= n; ++i) N[i].Dis = INF, N[i].Poped = 0;
  Q.push(make_pair(INF, S - N)), S->Dis = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Poped) continue;
    Cur->Poped = 1;
    for (auto i:(Cur->Ed)) {
      unsigned long long New(max(Cur->Dis + i->Val, NoFa[i->To - N]));
      if(i->To->Dis > New)
        i->To->Dis = New, Q.push(make_pair(INF - New, i->To - N));
    }
  }
}
signed main() {
//  freopen("ex_D2.in", "r", stdin);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), S = N + RD();
  for (unsigned i(0); i < m; ++i) {
    A = RD(), B = RD(), C = RD();
    E[i << 1].Val = E[(i << 1) ^ 1].Val = C;
    E[i << 1].To = N + B, E[(i << 1) ^ 1].To = N + A;
    N[A].Ed.push_back(E + (i << 1));
    N[B].Ed.push_back(E + ((i << 1) ^ 1));
  }
  Dij();
  for (unsigned i(1); i <= n; ++i) PFa[i] = N[i].Fa;
  for (unsigned i(1); i <= n; ++i) if(PFa[i]) {
//    printf("FUCK?\n");
    Tmp = PFa[i]->Val, PFa[i]->Val = E[(PFa[i] - E) ^ 1].Val = INF;
    Dij(), NoFa[i] = N[i].Dis;
    PFa[i]->Val = E[(PFa[i] - E) ^ 1].Val = Tmp;
  }
  DP();
  for (unsigned i(1); i <= n; ++i) Ans[i] = N[i].Dis;
//  freopen("D.out", "w", stdout);
//  for (unsigned i(1); i <= n; ++i) printf("%lld ", NoFa[i]);
  for (unsigned i(1); i <= n; ++i) printf("%lld ", (Ans[i] < INF) ? Ans[i] : -1);
//  }
  return Wild_Donkey;
}
/*
3 3 1
1 2 3
2 3 7
3 1 9
*/
