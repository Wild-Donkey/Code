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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
unsigned long long a[200005], Ans(0);
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned long long Lenth, Begin, Delta;
  unsigned Size, Use;
  inline void PsUp() { Size = LS->Size + RS->Size, Lenth = LS->Lenth + RS->Lenth; }
}N[600005], * CntN(N), * Root(N);
inline Node* Copy(Node* x) {
  Node* Cur(++CntN);
  --(x->Use), (*Cur) = (*x), Cur->Use = 1;
  if (Cur->LS) ++(Cur->LS->Use);
  if (Cur->RS) ++(Cur->RS->Use);
  return Cur;
}
inline void PsDw(Node* x) {
  if (x->LS) {
    if (x->LS->Use > 1) x->LS = Copy(x->LS);
    x->LS->Begin += x->Begin, x->LS->Delta += x->Delta;
    if (x->RS->Use > 1) x->RS = Copy(x->RS);
    x->RS->Begin += x->Begin + (x->Delta * x->LS->Lenth), x->RS->Delta += x->Delta;
    x->Begin = x->Delta = 0;
  }
}
inline Node* Rotate(Node* x) {
  PsDw(x);
  if (x->Size <= 5) return x;
  Node* Cur(NULL);
  if ((x->LS->Size * 3) < x->RS->Size)
    PsDw(Cur = x->RS), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, (x->LS = Cur)->PsUp();
  if ((x->RS->Size * 3) < x->LS->Size)
    PsDw(Cur = x->LS), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, (x->RS = Cur)->PsUp();
  if (Cur) Rotate(Cur);
  return x;
}
inline void Split(Node* x, unsigned long long Left) {
  if (x->Size == 1) {
    x->LS = ++CntN, x->RS = ++CntN;
    x->LS->Use = x->RS->Use = x->LS->Size = x->RS->Size = 1;
    x->LS->LS = x->RS->LS = x->LS->RS = x->RS->RS = NULL;
    x->LS->Lenth = Left, x->RS->Lenth = x->Lenth + Left;
    x->LS->Delta = x->RS->Delta = x->Delta;
    x->LS->Begin = x->Begin, x->RS->Begin = x->Begin + (x->LS->Lenth * x->Delta);
    x->Delta = x->Begin = 0;
    return;
  }
  PsDw(x);
  if (x->LS->Lenth == Left) return;
  Node* Cur;
  if (x->LS->Lenth > Left) Split(Cur = x->LS, Left), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur;
  else Split(Cur = x->RS, Left - x->LS->Lenth), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur;
  Cur->PsUp();
}
inline void SPLIT(Node* x, unsigned long long Left, Node*& LP, Node*& RP) {
  if (!Left) { LP = NULL, RP = x; return; }
  if (Left == x->Lenth) { LP = x, RP = NULL; return; }
  Split(x, Left), LP = x->LS, RP = x->RS;
}
inline void Details(Node* x) { printf("Pnt %u Size %u Val %u LS %u RS %u\n", x->Size, x->Begin, x->Delta, x->LS - N, x->RS - N); }
inline void PRINT(Node* x) {
  PsDw(x), Details(x);
  if (x->LS) PRINT(x->LS);
  if (x->RS) PRINT(x->LS);
}
inline Node* MERGE(Node* Rt, Node* L, Node* R) {
  if (L && R) { Rt->LS = L, Rt->RS = R, Rt->PsUp(); return Rotate(Rt); }
  if (L) return Rotate(L);  return Rotate(R);
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  unsigned long long Cur(a[n]);
  N->Size = 1, N->Lenth = a[n], N->Delta = 1, N->Begin = 0, N->Use = 1;
  for (unsigned i(n - 1), j(n); i; --i)if (a[i] > Cur) {
    Node* R1(Root), * Part1, * Part2;
    if (a[i] % Cur) {
      SPLIT(R1, a[i] % Cur, Part1, Part2);
      MERGE(R1, Part2, Part1);
    }

    j = i;
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}