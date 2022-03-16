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
unsigned b[80005], m, n, Q, Top(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Op[3];
struct Seg {
  Seg *LS, *RS;
  unsigned Val;
  inline void Find(Seg* x, Seg* y, Seg* z, unsigned L, unsigned R) {
//    printf("Now [%u, %u] C %u\n", L, R, C);
    if(L == R) {D = L;return;}
    unsigned Tot(LS->Val + x->LS->Val - y->LS->Val - z->LS->Val), Mid((L + R) >> 1);
//    printf("Tot %u = %u + %u - %u\n", Tot, LS->Val, x->LS->Val, y->LS->Val);
    if(C <= Tot) LS->Find(x->LS, y->LS, z->LS, L, Mid);
    else C -= Tot, RS->Find(x->RS, y->RS, z->RS, Mid + 1, R);
  }
}S[10000005], *CntS(S);
inline void Pls(Seg* x, Seg* y, unsigned L, unsigned R) {
  y->Val = x->Val + 1;
//  if(Flg) printf("Pls %u [%u, %u] %u\n", C, L, R, y->Val);
  if(L == R) return;
  unsigned Mid((L + R) >> 1);
  if(C <= Mid) Pls(x->LS, y->LS = ++CntS, L, Mid), y->RS = x->RS;
  else Pls(x->RS, y->RS = ++CntS, Mid + 1, R), y->LS = x->LS;
}
struct Node {
  vector <Node*> E;
  Node* Fa[18];
  Seg* Root;
  unsigned Dep, Val, Size;
  inline void Construct() {
//    printf("Constructed %d\n", this - Fa[0]);
    Node* Fa0(Fa[0]);
    Dep = Fa0->Dep + 1, Size = 1, C = Val, Pls(Fa0->Root, Root, 1, Top);
//    if(Dep != Root->Val) printf("Attention Dep %u Size %u\n", Dep, Root->Val);
    memset(Fa, 0, sizeof(Fa)), Fa[0] = Fa0;
    for (unsigned i(0); Fa[i]; ++i) Fa[i + 1] = Fa[i]->Fa[i];
//    for (auto i:E) printf("To %d Fa %d\n", i - this, i->Fa[0] - this);
    for (auto i:E) if(i != Fa[0]) i->Fa[0] = this, i->Construct(), Size += i->Size;
  }
}N[80005];
//  inline void Clr() {}
signed main() {
//  freopen("P3302_2.in", "r", stdin);
//  freopen("P3302.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  RD(), n = RD(), m = RD(), Q = RD(), N->Root = S;
  for (unsigned i(1); i <= n; ++i) b[i] = N[i].Val = RD(), N[i].Root = ++CntS;
  sort(b + 1, b + n + 1), Top = unique(b + 1, b + n + 1) - b;
  for (unsigned i(1); i <= n; ++i) N[i].Val = lower_bound(b + 1, b + Top, N[i].Val) - b;
  --Top, S->LS = S->RS = S, N->Fa[0] = N;
  for (unsigned i(1); i <= m; ++i) A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
  for (unsigned i(1); i <= n; ++i) if(!N[i].Fa[0]) N[i].Fa[0] = N, N[i].Construct();
  for (unsigned i(1); i <= Q; ++i) {
    scanf("%s", Op), A = (RD() ^ Ans), B = (RD() ^ Ans);
    if(Op[0] == 'Q') {
      C = (RD() ^ Ans);
//      printf("Qry %u to %u Dep %u,%u %uth\n", A, B, N[A].Dep, N[B].Dep, C);
      Node *CurA(N + A), *CurB(N + B);
      if(CurA->Dep < CurB->Dep) swap(CurA, CurB), swap(A, B);
      for (unsigned j(16); ~j; --j) {
//        printf("Now %u 2^%u: %u\n", CurA - N, j, CurA->Fa[j] - N);
        if(CurA->Fa[j] && (CurA->Fa[j]->Dep >= CurB->Dep)) CurA = CurA->Fa[j];
      }
//      putchar(0x0A);
//      printf("Jumped Same %u %u Dep %u %u\n", CurA - N, CurB - N, CurA->Dep, CurB->Dep);
      if(CurA == CurB) S->Find(N[A].Root, N[B].Fa[0]->Root, S, 1, Top);
      else {
        for (unsigned j(16); ~j; --j) if(CurA->Fa[j] != CurB->Fa[j]) CurA = CurA->Fa[j], CurB = CurB->Fa[j];
//        printf("LCA %u Dep %u\n", CurA->Fa[0] - N, CurA->Fa[0]->Dep);
//        printf("NA%u %u\n", N[A].Dep, N[A].Root->Val);
        N[A].Root->Find(N[B].Root, CurA->Fa[0]->Root, CurA->Fa[1]->Root, 1, Top);
      }
//      printf("Claclated %u\n", D);
      printf("%u\n", Ans = b[D]);
    } else {
//      printf("Link %u with %u\n", A, B, C);
      Node *RtA(N + A), *RtB(N + B);
      for (unsigned j(16); ~j; --j) if((RtA->Fa[j]) && (RtA->Fa[j] != N)) RtA = RtA->Fa[j];
      for (unsigned j(16); ~j; --j) if((RtB->Fa[j]) && (RtB->Fa[j] != N)) RtB = RtB->Fa[j];
      if(RtA->Size < RtB->Size) swap(A, B), swap(RtA, RtB);
//      printf("%u To %u\n", B, A);
      N[B].Fa[0] = N + A, N[B].Construct(), RtA->Size += N[B].Size;
      N[B].E.push_back(N + A), N[A].E.push_back(N + B);
    }
//    for (unsigned j(1); j <= n; ++j) printf("%u ", N[j].Dep);putchar(0x0A);
//    fprintf(stderr, "%u %u\n", i, CntS - S);
  }
//  }
  return Wild_Donkey;
}


