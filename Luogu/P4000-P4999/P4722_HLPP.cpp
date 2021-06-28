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
unsigned Hd(0), Tl(0), Gap[1205], m, n, Cnt(0), C, D, t, Tmp(0);
struct Node; 
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Contain;
}E[240005], *CntE(E - 1);
struct Node {
  Edge *Fst;
  unsigned Dep, Contain;
}N[1205], *Qu[1205], *A, *B, *S, *T;
struct Que {
  Node *P;
  inline const char operator<(const Que &x) const {
    return this->P->Dep < x.P->Dep;
  }
};
priority_queue <Que> Q;
signed main() {
  n = RD(), m = RD(), S = N + RD(), T = N + RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD(), C = RD();
    if(A == B) continue;
    (++CntE)->Nxt = A->Fst;
    A->Fst = CntE;
    CntE->To = B;
    CntE->Contain = C;
    (++CntE)->Nxt = B->Fst;
    B->Fst = CntE;
    CntE->To = A;
  }
  T->Dep = 1, Qu[++Tl] = T;
  register Node *x;
  while(Hd < Tl) {
    x = Qu[++Hd];
    register Edge *Sid(x->Fst);
    while (Sid) {
      if((!(Sid->To->Dep)) && (!(Sid->Contain))) {
        ++Gap[Sid->To->Dep = x->Dep + 1];
        Qu[++Tl] = Sid->To;
      }
      Sid = Sid->Nxt;
    }
  }
  --Gap[S->Dep];
  ++Gap[S->Dep = n + 1];
  register Que Pu;
  register Edge *Sid(S->Fst);
  while (Sid) {
    if(Sid->Contain) { 
      if(Sid->To != T && (!(Sid->To->Contain))) {
        Pu.P = Sid->To;
        Q.push(Pu);
      }
      Sid->To->Contain += Sid->Contain;
      (Sid + 1)->Contain = Sid->Contain;
      Sid->Contain = 0;
    }
    Sid = Sid->Nxt;
  }
  while(Q.size()) {
    x = (Q.top()).P, Q.pop();
    register unsigned Real;
    Sid = x->Fst;
    Tmp = 0x3f3f3f3f;
    while(Sid) {
      if(Sid->Contain) {
        if(Sid->To->Dep + 1 == x->Dep) {
          Real = min(x->Contain, Sid->Contain);
          if(!Real) {Sid = Sid->Nxt; continue;}
          x->Contain -= Real;
          Sid->Contain -= Real;
          E[(Sid - E) ^ 1].Contain += Real;
          if(Sid->To != S && Sid->To != T && (!(Sid->To->Contain))) {
            Pu.P = Sid->To, Q.push(Pu);
          }
          Sid->To->Contain += Real;
          if(!(x->Contain)) break;
        } else Tmp = min(Tmp, Sid->To->Dep);
      }
      Sid = Sid->Nxt;
    }
    if(x->Contain) {
      if(!(--Gap[x->Dep])) {
        for (register unsigned i(1); i <= n; ++i) {
          if(N + i != S && N + i != T && N[i].Dep > x->Dep) {
            N[i].Dep = n + 2;
          }
        }
      }
      ++Gap[x->Dep = Tmp + 1];
      Pu.P = x;
      Q.push(Pu);
    }
  }
  printf("%u\n", T->Contain);
  return Wild_Donkey;
}
/*
10 17 2 10
3 4 4
4 3 45
3 5 80
1 6 94
3 7 63
1 9 75
6 3 12
7 9 63
6 1 39
6 1 97
9 7 33
7 4 55
2 4 36
5 9 82
5 1 32
6 10 50
7 6 53
*/
