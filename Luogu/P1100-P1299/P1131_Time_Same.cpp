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
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t;
unsigned long long Ans(0);
struct Edge;
struct Node {
  Node *Fa;
  Edge *Fst;
  unsigned long long Dep;
}N[500005], *S;
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned Val;
}E[1000005], *CntE(E);
inline void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  CntE->Val = C;
}
void DFS(Node *x) {
//  printf("DFS %u\n", x - N);
  register Edge *Sid(x->Fst);
  register unsigned long long Max(0);
  while (Sid) {
    if(Sid->To != x->Fa) {
      Sid->To->Fa = x;
      DFS(Sid->To);
      Max = max(Sid->To->Dep + Sid->Val, Max);
      x->Dep = max(x->Dep, Sid->To->Dep + Sid->Val);
    }
    Sid = Sid->Nxt;
  }
  Sid = x->Fst;
  while (Sid) {
    if(Sid->To != x->Fa) {
      Ans += Max - Sid->To->Dep - Sid->Val;
    }
    Sid = Sid->Nxt; 
  } 
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), S = N + RD();
  for (register unsigned i(1); i < n; ++i) {
    A = RD(), B = RD(), C = RD();
    Link(N + A, N + B);
    Link(N + B, N + A);
  }
  DFS(S);
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}

