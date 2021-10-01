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
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Top(0), Tl(0), Hd(0);
char b[1005][1005];
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[2000005], * CntE(E);
struct Node {
  Edge* Fst;
  Node* Fa;
  unsigned DFSr, Low;
  char Situ;
}N[1005], * Q[1005], * Stack[1005], * CntN(N);
void Clr() {
  memset(N, 0, (CntN - N + 1) * (sizeof(Node)));
  n = RD(), m = RD(), CntE = E, CntN = N + n;
  Cnt = Ans = 0;
}
void Tarjan(Node* x) {
  Edge* Sid(x->Fst);
  x->Low = (Stack[++Top] = x)->DFSr = ++Cnt;
  while (Sid) {
    if (Sid->To->DFSr) x->Low = min(x->Low, Sid->To->DFSr);
    else {
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
      if (Sid->To->Low == x->DFSr) {
        Node* Cur(++CntN); Cur->Fa = x;
        do Stack[Top]->Fa = Cur;
        while (Stack[Top--] != Sid->To);
      }
    }
    Sid = Sid->Nxt;
  }
}
void BFS(Node* x) {
  Hd = Tl = 0, Q[++Tl] = x->Fa, x->Fa->Situ = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    Edge* Sid(Cur->Fst);
    if (!(Cur->Situ ^ 3)) {
      while (Sid) {
        if ((Sid->To->Fa == x) || (x->Fa == Sid->To)) {
          if (!(Sid->To->Situ)) Q[++Tl] = Sid->To;
          Sid->To->Situ = 3;
        }
        Sid = Sid->Nxt;
      }
    }
    else while (Sid) {
      if ((Sid->To->Fa == x) || (x->Fa == Sid->To)) {
        if (!(Sid->To->Situ)) Q[++Tl] = Sid->To;
        Sid->To->Situ |= (Cur->Situ ^ 3);
        if (!(Sid->To->Situ ^ 3)) { x->Situ = 3; return; }
      }
      Sid = Sid->Nxt;
    }
  }
}
signed main() {
  for (;;) {
    Clr();
    if (!n) return Wild_Donkey;
    for (unsigned i(1); i <= m; ++i) A = RD(), B = RD(), b[A][B] = b[B][A] = 1;
    for (unsigned i(1); i <= n; ++i) {
      b[i][i] = 1;
      for (unsigned j(1); j <= n; ++j) {
        if (!b[i][j]) (++CntE)->Nxt = N[i].Fst, N[i].Fst = CntE, CntE->To = N + j;
        else b[i][j] = 0;
      }
    }
    for (unsigned i(1); i <= n; ++i) if (!(N[i].DFSr)) Tarjan(N + i);
    for (Node* i(CntN); i > N + n; --i) BFS(i);
    for (Node* i(N + n + 1); i <= CntN; ++i) if (!((i->Situ) ^ 3)) i->Fa->Situ = 3;
    for (unsigned i(1); i <= n; ++i) if (N[i].Fa && (N[i].Fa->Situ == 3)) N[i].Situ = 3;
    for (unsigned i(1); i <= n; ++i) Ans += (N[i].Situ ^ 3) ? 1 : 0;
    printf("%u\n", Ans);
  }
}
