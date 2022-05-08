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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Tree {
  vector<pair<Tree*, unsigned> > E;
  Tree* Fa[19];
  unsigned Min[19], Dep, DFSr;
  inline void DFS() {
    DFSr = ++Cnt, memset(Min + 1, 0x3f, 72);
    for (unsigned i(0); Fa[i]; ++i)
      Fa[i + 1] = Fa[i]->Fa[i], Min[i + 1] = min(Min[i], Fa[i]->Min[i]);
    for (auto i:E) if(Fa[0] != i.first) 
      i.first->Dep = Dep + 1, i.first->Fa[0] = this, i.first->Min[0] = i.second, i.first->DFS();
  }
  inline unsigned Qry(Tree* Ac) {
    Tree* x(this);
    unsigned Rt(0x3f3f3f3f);
//    printf("Min"); for (unsigned i(5); ~i; --i) printf("%u ", Min[i]); putchar(0x0A);
    for (unsigned i(17); ~i; --i)
      if((x->Fa[i]) && (x->Fa[i]->Dep >= Ac->Dep)) Rt = min(Rt, x->Min[i]), x = x->Fa[i];
//    printf("%u\n", Rt);
    return Rt;
  }
}T[250005];
inline Tree* LCA(Tree* x, Tree* y) {
  if(x->Dep < y->Dep) swap(x, y);
  for (unsigned i(17); ~i; --i) 
    if((x->Fa[i]) && (x->Fa[i]->Dep >= y->Dep)) x = x->Fa[i];
  if(x == y) return x;
  for (unsigned i(17); ~i; --i)
    if(x->Fa[i] != y->Fa[i]) x = x->Fa[i], y = y->Fa[i];
  return x->Fa[0];
}
struct Node {
  vector<Node*> Son;
  Tree* Ori;
  unsigned long long f;
  unsigned ToFa;
  inline const char operator< (const Node& x) const {return Ori->DFSr < x.Ori->DFSr;}
  inline void AddSon(Node* x) {
//    printf("(%u)%u Son (%u)%u\n", this, this->Ori - T, x, x->Ori - T);
    Son.push_back(x);
    x->ToFa = x->Ori->Qry(this->Ori);
//    printf("Tofa %u\n", x->ToFa);
  }
  inline void DFS() {
    for (auto i:Son) i->DFS(), f += min((unsigned long long)i->ToFa, i->f);
  }
}N[250005], *Stack[250005], *CntN(N), **STop(Stack);
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    T[A].E.push_back({T + B, C});
    T[B].E.push_back({T + A, C});
  }
  T[1].Min[0] = 0x3f3f3f3f, T[1].Dep = 1, T[1].DFS(), m = RD();
//  for (unsigned i(1); i <= n; ++i) printf("N + %u = %u\n", i, N + i);
  for (unsigned i(1); i <= m; ++i) {
    while (CntN > N) (CntN--)->Son.clear();
    A = RD(), CntN = A + N + 1, STop = Stack;
    for (unsigned j(1); j <= A; ++j) 
      N[j].f = 0x3f3f3f3f3f3f3f3f, N[j].Ori = T + RD(), N[j].Son.clear(), N[j].ToFa = 0;
    N[++A].Ori = T + 1, N[A].f = 0, sort(N + 1, N + A + 1), *(++STop) = N + 1;
//    for (unsigned j(1); j <= A; ++j) printf("%u ", N[j].Ori - T); putchar(0x0A);
    for (unsigned j(2); j <= A; ++j) {
      Tree* Lca(LCA(N[j].Ori, N[j - 1].Ori));
      while((STop > Stack + 1) && ((*(STop - 1))->Ori->Dep >= Lca->Dep))
        (*(STop - 1))->AddSon(*STop), --STop;
//      printf("Done %u\n", j);
      Tree* Top((*STop)->Ori);
      if (Top == Lca) {*(++STop) = N + j; continue;}
      Node* Cur(++CntN);
      Cur->Ori = Lca, Cur->f = 0;
      if (Top->Dep > Lca->Dep) Cur->AddSon(*(STop--));
      *(++STop) = Cur, *(++STop) = N + j;
//      printf("Stack:"); for (Node** k(Stack + 1); k <= STop; ++k) printf("%u ", *k - N); putchar(0x0A);
    }
    while (STop > Stack + 1) (*(STop - 1))->AddSon(*STop), --STop;
    N[1].DFS();
    printf("%llu\n", N[1].f);
  }
//  }
  return Wild_Donkey;
}

