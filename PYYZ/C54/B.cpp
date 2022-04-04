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
bitset<1000005> No;
unsigned Pri[100005], CntP(0), Cnt[1000005], Small[1000005];
struct Node {
  Node* Fa; unsigned Size;
}N[100005];
pair<Node, Node*> Stack[200005], *STop(Stack), *SBot;
struct Edge {
  Node *To[2];
}E[100005];
struct Change {
  Edge* Ed;
  unsigned Range[2], Val;
  inline const char operator<(const Change& x) const { return Range[0] < x.Range[0]; }
}Edit[205], *CntE(Edit);
vector<Edge*> List[1000005];
vector<Change*> Added[1000005];
unsigned Val[100005], Tot[65];
unsigned long long Ans[105], Tmp(0), LTmp(0);
unsigned m, n, A, B, C, D;
inline unsigned Insert(unsigned y) {
  unsigned Cl(0), TmP; 
  Tot[0] = 1;
  while (y > 1) {
    TmP = Small[y];
    while (!(y % TmP)) y /= TmP;
    Tot[1 << (Cl++)] = TmP;
  }
  for (unsigned j(1), k(2); j < Cl; ++j, k <<= 1)
    for (unsigned l((1 << j) - 1); l; --l) Tot[k | l] = Tot[k] * Tot[l];
  return (1 << Cl) - 1;
}
inline Node* Find(Node* x) { while (x->Fa != x) x = x->Fa; return x;}
inline unsigned long long Calc(unsigned x) {return ((unsigned long long)x * (x - 1)) >> 1;}
inline void Add(Edge* x) {
  Node *LS(Find(x->To[0])), *RS(Find(x->To[1]));
  *(++STop) = {*LS, LS}, *(++STop) = {*RS, RS};
  if(LS == RS) printf("%u FAQ\n", x - E);
  if(LS->Size < RS->Size) swap(LS, RS);
  Tmp -= Calc(LS->Size), Tmp -= Calc(RS->Size); 
  LS->Size += RS->Size, RS->Fa = LS;
  Tmp += Calc(LS->Size);
}
//  inline void Clr() {}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("My.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  Cnt[1] = 0, Cnt[0] = 0, Small[1] = 1;
  for (unsigned i(2); i <= 1000000; ++i) {
    if(!No[i]) Pri[++CntP] = i, Cnt[i] = 1, Small[i] = i;
    for (unsigned j(1), k(i << 1); (k <= 1000000) && (j <= CntP); ++j, k = Pri[j] * i) {
      No[k] = 1, Cnt[k] = Cnt[i] + 1, Small[k] = Pri[j];
      if(!(i % Pri[j])) Cnt[k] = 0x3f3f3f3f;
    }
  }
//  for (unsigned i(1); i <= 1000000; ++i) {
//    printf("%u %u %u:", i, Small[i], Cnt[i]);
//    for (unsigned j(Insert(i)); ~j; --j) printf("%u ", Tot[j]);
//    putchar(0x0A);
//  }
  n = RD();
  for (unsigned i(1); i < n; ++i) E[i].To[0] = N + RD(), E[i].To[1] = N + RD(), Val[i] = RD();
  m = RD();
  map<Edge*, Change*> Last;
  for (unsigned i(1); i <= m; ++i) {
    A = RD();
    if(Val[A] < 0x3f3f3f3f) *(++CntE) = {E + A, 0, 0, Val[A]}, Val[A] = 0x3f3f3f3f, Last[E + A] = CntE;
    *(++CntE) = {E + A, i, 0, RD()}, Last[E + A]->Range[1] = i - 1, Last[E + A] = CntE; 
  }
  for (auto i:Last) { i.second->Range[1] = m; }
  for (Change* i(CntE); i > Edit; --i) {
    for (unsigned j(Insert(i->Val)); ~j; --j) Added[Tot[j]].push_back(i);
//    printf("[%u, %u] %u\n", i->Range[0], i->Range[1], i->Ed - E);
  }
  for (unsigned i(1); i < n; ++i) if(Val[i] < 0x3f3f3f3f)
    for (unsigned j(Insert(Val[i])); ~j; --j) List[Tot[j]].push_back(E + i);
  for (unsigned i(1); i <= n; ++i) N[i].Fa = N + i, N[i].Size = 1; 
  for (unsigned i(1); i <= 1000000; ++i) if(Cnt[i] < 0x3f3f3f3f) {
    Tmp = 0;
    while (STop > Stack) *(STop->second) = STop->first, --STop;
    for (auto j:List[i]) Add(j); LTmp = Tmp, SBot = STop;
    for (unsigned j(0); j <= m; ++j) {
      Tmp = LTmp;
      while (STop > SBot) *(STop->second) = STop->first, --STop;
      for (auto k:Added[i]) if((k->Range[0] <= j) && (j <= k->Range[1])) Add(k->Ed);// printf("Add %u\n", k->Ed - E);
//      if(Tmp) printf("For %u Time %u Add %llu\n", i, j, Tmp);
      if(Cnt[i] & 1) Ans[j] -= Tmp;
      else Ans[j] += Tmp;
    }
  }
  for (unsigned i(0); i <= m; ++i) printf("%llu\n", Ans[i]); 
//  }
  return Wild_Donkey;
}

