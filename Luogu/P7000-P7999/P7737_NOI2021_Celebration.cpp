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
unsigned a[300005];
unsigned m, n, Q, K;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> Son;
  Node *Fa, *Heavy, *Top;
  unsigned DFSr, Val, Size;
  inline void DFS1();
  inline void DFS2();
} N[300005], *CntN(N), *Qr[3][2];
struct Ori {
  vector<Ori*> E;
  Node* Bel;
  unsigned DFSr, Low;
  char Ist;
  inline void Tarjan();
} OrN[300005], *Stack[300005], **STop(Stack);
struct Seg {
  Seg *LS, *RS;
  unsigned Val;
  inline void Build(unsigned L, unsigned R);
  inline void Qry(unsigned L, unsigned R);
} S[600005], *CntS(S);
struct Edge;
struct Vir {
  Node* Nd;
  vector<Edge*> E, IE;
  char Tag;
  inline const char operator<(const Vir& x) const {
    return Nd->DFSr < x.Nd->DFSr;
  }
} V[20];
struct Edge {
  Vir* To[2];
  unsigned Val;
} Ed[40], *CntE(Ed);
inline void Ori::Tarjan() {
  Low = DFSr = ++Cnt, Ist = 1, *(++STop) = this;
  for (auto i : E) {
    if (!(i->DFSr)) i->Tarjan();
    if (i->Ist) Low = min(Low, i->Low);
  }
  if (Low == DFSr) {
    Node* Cur(++CntN);
    do (*STop)->Bel = Cur, (*STop)->Ist;
    while (*(STop--) != this);
  }
}
inline void Node::DFS1() {
  Size = 1;
  unsigned TmpS(0);
  for (auto i : Son) {
    i->DFS1(), Size += i->Size;
    if (TmpS < i->Size) TmpS = i->Size, Heavy = i;
  }
}
inline void Node::DFS2() {
  a[DFSr = ++Cnt] = Val;
  if (Heavy) Heavy->Top = Top, Heavy->DFS2();
  for (auto i : Son)
    if (i != Heavy) i->Top = i, i->DFS2();
}
inline void Seg::Build(unsigned L, unsigned R) {
  if (L == R) {
    Val = a[L];
    return;
  }
  unsigned Mid((L + R) >> 1);
  (LS = ++CntS)->Build(L, Mid);
  (RS = ++CntS)->Build(Mid + 1, R);
  Val += LS->Val + RS->Val;
}
inline void Seg::Qry(unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) {
    C += Val;
    return;
  }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) LS->Qry(L, Mid);
  if (B > Mid) RS->Qry(Mid + 1, R);
}
inline void Qry(Node* x, Node* y) {
  C = 0;
  while (x->Top != y->Top) {
    if (x->Top < y->Top) swap(x, y);
    A = y->Top->DFSr, B = y->DFSr, S->Qry(1, m);
    y = y->Top->Fa;
  }
  if (x < y) swap(x, y);
  A = x->DFSr, B = y->DFSr, S->Qry(1, m);
}
inline Node* LCA(Node* x, Node* y) {
  while (x->Top != y->Top) {
    if (x->Top < y->Top) swap(x, y);
    y = y->Top->Fa;
  }
  if (x < y) swap(x, y);
  return x;
}
inline void Link(Vir* x, Vir* y) {
  Qry(x->Nd, y->Nd);
  (++CntE)->Val = C - x->Nd->Val - y->Nd->Val;
  CntE->To[0] = x;
  CntE->To[1] = y;
  x->E.push_back(CntE);
  y->IE.push_back(CntE);
}
inline void Link_Zero(Vir* x, Vir* y) {
  (++CntE)->Val = 0;
  CntE->To[0] = x;
  CntE->To[1] = y;
  x->E.push_back(CntE);
  y->IE.push_back(CntE);
}
inline void Build() {
  Vir *StkN[20], **SNTop(StkN);
  *(++SNTop) = V + 1;
  unsigned CntAdd(Cnt);
  for (unsigned i(2); i <= CntAdd; ++i) {
    Node* Cur(LCA(V[i].Nd, (*SNTop)->Nd));
    while (Cur > (*(SNTop - 1))->Nd) Link(*(SNTop - 1), *SNTop), --SNTop;
    if (Cur == (*SNTop - 1)->Nd) {
      Link(*(SNTop - 1), *SNTop), --SNTop;
    } else {
      Link(V + (++Cnt), *SNTop), --SNTop;
      (*(++SNTop) = V + Cnt)->Nd = Cur;
    }
    *(++SNTop) = V + i;
  }
  while (SNTop - 1 > StkN) Link(*(SNTop - 1), *SNTop), --SNTop;
}
inline void Clr() { Cnt = 0, CntE = Ed; }
signed main() {
  freopen("celebration-1.in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Q = RD(), K = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    OrN[A].E.push_back(OrN + B);
    OrN[B].E.push_back(OrN + A);
  }
  for (unsigned i(1); i <= n; ++i)
    if (!OrN[i].DFSr) OrN[i].Tarjan();
  m = CntN - N;
  for (unsigned i(1); i <= n; ++i) {
    Node* Cur(OrN[i].Bel);
    for (auto j : OrN[i].E)
      if ((j->Bel != Cur) && ((!(j->Bel->Fa)) || (j->Bel->Fa > Cur)))
        j->Bel->Fa = Cur;
  }
  for (Node* i(N + 1); i < CntN; ++i) i->Fa->Son.push_back(i);
  Cnt = 0, CntN->DFS1(), CntN->Top = CntN, CntN->DFS2(), S->Build(1, m);
  for (unsigned i(1); i <= Q; ++i) {
    Clr();
    map<Node*, Vir*> Mp;
    V[Cnt = 1].Nd = CntN;
    for (unsigned j(0); j <= K; ++j)
      V[++Cnt].Nd = Qr[j][0] = OrN[RD()].Bel,
      V[++Cnt].Nd = Qr[j][1] = OrN[RD()].Bel;
    sort(V + 1, V + (K << 1)), Cnt = unique(V + 1, V + Cnt + 1) - V;
    for (unsigned j(1); j <= Cnt; ++j) Mp[V[j].Nd] = V + j;
    for (unsigned j(1); j <= K; ++j) Link_Zero(Mp[Qr[j][0]], Mp[Qr[j][1]]);
    Mp[Qr[0][0]]->DFS1(), Mp Build();
  }
  return Wild_Donkey;
}
// g++ P7737_NOI2021_Celebration.cpp -o faq -std=c++14 -O2