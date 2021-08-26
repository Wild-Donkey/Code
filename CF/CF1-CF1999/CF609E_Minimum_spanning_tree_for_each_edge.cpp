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
unsigned Fa[200005], Stack[200005], StTp(0), m, n, Cnt(0), A, B, C, D, t;
unsigned long long Sum(0), Ans[200005], Tmp(0);
bool b[10005];
struct FakeEdge {
  unsigned Val, Fr, To, Num;
  char Tag;
  inline const char operator< (const FakeEdge &x) const{
    return this->Val < x.Val;
  }
}FE[200005];
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[20];
  unsigned Max[20], Dep;
}N[200005];
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Val;
  char InTr;
}E[400005], *CntE(E);
void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  CntE->Val = C;
}
unsigned Find(unsigned x) {
  register unsigned Tmpx(x), TmpF;
  while (Fa[Tmpx] ^ Tmpx) {
    Stack[++StTp] = Tmpx;
    Tmpx = Fa[Tmpx];
  }
  while (StTp) {
    Fa[Stack[StTp--]] = Tmpx;
  }
  return Tmpx;
}
void DFS(Node *x) {
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa[0]) {
      Sid->To->Fa[0] = x;
      Sid->To->Max[0] = Sid->Val;
      Sid->To->Dep = x->Dep + 1;
      for (register unsigned i(0); Sid->To->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
        Sid->To->Max[i + 1] = max(Sid->To->Max[i], Sid->To->Fa[i]->Max[i]);
      }
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
}
unsigned LCA(Node *x, Node *y) {
  register unsigned TmpM(0);
  if(x->Dep < y->Dep) swap(x, y);
  for (register unsigned i(18); i < 0x3f3f3f3f; --i) {
    if(x->Fa[i]) {
      if(x->Fa[i]->Dep >= y->Dep) {
        TmpM = max(TmpM, x->Max[i]);
        x = x->Fa[i];
      }
    }
  }
  if(x == y) return TmpM;
  for (register unsigned i(18); i < 0x3f3f3f3f; --i) {
    if(x->Fa[i] != y->Fa[i]) {
      TmpM = max(TmpM, x->Max[i]);
      TmpM = max(TmpM, y->Max[i]);
      x = x->Fa[i];
      y = y->Fa[i];
    }
  }
  TmpM = max(TmpM, x->Max[0]);
  TmpM = max(TmpM, y->Max[0]);
  return TmpM;
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(); 
  for (register unsigned i(1); i <= m; ++i) {
    FE[i].Fr = RD(), FE[i].To = RD(), FE[i].Val = RD(), FE[i].Num = i;
  }
  sort(FE + 1, FE + m + 1);
  for (register unsigned i(1); i <= n; ++i) Fa[i] = i;
  for (register unsigned i(1); i <= m; ++i) {
    if(Find(FE[i].Fr) ^ Find(FE[i].To)) {
      FE[i].Tag = 1;
      Fa[Fa[FE[i].Fr]] = Fa[FE[i].To];
      Sum += FE[i].Val;
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    if(FE[i].Tag) {
      C = FE[i].Val;
      Link(N + FE[i].Fr, N + FE[i].To);
      Link(N + FE[i].To, N + FE[i].Fr);
    }
  }
  DFS(N + 1);
  for (register unsigned i(1); i <= m; ++i) {
    if(FE[i].Tag) {
      Ans[FE[i].Num] = Sum;
    } else {
//      printf("Ed %u Val %u, Rd %u\n", FE[i].Num, FE[i].Val, LCA(N + FE[i].Fr, N + FE[i].To));
      Ans[FE[i].Num] = Sum + FE[i].Val - LCA(N + FE[i].Fr, N + FE[i].To);
    }
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%llu\n", Ans[i]);
  }
  //  }
  return Wild_Donkey;
}


