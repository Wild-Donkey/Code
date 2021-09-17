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
#include <set>
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
unsigned a[200005];
unsigned m, n, q, M;
unsigned A, B, C, D, t;
unsigned Cnt(0), Top(0), Ans(0), Tmp(0);
char Op[5];
struct Seg {
  Seg* LS, * RS;
  unsigned Val;
}S[400005], * CntS(S);
struct Node;
struct Edge {
  Edge* Nxt;
  Node* To;
}E[200005];
struct Node {
  Edge* Fst;
  Seg* Root;
  Node* Son, * Fa, * Bro, * Heavy, * Top;
  unsigned DFSr, Low, Local, Size, Dep;
  char Square;
  multiset <unsigned> Val;
}N[200005], * Stack[100005], * CntN;
void Build(Seg* x, unsigned L, unsigned R) {
  if (L == R) { x->Val = a[L];return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntS, L, Mid), Build(x->RS = ++CntS, Mid + 1, R);
  x->Val = min(x->LS->Val, x->RS->Val);
}
void Change(Seg* x, unsigned L, unsigned R) {
  if (L == R) { x->Val = a[L]; return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) Change(x->LS, L, Mid);
  else Change(x->RS, Mid + 1, R);
  x->Val = min(x->LS->Val, x->RS->Val);
}
void Query(Seg* x, unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) { Tmp = min(Tmp, x->Val);return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) Query(x->LS, L, Mid);
  if (B > Mid) Query(x->RS, Mid + 1, R);
}
void Link(Node* x, Node* y, Edge* z) { z->Nxt = x->Fst, x->Fst = z, z->To = y; }
void Tarjan(Node* x, Edge* No) {
  // printf("Tarjan %u Edge No %u\n", x - N, No - E);
  x->Low = (Stack[++Top] = x)->DFSr = ++Cnt;
  Edge* Sid(x->Fst);
  while (Sid) {
    // printf("Fuck > %u -> %u Nxt %u\n", Sid - E, Sid->To - N, Sid->Nxt - E);
    if (!(Sid->To->DFSr)) {
      Tarjan(Sid->To, E + ((Sid - E) ^ 1)), x->Low = min(x->Low, Sid->To->Low);
      // printf("Low %u = %u my DFSr %u\n", Sid->To - N, Sid->To->Low, x->DFSr);
      if (x->DFSr == Sid->To->Low) {
        // printf("Fuck > %u -> %u\n", Sid - E, Sid->To - N);
        Node* Cur(++CntN);
        Cur->Bro = x->Son, x->Son = Cur, Cur->Square = 1, Cur->Fa = x;
        do Stack[Top]->Bro = Cur->Son, Cur->Son = Stack[Top], Stack[Top]->Fa = Cur; while (Stack[Top--] != Sid->To);
      }
    }
    x->Low = min(x->Low, Sid->To->DFSr);
    Sid = Sid->Nxt;
  }
}
void PreDFS(Node* x) {
  // printf("PreDFS %u\n", x - N);
  if (!(x->Son)) return;
  // printf("Have Son %u\n", x - N);
  Node* Now(x->Son);
  unsigned Mx(0);
  x->Size = 1;
  while (Now) {
    Now->Dep = x->Dep + 1, PreDFS(Now), x->Size += Now->Size;
    if (Now->Size > Mx) Mx = Now->Size, x->Heavy = Now;
    Now = Now->Bro;
  }
  if (x->Square) {
    Now = x->Son;
    while (Now) {
      x->Val.insert(Now->Local), Now = Now->Bro;
    }
  }
}
void DFS(Node* x) {
  if (!(x->Son)) return;
  x->DFSr = ++Cnt;
  if (x->Square)a[Cnt] = *(x->Val.begin());
  else a[Cnt] = x->Local;
  if (!(x->Heavy)) return;
  // printf("DFS %u\n", x - N);
  x->Heavy->Top = x->Top, DFS(x->Heavy);
  Node* Now(x->Son);
  while (Now) {
    if (Now != x->Heavy) {
      Now->Top = Now, DFS(Now);
    }
    Now = Now->Bro;
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), q = RD(), M = m << 1;
  for (unsigned i(1); i <= n; ++i) N[i].Local = RD();
  for (unsigned i(0); i < M; i += 2)
    C = RD(), D = RD(), Link(N + C, N + D, E + i), Link(N + D, N + C, E + (i ^ 1));
  CntN = N + n, Tarjan(N + 1, NULL);
  Cnt = 0, N[1].Dep = 1, PreDFS(N + 1), N[1].Top = N + 1, DFS(N + 1), Build(S, 1, Cnt);
  // for (unsigned i(1); i <= Cnt; ++i) printf("a[%u] %u\n", i, a[i]);
  for (unsigned i(1); i <= q; ++i) {
    scanf("%s", &Op), C = RD(), D = RD();
    // putchar(*Op); printf("(%u, %u)\n", C, D);
    if (*Op == 'A') {
      Node* QL(N + C), * QR(N + D);
      if (QL == QR) { printf("%u\n", QL->Local); continue; }
      Tmp = min(QL->Local, QR->Local);
      // printf("Ask %u -> %u (%u)\n", QL - N, QR - N, Tmp);
      if (QL->Fa && (!QL->Son)) QL = QL->Fa; if (QR->Fa && (!QR->Son)) QR = QR->Fa;
      // printf("Jump %u -> %u\n", QL - N, QR - N);
      // for (unsigned i(1); i <= Cnt; ++i) printf("a[%u] %u\n", i, a[i]);
      while (QL->Top != QR->Top) {
        // printf("Qry %u -> %u\n", QL - N, QR - N);
        if (QL->Top->Dep < QR->Top->Dep) A = QR->Top->DFSr, B = QR->DFSr, QR = QR->Top->Fa;
        else A = QL->Top->DFSr, B = QL->DFSr, QL = QL->Top->Fa;
        Query(S, 1, Cnt);
      }
      if (QL->Dep < QR->Dep) A = QL->DFSr, B = QR->DFSr, Query(S, 1, Cnt), QR = QL;
      else A = QR->DFSr, B = QL->DFSr, Query(S, 1, Cnt), QL = QR;
      if (QL->Square) Tmp = min(Tmp, QL->Fa->Local);
      printf("%u\n", Tmp);
    }
    else {
      Node* Chan(N + C);
      // printf("%u 's Fa is %u\n", Chan - N, Chan->Fa - N);
      if (Chan->Fa) {
        Chan->Fa->Val.erase(Chan->Local), Chan->Fa->Val.insert(Chan->Local = D);
        a[A = Chan->Fa->DFSr] = *(Chan->Fa->Val.begin()), Change(S, 1, Cnt);
      }
      Chan->Local = D;
      if (Chan->Son) a[A = Chan->DFSr] = Chan->Local, Change(S, 1, Cnt);
    }
  }
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
15 20 1
707036809
557646308
276040440
399323302
430746957
495913520
671577498
954408580
807817676
781832766
209903100
482823946
414453765
793349973
591266390
1 2
1 3
3 2
3 6
5 4
4 6
6 5
6 9
8 7
7 9
8 9
12 9
10 11
12 10
11 12
15 12
13 14
13 15
15 14
3 15
A 13 5
*/