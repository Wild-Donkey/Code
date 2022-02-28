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
unsigned a[200005], Stack[200005], STop(0), m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Fa, Val, Tag;
  inline void PsUp() {
    if (LS) Val = max(Val, LS->Val);
    if (RS) Val = max(Val, RS->Val);
  }
}N[10000005], * Ver[200005], * CntN(N);
inline Node* New() {
  Node* Cur(++CntN);
  Cur->Val = Cur->Tag = 0, Cur->LS = Cur->RS = NULL, Cur->Fa = 1;
  return Cur;
}
inline Node* Copy(Node* x) {
  // printf("Copy %u\n", x - N);
  Node* Cur(++CntN);
  (*Cur) = (*x), Cur->Fa = 1, --(x->Fa);
  if (Cur->LS) ++(Cur->LS->Fa);
  if (Cur->RS) ++(Cur->RS->Fa);
  return Cur;
}
inline void Chg(Node* x, Node* y, unsigned L, unsigned R) {
  // printf("Chg %u %u [%u, %u] if in [%u, %u]\n", x - N, y - N, L, R, A, B);
  if ((A <= L) && (R <= B)) { ++(y->Val), ++(y->Tag); return; }
  unsigned Mid((L + R) >> 1);
  if (A <= Mid) {
    if (!(x->LS)) x->LS = New();
    if (!(y->LS)) y->LS = New();
    else if (y->LS->Fa > 1) y->LS = Copy(y->LS);
    Chg(x->LS, y->LS, L, Mid);
  }
  if (Mid < B) {
    if (!(x->RS)) x->RS = New();
    if (!(y->RS)) y->RS = New();
    else if (y->RS->Fa > 1) y->RS = Copy(y->RS);
    Chg(x->RS, y->RS, Mid + 1, R);
  }
  y->PsUp();
}
inline void Qry(Node* x, unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) { Ans = max(Ans, x->Val + Tmp); return; }
  unsigned Mid((L + R) >> 1);  Tmp += x->Tag;
  if (A <= Mid) { if (x->LS) Qry(x->LS, L, Mid); else Ans = max(Ans, Tmp); }
  if (Mid < B) { if (x->RS)  Qry(x->RS, Mid + 1, R); else Ans = max(Ans, Tmp); }
  Tmp -= x->Tag;
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), t = RD(), Ver[0] = N;
  for (unsigned i(1); i <= n; ++i) {
    a[i] = RD();
    while (STop && (a[i] > a[Stack[STop]])) --STop;
    A = Stack[STop] + 1, B = Stack[++STop] = i;
    ++(Ver[i - 1]->Fa), Chg(Ver[i - 1], Ver[i] = Copy(Ver[i - 1]), 1, n);
  }
  for (unsigned i(1); i <= m; ++i) {
    Ans *= t, A = (RD() + Ans + n - 1) % n + 1, B = (RD() + Ans + n - 1) % n + 1;
    if (A > B) swap(A, B);
    Ans = Tmp = 0, Qry(Ver[B], 1, n);
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}