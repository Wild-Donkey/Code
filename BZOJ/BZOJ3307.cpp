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
inline int RD() {
  int intmp(0), insig(1);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    if (rdch == '-') {
      insig = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insig;
}
unsigned M, n, Ans[100005];
int Lst, A, B, C, D;  //全局变量存操作参数和答案防止调用函数时浪费时间
struct Node {
  Node *L, *R;  //左右儿子指针
  int Mxn, Mx;
} N[5000005], *Cntn(N);  //内存池 + 指针
struct Edge;
struct Grp {
  unsigned Fst;
  int Dep;
  unsigned Fa[17];
  unsigned Tre;
} G[100005], *Aci;
struct Edge {
  unsigned Nxt;
  unsigned To;
} E[200005], *Cnte(E);
inline void Udt(Node *x) {
  if (x->L && x->R) {
    if (x->L->Mxn >= x->R->Mxn) {
      x->Mx = x->L->Mx;
      x->Mxn = x->L->Mxn;
      return;
    }
    x->Mx = x->R->Mx;
    x->Mxn = x->R->Mxn;
    return;
  }
  if (x->L) {
    x->Mx = x->L->Mx;
    x->Mxn = x->L->Mxn;
    return;
  }
  if (x->R) {
    x->Mx = x->R->Mx;
    x->Mxn = x->R->Mxn;
    return;
  }
  return;
}
void Into(Node *x, Node *y, unsigned l, unsigned r) {
  if (l == r) {
    x->Mxn += y->Mxn;
    x->Mx = l;
    return;
  }
  unsigned int m((l + r) >> 1);
  if (x->L) {
    if (y->L) Into(x->L, y->L, l, m);
  } else x->L = y->L;
  if (x->R) {
    if (y->R) Into(x->R, y->R, m + 1, r);
  } else x->R = y->R;
  Udt(x);
  return;
}
void Lnk(unsigned x, unsigned y) {
  (++Cnte)->Nxt = G[x].Fst;
  G[x].Fst = Cnte - E;
  Cnte->To = y;
  return;
}
void Bld(Grp *x) {
  unsigned Sid(x->Fst);
  while (Sid) {
    if (E[Sid].To != x->Fa[0]) {
      G[E[Sid].To].Fa[0] = x - G;
      G[E[Sid].To].Dep = x->Dep + 1;
      unsigned int i(0);
      while (G[E[Sid].To].Fa[i]) {
        G[E[Sid].To].Fa[i + 1] = G[G[E[Sid].To].Fa[i]].Fa[i], ++i;
      }
      Bld(G + E[Sid].To);
    }
    Sid = E[Sid].Nxt;
  }
  return;
}
Grp *LCA(Grp *x, Grp *y) {
  if (x->Dep < y->Dep) swap(x, y);
  unsigned i(16);
  while (x->Dep > y->Dep) {
    if (x->Fa[i]) {
      if (G[x->Fa[i]].Dep >= y->Dep)
        x = G + x->Fa[i];
    }
    --i;
  }
  if (x->Dep == y->Dep) {
    if (x == y) return x;
    i = 16;
    while (i <= 16) {
      if (x->Fa[i] != y->Fa[i]) {
        x = G + x->Fa[i];
        y =	G + y->Fa[i];
      }
      --i;
    }
  }
  return G + x->Fa[0];
}
void Chg(Node *x, unsigned int l, const unsigned int &r) {
  if (l == r) {
    x->Mx = l;
    x->Mxn += D;
    return;
  }
  unsigned int m((l + r) >> 1);
  if (m >= C) {
    if (!(x->L)) Chg(x->L = ++Cntn, l, m);
    else Chg(x->L, l, m);
    return Udt(x);
  }
  if (!(x->R)) Chg(x->R = ++Cntn, m + 1, r);
  else Chg(x->R, m + 1, r);
  return Udt(x);
}
void DFS(Grp *x) {
  Edge *Sid(E + x->Fst);
  while (Sid - E) {
    if (Sid->To != x->Fa[0]) {
      DFS(G + Sid->To);
      if (G[Sid->To].Tre) {
        if (x->Tre) Into(N + x->Tre, N + G[Sid->To].Tre, 1, 100000);
        else x->Tre = G[Sid->To].Tre;
      }
    }
    Sid = E + Sid->Nxt;
  }
  if (x->Tre) {
    if (N[x->Tre].Mxn) {
      Ans[x - G] = N[x->Tre].Mx;
    } else {
      Ans[x - G] = 0;
    }
  } else {
    Ans[x - G] = 0;
  }
  return;
}
int main() {
  n = RD();
  M = RD();
  for (register unsigned int i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Lnk(A, B);
    Lnk(B, A);
  }
  G[1].Dep = 1;
  Bld(G + 1);
  for (register int i(1); i <= M; ++i) {  //操作
    A = RD();
    B = RD();
    C = RD();
    D = 1;
    Aci = LCA(G + A, G + B);
    if (!G[A].Tre) {
      G[A].Tre = (++Cntn) - N;
    }
    if (!G[B].Tre) {
      G[B].Tre = (++Cntn) - N;
    }
    if (!Aci->Tre) {
      Aci->Tre = (++Cntn) - N;
    }
    Chg(N + G[A].Tre, 1, 100000);
    Chg(N + G[B].Tre, 1, 100000);
    D = -1;
    Chg(N + Aci->Tre, 1, 100000);
    if (Aci->Fa[0]) {
      if (!G[Aci->Fa[0]].Tre)
        G[Aci->Fa[0]].Tre = (++Cntn) - N;
      Chg(N + G[Aci->Fa[0]].Tre, 1, 100000);
    }
  }
  DFS(G + 1);
  for (register int i(1); i <= n; ++i)
    printf("%d\n", Ans[i]);
  return 0;
}
