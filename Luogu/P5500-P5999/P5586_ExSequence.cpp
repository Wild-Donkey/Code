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
const unsigned Mod(1000000007);
unsigned m, n, Last;
unsigned Stack[600005], STop(0);
unsigned A, B, C, D, Opt, OV;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Mn(unsigned& x) { x -= ((x >= Mod) ? Mod : 0); }
struct Node {
  Node* LS, * RS;
  unsigned Size, Val, Tag, Def, Num, Use;
  char Flp;
  inline void PsUp() {
    Val = LS->Val + RS->Val, Mn(Val);
    Size = LS->Size + RS->Size;
  }
  inline Node* Copy() {
    int Del(Stack[STop] - Num);
    Node* Cur(this + Del);
    --Use, * Cur = *this, Cur->Use = 1, Cur->Num = Stack[STop--];
    if (Cur->LS) ++(Cur->LS->Use);
    if (Cur->RS) ++(Cur->RS->Use);
    return Cur;
  }
  inline void Cycle() {
    if (LS) { --(LS->Use); if (!(LS->Use)) LS->Cycle(); }
    if (RS) { --(RS->Use); if (!(RS->Use)) RS->Cycle(); }
    // printf("Recycle %u\n", Num);
    Stack[++STop] = Num;
  }
  inline void PsDw() {
    // printf("PsDw %u Flp %u Tag %u Def %u ", Num, Flp, Tag, ~Def);
    // printf("Not Leave\n");
    if (LS) {
      // printf("LS %u (%u) ", LS->Num, LS->Use);
      if (LS->Use > 1) LS = LS->Copy();
      if (~Def) LS->Def = Def, LS->Val = ((unsigned long long)Def * LS->Size) % Mod, LS->Tag = 0;
      LS->Tag += Tag, Mn(LS->Tag), LS->Val = (LS->Val + (unsigned long long)LS->Size * Tag) % Mod;
      if (Flp) LS->Flp ^= 1, swap(LS->LS, LS->RS);
    }
    if (RS) {
      // printf("RS %u (%u) ", RS->Num, RS->Use);
      if (RS->Use > 1) RS = RS->Copy();
      if (~Def) RS->Def = Def, RS->Val = ((unsigned long long)Def * RS->Size) % Mod, RS->Tag = 0;
      RS->Tag += Tag, Mn(RS->Tag), RS->Val = (RS->Val + (unsigned long long)RS->Size * Tag) % Mod;
      if (Flp) RS->Flp ^= 1, swap(RS->LS, RS->RS);
    }
    // putchar(0x0A);
    Tag = Flp = 0, Def = 0xffffffff;
  }
  inline Node* Rotate() {
    // printf("Rotate %u with %u Ele\n", Num, Size);
    PsDw();
    if (Size <= 5) return this;
    Node* Cur(NULL);
    if ((LS->Size * 3) < RS->Size) (Cur = RS)->PsDw(), RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, (LS = Cur)->PsUp();
    if ((RS->Size * 3) < LS->Size) (Cur = LS)->PsDw(), LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, (RS = Cur)->PsUp();
    if (Cur) Cur->Rotate();
    return this;
  }
  inline void Split(unsigned Left) {
    PsDw();
    if (LS->Size == Left) return;
    Node* Cur;
    if (LS->Size > Left) (Cur = LS)->Split(Left), LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, RS = Cur;
    else (Cur = RS)->Split(Left - LS->Size), RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, LS = Cur;
    Cur->PsUp();
  }
  inline void SPLIT(unsigned Left, Node*& LP, Node*& RP) {
    // printf("SPLIT %u For %u And %u\n", Num, Left, Size - Left);
    if (!Left) { LP = NULL, RP = this; return; }
    if (Left == Size) { LP = this, RP = NULL; return; }
    Split(Left), LP = LS, RP = RS;
  }
  inline void Details() {
    printf("Pnt %u Size %u Val %u ", Num, Size, Val);
    if (LS) printf("LS %u ", LS->Num);
    if (RS) printf("RS %u ", RS->Num);
    putchar(0x0A);
  }
  inline void Prt() {
    // printf("Prt %u Size %u Son: ", Num, Size);
    // if (LS) printf("%u ", LS->Num);
    // if (RS) printf("%u ", RS->Num);
    // putchar(0x0A);
    if (Size == 1) { printf("%u ", Val); return; }
    PsDw();
    if (LS) LS->Prt();
    if (RS) RS->Prt();
  }
  inline void PRINT() {
    PsDw();
    Details();
    if (LS) LS->PRINT();
    if (RS) RS->PRINT();
  }
}N[600005], * CntN(N), * Root(N);
inline void Build(Node* x, unsigned L, unsigned R) {
  x->Def = 0xffffffff, x->Num = x - N, x->Use = 1;
  if (L == R) { x->Val = RD(), x->LS = NULL, x->RS = NULL, x->Size = 1; return; }
  unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->PsUp();
}
inline Node* MERGE(Node* Rt, Node* L, Node* R) {
  // printf("MERGE %u %u %u\n", Rt - N, L - N, R - N);
  if (L && R) { Rt->LS = L, Rt->RS = R, Rt->PsUp(); return Rt->Rotate(); }
  // printf("L %u R %u\n", L->Num, R->Num);
  if (L) return L->Rotate();
  return R->Rotate();
}
//  inline void Clr () {}
signed main() {
  // freopen("P5350.in", "r", stdin);
  // freopen("P5350.out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Build(N, 1, n);
  for (unsigned i(1); i <= m; ++i) {
    Opt = RD(), A = (RD() ^ Last), B = (RD() ^ Last);
    // printf("Now %u\n", i);
    Node* Part1(NULL), * Part2(NULL), * Part3(NULL), * Rt1(NULL), * Rt2(NULL);
    (Rt1 = Root)->SPLIT(A - 1, Part1, Part2);
    (Rt2 = Part2)->SPLIT(B - A + 1, Part2, Part3);
    // printf("Parts %u %u %u\n", Part1 - N, Part2 - N, Part3 - N);
    switch (Opt) {
    case(1): {
      printf("%u\n", Last = Part2->Val);
      break;
    }
    case(2): {
      Part2->Def = (RD() ^ Last), Part2->Tag = 0, Part2->Val = (unsigned long long)Part2->Size * Part2->Def % Mod;
      break;
    }
    case(3): {
      Part2->Tag += (OV = (RD() ^ Last)), Mn(Part2->Tag), Part2->Val = (Part2->Val + (unsigned long long)Part2->Size * OV) % Mod;
      // printf("Add %u\n", OV);
      break;
    }
    case(6): {
      Part2->Flp = 1, swap(Part2->LS, Part2->RS);
      break;
    }
    default: {
      Node* Part4(NULL), * Part5(NULL), * Rt3(NULL), * Rt4(NULL);
      C = (RD() ^ Last), D = (RD() ^ Last);
      if (C > B)  (Rt3 = Part3)->SPLIT(C - B - 1, Part3, Part4);
      else (Rt3 = Part1)->SPLIT(C - 1, Part1, Part4);
      (Rt4 = Part4)->SPLIT(D - C + 1, Part4, Part5);
      // printf("Parts %u %u %u %u %u\n", Part1 - N, Part2 - N, Part3 - N, Part4 - N, Part5 - N);
      if (Opt & 1) swap(Part4, Part2);
      else Part4->Cycle(), ++((Part4 = Part2)->Use);
      Part4 = MERGE(Rt4, Part4, Part5);
      if (C > B) Part3 = MERGE(Rt3, Part3, Part4);
      else Part1 = MERGE(Rt3, Part1, Part4);
      break;
    }
    }
    Part2 = MERGE(Rt2, Part2, Part3);
    Root = MERGE(Rt1, Part1, Part2);
    // Root->PRINT();
    // printf("After %u:", i), Root->Prt(), putchar(0x0A);
  }
  Root->Prt(), putchar(0x0A);
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
10 10
911616723 667663273 691146885 965015377 205230478 641859055 232410115 817771875 323420518 700453455
911616723 667663273 691146885 965015377 205230478 641859055 232410115 817771875 323420518 700453455
2 4 4 266128540
4 9 10 1 2
6 5 8
4 5 7 8 10
3 7 9 703466373
4 6 8 3 5
1 7 10
3 1 10 390058271
2 2 9 873260451
3 6 7 449097252

*/