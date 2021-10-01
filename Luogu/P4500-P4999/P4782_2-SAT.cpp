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
unsigned m, n, n2, Top(0), SCC(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char Ans[1000005];
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[2000005], * CntE(E);
struct Node {
  Edge* Fst;
  unsigned Low, DFSr, Bel;
  char InS;
}N[2000005], * Stack[2000005];
inline void Link(Node* x, Node* y) {
  (++CntE)->Nxt = x->Fst, x->Fst = CntE, CntE->To = y;
}
inline void Tarjan(Node* x) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x, x->InS = 1;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid->To->DFSr) {
      if(Sid->To->InS) x->Low = min(x->Low, Sid->To->Low);
    } else {
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if(x->Low == x->DFSr) {
    ++SCC;
    do Stack[Top]->Bel = SCC, Stack[Top]->InS = 0; while (Stack[Top--] != x);
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n2 = ((n = RD()) << 1), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = (RD() << 1), B = RD(), C = (RD() << 1), D = RD();
    Link(N + (A ^ B ^ 1), N + (C ^ D));
    Link(N + (C ^ D ^ 1), N + (A ^ B));
  }
  for (unsigned i(1); i <= n2; ++i) if(!N[i + 1].DFSr) Tarjan(N + i + 1);
  for (unsigned i(2); i <= n2; i += 2) {
    if(N[i ^ 1].Bel == N[i].Bel) {printf("IMPOSSIBLE\n");return 0;}
    Ans[i >> 1] = (N[i ^ 1].Bel < N[i].Bel) ? 1 : 0;
  }
  printf("POSSIBLE\n");
  for (unsigned i(1); i <= n; ++i) printf("%u ", Ans[i]);
//  }
  return Wild_Donkey;
}
/*
10 2
10 0 10 0
7 0 2 1
*/
