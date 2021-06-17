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
unsigned a[50005], m, n, Cnt(0), OpL, OpR, A, B, C, D, t, Tmp(0);
int Ans, OpVal, OpTmp;
struct SubNode {
  SubNode *LS, *RS;
  int Val, Ival;
  unsigned Size;
} SN[2000005], *CntSN(SN);
struct Node {
  Node *LS, *RS;
  SubNode *Root;
} N[100005], *CntN(N);
void Print(SubNode *x) {
  printf("Point %u\nLS %u RS %u\n%u [%u, %u]\n", x - SN, x->LS - SN, x->RS - SN,
         x->Size, x->Ival, x->Val);
  return;
}
void Rotate(SubNode *x) {
  x->Size = x->LS->Size + x->RS->Size;
  x->Ival = x->LS->Ival, x->Val = x->RS->Val;
  if (x->LS->Size * 3 < x->RS->Size) {
    register SubNode *Move(x->RS);
    x->RS = Move->RS;
    Move->RS = Move->LS;
    Move->LS = x->LS;
    x->LS = Move;
    Move->Ival = Move->LS->Ival, Move->Val = Move->RS->Val,
    Move->Size = Move->LS->Size + Move->RS->Size;
    return;
  }
  if (x->RS->Size * 3 < x->LS->Size) {
    register SubNode *Move(x->LS);
    x->LS = Move->LS;
    Move->LS = Move->RS;
    Move->RS = x->RS;
    x->RS = Move;
    Move->Ival = Move->LS->Ival, Move->Val = Move->RS->Val,
    Move->Size = Move->LS->Size + Move->RS->Size;
  }
}
SubNode *Insert(SubNode *x) {
  if (x->Size == 1) {
    SubNode *Fa(++CntSN);
    if (x->Val < OpVal) {
      Fa->LS = x;
      Fa->RS = ++CntSN;
    } else {
      Fa->RS = x;
      Fa->LS = ++CntSN;
    }
    CntSN->Val = CntSN->Ival = OpVal, CntSN->Size = 1;
    Fa->Size = 2;
    Fa->Ival = Fa->LS->Ival, Fa->Val = Fa->RS->Val;
    return Fa;
  }
  if (x->LS->Val < OpVal)
    x->RS = Insert(x->RS);
  else
    x->LS = Insert(x->LS);
  Rotate(x);
  return x;
}
SubNode *Delete(SubNode *x) {
  if (x->LS->Val < OpTmp) {
    if (x->RS->Size == 1) {
      if (x->RS->Val == OpTmp) {
        return x->LS;
      } else {
        return x;
      }
    }
    x->RS = Delete(x->RS);
  } else {
    if (x->LS->Size == 1) {
      if (x->LS->Val == OpTmp) {
        return x->RS;
      } else {
        return x;
      }
    }
    x->LS = Delete(x->LS);
  }
  Rotate(x);
  return x;
}
void SubRank(SubNode *x) {
  if (x->Size == 1) {
    if (x->Val < OpVal) ++Ans;
    return;
  }
  if (x->LS->Val < OpVal)
    Ans += x->LS->Size, SubRank(x->RS);
  else
    SubRank(x->LS);
}
void SubPre(SubNode *x) {
  if (x->Size == 1) {
    if (x->Val < OpVal) Ans = max(Ans, x->Val);
    return;
  }
  if (x->RS->Ival >= OpVal) {
    SubPre(x->LS);
  } else {
    SubPre(x->RS);
  }
}
void SubSuc(SubNode *x) {
  if (x->Size == 1) {
    if (x->Val > OpVal) Ans = min(Ans, x->Val);
    return;
  }
  if (x->LS->Val < OpVal) {
    SubSuc(x->RS);
  } else {
    SubSuc(x->LS);
  }
}
void Build(Node *x, unsigned L, unsigned R) {
  x->Root = ++CntSN;
  x->Root->Val = x->Root->Ival = a[L];
  x->Root->Size = 1;
  if (L == R) return;
  for (register unsigned i(L + 1); i <= R; ++i) {
    OpVal = a[i], x->Root = Insert(x->Root);
  }
  register unsigned Mid((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
}
void Change(Node *x, unsigned L, unsigned R) {
  x->Root = Insert(x->Root);
  x->Root = Delete(x->Root);
  if (L == R) {
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if (Mid < OpL) {
    Change(x->RS, Mid + 1, R);
  } else {
    Change(x->LS, L, Mid);
  }
  return;
}
void Rank(Node *x, unsigned L, unsigned R) {
  if (L >= OpL && R <= OpR) {
    SubRank(x->Root);
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if (OpL <= Mid) {
    Rank(x->LS, L, Mid);
  }
  if (Mid < OpR) {
    Rank(x->RS, Mid + 1, R);
  }
  return;
}
void Pre(Node *x, unsigned L, unsigned R) {
  if (L >= OpL && R <= OpR) {
    return SubPre(x->Root);
  }
  register unsigned Mid((L + R) >> 1);
  if (OpL <= Mid) {
    Pre(x->LS, L, Mid);
  }
  if (Mid < OpR) {
    Pre(x->RS, Mid + 1, R);
  }
}
void Suc(Node *x, unsigned L, unsigned R) {
  if (L >= OpL && R <= OpR) {
    return SubSuc(x->Root);
  }
  register unsigned Mid((L + R) >> 1);
  if (OpL <= Mid) {
    Suc(x->LS, L, Mid);
  }
  if (Mid < OpR) {
    Suc(x->RS, Mid + 1, R);
  }
}
void Find() {
  register int L(0), R(100000000), Mid;
  while (L < R) {
    Mid = ((L + R + 1) >> 1);
    Ans = 1, OpVal = Mid, Rank(N, 1, n);
    if (Ans > OpTmp)
      R = Mid - 1;
    else
      L = Mid;
  }
  Ans = L;
}
int main() {
  n = RD(), m = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  Build(N, 1, n);
  for (register unsigned i(1); i <= m; ++i) {
    A = RD();
    switch (A) {
      case 1: {
        OpL = RD(), OpR = RD(), OpVal = RD();
        Ans = 1, Rank(N, 1, n);
        break;
      }
      case 2: {
        OpL = RD(), OpR = RD(), OpTmp = RD();
        Find();
        break;
      }
      case 3: {
        OpL = RD();
        OpTmp = a[OpL];
        a[OpL] = OpVal = RD();
        Change(N, 1, n);
        break;
      }
      case 4: {
        OpL = RD(), OpR = RD(), OpVal = RD();
        Ans = -2147483647, Pre(N, 1, n);
        break;
      }
      case 5: {
        OpL = RD(), OpR = RD(), OpVal = RD();
        Ans = 2147483647, Suc(N, 1, n);
        break;
      }
    }
    if (A != 3) {
      printf("%d\n", Ans);
    }
  }
  return Wild_Donkey;
}
