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
unsigned M, m, n, q;
unsigned AskFr, AskTo, C, D, t, Top(0);
unsigned Cnt(0), Ans(0), Tmp(0);
char Goal(0);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char ToPr;
}E[200005];
struct BCC {
  BCC* Son, * Fa, * Bro;
  Edge* FaTo;
  int Dif;
  char Vis;
}B[100005], * CntB(B), * DoFr, * DoTo;
struct Node {
  Edge* Fst;
  BCC* Bel;
  unsigned DFSr, Low;
}N[100005], * Stack[100005];
void Link(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->Bel) {
      if (Sid->To->Bel != x->Bel) {
        Sid->To->Bel->Bro = x->Bel->Son;
        x->Bel->Son = Sid->To->Bel;
        Sid->To->Bel->Fa = x->Bel;
        Sid->To->Bel->FaTo = Sid;
      }
    }
    Sid = Sid->Nxt;
  }
  return;
}
void DFS(Node* x, Edge* No) {
  x->DFSr = x->Low = ++Cnt, Stack[++Top] = x;
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid != No) {
      if (Sid->To->DFSr) x->Low = min(x->Low, Sid->To->Low);
      else DFS(Sid->To, E + ((Sid - E) ^ 1)), x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if (x->DFSr == x->Low) {
    ++CntB;
    do {
      Stack[Top]->Bel = CntB, Link(Stack[Top]);
    } while (Stack[Top--] != x);
  }
}
void DFSB(BCC* x) {
  BCC* Now(x->Son);
  x->Vis = 1;
  while (Now) {
    DFSB(Now), x->Dif += Now->Dif;
    Now = Now->Bro;
  }
  if (x->Dif < 0) x->FaTo->ToPr = 'R';
  if (x->Dif > 0) x->FaTo->ToPr = 'L';
  return;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), M = m << 1;
  for (unsigned i(0); i < M; i += 2) {
    C = RD(), D = RD();
    E[i].Nxt = N[C].Fst, N[C].Fst = E + i, E[i].To = N + D;
    E[i ^ 1].Nxt = N[D].Fst, N[D].Fst = E + (i ^ 1), E[i ^ 1].To = N + C;
  }
  for (unsigned i(1); i <= n; ++i) if (!(N[i].DFSr)) DFS(N + i, NULL);
  q = RD();
  for (unsigned i(1); i <= q; ++i) ++(N[RD()].Bel->Dif), --(N[RD()].Bel->Dif);
  for (BCC* i(CntB); i > B; --i) if (!(i->Vis)) DFSB(i);
  for (unsigned i(0); i < M; i += 2) {
    if (E[i].ToPr) { putchar(E[i].ToPr); continue; }
    if (E[i ^ 1].ToPr) putchar((E[i ^ 1].ToPr ^ 'L') ? 'L' : 'R');
    else putchar('B');
  }
  putchar('\n');
  //  }
  return Wild_Donkey;
}