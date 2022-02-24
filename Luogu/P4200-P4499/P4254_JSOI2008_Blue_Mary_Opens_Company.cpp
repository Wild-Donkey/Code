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
#include <set>
#include <string>
#include <unordered_map>
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
const double Ep(0.0000001);
double Ans(0);
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
char IO[10];
struct Seg {
  double Y0, K;
  inline void Inp() { scanf("%lf%lf", &Y0, &K), Y0 -= K; }
  inline double Get(unsigned x) { /*printf("Get %u Got %lf\n", x, Y0 + K * x);*/return Y0 + K * x; }
}S[100005];
struct Node {
  Seg* Mx;
  Node* LS, * RS;
  inline void Insert(unsigned L, unsigned R, Seg* x) {
    if (!Mx) { Mx = x; return; }
    if (L == R) { if (x->Get(L) > Mx->Get(L)) Mx = x; return; }
    unsigned Mid((L + R) >> 1);
    if (x->Get(Mid) > Mx->Get(Mid)) {
      if ((x->Get(L) + Ep < Mx->Get(L)) || (x->Get(R) + Ep < Mx->Get(R))) {
        if (x->K > Mx->K) LS->Insert(L, Mid, Mx);
        else RS->Insert(Mid + 1, R, Mx);
      }
      Mx = x;
    }
    else {
      if ((Mx->Get(L) + Ep < x->Get(L)) || (Mx->Get(R) + Ep < x->Get(R))) {
        if (x->K > Mx->K) RS->Insert(Mid + 1, R, x);
        else LS->Insert(L, Mid, x);
      }
    }
  }
  inline void Find(unsigned L, unsigned R) {
    // printf("Find %u in [%u, %u] About %u\n", A, L, R, Mx - S);
    if (Mx) Ans = max(Ans, Mx->Get(A));
    if (L == R) return;
    unsigned Mid((L + R) >> 1);
    if (A <= Mid) LS->Find(L, Mid);
    else RS->Find(Mid + 1, R);
  }
}N[100005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  printf("%d %d\n", (int)-2.1, (int)-2.9);
  Build(N, 1, 50000);
  n = RD();
  for (unsigned i(1); i <= n; ++i) {
    scanf("%s", IO);
    if (*IO == 'P') S[++Cnt].Inp(), N->Insert(1, 50000, S + Cnt);
    else A = RD(), Ans = 0, N->Find(1, 50000), printf("%d\n", (int)(Ans / 100));// printf("%lf\n", Ans);
  }
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
10
Project 5.10200 0.65000
Project 2.76200 1.43000
Query 4
Query 2
Project 3.80200 1.17000
Query 2
Query 3
Query 1
Project 4.58200 0.91000
Project 5.36200 0.39000
*/