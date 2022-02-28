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
unsigned Stack[1000005], * STop(Stack);
char Op[10];
struct Node {
  unsigned Size, LS, RS;
  int Sum, Sub, Pre, Suf, Chg;
  char Flip;
}N[1000005], * Root(N);
inline unsigned New() {
  if (STop != Stack) return *(STop--);
  return ++Cnt;
}
inline void PsUp(Node* x) {
  x->Size = N[x->LS].Size + N[x->RS].Size;
  x->Sum = N[x->LS].Sum + N[x->RS].Sum;
  x->Pre = max(N[x->LS].Pre, N[x->LS].Sum + N[x->RS].Pre);
  x->Suf = max(N[x->RS].Suf, N[x->RS].Sum + N[x->LS].Suf);
  x->Sub = max(max(N[x->LS].Sub, N[x->RS].Sub), N[x->LS].Suf + N[x->RS].Pre);
}
inline void Build(Node* x, unsigned y) {
  x->Chg = 0x3f3f3f3f, x->Flip = 0;
  if (y == 1) { x->Size = 1, x->Sub = x->Pre = x->Suf = x->Sum = RDsg(), x->LS = x->RS = 0x3f3f3f3f; return; }
  unsigned Mid(y >> 1);
  Build(N + (x->LS = New()), Mid);
  Build(N + (x->RS = New()), y - Mid);
  PsUp(x);
}
inline void PsDw(Node* x) {
  // printf("FAQ %u %u %u\n", x - N, x->LS, x->RS);
  if (x->LS >= 0x3f3f3f3f) return;
  if ((x->Chg) ^ 0x3f3f3f3f) {
    N[x->LS].Chg = N[x->RS].Chg = x->Chg;
    N[x->LS].Sub = N[x->LS].Pre = N[x->LS].Suf = max(x->Chg, N[x->LS].Sum = N[x->LS].Size * x->Chg);
    N[x->RS].Sub = N[x->RS].Pre = N[x->RS].Suf = max(x->Chg, N[x->RS].Sum = N[x->RS].Size * x->Chg);
    x->Flip = 0, x->Chg = 0x3f3f3f3f;
  }
  if (x->Flip) {
    N[x->LS].Flip ^= 1, N[x->RS].Flip ^= 1;
    swap(N[x->LS].LS, N[x->LS].RS);
    swap(N[x->LS].Pre, N[x->LS].Suf);
    swap(N[x->RS].LS, N[x->RS].RS);
    swap(N[x->RS].Pre, N[x->RS].Suf);
    x->Flip = 0;
  }
}
inline Node* Rotate(Node* x) {
  if (x->LS >= 0x3f3f3f3f) return x;
  PsDw(x);
  if (x->Size <= 5) return x;
  if (N[x->LS].Size >= (N[x->RS].Size << 1)) {
    Node* Cur(N + x->LS);
    PsDw(Cur), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur - N, PsUp(Cur);
  }
  if (N[x->RS].Size >= (N[x->LS].Size << 1)) {
    Node* Cur(N + x->RS);
    PsDw(Cur), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur - N, PsUp(Cur);
  }
  return x;
}
inline void Recycle(unsigned x) {
  // printf("Recycle %u\n", x);
  *(++STop) = x;
  if (N[x].LS < 0x3f3f3f3f) Recycle(N[x].LS), Recycle(N[x].RS);
}
inline void Split(Node* x, unsigned Left) {
  PsDw(x);
  if (N[x->LS].Size == Left) return;
  Node* Cur;
  if (N[x->LS].Size > Left) Split(Cur = N + x->LS, Left), x->LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = x->RS, x->RS = Cur - N;
  else Split(Cur = N + x->RS, Left - N[x->LS].Size), x->RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = x->LS, x->LS = Cur - N;
  PsUp(Cur);
}
inline void SPLIT(Node* x, Node*& L, Node*& R, unsigned Left) {
  if (!Left) { L = NULL, R = x; return; }
  if (Left == x->Size) { L = x, R = NULL; return; }
  Split(x, Left), L = N + x->LS, R = N + x->RS, * (++STop) = x - N;
}
inline Node* Merge(unsigned L, unsigned R) {
  if (L >= 0x3f3f3f3f) return N + R;
  if (R >= 0x3f3f3f3f) return N + L;
  Node* Cur(N + New());
  Cur->Chg = 0x3f3f3f3f, Cur->Flip = 0, Cur->LS = L, Cur->RS = R, PsUp(Cur), Rotate(Cur);
  return Cur;
}
signed main() {
  // freopen("P2042_3.in", "r", stdin);
  // freopen("P2042.out", "w", stdout);
  //  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), Build(N, n);
  for (unsigned i(1); i <= m; ++i) {
    // for (unsigned j(0); j <= Cnt; ++j) printf("%u (%u, %u)\n", j, N[j].LS, N[j].RS);
    scanf("%s", Op);
    if (Op[2] == 'X') { printf("%d\n", Root->Sub); continue; }
    Node* Part1, * Part2, * Part3;
    if (Op[0] == 'I') {
      SPLIT(Root, Part1, Part3, RD()), Build(Part2 = N + New(), RD());
      Part1 = Merge(Part1 - N, Part2 - N), Root = Merge(Part1 - N, Part3 - N);
      continue;
    }
    SPLIT(Root, Part1, Part3, RD() - 1);
    SPLIT(Part3, Part2, Part3, RD());
    switch (Op[0]) {
    case 'D': {
      if (Part2) Recycle(Part2 - N), Part2 = NULL;
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
      printf("%d\n", Part2 ? (Part2->Sum) : 0);
      break;
    }
    }
    Part3 = Merge(Part2 - N, Part3 - N);
    Root = Merge(Part1 - N, Part3 - N);
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