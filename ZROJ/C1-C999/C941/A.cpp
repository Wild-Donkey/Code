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
unsigned Pnts[200005][2], m, n, Cnt(0), C, D, t, Ans(0), Tmp(0);
char b[10005];
struct Edge;
struct Node {
  Edge *Fst;
  unsigned long long Dist1, Dist2;
  bool InQue;
}N[100005], *A, *B;
struct Edge {
  Node *To;
  Edge *Nxt;
  unsigned long long Val;
}E[400005], *CntE(E);
struct Pnt{
  Node *P;
  unsigned long long Dist;
  const inline char operator <(const Pnt &x) const{
    return this->Dist > x.Dist;
  }
}TmpP;
void Link (Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
  CntE->Val = C;
}
priority_queue<Pnt> Q;
int main() {
  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = N + RD(), B = N + RD(), C = RD();
    Link(A, B), Link(B, A);
    Pnts[i][0] = A - N, Pnts[i][1] = B - N;
  }
  for (register unsigned i(1); i <= n; ++i) {
    N[i].Dist1 = N[i].Dist2 = 2147483647;
  }
  TmpP.P, N[1].Dist1 = 0, TmpP.P = N + 1, Q.push(TmpP);
  while (Q.size()) {
    register Node *Now((Q.top()).P); Q.pop();
    if(Now->InQue) continue;
    Now->InQue = 1;
    Edge *Sid(Now->Fst);
    while (Sid) {
      if(Sid->To->Dist1 > Now->Dist1 + Sid->Val) {
        Sid->To->Dist1 = Now->Dist1 + Sid->Val;
        TmpP.Dist = Sid->To->Dist1, TmpP.P = Sid->To, Q.push(TmpP);
      }
      Sid = Sid->Nxt;
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    N[i].InQue = 0;
  }
  TmpP.P, N[n].Dist2 = 0, TmpP.P = N + n, Q.push(TmpP);
  while (Q.size()) {
    register Node *Now((Q.top()).P); Q.pop();
    if(Now->InQue) continue;
    Now->InQue = 1;
    Edge *Sid(Now->Fst);
    while (Sid) {
      if(Sid->To->Dist2 > Now->Dist2 + Sid->Val) {
        Sid->To->Dist2 = Now->Dist2 + Sid->Val;
        TmpP.Dist = Sid->To->Dist2, TmpP.P = Sid->To, Q.push(TmpP);
      }
      Sid = Sid->Nxt;
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    printf("%llu\n", N[i].Dist1 + N[i].Dist2);
  }
  for (register unsigned i(1); i <= m; ++i) {
    printf("%llu\n", E[i << 1].Val + min(N[Pnts[i][0]].Dist1 + N[Pnts[i][1]].Dist2, N[Pnts[i][1]].Dist1 + N[Pnts[i][0]].Dist2));
  }
//  }
  return Wild_Donkey;
}
/*
4 4
1 2 3
2 3 4
3 4 5
1 3 5
*/
