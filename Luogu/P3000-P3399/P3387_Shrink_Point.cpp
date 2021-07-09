#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), Hd(0), CntP(0), Sum, A, B, t, Ans[10005], FinalAns(0);
struct Node; 
struct Edge {
  Node *To;
  Edge *Nxt;
}E[200005], *CntE(E);
struct Node {
  Node *Bel;
  Edge *Fst;
  unsigned DFSr, Low, Val;
  char Instack;
}SN[10005], N[10005], *Stack[10005], *CntN(N);
inline void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
}
void Tarjan(Node *x) {
  x->Low = x->DFSr = ++Cnt;
  Stack[++Hd] = x;
  x->Instack = 1;
//  printf("Me %u RK %u\n", x - N, x->DFSr);
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To->Instack) {
      x->Low = min(x->Low, Sid->To->DFSr);
    } else {
      if(!(Sid->To->DFSr)) Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
//  printf("Low[%u] = %u\n", x - N, x->Low);
  if(x->Low == x->DFSr) {
    ++CntP;
    do {
//      printf("%u %u\n", Hd, Stack[Hd] - N);
      Stack[Hd]->Bel = SN + CntP;
      SN[CntP].Val += Stack[Hd]->Val;
      Stack[Hd]->Instack = 0; 
    } while (Stack[Hd--] != x);
  }
}
void DFS(Node *x) {
//  printf("DFS %u %u\n", x - SN, x->Val);
  x->Low = x->DFSr = ++Cnt;
  Stack[++Hd] = x;
  x->Instack = 1;
  Edge *Sid(x->Fst);
  while (Sid) {
    if(!(Sid->To->Instack)) DFS(Sid->To);
    Ans[x - SN] = max(Ans[x - SN], Ans[Sid->To - SN]);
    Sid = Sid->Nxt;
  }
  Ans[x - SN] += x->Val;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Val = RD();
  }
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    Link(A + N, B + N);
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!N[i].DFSr) {
      Tarjan(N + i);
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    register Edge *Sid(N[i].Fst);
    while (Sid) {
      if(N[i].Bel != Sid->To->Bel) Link(N[i].Bel, Sid->To->Bel);
      Sid = Sid->Nxt;
    }
  }
  for (register unsigned i(1); i <= CntP; ++i) {
    if(!(SN[i].Instack)) {
      DFS(SN + i);
      FinalAns = max(FinalAns, Ans[i]);
    }
  }
  printf("%u\n", FinalAns);
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}
/*
6 10
1 2 3 4 5 6
1 2
1 3
1 4
2 5
3 5
4 5
5 6
2 4
4 1
5 1
*/
