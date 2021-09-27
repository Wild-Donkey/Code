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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, M;
unsigned Cnt(0), C, D, t;
unsigned Top(0), Ans(0), Tmp(0);
char Last(0), E1(0);
struct BCC {
  BCC* Son, * Bro, * Fa;
  char Vis;
}B[300005], *CntB(B), * Now, *TOP;
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Type;
}E[600005];
struct Node {
  Edge* Fst;
  BCC* Bel;
  unsigned DFSr, Low;
}N[300005], *Stack[300005];
void Link(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->Bel) {
      if (Sid->To->Bel != x->Bel) Sid->To->Bel->Bro = x->Bel->Son, x->Bel->Son = Sid->To->Bel, Sid->To->Bel->Fa = x->Bel, Sid->To->Bel->Vis |= Sid->Type << 2;
      else x->Bel->Vis |= Sid->Type;
    }
    Sid = Sid->Nxt;
  }
}
void Tarjan(Node* x, Edge* No) {
  x->Low = x->DFSr = ++Cnt;
  Stack[++Top] = x;
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid != No) {
      if(!Sid->To->DFSr) Tarjan(Sid->To, E + ((Sid - E) ^ 1));
      x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if(x->Low == x->DFSr) {
    ++CntB;
    do Stack[Top]->Bel = CntB, Link(Stack[Top]);
    while(Stack[Top--] != x); 
  }
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), M = m << 1;
  for (unsigned i(0); i < M; i += 2) {
    C = RD(), D = RD(), E[i ^ 1].Type = E[i].Type = RD();
    E[i].To = N + D, E[i].Nxt = N[C].Fst, N[C].Fst = E + i;
    E[i ^ 1].To = N + C, E[i ^ 1].Nxt = N[D].Fst, N[D].Fst = E + (i ^ 1);
  }
  Tarjan(N + 1, NULL), Last = ((Now = N[C = RD()].Bel)->Vis |= 2), D = RD();
//  for (unsigned i(1); i <= n; ++i) printf("Bel %u\n", N[i].Bel - B);
  while (Now) {
    Now->Vis |= Last;
    Last = Now->Vis;
    Now = Now->Fa;
  }
  Now = N[D].Bel, Last = 0;
//  printf("%u and %u\n", N[C].Bel - B, N[D].Bel 1- B);
  for(;;) {
//    printf("Jump %u\n", Now - B);
    if(Now) TOP = Now;
    else break;
    Last |= Now->Vis;
    if(Now->Vis & 2) break;
    Now = Now->Fa;
  }
  Now = N[C].Bel;
  while (Now != TOP) {
    E1 |= Now->Vis;
    Now = Now->Fa;
//    printf("Now %u\n", Now - B);
  }
  Now = N[D].Bel;
  while (Now != TOP) {
    E1 |= Now->Vis;
    Now = Now->Fa;
//    printf("Now %u\n", Now - B);
  }
  Last |= (E1 >> 2);
//  printf("%u %u %u\n", Last, Now - B, TOP - B);
  printf((Last & 1) ? "YES\n" : "NO\n");
//  }
  return Wild_Donkey;
}

