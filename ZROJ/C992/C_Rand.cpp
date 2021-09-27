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
unsigned m, n, Tl(0), Hd(0); 
unsigned A, B, D, t, P(42);
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
unsigned Seed(200410223), Last(1), Mod(998244353);
unsigned Stack[50005][2], Can[5], Choice[5], Top;
char C[3] = {'R', 'G', 'B'};
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Col;
}E[400005];
struct Node {
  Edge* Fst;
  unsigned Deg, f[3];
}N[50005], * Q[50005], * List[50005];
unsigned Rand() {
  return Last = (unsigned long long)Last * Seed % Mod;
}
void Random() {
  for (unsigned i(1); i <= m; ++i) E[i].Col = C[Rand() % 3];
}
void Judge () {
  Ans = 0;
  for (unsigned i(1); i <= n; ++i) N[i].f[0] = N[i].f[1] = N[i].f[2] = 0;
  for (unsigned i(1); i <= n; ++i) {
    Ans = max(Ans, List[i]->f[0]);
    Ans = max(Ans, List[i]->f[1]);
    Ans = max(Ans, List[i]->f[2]);
    Edge* Sid(List[i]->Fst);
    while (Sid) {
      if(Sid->Col == 'R') Sid->To->f[0] = max(Sid->To->f[0], List[i]->f[0] + 1);
      if(Sid->Col == 'G') Sid->To->f[1] = max(Sid->To->f[1], List[i]->f[1] + 1);
      if(Sid->Col == 'B') Sid->To->f[2] = max(Sid->To->f[2], List[i]->f[2] + 1);
      Sid = Sid->Nxt;
    }
  }
}
signed main() {
  freopen("C.in", "r", stdin);
//  freopen("C.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    ++N[B].Deg, E[i].Nxt = N[A].Fst, N[A].Fst = E + i, E[i].To = N + B;
  }
  for (unsigned i(1); i <= n; ++i) if(!(N[i].Deg)) Q[++Tl] = N + i;
  while (Tl ^ Hd) {
    Node* Cur(Q[++Hd]);
    Edge* Sid(Cur->Fst);
    List[++Cnt] = Cur;
    while (Sid) {
      if(!(--(Sid->To->Deg))) Q[++Tl] = Sid->To;
      Sid = Sid->Nxt;
    }
  }
  while (Ans > P) {
    Random(), Judge();
//    printf("Ans %u\n", Ans);
  }
  for (unsigned i(1); i <= m; ++i) putchar(E[i].Col), putchar('\n');
//  }
//  system(\"pause\");
  return Wild_Donkey;
}
