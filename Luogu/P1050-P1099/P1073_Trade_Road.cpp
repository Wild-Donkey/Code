#include <algorithm>
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
unsigned A, B, C, D, Top;
unsigned Cnt(0), Tmp(0);
struct SCC;
struct Node;
struct SCCE {
  SCC* To;
  SCCE* Nxt;
}SE[1000005], * CntSE(SE);
struct SCC {
  SCCE* Fst;
  unsigned Max, Min, Ans;
}S[100005], * CntS(S);
struct Edge {
  Node* To;
  Edge* Nxt;
}E[1000005], * CntE(E);
struct Node {
  Edge* Fst;
  SCC* Bel;
  unsigned Val, DFSr, Low;
  char InStk;
}N[100005], * Stack[100005];
void Add(Node* x) {
  // printf("Add %u\n", CntSE - SE);
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->Bel) {
      (++CntSE)->Nxt = x->Bel->Fst;
      x->Bel->Fst = CntSE;
      CntSE->To = Sid->To->Bel;
    }
    Sid = Sid->Nxt;
  }
}
void DFS(Node* x) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x, x->InStk = 1;
  // printf("DFS %u DFSr %u\n", x - N, x->DFSr);
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->DFSr) {
      if (Sid->To->InStk) x->Low = min(x->Low, Sid->To->Low);
    }
    else {
      DFS(Sid->To);
      x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if (x->Low == x->DFSr) {
    (++CntS)->Min = 0x3f3f3f3f;
    while (Stack[Top] != x) {
      CntS->Max = max(CntS->Max, Stack[Top]->Val);
      CntS->Min = min(CntS->Min, Stack[Top]->Val);
      Stack[Top]->InStk = 0, Stack[Top--]->Bel = CntS;
    }
    CntS->Max = max(CntS->Max, Stack[Top]->Val);
    CntS->Min = min(CntS->Min, Stack[Top]->Val);
    Stack[Top]->InStk = 0, Stack[Top--]->Bel = CntS;
  }
}
signed main() {
  // freopen("P1073_2.in", "r", stdin);
  // freopen("P1073.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Val = RD();
  for (unsigned i(0); i < m; ++i) {
    A = RD(), B = RD(), C = RD();
    (++CntE)->Nxt = N[A].Fst, N[A].Fst = CntE, CntE->To = N + B;
    if (C & 2)
      (++CntE)->Nxt = N[B].Fst, N[B].Fst = CntE, CntE->To = N + A;
  }
  DFS(N + 1);
  for (unsigned i(1); i <= n; ++i) if (N[i].Bel) Add(N + i);
  for (SCC* i(CntS); i > S;--i) {
    i->Ans = max(i->Ans, i->Max - i->Min);
    SCCE* Sid(i->Fst);
    while (Sid) {
      Sid->To->Min = min(i->Min, Sid->To->Min);
      Sid->To->Ans = max(i->Ans, Sid->To->Ans);
      Sid = Sid->Nxt;
    }
    // printf("Ans of %u is %u\n", i - S, i->Ans);
  }
  // printf("%u Bel to %u\n", n, N[n].Bel - S);
  printf("%u\n", N[n].Bel->Ans);
  //  }
  // system("pause");
  return Wild_Donkey;
}