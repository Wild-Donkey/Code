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
long long a[100005], b[100005];
long long Sum[100005], Min, m(0), Pos;
long long A, Pls[15], Ans;
long long n, Cnt, PCnt[15], Last;
struct Node {
  Node* LS, * RS;
  long long ValL, ValR;
  unsigned Size;
}N[200005], * CntN(N), * Root(N);
inline void Clr() {
  // printf("Done?\n");
  if (m > 0) memset(Pls, 0, m << 3), memset(PCnt, 0, m << 3);
  // printf("Half\n");
  n = RD(), Ans = 0, Min = 0x3f3f3f3f3f3f3f3f, Root = CntN = N;
  // printf("Done!\n");
}
void Print(Node* x) {
  printf("Size %u [%lld, %lld] LS %u, RS %u\n", x->Size, x->ValL, x->ValR, x->LS - N, x->RS - N);
}
Node* Insert(Node* x) {
  // printf("Insert %lld to %u\n", A, x - N), Print(x);
  ++x->Size;
  if (x->Size == 2) {
    Node* Now(++CntN);
    Now->ValL = Now->ValR = A, Now->Size = 1, Now->LS = Now->RS = NULL;
    if (A > x->ValL) x->RS = Now, x->LS = ++CntN, x->LS->Size = 1, x->LS->LS = x->LS->RS = NULL, x->LS->ValL = x->LS->ValR = x->ValL;
    else x->LS = Now, x->RS = ++CntN, x->RS->Size = 1, x->RS->LS = x->RS->RS = NULL, x->RS->ValL = x->RS->ValR = x->ValR;
    x->ValL = x->LS->ValL, x->ValR = x->RS->ValR;
    return x;
  }
  if ((x->LS) && (x->LS->ValR >= A)) x->LS = Insert(x->LS), x->ValL = x->LS->ValL;
  else x->RS = Insert(x->RS), x->ValR = x->RS->ValR;
  if (!(x->LS)) { return x->RS; }
  if (!(x->RS)) { return x->LS; }
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
unsigned Find(Node* x) {
  if (x->Size == 1) return (unsigned)(x->ValL > A);
  if ((x->RS) && (x->RS->ValL > A)) return ((x->LS) ? (Find(x->LS) + x->RS->Size) : x->RS->Size);
  else return Find(x->RS);
}
int main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (;;) {
    Clr();
    if (!n) break;
    for (unsigned i(1); i <= n; ++i) { Sum[i] = Sum[i - 1] + (a[i] = RDsg()); if (Sum[i] < Min) Min = Sum[i], Pos = i; }
    if ((m = Sum[n]) <= 0) { printf("-1\n");continue; }
    for (unsigned i(1); i <= n; ++i) { b[i] = a[(Pos + i > n) ? (Pos + i - n) : (Pos + i)]; }
    for (unsigned i(1); i <= n; ++i) Sum[i] = Sum[i - 1] + b[i];
    Root->ValL = Root->ValR = Sum[1], Root->Size = 1, Root->LS = Root->RS = NULL;
    for (unsigned i(2); i <= n; ++i) A = Sum[i], Ans += Find(Root), Root = Insert(Root);
    sort(Sum + 1, Sum + n + 1, greater<long long>()), Sum[n + 1] = 0x3f3f3f3f3f3f3f3f, Last = 1, Cnt = 1;
    for (unsigned i(1); i <= n; ++i, ++Cnt) {
      if (Sum[i] ^ Sum[i + 1]) {
        Pos = Sum[i] % m, A = Sum[i] / m;
        for (unsigned j(0); j < m; ++j) Ans += (Pls[j] - PCnt[j] * (A + ((Pos < j) ? 0 : 1))) * Cnt;
        Pls[Pos] += Cnt * A, PCnt[Pos] += Cnt, Cnt = 0;
      }
    }
    printf("%lld\n", Ans);
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
