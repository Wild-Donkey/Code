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
unsigned m, n, A, B, C, t, Ans(0);
int D;
struct Node {
  Node *LS, *RS;
  unsigned Cnt, Size;
  int Val, InVal;
}N[20000005], *Ver[500005], *CntN(N);
inline void Rotate(Node *x) {
//  printf("Rotate %u\n", x - N);
  if(x->Size > 4) {
    register Node *Tmp(++CntN);
    if(x->LS->Size * 3 < x->RS->Size) {
      Tmp->LS = x->LS;
      Tmp->RS = x->RS->LS;
      x->RS = x->RS->RS;
      x->LS = Tmp;
      Tmp->InVal = Tmp->LS->InVal;
      Tmp->Val = Tmp->RS->Val;
      Tmp->Size = Tmp->LS->Size + Tmp->RS->Size;
      Tmp->Cnt = Tmp->LS->Cnt + Tmp->RS->Cnt;
      return;
    }
    if(x->RS->Size * 3 < x->LS->Size) {
      Tmp->RS = x->RS;
      Tmp->LS = x->LS->RS;
      x->LS = x->LS->LS;
      x->RS = Tmp;
      Tmp->InVal = Tmp->LS->InVal;
      Tmp->Val = Tmp->RS->Val; 
      Tmp->Size = Tmp->LS->Size + Tmp->RS->Size;
      Tmp->Cnt = Tmp->LS->Cnt + Tmp->RS->Cnt;
      return;
    }
  }
}
void Insert(Node *x, Node *y) {
  y->Cnt = x->Cnt + 1;
  if(x->Val == x->InVal) {
    if(x->Val ^ D) {
      y->Size = 2;
      y->LS = ++CntN, y->RS = ++CntN;
      if(x->Val < D) {
        y->LS->InVal = y->LS->Val = x->Val;
        y->RS->InVal = y->RS->Val = D;
        y->RS->Cnt = 1;
        y->LS->Cnt = x->Cnt;
        y->Val = D;
        y->InVal = x->InVal;
      } else {
        y->RS->InVal = y->RS->Val = x->Val;
        y->LS->InVal = y->LS->Val = D;
        y->LS->Cnt = 1;
        y->RS->Cnt = x->Cnt;
        y->InVal = D;
        y->Val = x->Val;
      }
      y->LS->Size = y->RS->Size = 1;
    } else {
      y->Val = y->InVal = D, y->Size = 1;
    }
    return;
  }
  if(D <= x->LS->Val) {
    y->RS = x->RS;
    Insert(x->LS, y->LS = ++CntN);
    y->InVal = y->LS->InVal;
    y->Val = x->Val;
  } else {
    y->LS = x->LS;
    Insert(x->RS, y->RS = ++CntN);
    y->Val = y->RS->Val;
    y->InVal = x->InVal;
  }
  y->Size = y->LS->Size + y->RS->Size;
  Rotate(y);
}
Node *Delete (Node *x, Node *y)  {
//  printf("Delete %u [%d, %d]\n", x - N, x->InVal, x->Val);
  if(x->Val == x->InVal) {
    y->Cnt = x->Cnt;
    if(x->Val == D) {
      --(y->Cnt);
    }
    if(y->Cnt) {
      y->Val = y->InVal = x->Val;
      y->Size = 1;
      return y;
    } else {
      return NULL;
    }
  }
  if(D <= x->LS->Val) {
    y->LS = Delete(x->LS, ++CntN);
    if(!(y->LS)) {
      return x->RS;
    }
    y->RS = x->RS;
    y->InVal = y->LS->InVal;
    y->Val = x->Val;
  } else {
    y->RS = Delete(x->RS, ++CntN);
    if(!(y->RS)) {
      return x->LS;
    }
    y->LS = x->LS;
    y->Val = y->RS->Val;
    y->InVal = x->InVal;
  }
//  printf("%u LS %u RS %u\n", y - N, y->LS - N, y->RS - N);
  y->Size = y->LS->Size + y->RS->Size;
  y->Cnt = y->LS->Cnt + y->RS->Cnt;
  Rotate(y);
  return y;
}
void Find(Node *x) {
//  printf("Find %u [%d, %d] %u %u\n", x - N, x->InVal, x->Val, x->Size, x->Cnt);
  if(x->Size == 1) {
    if(x->Val < D) {
      Ans += x->Cnt;
    }
    return;
  }
  if(D > x->LS->Val) {
    Ans += x->LS->Cnt;
    Find(x->RS);
  } else {
    Find(x->LS);
  }
  return;
}
void Rank(Node *x) {
  if(x->Size == 1) {
    Ans = x->Val;
    return;
  }
  if(x->LS->Cnt < C) {
    C -= x->LS->Cnt;
    return Rank(x->RS);
  } else {
    return Rank(x->LS);
  }
}
int main() {
//  freopen("P3835_19.in", "r", stdin);
//  freopen("P3835.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  Ver[0] = N;
  N->Val = N->InVal = 0x3f3f3f3f;
  N->Cnt = N->Size = 1;
  for (register unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    switch (B){
      case (1):{
        D = RDsg();
        Insert(Ver[A], Ver[i] = ++CntN);
        break;
      }
      case (2):{
        D = RDsg();
        Ver[i] = Delete(Ver[A], ++CntN);
        break;
      }
      case (3):{
        D = RDsg();
        Ans = 1, Find(Ver[i] = Ver[A]);
        break;
      }
      case (4):{
        C = RD();
        Rank(Ver[i] = Ver[A]);
        break;
      }
      case (5):{
        D = RDsg();
        Ans = 0, Find(Ver[i] = Ver[A]);
        C = Ans, Rank(Ver[i]);
        break;
      }
      case (6):{
        D = RDsg();
        ++C, Ans = 1, Find(Ver[i] = Ver[A]);
        C = Ans, Rank(Ver[i]);
        break;
      }
    }
    if(B >= 3) {
      printf("%d\n", Ans);
    }
  }
//  }
  return Wild_Donkey;
}

