#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
using namespace std;
inline int RD() {
  int intmp = 0, insign = 1;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    if (rdch == '-') {
      insign = -1;
    }
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp * insign;
}
int m, n, A, B;
struct Node {
  unsigned Siz, Val;
  Node *LS, *RS;
  bool Tag;
  inline void PsDw() {
    if (Tag) {
      if (LS) LS->Tag ^= 1;
      if (RS) RS->Tag ^= 1;
      swap(LS, RS);
      Tag = 0;
    }
    return;
  }
  inline void Clr() {
    LS = RS = NULL;
    Siz = Val = Tag = 0;
  }
}N[300005], * Stack[300005], **STop(Stack), *Rot(N);
inline void Bld(Node* x, const unsigned L, const unsigned R) {
  x->Siz = R - L + 1;
  if(L == R) {x->Val = L; return;}
  unsigned Mid((L + R) >> 1);
  Bld(x->LS = *(STop--), L, Mid);
  Bld(x->RS = *(STop--), Mid + 1, R);
}
inline Node* Rotate(Node *x) {
//  printf("Rotate %u\n", x - N);
  x->PsDw();
  if(!(x->LS || x->RS)) return x;
  if(!(x->LS)) {*(++STop) = x, putchar('!'); return Rotate(x->RS);}
  if(!(x->RS)) {*(++STop) = x, putchar('!'); return Rotate(x->LS);}
  if(x->Siz <= 5) return x;
  if((x->LS->Siz << 2) < x->Siz) {
    Node* Cur(x->RS);
    Cur = Rotate(Cur);
    x->RS = Cur->RS;
    Cur->RS = Cur->LS;
    Cur->LS = x->LS;
    x->LS = Cur;
    Cur->Siz = Cur->LS->Siz + Cur->RS->Siz;
  }
  if((x->RS->Siz << 2) < x->Siz) {
    Node* Cur(x->LS);
    Cur = Rotate(Cur);
    x->LS = Cur->LS;
    Cur->LS = Cur->RS;
    Cur->RS = x->RS;
    x->RS = Cur;
    Cur->Siz = Cur->LS->Siz + Cur->RS->Siz;
  }
  return x;
}
inline void Split(Node* x, Node*& SuL, Node*& SuR) {
  if(!A) {SuR = x;return;}
//  printf("Split %u, %u in %u\n", x - N, A, x->Siz);
  x->PsDw();
  if(x->LS) {
    if(x->LS->Siz <= A) {
      (SuL = *(STop--))->Clr(), SuL->LS = x->LS;
      A -= x->LS->Siz, Split(x->RS, SuL->RS, SuR);
    } else {
      (SuR = *(STop--))->Clr(), SuR->RS = x->RS;
      Split(x->LS, SuL, SuR->LS);
    }
  } else Split(x->RS, SuL, SuR);
  *(++STop) = x;
  if(SuL) {
    if(SuL->LS || SuL->RS) {
      if(!(SuL->LS)) *(++STop) = SuL, SuL = SuL->RS;
      else {
        if(!(SuL->RS)) *(++STop) = SuL, SuL = SuL->LS;
        else SuL->Siz = SuL->LS->Siz + SuL->RS->Siz;
      }
    }
  }
  if(SuR) {
    if(SuR->LS || SuR->RS) {
      if(!(SuR->LS)) *(++STop) = SuR, SuR = SuR->RS, putchar('!');
      else {
        if(!(SuR->RS)) *(++STop) = SuR, SuR = SuR->LS, putchar('!');
        else SuR->Siz = SuR->LS->Siz + SuR->RS->Siz;
      }
    }
  }
}
inline Node* Merge(Node* x, Node* y) {
  if(!x) return y;
  if(!y) return x;
  Node* Cur(*(STop--));
  Cur->Clr();
  Cur->Siz = x->Siz + y->Siz;
  Cur->LS = x, Cur->RS = y;
  return Rotate(Cur);
}
void Prt(Node *x) {
  if(x->Siz == 1) {if((x->Val) && (x->Val <= n)) printf("%d ", x->Val); return;}
  x->PsDw();
  if (x->LS) Prt(x->LS), Prt(x->RS);
}
int main() {
//  freopen("P3391_4.in", "r", stdin);
//  freopen("P3391.out", "w", stdout);
  n = RD(), m = RD();
  for (unsigned i(300004); i; --i) *(++STop) = N + i;
  Bld(Rot = N, 0, n + 1);
  for (register int i(1); i <= m; ++i) {
    A = RD(), B = RD() - A + 1;
    if (B <= 1) continue;
    Node* Le(NULL), * Ri(NULL), * Mi(NULL),* TmpR(NULL);
    Split(Rot, Le, Ri), A = B, Split(Ri, Mi, TmpR);
    Mi->Tag ^= 1;
    Rot = Merge(Le, Mi);
    Rot = Merge(Rot, TmpR);
  }
  Prt(Rot);
  // system("pause");
  return 0;
}
/*
100 4
6 9
4 8
2 9
3 5
*/
