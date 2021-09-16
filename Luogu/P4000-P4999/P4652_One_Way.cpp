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
struct Seg {
  Seg* LS, * RS;
  char Val;
}S[200005], * CntS(S);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char ToPr;
}E[200005];
struct BCC {
  BCC* Son, * Fa[20], * Bro, * Top, * Heavy;
  Edge* FaTo;
  unsigned DFSr, Dep, Size;
}B[100005], * SortByDFS[100005], * CntB(B), * DoFr, * DoTo, * DoLCA;
struct Node {
  Edge* Fst;
  BCC* Bel;
  unsigned DFSr, Low;
  char InStack;
}N[100005], * Stack[100005];
void Link(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->Bel) {
      if (Sid->To->Bel != x->Bel) {
        Sid->To->Bel->Bro = x->Bel->Son;
        x->Bel->Son = Sid->To->Bel;
        Sid->To->Bel->Fa[0] = x->Bel;
        Sid->To->Bel->FaTo = Sid;
      }
    }
    Sid = Sid->Nxt;
  }
  return;
}
void PushDown(Seg* x) { if (x->Val) x->LS->Val = x->RS->Val = x->Val, x->Val = 0; }
void Build(Seg* x, unsigned L, unsigned R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid), Build(x->RS = ++CntS, Mid + 1, R);
}
void Change(Seg* x, unsigned L, unsigned R) {
  // printf("Change Now [%u, %u] Do [%u, %u]\n", L, R, C, D);
  if ((C <= L) && (R <= D)) { x->Val = Goal;return; }
  unsigned Mid((L + R) >> 1); PushDown(x);
  if (C <= Mid) Change(x->LS, L, Mid);
  if (D > Mid) Change(x->RS, Mid + 1, R);
}
void Print(Seg* x, unsigned L, unsigned R) {
  if (L == R) { if (SortByDFS[L]->FaTo) SortByDFS[L]->FaTo->ToPr = x->Val;return; }
  unsigned Mid((L + R) >> 1); PushDown(x);
  Print(x->LS, L, Mid), Print(x->RS, Mid + 1, R);
}
void DFS(Node* x, Edge* No) {
  x->DFSr = x->Low = ++Cnt, Stack[++Top] = x, x->InStack = 1;
  // printf("%u DFSr %u Now Stack %u No %u\n", x - N, x->DFSr, Top, No - E);
  Edge* Sid(x->Fst);
  while (Sid) {
    // printf("Sid %u\n", Sid - E);
    if (Sid != No) {
      if (Sid->To->DFSr) { if (Sid->To->InStack) x->Low = min(x->Low, Sid->To->Low); }
      else DFS(Sid->To, E + ((Sid - E) ^ 1)), x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if (x->DFSr == x->Low) {
    ++CntB;
    while (Stack[Top] != x) {
      Stack[Top]->Bel = CntB, Link(Stack[Top]), Stack[Top--]->InStack = 0;
    }
    Stack[Top]->Bel = CntB, Link(Stack[Top]), Stack[Top--]->InStack = 0;
  }
}
void PreDFSB(BCC* x) {
  BCC* Now(x->Son);
  unsigned MaxSz(0);
  x->Size = 1;
  // printf("PreDFS %u\n", x - B);
  while (Now) {
    for (char i(0); Now->Fa[i]; ++i) Now->Fa[i + 1] = Now->Fa[i]->Fa[i];
    Now->Dep = x->Dep + 1, PreDFSB(Now), x->Size += Now->Size;
    if (MaxSz < Now->Size) x->Heavy = Now, MaxSz = Now->Size;
    Now = Now->Bro;
  }
  return;
}
void DFSB(BCC* x) {
  BCC* Now(x->Son);
  x->DFSr = ++Cnt, SortByDFS[Cnt] = x;
  if (!(x->Heavy)) return;
  x->Heavy->Top = x->Top, DFSB(x->Heavy);
  // printf("PreDFS %u\n", x - B);
  while (Now) {
    if (Now != x->Heavy) Now->Top = Now, DFSB(Now);
    Now = Now->Bro;
  }
  return;
}
void LCA(BCC* x, BCC* y) {
  if (x->Dep < y->Dep) swap(x, y);
  for (char i(17); ~i; --i) if ((x->Fa[i]) && (x->Fa[i]->Dep >= y->Dep)) x = x->Fa[i];
  if (x == y) { DoLCA = x;return; }
  for (char i(17); ~i; --i) if ((x->Fa[i]) && (x->Fa[i] != y->Fa[i])) x = x->Fa[i], y = y->Fa[i];
  DoLCA = x->Fa[0];
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
  Cnt = 0;
  for (BCC* i(CntB); i > B; --i) if (!(i->DFSr))
    i->Dep = 1, PreDFSB(i), i->Top = i, DFSB(i);
  Build(S, 1, Cnt), q = RD();
  for (unsigned i(1); i <= q; ++i) {
    DoFr = N[RD()].Bel, DoTo = N[RD()].Bel;
    if (DoFr == DoTo) continue;
    LCA(DoFr, DoTo), Goal = 'L';
    while (DoFr->Top != DoLCA->Top)
      C = DoFr->Top->DFSr, D = DoFr->DFSr, Change(S, 1, Cnt), DoFr = DoFr->Top->Fa[0];
    if (DoFr != DoLCA) C = DoLCA->DFSr + 1, D = DoFr->DFSr, Change(S, 1, Cnt);
    Goal = 'R';
    while (DoTo->Top != DoLCA->Top)
      C = DoTo->Top->DFSr, D = DoTo->DFSr, Change(S, 1, Cnt), DoTo = DoTo->Top->Fa[0];
    if (DoTo != DoLCA) C = DoLCA->DFSr + 1, D = DoTo->DFSr, Change(S, 1, Cnt);
  }
  Print(S, 1, Cnt);
  for (unsigned i(0); i < M; i += 2) {
    if (E[i].ToPr) { putchar(E[i].ToPr); continue; }
    if (E[i ^ 1].ToPr) putchar((E[i ^ 1].ToPr ^ 'L') ? 'L' : 'R');
    else putchar('B');
  }
  putchar('\n');
  //  }
  system("pause");
  return Wild_Donkey;
}