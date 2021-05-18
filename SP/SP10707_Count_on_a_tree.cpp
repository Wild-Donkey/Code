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
unsigned a[100005], b[100005], List[100005], m, n, Cnt[100005], CntC(0), CntEu(0), A, B, C, D, t, Ans[100005], Tmp(0), BlockLen;
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[18];
  unsigned Val, Dep, Pre, Suf;
  char Have;
}N[100005], *CntN(N), *Ace, *Euler[200005];
struct Edge {
  Node *To;
  Edge *Nxt;
}E[200005], *CntE(E);
struct Qry{
  unsigned Block, L, R, Num;
  inline const char operator<(const Qry &x) const{
    return (this->Block ^ x.Block) ? (this->Block < x.Block) : (this->R < x.R);
  }
}Q[100005];
inline void Link (Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  return;
}
void DFS (Node *x) {
  Edge *Sid(x->Fst);
  x->Pre = ++CntEu;
  Euler[CntEu] = x;
  while (Sid) {
    if(Sid->To != x->Fa[0]) {
      Sid->To->Fa[0] = x;
      Sid->To->Dep = x->Dep + 1;
      for (register unsigned i(0); Sid->To->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
      }
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
  x->Suf = ++CntEu;
  Euler[CntEu] = x;
  return;
}
Node *LCA(Node *x, Node *y) {
  if(x->Dep < y->Dep) {
    register Node *Tmp(x);
    x = y, y = Tmp;
  }
  for (register unsigned i(17); x->Dep > y->Dep; --i) {
    if(x->Fa[i]) {
      if(x->Fa[i]->Dep >= y->Dep) {
        x = x->Fa[i];
      }
    }
  }
  if(x == y) {
    return x;
  }
  for (register unsigned i(17); x->Fa[0] != y->Fa[0]; --i) {
    if(x->Fa[i] != y->Fa[i]) {
      x = x->Fa[i];
      y = y->Fa[i];
    }
  }
  return x->Fa[0];
}
int main() {
  n = RD(), m = RD();
  BlockLen = ((n) / (sqrt(m >> 1) + 1)) + 1;
  for (register unsigned i(1); i <= n; ++i) {
    a[i] = RD();
  }
  memcpy(b, a, sizeof(a));
  sort(b + 1, b + n + 1);
  for (register unsigned i(1); i <= n; ++i) {
    if(b[i] ^ b[i - 1]) {
      List[++CntC] = b[i];
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Val = lower_bound(List + 1, List + CntC + 1, a[i]) - List;
  }
  for (register unsigned i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Link(A + N, B + N);
    Link(B + N, A + N);
  }
  N[1].Dep = 1;
  N[1].Fa[0] = NULL;
  N[1].Have = 1;
  DFS(N + 1);
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RD();
    Q[i].Num = i;
    if((N[A].Pre <= N[B].Pre) && (N[A].Suf >= N[B].Suf)) {//B in A
      Q[i].L = N[A].Pre, Q[i].R = N[B].Pre;
      continue;
    }
    if((N[B].Pre <= N[A].Pre) && (N[B].Suf >= N[A].Suf)) {//A in B
      Q[i].L = N[B].Pre, Q[i].R = N[A].Pre;
      continue;
    }
    Q[i].L = (N[A].Suf < N[B].Suf) ? N[A].Suf : N[B].Suf;
    Q[i].R = (N[A].Pre < N[B].Pre) ? N[B].Pre : N[A].Pre;
  }
  for (register unsigned i(1); i <= m; ++i) {
    Q[i].Block = Q[i].L / BlockLen;
  }
  sort(Q + 1, Q + m + 1);
  Q[0].L = Q[0].R = 1;
  Cnt[Euler[1]->Val] = 1;
  Ans[0] = 1, Euler[1]->Have = 1;
  for (register unsigned i(1); i <= m; ++i) {
    while(Q[0].L > Q[i].L){ // 左端点左移
      if(Euler[--Q[0].L]->Have ^= 1) { // 正标记
        Ans[0] += !(Cnt[Euler[Q[0].L]->Val]++);
      }
      else {                    // 负标记 
        Ans[0] -= !(--Cnt[Euler[Q[0].L]->Val]);
      }
    }
    while(Q[0].R < Q[i].R){ // 右端点右移
      if(Euler[++Q[0].R]->Have ^= 1) { // 正标记
        Ans[0] += !(Cnt[Euler[Q[0].R]->Val]++);
      }
      else {                    // 负标记 
        Ans[0] -= !(--Cnt[Euler[Q[0].R]->Val]);
      }
    }
    while(Q[0].L < Q[i].L){ // 左端点右移
      if(Euler[Q[0].L]->Have ^= 1) { // 正标记
        Ans[0] += !(Cnt[Euler[Q[0].L++]->Val]++);
      }
      else {                  // 负标记 
        Ans[0] -= !(--Cnt[Euler[Q[0].L++]->Val]);
      }
    }
    while(Q[0].R > Q[i].R){ // 右端点左移
      if(Euler[Q[0].R]->Have ^= 1) { // 正标记
        Ans[0] += !(Cnt[Euler[Q[0].R--]->Val]++);
      }
      else {                  // 负标记 
        Ans[0] -= !(--Cnt[Euler[Q[0].R--]->Val]);
      }
    }
    Ans[Q[i].Num] = Ans[0];
    Ans[Q[i].Num] += (!Cnt[LCA(Euler[Q[i].L], Euler[Q[i].R])->Val]);
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%u\n", Ans[i]);
  }
  return Wild_Donkey;
}
/*
10 1
1 2 3 4 5 6 7 8 9 10
2 1
3 2
4 2
5 4
6 2
7 6
8 3
9 1
10 2
1 3
*/
