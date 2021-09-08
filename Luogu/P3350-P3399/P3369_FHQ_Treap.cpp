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
const unsigned Base(1000000009);
unsigned Seed(1000000007), m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, RVal, Size;
}N[2000005], *CntN(N);
inline unsigned Rand() {
  return Seed *= Base;
}
void Upd(Node *x) {
  x->Size = 1;
  if (x->LS) x->Size += x->LS->Size;
  if (x->RS) x->Size += x->RS->Size;
}
pair<Node*, Node*> Split (Node *x) {
//  printf("Split %u %u\n", x - N, x->Val);
  register pair<Node*, Node*> TmpP;
  if(x->Val > C) {
    if(x->LS) {
      TmpP = Split(x->LS);
      x->LS = TmpP.second;
      Upd(x);
      return make_pair(TmpP.first, x);
    } else {
      TmpP.first = NULL, TmpP.second = x;
      return TmpP;
    }
  } else {
    if(x->RS) {
      TmpP = Split(x->RS);
      x->RS = TmpP.first;
      Upd(x);
      return make_pair(x, TmpP.second);
    } else {
      TmpP.first = x, TmpP.second = NULL;
      return TmpP;
    }
  }
}
Node *Merge(Node *x, Node *y) {
//  printf("Merge %u %u\n", x - N, y - N);
  if(!x) return y;
  if(!y) return x;
//  printf("MergeVal %u %u\n", x->Val, y->Val); 
  if(x->RVal < y->RVal) {
    x->RS = Merge(x->RS, y);
    Upd(x);
    return x;
  } else {
    y->LS = Merge(x, y->LS);
    Upd(y);
    return y;
  }
}
void Insert() {
  C = B;
  register pair<Node*, Node*> TmpP(Split(N));
  register Node *LTr(TmpP.first), *RTr(TmpP.second), *Now(++CntN);
  Now->RVal = Rand(), Now->Val = B, Now->Size = 1; 
  Now = Merge(LTr, Now);
  Merge(Now, RTr);
}
void Delete() {
  C = B - 1;
  register pair<Node*, Node*> TmpP1(Split(N));
  C = B;
  register pair<Node*, Node*> TmpP2(Split(TmpP1.second));
  register Node *Now(TmpP2.first);
  if(Now) {
    Now = Merge(Now->LS, Now->RS);
    Now = Merge(TmpP1.first, Now);
  } else {
    Now = TmpP1.first;
  }
  Merge(Now, TmpP2.second);
}
void Rank() {
  register Node *now(N);
  while (now) {
//    printf("%u Rank %u\n", now->Val, D);
    if(now->Val < B) {
      if(now->LS) D += now->LS->Size;
      ++D;
      now = now->RS;
    } else { 
      now = now->LS;
    }
  }
}
void Find() {
//  printf("Find %u\n", B);
  register Node *now(N);
  while (now) {
//    printf("Now %u B %u\n", now - N, B);
    if(now->LS) {
      if(now->LS->Size < B) {
        B -= now->LS->Size;
      } else {
        now = now->LS;
        continue; 
      } 
    }
    if(B ^ 1) {
      --B, now = now->RS;
    } else {
      D = now->Val - 20000000;
      return;
    }
  }
}
int main() {
//  freopen("P3369_6.in", "r", stdin);
//  freopen("P3369.out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  m = RD();
  N[0].RVal = 0, N[0].Val = 0, N[0].Size = 0; 
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    B = RDsg() + 20000000;
    switch (A) {
      case (1) :{
        Insert();
        break;
      }
      case (2) :{
        Delete(); 
        break;
      }
      case (3) :{
        D = 0, Rank();
        break;
      }
      case (4) :{
        B -= 19999999; 
        Find();
        break;
      }
      case (5) :{
        D = 0, Rank();
        B = D, Find();
        break;
      }
      case (6) :{
        ++B, D = 1, Rank();
        B = D, Find();
        break;
      }
    }
    if(A >= 3) {
      printf("%d\n", D);
    } 
  }
//  }
  return Wild_Donkey;
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598

106465
84185
492737
*/
