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
unsigned m, n, Last;
unsigned Stack[600005], STop(0);
unsigned A, B, C, D, Opt, OV;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  Node* LS, * RS;
  unsigned Size, Val;
  inline void PsUp() {
    Val = LS->Val + RS->Val;
    Size = LS->Size + RS->Size;
  }
  inline Node* Rotate() {
    if (LS && (!RS)) return LS->Rotate();
    if ((!LS) && RS) return RS->Rotate();
    if (Size <= 5) return this;
    Node* Cur(NULL);
    if ((LS->Size * 3) < RS->Size) Cur = RS, RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, (LS = Cur)->PsUp();
    if ((RS->Size * 3) < LS->Size) Cur = LS, LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, (RS = Cur)->PsUp();
    if (Cur) Cur->Rotate();
    return this;
  }
  inline void Split(unsigned Left) {
    if (LS->Size == Left) return;
    Node* Cur;
    if (LS->Size > Left) (Cur = LS)->Split(Left), LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, RS = Cur;
    else (Cur = RS)->Split(Left - LS->Size), RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, LS = Cur;
    Cur->PsUp();
  }
  inline void SPLIT(unsigned Left, Node*& LP, Node*& RP) {
    if (!Left) { LP = NULL, RP = this; return; }
    if (Left == Size) { LP = this, RP = NULL; return; }
    Split(Left), LP = LS, RP = RS;
  }
  inline void Details() {
    printf("Size %u Val %u ", Size, Val);
    putchar(0x0A);
  }
  inline void Prt() {
    if (Size == 1) { printf("%u ", Val); return; }
    if (LS) LS->Prt();
    if (RS) RS->Prt();
  }
  inline void PRINT() {
    Details();
    if (LS) LS->PRINT();
    if (RS) RS->PRINT();
  }
}N[600005], * CntN(N), * Root(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  if (L == R) { x->Val = RD(), x->LS = NULL, x->RS = NULL, x->Size = 1; return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->PsUp();
}
inline Node* MERGE(Node* Rt, Node* L, Node* R) {
  if (L && R) { Rt->LS = L, Rt->RS = R, Rt->PsUp(); return Rt->Rotate(); }
  if (L) return L->Rotate();
  return R->Rotate();
}
inline Node* Insert(Node* Rt, unsigned Pos, unsigned x) {
  Node* Part2(++CntN), * Part1, * Part3, * NRot(++CntN);
  Part2->Val = x, Part2->Size = 1, Part2->LS = Part2->RS = NULL;
  Rt->SPLIT(Pos, Part1, Part3);
  if (!Part3) { MERGE(NRot, Part1, Part2); return NRot; }
  else { MERGE(NRot, Part2, Part3); return MERGE(Rt, Part1, NRot); }
}
inline void Qry(Node* x, unsigned L, unsigned R) {
  Node* Part1(NULL), * Part2(NULL), * Part3(NULL), * Rt1(NULL), * Rt2(NULL);
  (Rt1 = Root)->SPLIT(A - 1, Part1, Part2);
  (Rt2 = Part2)->SPLIT(B - A + 1, Part2, Part3);
  /*
    YOUR CODE HERE, Part 2 is what you need
  */
  Part2 = MERGE(Rt2, Part2, Part3);
  Root = MERGE(Rt1, Part1, Part2);
}
signed main() {
  n = RD(), m = RD(), Build(N, 1, n);
  Root->Prt(), putchar(0x0A);
  return Wild_Donkey;
}