#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp = 0;
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') {
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    intmp = intmp * 10 + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) {
    rdch = getchar();
  }
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = rdtp * 10 + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
unsigned a[10005], m, n, Cnt(0), A, C, D, t, Tmp(0);
int Ans, B;
struct Node {
  Node *LS, *RS;
  int Size, Value, InValue;
}N[200005], *CntN(N), *Root(N);
inline void Rotate(Node *x) {
  x->Size = x->LS->Size + x->RS->Size;
  x->InValue = x->LS->InValue, x->Value = x->RS->Value;
  if(x->LS->Size * 3 < x->RS->Size) {
    register Node *Move(x->RS);
    x->RS = Move->RS;
    Move->RS = Move->LS;
    Move->LS = x->LS;
    x->LS = Move;
    Move->Value = Move->RS->Value, Move->InValue = Move->LS->InValue;
    Move->Size = Move->LS->Size + Move->RS->Size;
    return;
  }
  if(x->RS->Size * 3 < x->LS->Size) {
    register Node *Move(x->LS);
    x->LS = Move->LS;
    Move->LS = Move->RS;
    Move->RS = x->RS;
    x->RS = Move;
    Move->Value = Move->RS->Value, Move->InValue = Move->LS->InValue;
    Move->Size = Move->LS->Size + Move->RS->Size; 
    return;
  }
}
Node *Insert(Node *x) {
  if(x->Size == 1) {
    register Node *Fa(++CntN);
    if(B > x->Value) Fa->LS = x, Fa->RS = ++CntN;
    else Fa->RS = x, Fa->LS = ++CntN;
    CntN->Value = CntN->InValue = B, CntN->Size = 1;
    Fa->Value = Fa->RS->Value, Fa->InValue = Fa->LS->InValue, Fa->Size = 2;
    return Fa;
  }
  if(x->LS->Value < B) x->RS = Insert(x->RS);
  else x->LS = Insert(x->LS);
  Rotate(x);
  return x;
}
Node *Delete(Node *x) {
  if(x->Size == 1) return x;
  if(x->LS->Value < B) {
    if(x->RS->Size == 1) {
      if(x->RS->Value == B) return x->LS;
      else return x;
    } else x->RS = Delete(x->RS);
  } else {
    if(x->LS->Size == 1) {
      if(x->LS->Value == B) return x->RS;
      else return x;
    } else x->LS = Delete(x->LS);
  }
  Rotate(x);
  return x;
}
void Rank (Node *x) {
  if(x->Size == 1) {if(x->Value < B) ++Ans;return;}
  if(x->LS->Value < B) Ans += x->LS->Size, Rank(x->RS);
  else Rank(x->LS);
}
void Find(Node *x) {
  if(x->Size == 1) {Ans = x->Value;return;}
  if(x->LS->Size < B) B -= x->LS->Size, Find(x->RS);
  else Find(x->LS);
}
void Pre/*Predecessor*/(Node *x) {
  if(x->Size == 1) {Ans = x->Value;return;}
  if(x->RS->InValue > B) Pre(x->LS);
  else Pre(x->RS);
}
void Suc/*Successor*/(Node *x) {
  if(x->Size == 1) {Ans = x->Value;return;}
  if(x->LS->Value < B) Suc(x->RS);
  else Suc(x->LS);
}
int main() {
  n = RD();
  N[0].Value = N[0].InValue = 0x3f3f3f3f, N[0].Size = 1;  
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    B = RDsg();
    switch(A) {
      case 1:{Root = Insert(Root); break;}
      case 2:{Root = Delete(Root);break;}
      case 3:{Ans = 1, Rank(Root);break;}
      case 4:{Find(Root);break;}
      case 5:{--B, Pre(Root);break;}
      case 6:{++B, Suc(Root);break;}
    }
    if(A >= 3) printf("%d\n", Ans);
  }
  return Wild_Donkey;
}
