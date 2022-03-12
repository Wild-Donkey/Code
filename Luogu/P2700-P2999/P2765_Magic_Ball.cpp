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
unsigned n, n2, Sq[65];
unsigned A, B, C, D, t;
unsigned Nxt[1605];
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned char Idg[1605]; 
struct Node;
struct Edge {
  Node* To;
  unsigned Inv;
  unsigned char Cap;
  Edge (Node* x, const unsigned char y) {To = x, Cap = 1;}
  Edge (Node* x) {To = x, Cap = 0;}
};
struct Node {
  vector<Edge> E;
  unsigned Dep;
}N[3205], * Q[3205], * Fr, * Th;
inline void Clr() {
  n2 = ((Ans = C) << 1) ^ 1;
  for (Node* i(N + n2); i >= N; --i) i->E.clear();
}
inline char BFS() {
  for (Node* i(N + n2); i > N; --i) i->Dep = 0x3f3f3f3f;
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dep = 1;
  while (Tl ^ Hd) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->E) if((i.Cap) && (i.To->Dep >= 0x3f3f3f3f))
      i.To->Dep = Cur->Dep + 1, Q[++Tl] = i.To;
  }
  return N[1].Dep < 0x3f3f3f3f;
}
inline unsigned char DFS(Node* x, unsigned Come) {
  if(x == N + 1) { --Ans; return 1; }
  unsigned Res(Come);
  for (unsigned i(x->E.size() - 1); ~i; --i)
    if((x->E[i].Cap) && (x->E[i].To->Dep == x->Dep + 1)) {
      unsigned char Push(DFS(x->E[i].To, 1));
      if(!Push) {x->E[i].To->Dep == 1; continue;}
      --Res, --(x->E[i].Cap), ++(x->E[i].To->E[x->E[i].Inv].Cap);
      if(!Res) break;
    }
  return Res < Come;
}
inline void Judge () {
  for (unsigned i(2); i <= n2; i += 2) {
    N[0].E.push_back(Edge(N + i, 1));
    N[i].E.push_back(Edge(N));
    N[0].E[(i >> 1) - 1].Inv = 0;
    N[i].E[0].Inv = (i >> 1) - 1;
  }
  for (unsigned i(3); i <= n2; i += 2) {
    N[1].E.push_back(Edge(N + i));
    N[i].E.push_back(Edge(N + 1, 1));
    N[1].E[(i >> 1) - 1].Inv = 0;
    N[i].E[0].Inv = (i >> 1) - 1;
  }
  for (unsigned i(1); i <= C; ++i) {
    Fr = N + (i << 1);
    for (unsigned j(2); Sq[j] <= C + i; ++j) if((i << 1) < Sq[j]) {
      Th = N + (((Sq[j] - i) << 1) ^ 1);
      Fr->E.push_back(Edge(Th, 1));
      Th->E.push_back(Edge(Fr));
      Fr->E.back().Inv = Th->E.size() - 1;
      Th->E.back().Inv = Fr->E.size() - 1;
    }
  }
  while (BFS()) DFS(N, 0x3f3f3f3f);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  A = 1, B = 1600;
  for (unsigned i(1); i <= 60; ++i) Sq[i] = i * i;
  while (A ^ B) {
    C = (A + B + 1) >> 1, Clr(), Judge();
//    printf("[%u, %u] = %u Ans %u\n", A, B, C, Ans);
    if(Ans > n) B = C - 1;
    else A = C;
  }
  printf("%u\n", C = A);
  Clr(), Judge();
  for (Node* i(N + n2 - 1); i > N; i -= 2)
    for (auto j:i->E) if((j.To > N) && (!(j.Cap)))
      Nxt[(i - N) >> 1] = (j.To - N) >> 1, Idg[(j.To - N) >> 1] = 1;
  for (unsigned i(1), j; i <= A; ++i) if(!(Idg[i])) {
    j = i;
    while (j) printf("%u ", j), j = Nxt[j];
    putchar(0x0A);
  }
  return Wild_Donkey;
}

