#pragma GCC optimize(2)
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize(3)
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
}N[18000005], * Ver[200005], * CntN(N);
inline Node* New(unsigned x) {
  Node* Cur(++CntN);
  Cur->Val = Cur->Tag = x, Cur->LS = Cur->RS = NULL, Cur->Fa = 1;
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
inline void PsDw(Node* x) {
  if (!(x->LS)) x->LS = New(x->Tag);
  else {
    if (x->LS->Fa > 1) x->LS = Copy(x->LS);
    x->LS->Tag += x->Tag, x->LS->Val += x->Tag;
  }
  if (!(x->RS)) x->RS = New(x->Tag);
  if (x->RS) {
    if (x->RS->Fa > 1) x->RS = Copy(x->RS);
    x->RS->Tag += x->Tag, x->RS->Val += x->Tag;
  }
  x->Tag = 0;
}
inline void Chg(Node* x, Node* y, unsigned L, unsigned R) {
  // printf("Chg %u %u [%u, %u] if in [%u, %u]\n", x - N, y - N, L, R, A, B);
  if ((A <= L) && (R <= B)) { ++(y->Val), ++(y->Tag); return; }
  unsigned Mid((L + R) >> 1);
  PsDw(x), PsDw(y);
  if (A <= Mid)  Chg(x->LS, y->LS, L, Mid);
  if (Mid < B) Chg(x->RS, y->RS, Mid + 1, R);
  y->PsUp();
}
inline void Qry(Node* x, unsigned L, unsigned R) {
  if ((A <= L) && (R <= B)) { Ans = max(Ans, x->Val); return; }
  unsigned Mid((L + R) >> 1);
  PsDw(x);
  if (A <= Mid) { Qry(x->LS, L, Mid); }
  if (Mid < B) { Qry(x->RS, Mid + 1, R); }
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
    Ans = 0, Qry(Ver[B], 1, n);
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}