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
unsigned m, n, Cnt;
unsigned A, B, C, DL, DR, t;
struct Seg {
  unsigned CL, CR, Val, Tag;
  Seg *LS, *RS;
  inline void PsDw(unsigned L, unsigned R) {
    if (Tag) {
      LS->Val = L, LS->Tag = LS->CL = LS->CR = Tag;
      RS->Val = R, RS->Tag = RS->CL = RS->CR = Tag;
      Tag = 0;
    }
  }
  inline void Chg(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) {
      // printf("Chg [%u,%u] %u\n", L, R, C);
      Val = R - L, Tag = CL = CR = C;
      return;
    }
    unsigned Mid((L + R) >> 1);
    PsDw(Mid - L, R - Mid - 1);
    if (A <= Mid) LS->Chg(L, Mid);
    if (B > Mid) RS->Chg(Mid + 1, R);
    Val = LS->Val + RS->Val + ((LS->CR == RS->CL) && (LS->CR));
    CL = LS->CL, CR = RS->CR;
  }
  inline void Qry(unsigned L, unsigned R) {
    if ((A <= L) && (R <= B)) {
      // printf("Qry [%u,%u] %u\n", L, R, Val);
      C += Val;
      if (L == A) DL = CL;
      if (R == B) DR = CR;
      return;
    }
    unsigned Mid((L + R) >> 1);
    PsDw(Mid - L, R - Mid - 1);
    if ((A <= Mid) && (B > Mid)) C += ((LS->CR == RS->CL) && (LS->CR));
    if (A <= Mid) LS->Qry(L, Mid);
    if (B > Mid) RS->Qry(Mid + 1, R);
  }
  inline void Build(unsigned L, unsigned R);
} S[200005], *CntS(S);
inline void Seg::Build(unsigned L, unsigned R) {
  Tag = Val = CL = CR = 0;
  if (L == R) return;
  unsigned Mid((L + R) >> 1);
  (LS = ++CntS)->Build(L, Mid);
  (RS = ++CntS)->Build(Mid + 1, R);
}
struct Node {
  vector<Node *> E;
  Node *Heavy, *Top, *Fa;
  unsigned DFSr, Size, Dep;
  inline void DFS1();
  inline void DFS2();
} N[100005];
inline void Node::DFS1() {
  unsigned SzH(0);
  Size = 1, Heavy = NULL;
  for (auto i : E)
    if (i != Fa) {
      i->Fa = this, i->Dep = Dep + 1, i->DFS1(), Size += i->Size;
      if (SzH < i->Size) SzH = i->Size, Heavy = i;
    }
}
inline void Node::DFS2() {
  DFSr = ++Cnt;
  if (Heavy) Heavy->Top = Top, Heavy->DFS2();
  for (auto i : E)
    if ((i != Fa) && (i != Heavy)) {
      i->Top = i, i->DFS2();
    }
}
inline void Chg(Node *x, Node *y) {
  C = ++Cnt;
  while (x->Top != y->Top) {
    if (x->Top->Dep < y->Top->Dep) swap(x, y);
    A = x->Top->DFSr, B = x->DFSr, S->Chg(1, n), x = x->Top->Fa;
  }
  if (x->Dep < y->Dep) swap(x, y);
  A = y->DFSr, B = x->DFSr, S->Chg(1, n);
}
inline void Qry(Node *x, Node *y) {
  C = 0;
  unsigned xB(0), yB(0);
  while (x->Top != y->Top) {
    if (x->Top->Dep < y->Top->Dep) swap(x, y), swap(xB, yB);
    A = x->Top->DFSr, B = x->DFSr, S->Qry(1, n);
    // printf("Qry [%u, %u] %u (%u, %u)\n", A, B, C, DL, DR);
    C += ((xB == DR) && DR), xB = DL, x = x->Top->Fa;
  }
  if (x->Dep < y->Dep) swap(x, y), swap(xB, yB);
  A = y->DFSr, B = x->DFSr, S->Qry(1, n);
  // printf("Qry [%u, %u] %u (%u, %u)\n", A, B, C, DL, DR);
  C += ((xB == DR) && DR) + ((yB == DL) && DL);
}
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].E.clear();
  n = RD(), m = RD(), CntS = S;
}
signed main() {
  // freopen("P7735_1.in", "r", stdin);
  // freopen("P7735.out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr(), S->Build(1, n);
    for (unsigned i(1); i < n; ++i) {
      A = RD(), B = RD();
      N[A].E.push_back(N + B);
      N[B].E.push_back(N + A);
    }
    Cnt = 0, N[1].Dep = 1, N[1].DFS1(), N[1].Top = N + 1, N[1].DFS2(), Cnt = 0;
    // for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].DFSr);
    // putchar(0x0A);
    for (unsigned i(1); i <= m; ++i) {
      C = RD(), A = RD(), B = RD();
      if (C == 1)
        Chg(N + A, N + B);
      else
        Qry(N + A, N + B), printf("%u\n", C);
    }
  }
  //  system("pause");
  return Wild_Donkey;
}
/*
g++ P7735_Light_and_Heavy.cpp -o faq -std=c++14 -O2 -Wl,--stack=1024000000
*/