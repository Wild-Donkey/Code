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
unsigned a[10005], m, n, Cnt(0), A, B, C, Pos, ActVal, ActDeep, t, Ans(0), Tmp(0);
char b[10005];
struct Node {
  Node *LS, *RS;
  unsigned Val, Dep;
}N[4000005], *Ver[200005], *CntN(N), *Found;
Node *Build(unsigned L, unsigned R) {
  register Node *x(++CntN);
  if(L ^ R) {
    register unsigned Mid((L + R) >> 1);
    x->LS = Build(L, Mid);
    x->RS = Build(Mid + 1, R);
  } else {
    x->Val = ++Cnt;
    x->Dep = 1;
  }
  return x;
}
void Chg(Node *x, Node *y, unsigned L, unsigned R) {
  if(L ^ R) {
    register unsigned Mid((L + R) >> 1);
    if(Pos <= Mid) {
      if(y->LS == x->LS) y->LS = ++CntN, y->LS->LS = x->LS->LS, y->LS->RS = x->LS->RS;
      Chg(x->LS, y->LS, L, Mid);
    } else {
      if(y->RS == x->RS) y->RS = ++CntN, y->RS->LS = x->RS->LS, y->RS->RS = x->RS->RS;
      Chg(x->RS, y->RS, Mid + 1, R);
    }
  } else {
    y->Val = ActVal;
    y->Dep = max(y->Dep, 1 + ActDeep);
  }
}
void Qry(Node *x, unsigned L, unsigned R) {
  if(L ^ R) {
    register unsigned Mid((L + R) >> 1);
    if(Pos <= Mid) Qry(x->LS, L, Mid);
    else Qry(x->RS, Mid + 1, R);
  } else Found = x;
}
unsigned Find(unsigned x, unsigned Version) {
  register unsigned y(x);
  Pos = y, Qry(Ver[Version], 1, n);
  while (y ^ Found->Val)
    y = Found->Val, Pos = y, Qry(Ver[Version], 1, n);
  Pos = x, ActVal = y, ActDeep = Found->Dep, Chg(Ver[Version - 1], Ver[Version], 1, n);
  return y;
}
int main() {
  n = RD(), m = RD();
  Ver[0] = Build(1, n);
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    switch (A) {
      case 1: {
        Ver[i] = ++CntN, Ver[i]->LS = Ver[i - 1]->LS, Ver[i]->RS = Ver[i - 1]->RS;
        Find(RD(), i), A = Found->Val, B = Found->Dep;
        Find(RD(), i);
        if(B < Found->Dep) Pos = A, ActVal = Found->Val, ActDeep = B;
        else ActVal = A, Pos = Found->Val, ActDeep = Found->Dep;
        Chg(Ver[i - 1], Ver[i], 1, n);
        break;
      } 
      case 2:{
        Ver[i] = Ver[RD()];
        break;
      }
      case 3:{
        Ver[i] = ++CntN, Ver[i]->LS = Ver[i - 1]->LS, Ver[i]->RS = Ver[i - 1]->RS;
        A = Find(RD(), i), B = Find(RD(), i);
        printf("%u\n", (A == B));
        break;
      }
    } 
  }
  return Wild_Donkey;
}

