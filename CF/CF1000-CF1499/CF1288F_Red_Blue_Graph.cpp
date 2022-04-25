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
#define INF 0x3f3f3f
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
unsigned a[10005], m1, n1, n2, r, b;
unsigned A, B, C, D, t, Tl(0), Hd(0);
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned Pr[205][2][2];
char IO[205];
struct Node;
struct Edge {
  Node* To;
  unsigned Inv, Cap;
  int Val;
};
struct Node {
  vector<Edge> E;
  Node* Pre;
  unsigned Come;
  int Dis;
}N[405], * Q[100005], *N1(N + 1), * N2;
inline void Link(Node* x, Node* y, const unsigned Ca, const int Va) {
  x->E.push_back((Edge){y, 0, Ca, Va});
  y->E.push_back((Edge){x, 0, 0, -Va});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
}
inline char SPFA() {
  for (Node* i(N2 + n2); i > N; --i) i->Dis = INF;
  Hd = Tl = 0;
  (Q[++Tl] = N)->Dis = 0;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (unsigned i(Cur->E.size() - 1); ~i; --i)
      if((Cur->E[i].Cap) && (Cur->E[i].To->Dis > Cur->Dis + Cur->E[i].Val)) {
        Cur->E[i].To->Pre = Cur, Cur->E[i].To->Come = i;
        Cur->E[i].To->Dis = Cur->Dis + Cur->E[i].Val, Q[++Tl] = Cur->E[i].To;
      }
  }
  return N[1].Dis < 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  N2 = N1 + (n1 = RD()), n2 = RD(), m1 = RD(), r = RD(), b = RD();
  scanf("%s", IO + 1);
  for (unsigned i(1); i <= n1; ++i) {
    if(IO[i] == 'R') Link(N, N1 + i, 1, -INF), Link(N, N1 + i, 400, 0), ++Cnt;
    if(IO[i] == 'B') Link(N1 + i, N + 1, 1, -INF), Link(N1 + i, N + 1, 400, 0), ++Cnt;
    if(IO[i] == 'U') Link(N, N1 + i, 400, 0), Link(N1 + i, N + 1, 400, 0);
  }
  scanf("%s", IO + 1);
  for (unsigned i(1); i <= n2; ++i) {
    if(IO[i] == 'R') Link(N2 + i, N + 1, 1, -INF), Link(N2 + i, N + 1, 400, 0), ++Cnt;
    if(IO[i] == 'B') Link(N, N2 + i, 1, -INF), Link(N, N2 + i, 400, 0), ++Cnt;
    if(IO[i] == 'U') Link(N, N2 + i, 400, 0), Link(N2 + i, N + 1, 400, 0);
  }
  for (unsigned i(1); i <= m1; ++i) {
    A = RD(), B = RD();
    Link(N1 + A, N2 + B, 1, r), Pr[i][0][0] = A, Pr[i][0][1] = N1[A].E.size() - 1;
    Link(N2 + B, N1 + A, 1, b), Pr[i][1][0] = B, Pr[i][1][1] = N2[B].E.size() - 1;
  }
  while (SPFA()) {
//    printf("Min %d\n", N[1].Dis);
    Node* Cur(N + 1);
    unsigned Flow(INF);
    while (Cur > N) Flow = min(Flow, Cur->Pre->E[Cur->Come].Cap), Cur = Cur->Pre;
    Ans += Flow * (Cur = N + 1)->Dis;
    while (Cur > N) Cur->Pre->E[Cur->Come].Cap -= Flow, Cur->E[Cur->Pre->E[Cur->Come].Inv].Cap += Flow, Cur = Cur->Pre;
  }
  Ans += Cnt * INF;
  if(Ans >= INF) {printf("-1\n");return 0;}
  printf("%d\n", Ans);
  for (unsigned i(1); i <= m1; ++i) {
    if(!(N1[Pr[i][0][0]].E[Pr[i][0][1]].Cap)) putchar('R');
    else if(!(N2[Pr[i][1][0]].E[Pr[i][1][1]].Cap)) putchar('B');
    else putchar('U');
  }
//  }
  return Wild_Donkey;
}

