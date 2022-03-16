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
unsigned a[100005][2], m, n, p;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0), Now(0);
struct SCC {
  vector<SCC*> E;
  unsigned DFSr, Idg, Topo;
}S[100005], *SCnt(S), *Que[100005], **Tl(Que), **Hd(Que);
struct Node {
  vector<Node*> E;
  SCC *Bel;
  unsigned DFSr, Low;
  char Istk;
}N[100005], *Stack[100005], **STop(Stack);
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, (*(++STop) = x)->Istk = 1;
  for (auto i:x->E) {
    if(!(i->DFSr)) Tarjan(i);
    if(i->Istk) x->Low = min(i->Low, x->Low);
  }
  if(x->Low == x->DFSr) {
    (++SCnt)->DFSr = x->DFSr;
    do {
      (*STop)->Bel = SCnt, (*STop)->Istk = 0;
    }while (*(STop--) != x);
  }
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    a[i][0] = A = RD(), a[i][1] = B = RD(), N[A].E.push_back(N + B);
  }
  for (unsigned i(1); i <= n; ++i) sort(N[i].E.begin(), N[i].E.end());
  for (unsigned i(1); i <= n; ++i) if(!(N[i].DFSr)) Tarjan(N + i);
  for (unsigned i(1); i <= n; ++i) for(auto j:N[i].E)
    if(N[i].Bel != j->Bel) ++(j->Bel->Idg), N[i].Bel->E.push_back(j->Bel);
  for (SCC *i(S + 1); i <= SCnt; ++i) if(!(i->Idg)) *(++Tl) = i;
  while (Hd < Tl) {
    SCC *Cur(*(++Hd));
    Cur->Topo = ++Ans;
    for (auto i:Cur->E) if(!(--(i->Idg))) *(++Tl) = i;
  }
  p = RD();
  for (unsigned i(1); i <= p; ++i) {
    A = RD(), B = RD(), Now = 0;
    if(N[A].Bel->Topo > N[B].Bel->Topo) continue;
    if(N[A].Bel->DFSr >= N[B].Bel->DFSr) Flg = Now = 1;
//    if(Now) printf("No %u %u <= %u\n", i, N[A].Bel->DFSr, N[B].Bel->DFSr);
  }
  if(Flg) {printf("NO\n");return 0;}
  printf("YES\n%u\n", m);
  for (unsigned i(1); i <= m; ++i) printf("%u %u\n", a[i][0], a[i][1]);
//  }
  return Wild_Donkey;
}
/*
2
1
1 2
1
2 1

4
4
1 2
1 3
2 4
3 4
3
2 3
3 2
4 1

4
3
1 2
2 3
4 2
2
1 4
4 1

5
4
1 2
2 3
4 5
4 2
1
4 2
*/
