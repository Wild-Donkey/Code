#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
unsigned long long Ans(0);
bitset<50005> States;
unsigned n, m, Cnt(0);
unsigned A, B, C, D, Dl, Dr;
unsigned Des[50005], *DTop(Des);
inline unsigned RD() {
  unsigned RTmp(0);
  char RChr(getchar());
  while ((RChr < '0') || (RChr > '9')) RChr = getchar();
  while ((RChr >= '0') && (RChr <= '9'))
    RTmp = (RTmp << 3) + (RTmp << 1) + RChr - 48, RChr = getchar();
  return RTmp;
}
struct Node {
  Node *LS, *RS;
  unsigned L, R, Size;
  inline void Udt() { L = LS->L, R = RS->R, Size = LS->Size + RS->Size; }
  inline Node* Rotate();
  inline void Find();
  inline void DFS();
  inline Node* Del(unsigned x);
  inline void Touch(unsigned x);
  inline Node* Insert();
} N[300005], *Root(N), *CntN(N), *Tcd;
inline void Node::DFS() {
  printf("%u Size %u LS %u RS %u\n", this - N, Size, LS - N, RS - N);
  if (!LS) printf("%u: [%u, %u]\n", this - N, L, R);
  if (LS) LS->DFS();
  if (RS) RS->DFS();
}
inline Node* Node::Rotate() {
  if ((!LS) && (!RS)) return this;
  if (!LS) return RS;
  if (!RS) return LS;
  Udt();
  if (Size <= 5) return this;
  Node* Cur;
  if (((LS->Size) << 2) < Size)
    Cur = RS, RS = Cur->RS, Cur->RS = Cur->LS, Cur->LS = LS, (LS = Cur)->Udt();
  if (((RS->Size) << 2) < Size)
    Cur = LS, LS = Cur->LS, Cur->LS = Cur->RS, Cur->RS = RS, (RS = Cur)->Udt();
  Udt();
  return this;
}
inline Node* Node::Del(unsigned x) {
  if (!LS) {
    Dl = L, Dr = R;
    return NULL;
  }
  if (LS->Size >= x) {
    LS = LS->Del(x);
    return Rotate();
  }
  RS = RS->Del(x - LS->Size);
  return Rotate();
}
inline Node* Node::Insert() {
  if (!LS) {
    if (L < A) swap(L, A), swap(R, B);
    (LS = ++CntN)->Size = 1, LS->L = A, LS->R = B;
    (RS = ++CntN)->Size = 1, RS->L = L, RS->R = R;
    Udt();
    return this;
  }
  if (LS->R < A) {
    RS = RS->Insert();
    return Rotate();
  }
  LS = LS->Insert();
  return Rotate();
}
inline void Node::Find() {
  if (!LS) {
    ++B;
    return;
  }
  if (LS->R < A) {
    B += LS->Size;
    return RS->Find();
  }
  return LS->Find();
}
inline void Node::Touch(unsigned x) {
  if (!LS) {
    Tcd = this;
    return;
  }
  if (LS->Size >= x)
    LS->Touch(x);
  else
    RS->Touch(x - LS->Size);
}
signed main() {
  // freopen("guizi0.in", "r", stdin);
  // freopen("guizi2.in", "r", stdin);
  n = RD(), m = RD();
  Root->L = 1, Root->R = n, Root->Size = 1;
  for (unsigned i(1); i <= m; ++i) {
    // printf("Before %u\n", i);
    // Root->DFS();
    char Op[2];
    scanf("%s", Op);
    if (Op[0] == 'R') {
      A = D = *(DTop--);
      B = 0, Root->Find(), Root->Touch(B);
      unsigned TmpA(D), TmpB(D);
      States[D] = 0;
      if ((D < n) && (!States[D + 1])) Root = Root->Del(B + 1), TmpB = Dr;
      Root = Root->Del(B);
      if ((D - 1) && (!States[D - 1])) Root = Root->Del(B - 1), TmpA = Dl;
      A = TmpA, B = TmpB;
      if (Root)
        Root = Root->Insert();
      else
        *(Root = ++CntN) = {NULL, NULL, A, B, 1};
    } else {
      A = D = RD();
      if (Op[0] == 'D') {
        States[D] = 1, A = *(++DTop) = D, B = 0, Root->Find(), Root->Touch(B);
        Dl = Tcd->L, Dr = Tcd->R, Tcd->L = Tcd->R = D;
        if (Dl < D) A = Dl, B = D - 1, Root = Root->Insert();
        if (D < Dr) A = D + 1, B = Dr, Root = Root->Insert();
      } else {
        if (States[D]) {
          printf("0\n");
          continue;
        }
        B = 0, Root->Find(), Root->Touch(B);
        printf("%u\n", Tcd->R - Tcd->L + 1);
      }
    }
  }
  return 0;
}
/*
g++ P1503_Ghost_into_Village.cpp -o faq -std=c++14 -O2 && faq
*/