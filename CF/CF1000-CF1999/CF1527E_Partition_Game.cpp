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
unsigned a[35005], f[35005], Pre[35005], Pos[35005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, Tag;
}N[100005], *CntN(N);
void Ins(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    return;
  } 
  register unsigned Mid((L + R) >> 1); 
  Ins(x->LS = ++CntN, L, Mid);
  Ins(x->RS = ++CntN, Mid + 1, R);
}
void Build(Node *x, unsigned L, unsigned R) {
  x->Tag = 0;
  if(L == R) {
    x->Val = f[L]; 
    return;
  }
  register unsigned Mid((L + R) >> 1); 
  Build(x->LS, L, Mid);
  Build(x->RS, Mid + 1, R);
  x->Val = min(x->LS->Val, x->RS->Val);
}
void PsDw(Node *x) {
  if(x->Tag) {
    x->LS->Tag += x->Tag;
    x->LS->Val += x->Tag;
    x->RS->Tag += x->Tag;
    x->RS->Val += x->Tag;
    x->Tag = 0;
  }
}
void Chg(Node *x, unsigned L, unsigned R) {
//  printf("Chg %u [%u, %u] [1, %u]\n", x - N, L, R, A);
  if(R <= A) {
    x->Val += B;
    x->Tag += B;
    return;
  }
  PsDw(x);
  register unsigned Mid((L + R) >> 1);
  Chg(x->LS, L, Mid);
  if(Mid < A) {
    Chg(x->RS, Mid + 1, R);
  }
  x->Val = min(x->LS->Val, x->RS->Val);
}
void Qry(Node *x, unsigned L, unsigned R) {
//  printf("Qry %u [%u, %u] [1, %u]\n", x - N, L, R, A);
  if(R <= A) {
    Ans = min(Ans, x->Val);
    return;
  }
  PsDw(x);
  register unsigned Mid((L + R) >> 1);
  Qry(x->LS, L, Mid);
  if(Mid < A) {
    Qry(x->RS, Mid + 1, R);
  }
}
int main() {
  // freopen(".in", "r", stdin);
  // freopen(".out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(1); i <= n; ++i) {
    if(!Pos[a[i]]) Pos[a[i]] = i;
    Pre[i] = Pos[a[i]];
    Pos[a[i]] = i;
//    printf("%u ", Pre[i]);
  }
//  putchar('\n');
  Ins(N, 1, n);
  for (register unsigned i(2); i <=n; ++i) {
    f[i] = f[i - 1] + i - Pre[i]; 
  }
  Build(N, 1, n); 
  for (register unsigned i(2); i <= m; ++i) {
    for (register unsigned j(i); j <= n; ++j) {
//      printf("%u %u\n", i, j);
      A = Pre[j] - 1, B = j - Pre[j];
      if(A) Chg(N, 1, n);
      A = j - 1, Ans = 0x3f3f3f3f, Qry(N, 1, n);
      f[j] = Ans;
//      printf("F = %u\n", f[j]);
    }
    Build(N, 1, n);
  }
  register Node *Now(N);
  while (Now->RS) {
    Now = Now->RS; 
  }
  printf("%u\n", Now->Val);
  //  }
  return Wild_Donkey;
}


