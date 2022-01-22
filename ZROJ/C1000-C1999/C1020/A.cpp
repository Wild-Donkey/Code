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
unsigned m, n, a[1000005];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans[1000005], Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Val, pVa, Hei;
}N[1000005], * CntN(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if(L == R) {x->Hei = 0, x->Val = a[L];return;}
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Hei = x->LS->Hei + 1;
  x->Val = max(x->LS->Val, x->RS->Val);
  x->pVa = max(max(x->LS->pVa, x->RS->pVa), min(x->LS->Val, x->RS->Val));
  Ans[x->pVa + 1] = x->Hei;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  m = 1 << (n = RD());
  for (unsigned i(1); i <= m; ++i) a[i] = RD();
  Build(N, 1, m);
  for (unsigned i(1); i <= m; ++i) Ans[i] = max(Ans[i - 1], Ans[i]);
  for (unsigned i(1); i <= m; ++i) printf("%u ", Ans[i]);
  putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
1 6 8 7 5 2 3 4
 6   8   5   4
   8       5
       8
1 7 2 3
 7   4
   7
*/
