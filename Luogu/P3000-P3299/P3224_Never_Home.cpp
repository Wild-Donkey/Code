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
unsigned a[100005], Fa[100005], Stack[100005], TopS(0), m, n, Cnt(0), A, B, D, t, Ans(0), Tmp(0);
char Op[5];
inline unsigned Find(unsigned x) {
  register unsigned Tmpx(x);
  while (Tmpx ^ Fa[Tmpx]) Stack[++TopS] = Tmpx, Tmpx = Fa[Tmpx];
  while (TopS) Fa[Stack[TopS--]] = Tmpx;
  return Tmpx;
}
struct Node {
  unsigned ValL, ValR, Size;
  Node* LS, * RS;
}N[300005], * Root[100005], * CntN, * C;
Node* Add(Node* x) {
  // printf("Add %u into %u which [%u, %u]\n", C - N, x - N, x->ValL, x->ValR);
  if (x->ValL == x->ValR) {
    // printf("So In?\n");
    (++CntN)->Size = 2;
    if (C->ValL < x->ValL) CntN->LS = C, CntN->RS = x;
    else CntN->RS = C, CntN->LS = x;
    CntN->ValL = CntN->LS->ValL;
    CntN->ValR = CntN->RS->ValR;
    return CntN;
  }
  ++(x->Size);
  if (C->ValL <= x->LS->ValR) x->LS = Add(x->LS);
  else x->RS = Add(x->RS);
  // printf("Back To %u [%u, %u], Size %u\n", x - N, x->ValL, x->ValR, x->Size);
  if (!(x->LS)) return x->RS;
  if (!(x->RS)) return x->LS;
  if (x->Size > 3) {
    if ((x->LS->Size * 3) < x->RS->Size) {
      register Node* TmpN(x->RS);
      x->RS = TmpN->RS;
      TmpN->RS = TmpN->LS;
      TmpN->LS = x->LS;
      x->LS = TmpN;
      TmpN->Size = TmpN->LS->Size + TmpN->RS->Size;
      TmpN->ValL = TmpN->LS->ValL;
      TmpN->ValR = TmpN->RS->ValR;
    }
    if ((x->RS->Size * 3) < x->LS->Size) {
      register Node* TmpN(x->LS);
      x->LS = TmpN->LS;
      TmpN->LS = TmpN->RS;
      TmpN->RS = x->RS;
      x->RS = TmpN;
      TmpN->Size = TmpN->LS->Size + TmpN->RS->Size;
      TmpN->ValL = TmpN->LS->ValL;
      TmpN->ValR = TmpN->RS->ValR;
    }
  }
  x->ValL = x->LS->ValL;
  x->ValR = x->RS->ValR;
  return x;
}
void DFS(Node* x) {
  if (x->ValL == x->ValR) { Stack[++TopS] = x - N;return; }
  if (x->LS) DFS(x->LS);
  if (x->RS) DFS(x->RS);
}
Node* Merge(Node* x, Node* y) {
  // printf("Merge(%u, %u)\n", x - N, y - N);
  DFS(x);
  register Node* Cur(y);
  while (TopS) C = N + Stack[TopS--], Cur = Add(Cur);
  return Cur;
}
void Qry(Node* x) {
  // printf("Qry %u %u %u\n", x - N, x->Size, x->ValL);
  if (B > x->Size) { Ans = -1; return; }
  if (x->ValL == x->ValR) { Ans = x - N; return; }
  if (x->LS) {
    if (x->LS->Size < B) B -= x->LS->Size, Qry(x->RS);
    else Qry(x->LS);
  }
  else Qry(x->RS);
}
signed main() {
  // freopen("P3224_10.in", "r", stdin);
  // freopen("P3224.out", "w", stdout);
  //  t = RD();
  //  for (register unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), CntN = N + n;
  for (register unsigned i(1); i <= n; ++i) N[i].ValL = N[i].ValR = RD(), N[i].Size = 1, Root[i] = N + i, Fa[i] = i;
  for (register unsigned i(1); i <= m; ++i) {
    A = Find(RD()), B = Find(RD());
    if (A == B) continue;
    if (Root[A]->Size < Root[B]->Size) Fa[A] = B, Root[B] = Merge(Root[A], Root[B]);
    else Fa[B] = A, Root[A] = Merge(Root[B], Root[A]);
  }
  m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    scanf("%s", &Op), A = RD(), B = RD();
    if (Op[0] ^ 'B') Qry(Root[Find(A)]), printf("%d\n", Ans);
    else { A = Find(A), B = Find(B); if (Root[A]->Size < Root[B]->Size) Fa[A] = B, Root[B] = Merge(Root[A], Root[B]); else Fa[B] = A, Root[A] = Merge(Root[B], Root[A]); }
  }
  // system("pause");
  return Wild_Donkey;
}