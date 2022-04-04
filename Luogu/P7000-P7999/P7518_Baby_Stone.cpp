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
unsigned m, n, c, q;
unsigned A, B, C, D, t;
unsigned Rk[50005], Ans[200005], Tmp(0);
struct Set{
  Set* Fa;
  unsigned Col, Size;
}Mer[200005], *Root[50005];
inline Set* Find (Set* x) {
  while (x->Fa != x) x = x->Fa;
  return x;
}
pair<Set*, Set> Stack[2000005], *STop(Stack);
pair<Set**, Set*> Stack2[2000005], *STop2(Stack2);
inline Set* Merge (Set *x, Set *y) {
  if(!x) return y;
  if(!y) return x;
  if(x->Size < y->Size) swap(x, y);
  *(++STop) = {x, *x}, *(++STop) = {y, *y};
  x->Size += y->Size, y->Fa = x;
//  printf("%u -> %u\n", y - Mer, x - Mer);
  return x;
}
struct Node {
  vector<Node*> E;
  Node *Beg, *Up[17], *Fa[19];
  vector<pair<unsigned, unsigned> > Frm;
  vector<unsigned> To;
  unsigned Col, Dep;
  inline void Init();
  inline void DFS();
}N[200005], *Last[50005];
inline void Node::Init () {
  Beg = Last[1], Up[0] = Last[Col + 1];
  for (unsigned i(0); Up[i]; ++i) Up[i + 1] = Up[i]->Up[i];
  for (unsigned i(0); Fa[i]; ++i) Fa[i + 1] = Fa[i]->Fa[i];
  Node* TmpL;
  for (auto i:E) if(i != Fa[0]) {
    TmpL = Last[i->Col], Last[i->Col] = i;
    i->Fa[0] = this, i->Dep = Dep + 1, i->Init();
    Last[i->Col] = TmpL;
  }
}
inline void Node::DFS () {
//  printf("DFS %u\n", this - N);
  pair<Set*, Set> *BackUp(STop);
  pair<Set**, Set*> *BackUp2(STop2);
  for (auto i:Frm) {
    Set *&Point(Root[i.first]);
    *(++STop2) = {&Point, Point};
    if(!Point) Point = Mer + i.second;
    else Point = Merge(Point, Mer + i.second);
    Point->Col = i.first;
//    printf("%u To %u\n", i.second, i.first);
  }
  if(Root[Col]) {
//    printf("%u Add\n", Col);
    (*(++STop2)) = {Root + Col + 1, Root[Col + 1]};
    (*(++STop2)) = {Root + Col, Root[Col]};
    Root[Col + 1] = Root[Col + 1] ? Merge(Find(Root[Col]), Find(Root[Col + 1])) : Root[Col];
    (*(++STop)) = {Root[Col + 1], *Root[Col + 1]};
    Root[Col] = NULL, Root[Col + 1]->Col = Col + 1;
  }
  for (auto i:To) /*printf("End %u\n", i), */Ans[i] = Find(Mer + i)->Col;
//  printf("STop %u : %u\n", STop - BackUp, STop->first - Mer);
  for (auto i:E) if(i != Fa[0]) i->DFS();
  while (STop > BackUp) *(STop->first) = STop->second, --STop;
  while (STop2 > BackUp2) *(STop2->first) = STop2->second, --STop2;
}
inline Node* LCA(Node* x, Node* y) {
  if(x->Dep < y->Dep) swap(x, y);
  for (unsigned i(17); ~i; --i)
    if((x->Fa[i]) && (x->Fa[i]->Dep >= y->Dep)) x = x->Fa[i];
//  printf("Jumped %u %u\n", x - N, y - N);
  if(x == y) return x;
  for (unsigned i(17); ~i; --i) if(x->Fa[i] != y->Fa[i]) x = x->Fa[i], y = y->Fa[i];
  return x->Fa[0];
}
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), memset(Rk, 0, ((m = RD()) + 1) << 2), c = RD(); 
  for (unsigned i(1); i <= c; ++i) Rk[RD()] = i;
  for (unsigned i(1); i <= n; ++i) N[i].Col = Rk[RD()];
//  for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Col); putchar(0x0A);
  for (unsigned i(1); i < n; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  Last[N[1].Col] = N + 1;
  N[1].Fa[0] = NULL, N[1].Dep = 1, N[1].Init();
  Last[N[1].Col] = NULL;
  memset(Ans, 0, ((q = RD()) + 1) << 2);
  for (unsigned i(1); i <= q; ++i) {
    Node *S(N + RD()), *T(N + RD()), *L_CA(LCA(S, T));
//    printf("(%u, %u) %u\n", S - N, T - N, L_CA - N);
    T->To.push_back(i), S = S->Beg;
    if(S && (S->Dep > L_CA->Dep)) {
      Ans[i] = 1;
      for (unsigned j(15); ~j; --j)
        if((S->Up[j]) && (S->Up[j]->Dep > L_CA->Dep))
          S = S->Up[j], Ans[i] += (1 << j);
    }
//    printf("%u Rise %u\n", i, Ans[i]);
    L_CA->Frm.push_back({Mer[i].Col = (Ans[i] + 1), i});
  }
  for (unsigned i(1); i <= q; ++i) Mer[i].Fa = Mer + i;
  N[1].DFS();
  for (unsigned i(1); i <= q; ++i) printf("%u\n", Ans[i] - 1);
//  }
  return Wild_Donkey;
}

