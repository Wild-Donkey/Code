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
unsigned V[100005], W[100005], SumW[100005], Q, m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Ti, Que;
long long Euler[200005];
bool b[10005];
struct Edge;
struct Node {
  Edge *Fst;
  Node *Fa[20];
  unsigned Dep, Frnt, Back;
}N[100005];
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
inline void Clr() {}
void DFS(Node *x) {
  x->Frnt = ++Cnt;
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa[0]) {
      Sid->To->Fa[0] = x;
      DFS(Sid->To);
      for(register unsigned i(0); Sid->To->Fa[i]; ++i) {
        Sid->To->Fa[i + 1] = Sid->To->Fa[i]->Fa[i];
      }
    }
    Sid = Sid->Nxt;
  }
  x->Back = ++Cnt;
}
Node *LCA(Node *x, Node *y) {
  
}
void Check(N + x, N + y) {
  
}
void Change() {
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Q = RD(); 
  for (register unsigned i(1); i <= m; ++i) {
    V[i] = RD();
  }
  for (register unsigned i(1); i <= n; ++i) {
    W[i] = RD(), SumW[i] = SumW[i - 1] + W[i];
  }
  for (register unsigned i(1); i < n; ++i) {
    A = RD();
    B = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  N[1].Dep = 1;
  DFS(N + 1);
  for (register unsigned i(1); i <= Cnt; ++i) {
    printf("%u %lld\n", i, Euler[i]);
  }
  for (register unsigned i(1); i <= Q, ++i) {
    if(RD()) {
      A = RD(), B = RD();
      Change(N + A, B);
    }
    else {
      A = RD(), B = RD();
      Check(N + A, N + B);
    }
  }
  sort(Query + 1, Query + Que + 1);
  for (register unsigned i(1); i <= Que; ++i) {
    
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}



