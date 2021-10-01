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
unsigned m, n, n2;
unsigned A, B, C, D, t;
unsigned Cnt(0), SCC(0), Top(0);
char Ch, Flg(0);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[2005], * CntE(E);
struct Node {
  Edge* Fst;
  unsigned Low, DFSr, Bel;
  char InS;
}N[205], *Stack[205];
inline void Clr() {
  memset(N, 0, (n2 + 2) * sizeof(Node));
  memset(E, 0, ((m + 1) << 1) * sizeof(Edge));
  n2 = ((n = RD()) << 1), m = RD(), Cnt = SCC = Flg = 0, CntE = E;
}
inline void Link(Node* x, Node* y) {
  (++CntE)->Nxt = x->Fst, x->Fst = CntE, CntE->To = y;
}
inline void Tarjan(Node* x) {
//  printf("Tar %u\n", x - N);
  x->Low = x->DFSr = ++Cnt, Stack[++Top] = x, x->InS = 1;
  Edge* Sid(x->Fst);
  while (Sid) {
//    printf("Sid %u to %u\n", Sid - E, Sid->To - N);
    if(Sid->To->DFSr) {
      if(Sid->To->InS) x->Low = min(x->Low, Sid->To->Low);
    } else {
      Tarjan(Sid->To), x->Low = min(x->Low, Sid->To->Low);
    }
    Sid = Sid->Nxt;
  }
  if(x->DFSr == x->Low) {
    ++SCC;
    do Stack[Top]->InS = 0, Stack[Top]->Bel = SCC;// printf("Top %u\n", Top);
    while (Stack[Top--] != x);
  }
}
signed main() {
//  freopen("P4171_1.in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= m; ++i) {
      Ch = getchar(); while (Ch < 'a') Ch = getchar();
      C = (Ch ^ 'm') ? 1 : 0, A = (RD() << 1);
      Ch = getchar(); while (Ch < 'a') Ch = getchar();
      D = (Ch ^ 'm') ? 1 : 0, B = (RD() << 1);
//      printf("%u %u %u %u\n", (A >> 1), (B >> 1), C, D);
      Link(N + (A ^ C ^ 1), N + (B ^ D));
      Link(N + (B ^ D ^ 1), N + (A ^ C));
    }
    for (unsigned i(1); i <= n2; ++i) if(!N[i + 1].DFSr) Tarjan(N + i + 1);
//    printf("Faq\n");
    for (unsigned i(2); i <= n2; i += 2) if(N[i].Bel == N[i ^ 1].Bel) {Flg = 1;break;}
    printf(Flg ? "BAD\n" : "GOOD\n");
  }
  return Wild_Donkey;
}

