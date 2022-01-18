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
#define Inf 1000000
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
unsigned a[500005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Mn, L, R, Tag, Size;
  char Re;
  inline void Udt() { Size = LS->Size + RS->Size, Mn = min(LS->Mn, RS->Mn); }
}N[5000005], * CntN(N), * Root;
inline void Clr() { n = RD(), Root = N; }
inline void PsDw(Node* x) {
  // printf("PsDw %u [%u, %u], Tag %u Rev %u LS %u RS %u\n", x - N, x->L, x->R, x->Tag, x->Re, x->LS - N, x->RS - N);
  if (x->LS) x->LS->R = x->L + x->LS->R - x->LS->L, x->LS->L = x->L;
  if (x->RS) x->RS->L = x->R - x->RS->R + x->RS->L, x->RS->R = x->R;
  if (x->Re) {
    swap(x->LS, x->RS);
    if ((x->LS) && (x->RS)) {
      // printf("From [%u, %u] [%u, %u] in [%u, %u]\n", x->LS->L, x->LS->R, x->RS->L, x->RS->R, x->L, x->R);
      x->LS->Re ^= 1, x->RS->Re ^= 1;
      x->LS->R = x->L + x->LS->R - x->LS->L;
      x->RS->L = x->LS->R + 1;
      x->LS->L = x->L, x->RS->R = x->R;
      // printf("To [%u, %u] [%u, %u]\n", x->LS->L, x->LS->R, x->RS->L, x->RS->R);
    }
    else {
      if (x->LS) x->LS->Re ^= 1;
      if (x->RS) x->RS->Re ^= 1;
    }
    x->Re = 0;
  }
  if (x->Tag) {
    if (x->LS) x->LS->Tag = x->LS->Tag ? min(x->LS->Tag, x->Tag) : x->Tag, x->LS->Mn = min(x->LS->Mn, x->Tag);
    if (x->RS) x->RS->Tag = x->RS->Tag ? min(x->RS->Tag, x->Tag) : x->Tag, x->RS->Mn = min(x->RS->Mn, x->Tag);
    x->Tag = 0;
  }
}
inline Node* Rotate(Node* x) {
  PsDw(x);
  if ((!(x->LS)) && (!(x->RS))) return x;
  if (!(x->RS)) return Rotate(x->LS);
  if (!(x->LS)) return Rotate(x->RS);
  if (x->Size < 5) return x;
  if ((x->LS->Size * 3) < x->RS->Size) {
    Node* Cur(Rotate(x->RS));
    x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur, Cur->Udt();
    Cur->L = Cur->LS->L, Cur->R = Cur->RS->R;
  }
  if ((x->RS->Size * 3) < x->LS->Size) {
    Node* Cur(Rotate(x->LS));
    x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur, Cur->Udt();
    Cur->L = Cur->LS->L, Cur->R = Cur->RS->R;
  }
  return x;
}
inline Node* Edit(Node* x) {
  // printf("Edit %u, Mn %u [%u, %u]\n", x - N, x->Mn, x->L, x->R);
  Rotate(x);
  if ((!(x->LS)) && (!(x->RS))) {
    if (x->L == x->R) --(x->Mn);
    else {
      if (x->L == A) {
        x->LS = (++CntN), * (x->LS) = (Node){ NULL, NULL, x->Mn - 1, A, A, 0, 1, 0 };
        x->RS = (++CntN), * (x->RS) = (Node){ NULL, NULL, x->Mn, A + 1, x->R, 0, 1, 0 };
        x->Udt();
        return x;
      }
      if (x->R == A) {
        x->RS = (++CntN), * (x->RS) = (Node){ NULL, NULL, x->Mn - 1, A, A, 0, 1, 0 };
        x->LS = (++CntN), * (x->LS) = (Node){ NULL, NULL, x->Mn, x->L, A - 1, 0, 1, 0 };
        x->Udt();
        return x;
      }
      x->LS = (++CntN), * (x->LS) = (Node){ NULL, NULL, x->Mn, x->L, A, 0, 1, 0 };
      x->RS = (++CntN), * (x->RS) = (Node){ NULL, NULL, x->Mn, A + 1, x->R, 0, 1, 0 };
      x->LS = Edit(x->LS), x->Udt();
    }
  }
  else {
    if (x->LS->R >= A) x->LS = Edit(x->LS);
    else x->RS = Edit(x->RS);
    x->Udt();
  }
  return x;
}
inline Node* Del(Node* x) {
  // printf("Del %u [%u, %u] Mn %u\n", x - N, x->L, x->R, x->Mn);
  if (x->L > A) return NULL;
  x = Rotate(x);
  if (!(x->LS)) { x->R = A;return x; }
  if (x->LS->R > A) return Del(x->LS);
  x->RS = Del(x->RS), x->R = A, x = Rotate(x);
  if (x->LS) x->Udt();
  return x;
}
inline Node* Isrt(Node* x) {
  // printf("Isrt %u [%u, %u] LS %u RS %u\n", x - N, x->L, x->R, x->LS - N, x->RS - N);
  x = Rotate(x);
  if (x->RS) { x->RS = Isrt(x->RS), x->R = A, x->Udt(); return Rotate(x); }
  if (x->Mn == B) { x->R = A; return x; }
  x->LS = (++CntN), * (x->LS) = (Node){ NULL, NULL, x->Mn, x->L, x->R, 0, 1, 0 };
  x->RS = (++CntN), * (x->RS) = (Node){ NULL, NULL, B, x->R + 1, A, 0, 1, 0 };
  x->R = A, x->Udt();  return Rotate(x);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    N[0] = (Node){ NULL, NULL, Inf + 1, 1, a[1] - 1, 0, 1, 0 };
    if (!(a[1] & 1)) A = a[1] >> 1, Root = Edit(Root);
    for (unsigned i(2); i <= n; ++i) {
      B = Root->Mn + 1;
      A = a[i] - 1;
      if (a[i] > a[i - 1]) Root = Isrt(Root);
      if (a[i] < a[i - 1]) Root = Del(Root);
      Root = Rotate(Root), Root->Tag = B, Root->Re = 1, Root->Mn = min(B, Root->Mn);
      // printf("Now %u Mn %u\n", i, Root->Mn - Inf + i);
      if (!(a[i] & 1)) A = a[i] >> 1, Root = Edit(Root);
      // printf("Now %u Mn %u\n", i, Root->Mn - Inf + i);
    }
    printf("%u\n", Root->Mn + n - Inf);
  }
  // system("pause");
  return Wild_Donkey;
}
/*
1
10
7 6 8 6 8 6 5 4 8 8
10
9 6 7 8 9 7 6 5 6 8
5
4 4 4 4 3
4
2 2 4 2
3
2 4 3
5
4 4 2 3 4
4
4 5 3 3

3
3
3
5
*/