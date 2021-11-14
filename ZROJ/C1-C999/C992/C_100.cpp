#include <algorithm>
#include <bitset>
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
inline int RD() {
  int intmp(0);
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
unsigned m, n, Tl(0), Hd(0); 
unsigned A, B, D, t, P(42), PP;
unsigned Cnt(0), Ans(0), Tmp(0);
char C[3] = {'R', 'G', 'B'};
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Col;
}E[200005];
struct Node {
  Edge* Fst;
  unsigned Midl, Big, ToPo, Deg;
}N[50005], * Q[50005];
inline void Color(Node* x) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if(x->Midl ^ Sid->To->Midl) {
      if(x->Big ^ Sid->To->Big) Sid->Col = 'B';
      else Sid->Col = 'G';
    } else Sid->Col = 'R';
    Sid = Sid->Nxt;
  }
}
signed main() {
//  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (int T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), PP = P * P; 
  for (unsigned i(1); i <= m; ++i)
    B = RD(), A = RD(), E[i].Nxt = N[A].Fst, N[A].Fst = E + i, E[i].To = N + B, ++N[B].Deg;
  for (unsigned i(1); i <= n; ++i) if(!(N[i].Deg)) Q[++Tl] = N + i;
  while (Tl ^ Hd) {
    Node* Cur(Q[++Hd]);
    Edge* Sid(Cur->Fst);
    Cur->ToPo = ++Cnt;
    while (Sid) {
      if(!(--(Sid->To->Deg))) Q[++Tl] = Sid->To;
      Sid = Sid->Nxt;
    }
  }
  for (unsigned i(1); i <= n; ++i) N[i].Midl = N[i].ToPo / P, N[i].Big = N[i].ToPo / PP;
  for (unsigned i(1); i <= n; ++i) Color(N + i);
  for (unsigned i(1); i <= m; ++i) putchar(E[i].Col), putchar('\n');
//  }
//  system(\"pause\");
  return Wild_Donkey;
}

