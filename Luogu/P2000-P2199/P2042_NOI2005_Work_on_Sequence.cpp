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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Op[10];
struct Node {
  Node* LS, * RS;
  unsigned Size;
  int Sum, Sub, Pre, Suf, Chg;
  char Flip;
  inline void PsUp() {
    Size = LS->Size + RS->Size;
    Sum = LS->Sum + RS->Sum;
    Pre = max(LS->Pre, LS->Sum + RS->Pre);
    Suf = max(RS->Suf, RS->Sum + LS->Suf);
    Sub = max(max(LS->Sub, RS->Sub), LS->Suf + RS->Pre);
  }
}N[1000005], * Stack[1000005], ** STop(Stack), * CntN(N), * Root(N);
inline void Details(Node* x) {
  printf("Node %u: Size %u Sum %d LS %u RS %u\n", x - N, x->Size, x->Sum, x->LS - N, x->RS - N);
  printf("Pre %u Sub %u Suf %u\n", x->Pre, x->Sub, x->Suf);
}
inline Node* New() {
  if (STop != Stack) return *(STop--);
  return ++CntN;
}
inline void Build(Node* x, unsigned y) {
  // printf("Build %u Size %u\n", x - N, y);
  x->Chg = 0x3f3f3f3f, x->Flip = 0;
  if (y == 1) { x->Size = 1, x->Sub = x->Pre = x->Suf = x->Sum = RDsg(), x->LS = x->RS = NULL; return; }
  unsigned Mid(y >> 1);
  Build(x->LS = New(), Mid);
  Build(x->RS = New(), y - Mid);
  x->PsUp();
}
inline void PsDw(Node* x) {
  if (!(x->LS)) return;
  if ((x->Chg) ^ 0x3f3f3f3f) {
    x->LS->Chg = x->RS->Chg = x->Chg;
    x->LS->Sub = x->LS->Pre = x->LS->Suf = max(x->Chg, x->LS->Sum = x->LS->Size * x->Chg);
    x->RS->Sub = x->RS->Pre = x->RS->Suf = max(x->Chg, x->RS->Sum = x->RS->Size * x->Chg);
    x->Flip = 0, x->Chg = 0x3f3f3f3f;
  }
  if (x->Flip) {
    x->LS->Flip ^= 1, x->RS->Flip ^= 1;
    swap(x->LS->LS, x->LS->RS);
    swap(x->LS->Pre, x->LS->Suf);
    swap(x->RS->LS, x->RS->RS);
    swap(x->RS->Pre, x->RS->Suf);
    x->Flip = 0;
  }
}
inline void DFS(Node* x) {
  if (x->Size == 1) { printf("%d ", x->Sum); return; }
  PsDw(x);
  DFS(x->LS), DFS(x->RS);
}
inline Node* Rotate(Node* x) {
  if (!(x->LS)) return x;
  PsDw(x);
  if (x->Size <= 5) return x;
  if (x->LS->Size >= (x->RS->Size << 1)) {
    Node* Cur(x->LS);
    PsDw(Cur), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur, Cur->PsUp();
  }
  if (x->RS->Size >= (x->LS->Size << 1)) {
    Node* Cur(x->RS);
    PsDw(Cur), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur, Cur->PsUp();
  }
  return x;
}
inline void Recycle(Node* x) {
  *(++STop) = x;
  if (x->LS) Recycle(x->LS), Recycle(x->RS);
}
inline void Split(Node* x, unsigned Left) {
  PsDw(x);
  if (x->LS->Size == Left) return;
  Node* Cur;
  if (x->LS->Size > Left) Split(Cur = x->LS, Left), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur;
  else Split(Cur = x->RS, Left - x->LS->Size), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur;
  Cur->PsUp();
}
inline void SPLIT(Node* x, Node*& L, Node*& R, unsigned Left) {
  if (!Left) { L = NULL, R = x; return; }
  if (Left == x->Size) { L = x, R = NULL; return; }
  Split(x, Left), L = x->LS, R = x->RS, * (++STop) = x;
}
inline Node* Merge(Node* L, Node* R) {
  if (!L) return R;
  if (!R) return L;
  Node* Cur(New());
  Cur->Chg = 0x3f3f3f3f, Cur->Flip = 0, Cur->LS = L, Cur->RS = R, Cur->PsUp(), Rotate(Cur);
  return Cur;
}
signed main() {
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD(), Build(N, n);
  for (unsigned i(1); i <= m; ++i) {
    // DFS(Root), putchar(0x0A);
    scanf("%s", Op);
    if (Op[2] == 'X') { printf("%d\n", Root->Sub); continue; }
    Node* Part1, * Part2, * Part3;
    if (Op[0] == 'I') {
      SPLIT(Root, Part1, Part3, RD()), Build(Part2 = New(), RD());
      Part1 = Merge(Part1, Part2), Root = Merge(Part1, Part3);
      continue;
    }
    SPLIT(Root, Part1, Part3, RD() - 1);
    SPLIT(Part3, Part2, Part3, RD());
    switch (Op[0]) {
    case 'D': {
      Recycle(Part2), Part2 = NULL;
      break;
    }
    case 'M': {
      if (Part2) Part2->Chg = RDsg(), Part2->Sub = Part2->Pre = Part2->Suf = max(Part2->Chg, (Part2->Sum = Part2->Chg * Part2->Size));
      else RDsg();
      break;
    }
    case 'R': {
      if (Part2) Part2->Flip ^= 1, swap(Part2->LS, Part2->RS), swap(Part2->Pre, Part2->Suf);
      break;
    }
    case 'G': {
      // printf("Parts %u %u %u\n", Part1 - N, Part2 - N, Part3 - N);
      // if (Part1) Details(Part1);
      // if (Part2) Details(Part2);
      // if (Part3) Details(Part3);
      printf("%d\n", Part2 ? (Part2->Sum) : 0);
      break;
    }
    }
    // printf("Parts %u %u\n", Part1 - N, Part3 - N);
    // if (Part1) Details(Part1);
    // if (Part3) Details(Part3);
    Part3 = Merge(Part2, Part3);
    Root = Merge(Part1, Part3);
  }
  return Wild_Donkey;
}
/*
9 8
2 -6 3 5 1 -5 -3 6 3
GET-SUM 5 4
MAX-SUM
INSERT 8 3 -5 7 2
DELETE 12 1
MAKE-SAME 3 3 2
REVERSE 3 6
MAX-SUM
GET-SUM 5 4
*/