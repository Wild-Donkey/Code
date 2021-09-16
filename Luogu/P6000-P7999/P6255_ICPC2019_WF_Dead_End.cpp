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
unsigned m, n, M;
unsigned A, C, D, t;
unsigned Cnt(0), Top(0), CntRoot(0), CntPrt(0);
struct Node;
struct BCC;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[1000005];
struct EdgeIO {
  unsigned Frm, To;
  const inline char operator <(const EdgeIO& x) const { return (this->Frm ^ x.Frm) ? (this->Frm < x.Frm) : (this->To < x.To); }
}IO[1000005];
struct EdgeB {
  BCC* To;
  EdgeB* Nxt;
  EdgeIO UsedTo;
  char Ava, Deleted;
}EB[1000005];
struct BCC {
  BCC* Fa;
  EdgeB* Fst, * Dont;
  char Turn, SubTree, Deleted;
}B[500005], * Root[500005], * CntB(B);
struct Node {
  Edge* Fst;
  BCC* Bel;
  unsigned DFSr, Low;
}N[500005], * Stack[500005];
void Link(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid->To->Bel) {
      if (Sid->To->Bel < x->Bel) {
        EB[Cnt].UsedTo.Frm = x - N, EB[Cnt].UsedTo.To = Sid->To - N;
        EB[Cnt].Nxt = x->Bel->Fst, x->Bel->Fst = EB + Cnt, EB[Cnt++].To = Sid->To->Bel;
        EB[Cnt].UsedTo.Frm = Sid->To - N, EB[Cnt].UsedTo.To = x - N;
        EB[Cnt].Nxt = Sid->To->Bel->Fst, Sid->To->Bel->Fst = EB + Cnt, EB[Cnt++].To = x->Bel;
        Sid->To->Bel->Fa = x->Bel;
      }
    }
    Sid = Sid->Nxt;
  }
}
void Shrink(Node* x, Edge* No) {
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x;
  Edge* Sid(x->Fst);
  while (Sid) {
    if (Sid != No) {
      if (!(Sid->To->DFSr)) Shrink(Sid->To, E + ((Sid - E) ^ 1)), x->Low = min(x->Low, Sid->To->Low);
      else x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if (x->DFSr == x->Low) {
    ++CntB, CntB->Turn = (Stack[Top] != x);
    do { Stack[Top]->Bel = CntB; } while (Stack[Top--] != x);
  }
}
void Del(BCC* x) {
  EdgeB* Sid(x->Fst);
  while (Sid) { if (Sid != x->Dont) Sid->Deleted = 1; Sid = Sid->Nxt; }
}
void DFSFall(BCC* x) {
  EdgeB* Sid(x->Fst);
  x->SubTree = x->Turn;
  while (Sid) {
    if (Sid->To != x->Fa) {
      DFSFall(Sid->To), x->SubTree |= Sid->To->SubTree;
      if (!(Sid->To->SubTree)) {
        Sid->Ava = 1;
        if (Sid->To->Dont) Sid->To->Dont = EB + 0x3f3f3f3f;
        else Sid->To->Dont = EB + ((Sid - EB) ^ 1);
        Sid->To->Deleted = 1;
      }
    }
    Sid = Sid->Nxt;
  }
}
void DFSRise(BCC* x) {
  BCC* Son(NULL);
  EdgeB* Sid(x->Fst);
  char More(0);
  while (Sid) {
    if ((Sid->To != x->Fa) && (Sid->To->SubTree)) More = (Son ? 1 : 0), Son = Sid->To;
    Sid = Sid->Nxt;
  }
  Sid = x->Fst;
  if (More || (x->Turn)) {
    while (Sid) {
      if (Sid->To != x->Fa) Sid->To->Turn = 1, DFSRise(Sid->To);
      Sid = Sid->Nxt;
    }
    return;
  }
  if (!Son) {
    while (Sid) {
      if (Sid->To != x->Fa) {
        DFSRise(Sid->To), EB[((Sid - EB) ^ 1)].Ava = 1, x->Deleted = 1;
        if (x->Dont) x->Dont = EB + 0x3f3f3f3f; else x->Dont = Sid;
      }
      Sid = Sid->Nxt;
    }
    return;
  }
  while (Sid) {
    if (Sid->To != x->Fa) {
      if (Sid->To == Son) {
        DFSRise(Sid->To), EB[((Sid - EB) ^ 1)].Ava = 1, x->Deleted = 1;
        if (x->Dont) x->Dont = EB + 0x3f3f3f3f; else x->Dont = Sid;
      }
      else Sid->To->Turn = 1, DFSRise(Sid->To);
    }
    Sid = Sid->Nxt;
  }
}
signed main() {
  n = RD(), m = RD(), M = (m << 1);
  for (unsigned i(0); i < m; ++i) IO[i].Frm = RD(), IO[i].To = RD();
  sort(IO, IO + m);
  for (unsigned i(0); i < M; i += 2) {
    C = IO[i >> 1].Frm, D = IO[i >> 1].To;
    E[i].Nxt = N[C].Fst, N[C].Fst = E + i, E[i].To = N + D;
    E[i ^ 1].Nxt = N[D].Fst, N[D].Fst = E + (i ^ 1), E[i ^ 1].To = N + C;
  }
  for (unsigned i(1); i <= n; ++i) if (!(N[i].DFSr)) Shrink(N + i, NULL), Root[++CntRoot] = CntB;
  Cnt = 0;
  for (unsigned i(1); i <= n; ++i) Link(N + i);
  for (unsigned i(1); i <= CntRoot; ++i) DFSFall(Root[i]), DFSRise(Root[i]);
  for (BCC* i(B + 1); i <= CntB; ++i) if (i->Deleted) Del(i);
  for (unsigned i(0); i < Cnt; ++i) if (EB[i].Ava && (!EB[i].Deleted)) IO[++CntPrt] = EB[i].UsedTo;
  sort(IO + 1, IO + CntPrt + 1);
  printf("%u\n", CntPrt);
  for (unsigned i(1); i <= CntPrt; ++i) printf("%u %u\n", IO[i].Frm, IO[i].To);
  system("pause");
  return Wild_Donkey;
}