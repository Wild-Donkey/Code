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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Edge {
  Node* To;
  unsigned Val, Inv;
  Edge (Node* x, const unsigned& y) {To = x, Val = y;}
  Edge (Node* x) {To = x;}
};
struct Node {
  vector<Edge> Ed;
  unsigned Dep;
}N[1105], * Q[1105], * P, * T;
inline char BFS() {
  for (Node* i(N); i <= T; ++i) i->Dep = 0x3f3f3f3f;
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->Ed) if((i.Val) && (i.To->Dep >= 0x3f3f3f3f)) {
      (Q[++Tl] = i.To)->Dep = Cur->Dep + 1;
    }
  }
//  printf("Dep %u Ans %u\n", T->Dep, Ans);
  return T->Dep < 0x3f3f3f3f;
}
inline unsigned DFS (Node* x, unsigned Come) {
//  printf("Come %u TO %u\n", Come, x - N);
  if (x == T) {Ans -= Come; return Come;}
  unsigned Res(Come);
  for (unsigned i(x->Ed.size() - 1); ~i; --i) 
    if((x->Ed[i].Val) && (x->Ed[i].To->Dep == x->Dep + 1)){
      unsigned Go(min(Res, x->Ed[i].Val)), Push(DFS(x->Ed[i].To, Go));
      if(Push ^ Go) x->Ed[i].To->Dep = 0x3f3f3f3f;
      Res -= Push, x->Ed[i].Val -= Push, x->Ed[i].To->Ed[x->Ed[i].Inv].Val += Push;
      if(!Res) break;
    }
  return Come - Res;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  P = N + (m = RD()), T = P + (n = RD()) + 1;
  for (unsigned i(1); i <= m; ++i) {
    N->Ed.push_back(Edge(N + i, RD()));
    N[i].Ed.push_back(Edge(N + i));
    N->Ed.back().Inv = N[i].Ed.size() - 1;
    N[i].Ed.back().Inv = N->Ed.size() - 1;
    Ans += N->Ed.back().Val;
  }
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(RD()); j; --j) {
      A = RD();
      N[A].Ed.push_back(Edge(P + i, 1));
      P[i].Ed.push_back(Edge(N + A));
      N[A].Ed.back().Inv = P[i].Ed.size() - 1;
      P[i].Ed.back().Inv = N[A].Ed.size() - 1;
    }
    P[i].Ed.push_back(Edge(T, 1));
    T->Ed.push_back(Edge(P + i));
    T->Ed.back().Inv = P[i].Ed.size() - 1;
    P[i].Ed.back().Inv = T->Ed.size() - 1;
  }
  while (BFS()) DFS(N, 0x3f3f3f3f);
  if(Ans) {printf("No Solution!\n"); return 0;}
  for (unsigned i(1); i <= m; ++i) {
    printf("%u:", i);
    for (auto j:N[i].Ed) if((!(j.Val)) && (j.To > P)) printf(" %u", j.To - P);
    putchar(0x0A);
  }
//  }
  return Wild_Donkey;
}

