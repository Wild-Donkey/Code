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
const unsigned MOD(1000000007);
unsigned a[10005], b[10005], m, n, Cnt(0), Hd(0), Tl(0), t, Ans(0), Tmp(0);
char c[10005];
struct Edge;
struct Node {
  Edge *Fst;
  unsigned Ways, Dist;
}N[200005], *Q[200005], *A, *B;
struct Edge {
  Node *To;
  Edge *Nxt;
}E[400005], *CntE(E);
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Dist = 0x3f3f3f3f;
  }
  for (register unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD();
    (++CntE)->Nxt = A->Fst;
    CntE->To = B;
    A->Fst = CntE;
    (++CntE)->Nxt = B->Fst;
    CntE->To = A;
    B->Fst = CntE;
  }
  Q[++Tl] = N + 1;
  register Node *now;
  N[1].Ways = 1, N[1].Dist = 0;
  while (Hd < Tl) {
    now = Q[++Hd];
    register Edge *Sid(now->Fst);
//    printf("Now %u\n", now - N);
    while (Sid) {
//      printf("To %u\n", Sid->To - N);
      if (Sid->To->Dist == now->Dist + 1) {
        Sid->To->Ways += now->Ways;
        if(Sid->To->Ways >= MOD) Sid->To->Ways -= MOD;
      }
      if (Sid->To->Dist > now->Dist + 1) {
        Sid->To->Dist = now->Dist + 1;
        Sid->To->Ways = now->Ways;
        Q[++Tl] = Sid->To;
      }
      Sid = Sid->Nxt;
    }
  }
  printf("%u\n", N[n].Ways);
//  }
  return Wild_Donkey;
}

