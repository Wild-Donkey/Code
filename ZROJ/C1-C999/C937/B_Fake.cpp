#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <queue>
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
int a[200005];
long long Sum[200005], A, B, m;
unsigned n;
unsigned C, D, t, Ans(0), Tmp(0);
char InQue[200005];
struct Node {
  Node* LS, * RS;
  long long ValL, ValR;
  unsigned Size;
}N[400005], * Stack[400005], ** Top(Stack), * Root(N);
inline void Clr() {
  n = RD(), Tmp = Ans = 0, Root = N, Top = Stack;
}
void Print(Node* x) {
  printf("Size %u [%lld, %lld] LS %u, RS %u\n", x->Size, x->ValL, x->ValR, x->LS - N, x->RS - N);
}
Node* Insert(Node* x) {
  // printf("Insert %lld to %u\n", A, x - N), Print(x);
  ++x->Size;
  if (x->Size == 2) {
    Node* Now(*(Top--));
    Now->ValL = Now->ValR = A, Now->Size = 1, Now->LS = Now->RS = NULL;
    if (A > x->ValL) x->RS = Now, x->LS = *(Top--), x->LS->Size = 1, x->LS->LS = x->LS->RS = NULL, x->LS->ValL = x->LS->ValR = x->ValL;
    else x->LS = Now, x->RS = *(Top--), x->RS->Size = 1, x->RS->LS = x->RS->RS = NULL, x->RS->ValL = x->RS->ValR = x->ValR;
    x->ValL = x->LS->ValL, x->ValR = x->RS->ValR;
    return x;
  }
  if ((x->LS) && (x->LS->ValR >= A)) x->LS = Insert(x->LS), x->ValL = x->LS->ValL;
  else x->RS = Insert(x->RS), x->ValR = x->RS->ValR;
  if (!(x->LS)) { *(++Top) = x; return x->RS; }
  if (!(x->RS)) { *(++Top) = x; return x->LS; }
  if (x->Size > 3) {
    if ((x->LS->Size << 1) < x->RS->Size) {
      Node* Now(x->RS);
      x->RS = Now->RS, Now->RS = Now->LS, Now->LS = x->LS, x->LS = Now;
      Now->ValL = Now->LS->ValL, Now->ValR = Now->RS->ValR;
      Now->Size = Now->LS->Size + Now->RS->Size;
    }
    if ((x->RS->Size << 1) < x->LS->Size) {
      Node* Now(x->LS);
      x->LS = Now->LS, Now->LS = Now->RS, Now->RS = x->RS, x->RS = Now;
      Now->ValL = Now->LS->ValL, Now->ValR = Now->RS->ValR;
      Now->Size = Now->LS->Size + Now->RS->Size;
    }
  }
  // printf("Inserted %lld to %u\n", A, x - N), Print(x);
  return x;
}
Node* Del(Node* x) {
  // printf("Delete %lld From %u\n", A, x - N), Print(x);
  --(x->Size);
  if (!(x->Size)) { *(++Top) = x; return NULL; }
  if ((x->LS) && (x->LS->ValR >= A)) { x->LS = Del(x->LS); }
  else { x->RS = Del(x->RS); }
  if (!(x->LS)) { *(++Top) = x; return x->RS; }
  if (!(x->RS)) { *(++Top) = x; return x->LS; }
  if (x->Size > 3) {
    if ((x->LS->Size << 1) < x->RS->Size) {
      Node* Now(x->RS);
      x->RS = Now->RS, Now->RS = Now->LS, Now->LS = x->LS, x->LS = Now;
      Now->ValL = Now->LS->ValL, Now->ValR = Now->RS->ValR;
      Now->Size = Now->LS->Size + Now->RS->Size;
    }
    if ((x->RS->Size << 1) < x->LS->Size) {
      Node* Now(x->LS);
      x->LS = Now->LS, Now->LS = Now->RS, Now->RS = x->RS, x->RS = Now;
      Now->ValL = Now->LS->ValL, Now->ValR = Now->RS->ValR;
      Now->Size = Now->LS->Size + Now->RS->Size;
    }
  }
  x->ValL = x->LS->ValL, x->ValR = x->RS->ValR;
  // printf("Deleted %lld From %u\n", A, x - N), Print(x);
  return x;
}
unsigned Find(Node* x) {
  if (x->Size == 1) return (unsigned)(x->ValL > A);
  if ((x->RS) && (x->RS->ValL > A)) return ((x->LS) ? (Find(x->LS) + x->RS->Size) : x->RS->Size);
  else return Find(x->RS);
}
int main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  while (1) {
    Clr();
    if (!n) break;
    for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + (a[i] = RDsg());
    for (unsigned i(1); i <= (n << 1); ++i) *(++Top) = N + i;
    m = Sum[n], N->ValL = N->ValR = a[1], N->Size = 1, N->LS = N->RS = 0;
    if (m <= 0) { printf("-1\n");continue; }
    for (register unsigned i(2); i < n; ++i) A = Sum[i], Ans += Find(Root), Root = Insert(Root);
    A = m, Tmp = Find(Root), Root = Insert(Root), B = Root->ValL;
    while (Root->ValL + m < Root->ValR) {
      // printf("After %u += %u Root %u\n", Ans, Tmp, Root - N);
      Ans += Tmp;
      A = B, Root = Del(Root);
      // printf("Deleted Root %u\n", Root - N), Print(Root);
      A += m, Tmp = Find(Root), B = Root->ValL, Root = Insert(Root);
    }
    printf("%u\n", Ans + Tmp);
  }
  return Wild_Donkey;
}
/*
4
-1 2 -2 2
3
2 3 3
8
-1 -1 -2 -2 1 1 1 2
4
1 2 -2 2
6
572 249 -681 -806 509 160
6
160 572 249 -681 -806 509
6
509 160 572 249 -681 -806
6
-806 509 160 572 249 -681
6
-681 -806 509 160 572 249
6
249 -681 -806 509 160 572
0
m = 3

*/
