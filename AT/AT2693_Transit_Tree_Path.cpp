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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
bool b[10005];
inline void Clr() {}
struct Edge; 
struct Node {
  Edge *Fst;
  Node *Fa; 
  unsigned long long Dep;
}N[100005], *S;
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Val;
}E[200005], *CntE(E);
void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  CntE->Val = C;
}
void DFS(Node *x) {
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa) {
      Sid->To->Fa = x;
      Sid->To->Dep = x->Dep + Sid->Val; 
      DFS(Sid->To);
    }
    Sid = Sid->Nxt;
  }
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (register unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Dep = 0x3f3f3f3f3f3f3f3f;
  }
  m = RD(), S = N + RD(), S->Dep = 0;
  DFS(S); 
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    printf("%llu\n", N[A].Dep + N[B].Dep); 
  }
  //  }
  return Wild_Donkey;
}

