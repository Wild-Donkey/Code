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
unsigned m, n, p, M, Top(0), Top2;
unsigned A, B, C, D, t;
unsigned Cnt(0), Num[100005], Ans(0), Tmp(0);
char InAva[105];
struct SCC;
struct SEdge {
  SCC* To;
  SEdge* Nxt;
}SE[5000005], * CntSE(SE);
struct SCC{
  SEdge* Fst;
  unsigned f, City;
}S[5000005], * CntS(S);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[5000005], * CntE(E);
struct Node {
  Edge* Fst;
  SCC* Bel;
  unsigned DFSr, Low;
  char Ava, InS;
}N[5000055], * Stack[5000005];
inline void Link(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if((Sid->To->Bel) && (Sid->To->Bel != CntS))
      (++CntSE)->Nxt = CntS->Fst, CntS->Fst = CntSE, CntSE->To = Sid->To->Bel;
    Sid = Sid->Nxt;
  }
}
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x, x->InS = 1;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(!(Sid->To->DFSr)) Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
    else if(Sid->To->InS) x->Low = min(x->Low, Sid->To->Low);
    Sid = Sid->Nxt;
  }
  if(x->Low == x->DFSr) {
    (++CntS), Top2 = Top, Ans = 0; 
//    printf("Height %u\n", Top);
    do if ((Stack[Top2]->Ava) && (!(Num[(Stack[Top2] - N - 1) / p]++))) ++Ans; 
    while (Stack[Top2--] != x);
    CntS->City = Ans;
//    printf("City %u = %u\n", CntS - S, Ans);
    while (Top ^ Top2) {
//      printf("Have %u\n", Stack[Top] - N);
      if (Stack[Top]->Ava) --Num[(Stack[Top] - N - 1) / p];
      Stack[Top]->Bel = CntS, Stack[Top]->InS = 0, Link(Stack[Top--]);
    }
  }
}
signed main() {
//  freopen(\".in\", \"r\", stdin);
//  freopen(\".out\", \"w\", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), p = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    for (unsigned j(1); j < p; ++j)
      (++CntE)->Nxt = N[(A * p) + j].Fst, N[(A * p) + j].Fst = CntE, CntE->To = N + (B * p) + j + 1;
    (++CntE)->Nxt = N[(A * p) + p].Fst, N[(A * p) + p].Fst = CntE, CntE->To = N + (B * p) + 1;
  }
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", InAva + 1);
    for (unsigned j(1); j <= p; ++j)
      N[(i * p) + j].Ava =  InAva[j] - '0';
  }
  Tarjan(N + p + 1), Ans = 0, CntS->f = CntS->City;
  for (SCC* i(CntS); i > S; --i) {
    SEdge* Sid(i->Fst);
    Ans = max(i->f, Ans);
//    printf("Now %u Udt %u %u\n", i - S, Ans, i->f);
    while (Sid) {
//      printf("To %u\n", Sid->To - S); 
      Sid->To->f = max(Sid->To->f, i->f + Sid->To->City);
      Sid = Sid->Nxt;
    }
  }
  printf("%u\n", Ans);
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

