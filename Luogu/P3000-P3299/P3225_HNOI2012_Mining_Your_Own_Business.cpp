#include <algorithm>
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
unsigned long long Ans(1);
unsigned m, n, A, B, C, D, t;
unsigned Size[100005], CntCut[100005];
unsigned Cnt(0), Tmp(0), Top(0), BCC(0);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[100005], * CntE(E);
struct Node {
  Edge* Fst;
  unsigned DFSr, Low, Bel;
  char Cut;
}N[100005], * Stack[100005];
inline void Clr() {
  memset(Size, 0, (BCC + 1) << 2);
  memset(CntCut, 0, (BCC + 1) << 2);
  memset(N, 0, (n + 1) * sizeof(Node));
  m = RD(), BCC = Cnt = n = 0, Ans = 1, CntE = E;
}
void Tarjan(Node* x) {
  // printf("Tarr %u\n", x - N);
  Edge* Sid(x->Fst);
  (Stack[++Top] = x)->Low = x->DFSr = ++Cnt;
  while (Sid) {
    if (Sid->To->DFSr) x->Low = min(x->Low, Sid->To->DFSr);
    else {
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
      if (Sid->To->Low == x->DFSr) {
        Size[++BCC] = x->Cut = 1, CntCut[BCC] = 1;
        do ++Size[BCC], CntCut[BCC] += Stack[Top]->Cut, Stack[Top]->Bel = BCC;
        while (Stack[Top--] != Sid->To);
      }
    }
    Sid = Sid->Nxt;
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  for (unsigned T(1);;++T) {
    Clr();
    if (!m) { return Wild_Donkey; }
    for (unsigned i(1); i <= m; ++i) {
      n = max(n, C = RD()), n = max(n, D = RD());
      // printf("Link %u %u\n", C, D);
      (++CntE)->Nxt = N[C].Fst, N[C].Fst = CntE, CntE->To = N + D;
      (++CntE)->Nxt = N[D].Fst, N[D].Fst = CntE, CntE->To = N + C;
    }
    Tarjan(N + 1), Cnt = 0, N[1].Bel = N[1].Fst->To->Bel;
    for (Edge* i(N[1].Fst); i; i = i->Nxt, ++Tmp)
      if (N[1].Bel != i->To->Bel) N[1].Bel = 0;
    if (N[1].Bel) --CntCut[BCC];
    // for (unsigned i(1); i <= BCC; ++i) printf("BCC %u: Size %u Cut %u\n", i, Size[i], CntCut[i]);
    if (BCC == 1) Cnt = 2, Ans = (n * (n - 1)) >> 1;
    else for (unsigned i(1); i <= BCC; ++i) if (CntCut[i] == 1)  Ans *= Size[i] - 1, Cnt += 1;
    printf("Case %u: %u %llu\n", T, Cnt, Ans);
  }
}
/*
1
1 2
Case 1: 2 1
2
1 2 1 3
Case 2: 2 1
2
1 2
1 3
Case 3: 2 1
3
1 2
2 3
1 3
Case 4: 2 3
5
1 2
1 3
1 4
1 5
1 6
Case 5: 5 1
5
6 1
6 2
6 3
6 4
6 5
Case 6: 4 1
*/