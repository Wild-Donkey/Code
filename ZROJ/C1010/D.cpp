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
#define INF 0x3f3f3f3f3f3f3f3f
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
unsigned long long Cnt(0), Tmp(0);
unsigned m, n, M(0);
unsigned A, B, C, D, t;
unsigned BFa[1000005], Stack[1000005], STop(0);
bitset<2000005> IsFa;
priority_queue<pair<unsigned long long, unsigned> > Q;
struct Node;
struct Edge {
  Node* To;
  unsigned long long Val;
}E[4000005];
struct Node {
  vector<Edge*> Ed;
  Edge* TF;
  Node* Fa;
  unsigned long long Dep, f, g;
  char Poped;
}N[1000005], * S;
struct NEdge {
  unsigned long long Val;
  unsigned L, R;
  inline const char operator <(const NEdge& x) const{return Val < x.Val;}
}NE[2000005];
inline unsigned Find(unsigned x) {
  while (x ^ BFa[x]) Stack[++STop] = x, x = BFa[x];
  while (STop) BFa[Stack[STop--]] = x;
  return x;
}
inline void Dij () {
  for (unsigned i(1); i <= n; ++i) N[i].Dep = INF, N[i].Poped = 0;
  Q.push(make_pair(INF, S - N)), S->Dep = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Poped) continue;
    Cur->Poped = 1;
    for (auto i:(Cur->Ed)) {
      if(i->To->Dep > Cur->Dep + i->Val) {
        if(i->To->TF) IsFa[(i->To->TF - E) >> 1] = 0;
        i->To->Fa = Cur, IsFa[((i->To->TF = i) - E) >> 1] = 1;
        i->To->Dep = Cur->Dep + i->Val;
        Q.push(make_pair(INF - i->To->Dep, i->To - N));
      }
    }
  }
}
inline void DP () {
  for (unsigned i(1); i <= n; ++i) N[i].f = INF, N[i].Poped = 0;
  Q.push(make_pair(INF, S - N)), S->f = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Poped) continue;
    Cur->Poped = 1;
    for (auto i:(Cur->Ed)) {
      unsigned long long New(max(Cur->f + i->Val, i->To->g));
      if(i->To->f > New) i->To->f = New, Q.push(make_pair(INF - New, i->To - N));
    }
  }
}
signed main() {
//  freopen("ex_D3.in", "r", stdin);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), S = N + RD();
  for (unsigned i(0); i < m; ++i) {
    A = RD(), B = RD(), C = RD();
    E[i << 1].Val = E[(i << 1) ^ 1].Val = C;
    E[i << 1].To = N + B, E[(i << 1) ^ 1].To = N + A;
    N[A].Ed.push_back(E + (i << 1));
    N[B].Ed.push_back(E + ((i << 1) ^ 1));
  }
  Dij();
//  if(m == 15) for (auto i:N[3].Ed) printf("To %u\n", i->To - N);
  for (unsigned i(0); i < m; ++i) if(!IsFa[i]){
    NE[++M].L = E[i << 1].To - N, NE[M].R = E[(i << 1) ^ 1].To - N;
    NE[M].Val = E[i << 1].Val + N[NE[M].L].Dep + N[NE[M].R].Dep;
//    printf("Cao %u %u\n", NE[M].L, NE[M].R);
//    if(NE[M].L == 4) printf("%u %u, Val %llu\n", NE[M].L, NE[M].R, NE[M].Val); 
    if(NE[M].Val > INF) --M;
  }
  for (unsigned i(1); i <= n; ++i) BFa[i] = i, N[i].g = INF;
  sort(NE + 1, NE + M + 1), S->g = 0;
  for (unsigned i(1); i <= M; ++i) {
    A = NE[i].L, A = Find(A);
    B = NE[i].R, B = Find(B);
    while (A ^ B) {
      if(N[A].Dep < N[B].Dep) swap(A, B);
//      if((A <= 10)) printf("Jump %u %u\n", A, B);
      N[A].g = NE[i].Val;
      BFa[A] = Find(N[A].Fa - N);
      A = Find(A), B = Find(B);
    }
  }
  for (unsigned i(1); i <= n; ++i) if(N[i].g < INF) N[i].g -= N[i].Dep;
  DP();
//  freopen("D.out", "w", stdout);
//  if(m == 15) {
////    for (unsigned i(13); i < m; ++i) {
////      printf("%u %u %u\n", E[i << 1].To - N, E[(i << 1) ^ 1].To - N, E[i << 1].Val);
////    }
//    for (unsigned i(1); i <= n; ++i) printf("%lld ", N[i].Dep);
//    putchar(0x0A);
//    for (unsigned i(1); i <= M; ++i) {
//      printf("[%u %u] %u\n", NE[i].L, NE[i].R, NE[i].Val);
//    }
////    for (unsigned i(1); i <= n; ++i) printf("%lld ", N[i].Fa - N);
////    putchar(0x0A);
//    for (unsigned i(1); i <= n; ++i) printf("%lld ", N[i].g);
//    putchar(0x0A);
//  }
  for (unsigned i(1); i <= n; ++i) printf("%lld ", (N[i].f < INF) ? N[i].f : -1);
//  }
  return Wild_Donkey;
}
/*
10 15 4
4 5 137067747
7 4 677815757
9 5 239749750
3 9 528592341
8 7 204252768
7 6 335529294
3 10 985328870
8 1 356883715
10 8 500322124
7 10 778003498
2 10 461861084
6 2 987878921
1 5 857049291
5 10 434681618
5 9 660682860


8 10 1954140014
7 10 2027568620
1 8 2233069278
10 3 2462488073
6 2 3034...
5 8 1
1 2 3
2 3 7
3 1 9
4 1 8
2 3 2
1 5 6
3 5 7
4 2 5
*/
