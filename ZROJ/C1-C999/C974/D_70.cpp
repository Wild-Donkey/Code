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
struct Edge;
struct Node {
  Edge* Fst;
  unsigned Deg, OldDeg;
  char Vis;
}N[1000005], * Q[1000005];
struct Edge {
  Node* To;
  Edge* Nxt;
}E[2000005];
long long Tmp(0), Ans(0xafafafafafafafaf), V1, V2, V3, Ans1, Ans2, Ans3;
unsigned Ansk, m, n, Cnt(0), A, B, C, D, t, Still(0);
unsigned Hd, Tl, List[1000005], LisTmp[1000005], LiSize(n), LiSizTmp(0);
void DFS(Node* x) {
  // printf("DFS %u\n", x - N);
  Edge* Sid(x->Fst);
  x->Vis = 1, LisTmp[++LiSizTmp] = x - N, ++Ans1, Ans2 += x->Deg, Ans3 += x->OldDeg - x->Deg;
  while (Sid) {
    // printf("Sid %u To %u\n", Sid - E, Sid->To - N);
    if (!(Sid->To->Vis))/* printf("%u????\n", Sid->To - N), */DFS(Sid->To);
    Sid = Sid->Nxt;
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  Still = n = RD(), m = RD() << 1;
  V2 = RDsg(), V1 = -(RDsg()), V3 = RDsg();
  for (unsigned i(0); i < m; i += 2) {
    A = RD(), B = RD();
    E[i].To = N + B;
    E[i].Nxt = N[A].Fst;
    N[A].Fst = E + i;
    E[i ^ 1].To = N + A;
    E[i ^ 1].Nxt = N[B].Fst;
    N[B].Fst = E + (i ^ 1);
    // printf("Link %u %u %u %u %u %u\n", i, i ^ 1, E[i].Nxt - E, E[i ^ 1].Nxt - E, N[A].Fst - E, N[B].Fst - E);
    ++(N[A].Deg), ++(N[B].Deg), ++(N[A].OldDeg), ++(N[B].OldDeg);
  }
  for (unsigned i(1); i <= n; ++i) List[i] = i;
  Ans1 = Ans2 = Ans3 = 0, DFS(N + 1), Ans2 >>= 1, Ans = Tmp = (Ans1 * V1) + (Ans2 * V2) + (Ans3 * V3), Ansk = 1;
  memset(LisTmp, 0, sizeof(LisTmp)), LiSizTmp = 0, LiSize = n;
  for (unsigned i(2); Still; ++i) {
    Hd = Tl = 0;
    // printf("Degree %u %u\n", i, Still);
    // for (unsigned j(1); j <= LiSize; ++j) printf("%u ", List[j]);
    // putchar('\n');
    for (unsigned j(1); j <= LiSize; ++j)
      if (N[List[j]].Deg == i - 1) Q[++Tl] = N + List[j], N[List[j]].Vis = 1;
      else if (N[List[j]].Deg >= i) N[List[j]].Vis = 0;
    if (!Tl) { if (Ans == Tmp) ++Ansk; continue; }
    while (Hd ^ Tl) {
      Node* Now(Q[++Hd]);
      --Still;
      Edge* Sid(Now->Fst);
      // printf("BFS %u Still %u\n", Now - N, Still);
      while (Sid) {
        // printf("%u\n", Sid - E);
        if (!(Sid->To->Vis)) {
          --(Sid->To->Deg);
          if (Sid->To->Deg < i) Sid->To->Vis = 1, Q[++Tl] = Sid->To;
        }
        Sid = Sid->Nxt;
      }
    }
    for (unsigned j(1); j <= LiSize; ++j) {
      if (!(N[List[j]].Vis)) {
        Ans1 = Ans2 = Ans3 = 0;
        DFS(N + List[j]);
        Ans2 >>= 1, Tmp = (Ans1 * V1) + (Ans2 * V2) + (Ans3 * V3);
        // printf("A1 %lld A2 %lld A3 %lld Tmp %lld Ans %lld\n", Ans1, Ans2, Ans3, Tmp, Ans);
        if (Tmp >= Ans) Ans = Tmp, Ansk = i;
      }
    }
    memcpy(List, LisTmp, (LiSize + 1) << 2), memset(LisTmp, 0, (LiSizTmp + 1) << 2), LiSize = LiSizTmp, LiSizTmp = 0;
  }
  printf("%u %lld\n", Ansk, Ans);
  // system("pause");
  return Wild_Donkey;
}
/*
27 39
8 9 5
1 2
2 9
3 4
10 5
3 6
4 6
4 7
7 8
6 8
4 8
3 8
3 7
3 9
3 10
9 10
10 4
7 11
7 12
11 12
12 13
13 14
8 15
15 16
15 17
15 18
16 18
16 19
19 20
19 21
19 22
20 21
20 22
21 22
21 23
21 24
23 24
24 27
25 27
26 27

2 103
*/