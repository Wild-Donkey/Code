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
unsigned Hd(0), Tl(0), Gap[10005], m, n, Cnt(0), C, D, t;
unsigned long long Ans;
struct Node; 
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Contain;
}E[10005], *CntE(E);
struct Node {
  Edge *Fst;
  unsigned Dep;
}N[205], *Que[205], *A, *B, *S, *T;
unsigned DFS(Node *x, unsigned Come) {
  if(x == T) {
    return Come;
  }
  register Edge *Sid(x->Fst);
  register unsigned Go(0), Tmp;
  while (Sid) {
    if((Sid->To->Dep + 1 == x->Dep) && (Sid->Contain)) {
      Tmp = DFS(Sid->To, min(Come, Sid->Contain));
      Come -= Tmp;
      Go += Tmp;
      Sid->Contain -= Tmp;
      (Sid + 1)->Contain += Tmp;
      if(!Come) {
        return Go;
      }
    }
    Sid = Sid->Nxt;
  }
  if(!(--Gap[(x->Dep)++])) S->Dep = n + 1;
  ++Gap[x->Dep];
  return Go;
}
signed main() {
  n = RD(), m = RD(), S = N + RD(), T = N + RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD(), C = RD();
    (++CntE)->Nxt = A->Fst;
    A->Fst = CntE;
    CntE->To = B;
    CntE->Contain = C;
    (++CntE)->Nxt = B->Fst;
    B->Fst = CntE;
    CntE->To = A;
  }
  T->Dep = 1, Que[++Tl] = T;
  register Node *x;
  while(Hd < Tl) {
    x = Que[++Hd];
    register Edge *Sid(x->Fst);
    while (Sid) {
      if(!(Sid->To->Dep)) {
        ++Gap[Sid->To->Dep = x->Dep + 1];
        Que[++Tl] = Sid->To;
      }
      Sid = Sid->Nxt;
    }
  }
  while (S->Dep <= n) {
    Ans += DFS(S, 0xffffffff);
  }
  printf("%llu\n", Ans);
  return Wild_Donkey;
}

