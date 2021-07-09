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
unsigned m, n, Cnt(0), Sons[20005], A, B, C, D, t, Tmp(0), Ans(0);
char Tag[20005];
struct Node; 
struct Edge {
  Node *To;
  Edge *Nxt;
}E[200005], *CntE(E);
struct Node {
  Edge *Fst;
  unsigned DFSr, Low;
}N[20005], *CntN(N);
inline void Link(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
}
void Tarjan(Node *x, Node *Fa) {
  x->Low = x->DFSr = ++Cnt;
//  printf("Me %u Fa %u RK %u\n", x - N, Fa - N, x->DFSr);
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To->DFSr) {
      if(Sid->To != Fa) {
        x->Low = min(x->Low, Sid->To->DFSr);
      }
    } else {
      ++Sons[x - N]; 
      Tarjan(Sid->To, x);
      x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
//  printf("Low[%u] = %u\n", x - N, x->Low);
  if(x->Low >= Fa->DFSr) Tag[Fa - N] = 1;
}
int main() {
  // double Ti(clock()), Mti(0);
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    Link(A + N, B + N);
    Link(B + N, A + N);
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!N[i].DFSr) {
      Tarjan(N + i, N);
      Tag[i] = ((Sons[i] > 0x1) ? 0x1 : 0x0);
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(Tag[i]) ++Ans;
  }
  printf("%u\n", Ans);
  for (register unsigned i(1); i <= n; ++i) {
    if(Tag[i]) printf("%u ", i);
  }
//  }
  // Ti = clock() - Ti;
  // printf("Time %lf MTime %lf\n", Ti, Mti);
  // system("pause");
  // fclose(stdin);
  // fclose(stdout);
  return Wild_Donkey;
}

