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
unsigned long long Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Tr {
  vector<Tr*> Son;
  Tr* Fa, * Heavy, * Top;
  unsigned long long ToFa, Pre, Cir, Dep;
  unsigned Size, DFSr, Deep;
}T[20005], * CntT, * List[20005];
struct Node {
  vector<pair<unsigned, Node*> > E;
  unsigned From;
  char Istk;
}N[10005], * Stack[10005], ** STop(Stack);
inline Tr* Get(Node* x) { return T + (x - N); }
inline void Jantar(Node* x, Node* Co) {
  // printf("Jantar %u %u\n", x - N, Co - N);
  x->Istk = 1, * (++STop) = x;
  for (auto i : x->E) if (i.second != Co) {
    Node* Cur(i.second);
    if (!(x->Istk)) x->Istk = 1, * (++STop) = x;
    if (Cur->Istk) {
      Tr* Mid(++CntT);
      Mid->Fa = Get(Cur), Mid->Cir = i.first, Mid->Pre = 0;
      while (*STop != Cur) {
        (*STop)->Istk = 0;
        // printf("Pop %u\n", *STop - N);
        Tr* Sn(Get(*STop));
        Sn->Pre = Mid->Cir;
        // printf("Sn %u Pre %llu %u %llu\n", Sn - T, Sn->Pre, Cur->From, Mid->Cir);
        Mid->Cir += (*(STop--))->From;
        Sn->Fa = Mid;
      }
    }
    else if (!(Get(i.second)->Fa)) Cur->From = i.first, Jantar(Cur, x);
  }
  if (!(Get(x)->Fa)) Get(x)->Fa = Get(Co), Get(x)->Pre = x->From;
  if (x->Istk) --STop, x->Istk = 0;
  // printf("Done %u\n", x - N);
}
inline void PreDFS(Tr* x) {
  // printf("PDFS %u\n", x - T);
  x->Size = 1;
  unsigned Mx(0);
  for (auto i : x->Son) {
    i->Dep = x->Dep + i->ToFa, i->Deep = x->Deep + 1, PreDFS(i);
    x->Size += i->Size;
    if (Mx < i->Size) Mx = i->Size, x->Heavy = i;
  }
}
inline void DFS(Tr* x) {
  List[x->DFSr = ++Cnt] = x;
  if (x->Heavy) x->Heavy->Top = x->Top, DFS(x->Heavy);
  for (auto i : x->Son) if (i != x->Heavy) i->Top = i, DFS(i);
}
inline void Qry(Tr* x, Tr* y) {
  // printf("Q %u %u Deep %llu %llu\n", x - T, y - T, x->Dep, y->Dep);
  Tr* Lx(NULL), * Ly(NULL);
  while (x->Top != y->Top) {
    // printf("Jump %u %u Dep %llu %llu\n", x->Top - T, y->Top - T, x->Top->Dep, y->Top->Dep);
    if (x->Top->Deep > y->Top->Deep) swap(x, y), swap(Lx, Ly);
    Ly = y->Top, Ans += y->Dep - y->Top->Fa->Dep, y = y->Top->Fa;
  }
  // printf("Done Jump %u Dep %u %u Dep %u\n", x - T, x->Deep, y - T, y->Deep);
  if (x->Deep > y->Deep) swap(x, y), swap(Lx, Ly);
  if (y->Deep > x->Deep) Ans += y->Dep - x->Dep, Ly = List[(y = x)->DFSr + 1];
  // printf("LCA %u Dep %llu\n", x - T, x->Dep);
  if ((Lx && Ly) && (x > T + n)) {
    Ans -= Lx->Dep - x->Dep;
    Ans -= Ly->Dep - y->Dep;
    unsigned long long Del((Lx->Pre > Ly->Pre) ? (Lx->Pre - Ly->Pre) : (Ly->Pre - Lx->Pre));
    Ans += min(Del, x->Cir - Del);
  }
  return;
}
//  inline void Clr() {}
signed main() {
  // freopen("P5236_1.in", "r", stdin);
  // freopen("P5236.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD(), CntT = T + n;
  for (unsigned i(1); i <= n; ++i) T[i].Cir = 0x3f3f3f3f3f3f3f3f;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].E.push_back({ C, N + B });
    N[B].E.push_back({ C, N + A });
  }
  Jantar(N + 1, NULL);
  for (Tr* i(T + 2); i <= CntT; ++i) i->Fa->Son.push_back(i), i->ToFa = min(i->Pre, i->Fa->Cir - i->Pre);
  // for (Tr* i(T + 2); i <= CntT; ++i) printf("Fa %u = %u Len %llu\n", i - T, i->Fa - T, i->ToFa);
  T[1].Top = T + 1, PreDFS(T + 1), DFS(T + 1);
  // for (Tr* i(T + 1); i <= CntT; ++i) printf("Top %u = %u\n", i - T, i->Top - T);
  for (unsigned i(1); i <= t; ++i) {
    A = RD(), B = RD(), Ans = 0;
    Qry(T + A, T + B);
    printf("%llu\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
7 9 10
1 2 2
1 3 1
2 3 3
3 7 4
3 6 2
6 7 1
3 5 1
3 4 2
4 5 5
*/