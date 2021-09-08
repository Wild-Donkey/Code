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
  unsigned Deg, OldDeg, Pos;
  char Vis;
}N[1000005], * Q[1000005];
struct Edge {
  Node* To;
  Edge* Nxt;
}E[2000005];
long long Tmp(0), Ans(0xafafafafafafafaf), V1, V2, V3, Ans1, Ans2, Ans3;
unsigned Ansk, m, n, Cnt(0), A, B, C, D, t, Still(0);
unsigned Bucket[1000005], BucketSize(0), List[1000005];
unsigned PntCnt[1000005], SidCnt[1000005], DegCnt[1000005], Stack[1000005], Top;
unsigned Find(unsigned x) {
  while (x ^ Bucket[x]) Stack[++Top] = x, x = Bucket[x];
  while (Top) Bucket[Stack[Top--]] = x;
  return x;
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
  for (unsigned i(1); i <= n; ++i) ++Bucket[N[i].Deg], BucketSize = max(BucketSize, N[i].Deg);
  for (unsigned i(1); i <= BucketSize; ++i) Bucket[i] += Bucket[i - 1];
  for (unsigned i(1); i <= n; ++i) N[i].Pos = Bucket[N[i].Deg]--, List[N[i].Pos] = i;
  for (unsigned i(1); i <= n; ++i) {
    Node* Now(N + List[i]);
    Edge* Sid(Now->Fst);
    while (Sid) {
      if (Sid->To->Deg > Now->Deg) {
        Tmp = Sid->To->Pos;
        Sid->To->Pos = ++Bucket[Sid->To->Deg];
        N[List[Bucket[Sid->To->Deg]]].Pos = Tmp;
        List[Tmp] = List[Bucket[Sid->To->Deg]];
        List[Bucket[(Sid->To->Deg)--]] = Sid->To - N;
      }
      Sid = Sid->Nxt;
    }
  }
  // for (unsigned i(1); i <= n; ++i) printf("%u %u %u\n", List[i], N[List[i]].Deg, N[List[i]].Pos);
  for (unsigned i(n); i; --i) Bucket[i] = i, PntCnt[i] = 1, DegCnt[i] = N[List[i]].OldDeg;
  for (unsigned i(n); i; --i) {
    Node* Now(N + List[i]);
    Edge* Sid(Now->Fst);
    unsigned NowRoot(Find(Now->Pos));
    while (Sid) {
      if (Sid->To->Pos >= Now->Pos) {
        A = Find(Sid->To->Pos);
        if (A ^ NowRoot) {
          if (PntCnt[A] < PntCnt[NowRoot]) {
            Bucket[A] = NowRoot;
            PntCnt[NowRoot] += PntCnt[A];
            DegCnt[NowRoot] += DegCnt[A];
            SidCnt[NowRoot] += SidCnt[A];
          }
          else {
            Bucket[NowRoot] = A;
            PntCnt[A] += PntCnt[NowRoot];
            DegCnt[A] += DegCnt[NowRoot];
            SidCnt[A] += SidCnt[NowRoot];
            NowRoot = A;
          }
        }
        ++SidCnt[NowRoot];
      }
      Sid = Sid->Nxt;
    }
    if (N[List[i - 1]].Deg ^ Now->Deg) {
      for (unsigned j(i); N[List[j]].Deg == Now->Deg; ++j) {
        unsigned Calc(Find(j));
        Tmp = V1 * PntCnt[Calc] + V2 * SidCnt[Calc] + V3 * (DegCnt[Calc] - (SidCnt[Calc] << 1));
        // printf("%u %u %u %u %lld\n", Calc, PntCnt[Calc], SidCnt[Calc], DegCnt[Calc] - (SidCnt[Calc] << 1), Tmp);
        if (Tmp >= Ans) Ans = Tmp, Ansk = Now->Deg;
      }
    }
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
3 6
3 7
3 8
3 9
3 10
4 6
4 7
4 8
4 10
5 10
6 8
7 8
7 11
7 12
8 15
9 10
11 12
12 13
13 14
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