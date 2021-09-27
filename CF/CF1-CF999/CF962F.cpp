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
unsigned m, n, M, Top(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Calced[100005], Ans[100005];
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[200005];
struct Node {
  Edge* Fst;
  Node* Son, * Bro, * Fa;
  unsigned DFSr, Low, Deg;
  char NoAva;
}N[200005], * Stack[100005], * CntN;
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid->To->DFSr) x->Low = min(x->Low, Sid->To->DFSr);
    else {
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
      if(Sid->To->Low == x->DFSr) {
        Node* Cur(++CntN);
        Cur->Bro = x->Son, x->Son = Cur, Cur->Fa = x;
        do Stack[Top]->Bro = Cur->Son, Cur->Son = Stack[Top], Stack[Top]->Fa = Cur;
        while (Stack[Top--] != Sid->To);
      }
    }
    Sid = Sid->Nxt;
  }
  return;
}
inline void PreDFS (Node* x) {
  Node* Cur(x->Son);
  while(Cur) PreDFS(Cur), Cur = Cur->Bro;
  Edge* Sid(x->Fst);
  Node* GrFa(x->Fa);
  if(GrFa) GrFa = GrFa->Fa;
  while(Sid) {
    if(!(Calced[(Sid - E) >> 1])) {
      Calced[(Sid - E) >> 1] = 1;
      if(Sid->To->Fa == x->Fa) ++(x->Deg), ++(Sid->To->Deg);
      if(Sid->To == GrFa) ++(x->Deg), ++(x->Fa->Deg);
    }
    Sid = Sid->Nxt;
  }
}
inline void DFS (Node* x) {
  Node* Cur(x->Son);
  if(x - N > n) {
    if(x->Deg ^ 2) x->NoAva = 1;
    while(Cur) {
      DFS(Cur);
      if(Cur->Deg ^ 2) x->NoAva = 1;
      Cur = Cur->Bro;
    }
  } else while(Cur) DFS(Cur), Cur = Cur->Bro;
}
inline void PlsDFS (Node* x) {
  Node* Cur(x->Son);
  while(Cur) PlsDFS(Cur), Cur = Cur->Bro;
  Edge* Sid(x->Fst);
  Node* GrFa(x->Fa);
  if(GrFa) GrFa = GrFa->Fa;
  while(Sid) {
    if(Calced[(Sid - E) >> 1]) {
      Calced[(Sid - E) >> 1] = 0;
      if((Sid->To->Fa == x->Fa) && (!(x->Fa->NoAva))) Ans[(Sid - E) >> 1] = 1;
      if((Sid->To == GrFa) && (!(x->Fa->NoAva))) Ans[(Sid - E) >> 1] = 1;
    }
    Sid = Sid->Nxt;
  }
}
signed main() {
  CntN = N + (n = RD()), M = ((m = RD()) << 1);
  for (unsigned i(0); i < M; i += 2) {
    A = RD(), B = RD();
    E[i].Nxt = N[A].Fst, N[A].Fst = E + i;
    E[i ^ 1].Nxt = N[B].Fst, N[B].Fst = E + (i ^ 1);
    E[i].To = N + B, E[i ^ 1].To = N + A;
  }
  for (unsigned i(1); i <= n; ++i) if(!N[i].DFSr) 
    Tarjan(N + i), PreDFS(N + i), DFS(N + i), PlsDFS(N + i);
  Cnt = 0;
  for (unsigned i(0); i < m; ++i) Cnt += Ans[i];
  printf("%u\n", Cnt);
  for (unsigned i(0); i < m; ++i) if(Ans[i]) printf("%u ", i + 1);
  return Wild_Donkey;
}

