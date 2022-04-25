#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned m, n, Cnt(0), A, B, t, Ans(0), Tmp(0);
char a[200005], Tmpc, Chgc;
struct Node {
  Node *LS, *RS;
  int CntD, Val, ValC, ValD, BdC, BdD, BdL, BdR;
}N[400005], *CntN(N);
inline void Print(Node *x) {
  printf("Point %u [%u, %u]\n", x - N, x->LS - N, x->RS - N);
  printf("Cnt) %u Val %u Val( %u Val) %u\n", x->CntD, x->Val, x->ValC, x->ValD);
  printf("( %u ) %u <- %u -> %u\n", x->BdC, x->BdD, x->BdL, x->BdR);
}
inline void Udt (Node *x, int Len) {
  x->CntD = x->LS->CntD + x->RS->CntD;
  x->ValC = x->RS->ValC + max(x->LS->ValC - x->RS->ValD, 0);
  x->ValD = x->LS->ValD + max(x->RS->ValD - x->LS->ValC, 0);
  x->BdC = max(x->LS->BdC, x->RS->BdC + ((Len + 1) >> 1) - ((x->LS->CntD) << 1));
  x->BdD = max(x->RS->BdD, x->LS->BdD + ((x->RS->CntD) << 1) - (Len >> 1));
  x->BdL = max(x->LS->BdL, max(x->LS->ValD + x->LS->ValC + x->RS->BdC, x->RS->BdL + x->LS->ValD - x->LS->ValC));
  x->BdR = max(x->RS->BdR, max(x->RS->ValD + x->RS->ValC + x->LS->BdD, x->LS->BdR + x->RS->ValC - x->RS->ValD));
  x->Val = max(x->LS->Val, x->RS->Val);
  register int TmpV = max(x->LS->BdR + x->RS->BdC, x->RS->BdL + x->LS->BdD);
  x->Val = max(x->Val, TmpV);
  return; 
}
void Build (Node *x, unsigned L, unsigned R) {
//  printf("Build [%u, %u]\n", L, R);
  if(L == R) {
    x->BdL = x->BdR = x->Val = 1;
    x->BdD = x->ValD = x->CntD = a[L];
    x->BdC = x->ValC = a[L] ^ 0x1;
//    Print(x);
    return;
  }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  Udt(x, R - L + 1);
//  Print(x);
}
void Chg(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->BdD = x->ValD = x->CntD = a[L];
    x->BdC = x->ValC = a[L] ^ 0x1;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) Chg(x->LS, L, Mid);
  else Chg(x->RS, Mid + 1, R);
  Udt(x, R - L + 1); 
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = ((RD() - 1) << 1), m = RD();
  scanf("%s", a + 1);
  for (register unsigned i(1); i <= n; ++i) a[i] -= '(';
  Build(N, 1, n);
  printf("%d\n", N->Val);
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    if(a[A] ^ a[B]) {
      swap(a[A], a[B]);
      Chg(N, 1, n);
      A = B;
      Chg(N, 1, n);
    }
    printf("%d\n", N->Val);
  }
  //  }
  return Wild_Donkey;
}


