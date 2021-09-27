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
inline unsigned RD() {
  unsigned intmp(0);
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
unsigned m, n, q, Hd, Tl;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Qry[200005][2];
unsigned Top;
struct Node;
struct Edge{
  Node* To;
  Edge* Nxt;
}E[200005], *CntE(E);
struct Node {
  Edge* Fst;
  unsigned ToPo, Deg;
}N[200005], * Q[200005];
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].Fst = NULL, N[i].Deg = NULL;
  n = RD(), m = RD(), Hd = Tl = q = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= m; ++i) {
      C = RD(), A = RD(), B = RD();
      if(C) (++CntE)->Nxt = N[A].Fst, N[A].Fst = CntE, CntE->To = N + B, ++N[B].Deg;
      else Qry[++q][0] = A, Qry[q][1] = B;
    }
    for (unsigned i(1); i <= n; ++i) if(!N[i].Deg) Q[++Tl] = N + i;
    while (Tl ^ Hd) {
      Node* Cur(Q[++Hd]);
      Edge* Sid(Cur->Fst);
      Cur->ToPo = ++Cnt;
      while(Sid) {
        if(!(--(Sid->To->Deg))) Q[++Tl] = Sid->To;
        Sid = Sid->Nxt; 
      }
    }
    if(Tl < n) {printf("NO\n"); continue;}
    printf("YES\n");
    for (unsigned i(1); i <= q; ++i) {
      if(N[Qry[i][0]].ToPo > N[Qry[i][1]].ToPo) swap(Qry[i][0], Qry[i][1]);
      printf("%u %u\n", Qry[i][0], Qry[i][1]);
    }
    for (unsigned i(1); i <= n; ++i) {
      Edge* Sid(N[i].Fst);
      while (Sid) {
        printf("%u %u\n", i, Sid->To - N);
        Sid = Sid->Nxt;
      }
    }
  }
//  system(\"pause\");
  return Wild_Donkey;
}

