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
unsigned V[100005], W[100005], Q, m, n, Cnt[100005], CntEu(0), A, B, C, D, t, Ans(0), Tmp(0), Ti, Que;
long long Euler[200005];
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[20];
  unsigned Dep, Frnt, Back;
  char Have;
}N[100005], *Euler[200005];
struct Edge {
  Edge *Nxt;
  Node *To;
}E[200005], CntE;
inline void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  return;
}
void DFS(Node *x) {
  x->Frnt = ++CntEu;
  Euler[CntEu] = x;
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa[0]) {
      Sid->To->Fa[0] = x;
      Sid->To->Dep = x->Dep + 1;
      for(register unsigned i(0); Sid->To->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
      }
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  x->Back = ++Cnt;
  Euler[CntEu] = x;
}
Node *LCA(Node *x, Node *y) {
  if(x->Dep < x->Dep) {
    Node *TmpNd(x), x = y, y = TmpNd;
  }
  for (register unsigned i(19); x->Dep > y->Dep; --i) {
    if(x->Fa[i]) {
      x = (x->Fa[i]->Dep >= y->Dep) ? x->Fa[i] : x;
    }
  }
  if (x == y) {
    return x;
  }
  for (register unsigned i(19); x->Fa[0] != y->Fa[0]; --i) {
    if(x->Fa[i] != y->Fa[i]) {
      x = x->Fa[i], y = y->Fa[i];
    }
  }
  return x->Fa[0];
}
struct Qry {
  unsigned L, R, Ti, BlockL, BlockR;
  inline const char operator<(const Qry &x) const {
    return (this->BlockL ^ x.BlockL) ? (this->BlockL < x.BlockL) : ((this->BlockR ^ x.BlockR) ? (this->BlockR < x.BlockR) : this->Ti < x.Ti);
  } 
}Q[100005];
int main() {
  n = RD(), m = RD(), Q = RD(); 
  for (register unsigned i(1); i <= m; ++i) {
    V[i] = RD();
  }
  for (register unsigned i(1); i <= n; ++i) {
    W[i] = RD();
  }
  for (register unsigned i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  N[1].Dep = 1;
  N[1].Fa = NULL;
  DFS(N + 1);
  for (register unsigned i(1); i <= Cnt; ++i) {
    printf("%u %lld\n", i, Euler[i]);
  }
  for (register unsigned i(1); i <= Q, ++i) {
    if(RD()) {
      A = RD(), B = RD();
    }
    else {
      A = RD(), B = RD();
      Q[]
    }
  }
  sort(Query + 1, Query + Que + 1);
  for (register unsigned i(1); i <= Que; ++i) {
    while (Q[0].Ti < Q[i].Ti) {
      Ans += (Chg[Q[0].Ti]) * ();
    }
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



