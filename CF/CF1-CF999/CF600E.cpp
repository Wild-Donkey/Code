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
unsigned m, n, Cnt(0), A, B, t, Tmp(0);
struct Tr; 
struct Edge {
  Tr *To;
  Edge *Nxt;
}E[200005], *CntE(E);
struct Node {
  Node *LS, *RS;
  unsigned Val;
  unsigned long long Pos;
}N[4000005], *CntN(N);
struct Tr {
  Node *Seg;
  Edge *Fst;
  Tr *Fa;
}T[100005], *C, *D;
void Link(Tr *x, Tr *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
}
void Insert (Node *x, unsigned L, unsigned R) {
  x->Val = 1, x->Pos = A;
  if(L == R) return;
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) Insert(x->LS = ++CntN, L, Mid);
  else Insert(x->RS = ++CntN, Mid + 1, R);
}
void AddUp(Node *x, Node *y) {
//  printf("x %u L %u R %u    y %u L %u R %u\n", x - N, x->LS - N, x->RS - N, y - N, y->LS - N, y->RS - N);
  if(!((x->LS)||(x->RS)||(y->LS)||(y->RS))) {
    x->Val += y->Val;
//    printf("Leaf %u %u %u\n", x - N, x->Val, x->Pos);
    return;
  }
  if(x->LS && y->LS) {
    AddUp(x->LS, y->LS);
  } else {
    if(y->LS) {
      x->LS = y->LS;
    }
  }
  if(x->RS && y->RS) {
    AddUp(x->RS, y->RS);
  } else {
    if(y->RS) {
      x->RS = y->RS;
    }
  }
  if(x->LS && x->RS) {
    if(x->LS->Val == x->RS->Val) {
      x->Pos = x->LS->Pos + x->RS->Pos;
      x->Val = x->LS->Val;
    } else {
      if(x->LS->Val < x->RS->Val) {
        x->Val = x->RS->Val, x->Pos = x->RS->Pos;
      } else {
        x->Val = x->LS->Val, x->Pos = x->LS->Pos;
      }
    }
  } else {
    if(x->LS) {
      x->Val = x->LS->Val, x->Pos = x->LS->Pos;
    } else {
      x->Val = x->RS->Val, x->Pos = x->RS->Pos;
    }
  }
//  printf("%u L:%u R:%u %u %u\n", x - N, x->LS - N, x->RS - N, x->Val, x->Pos); 
}
void DFS(Tr *x) {
  Edge *Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa) {
      Sid->To->Fa = x;
      DFS(Sid->To);
//      printf("\n%u TO %u\n", x - T, Sid->To - T);
      AddUp(x->Seg, Sid->To->Seg);
    }
    Sid = Sid->Nxt;
  }
}
int main() {
//  freopen("CF600E.in", "r", stdin);
//  freopen("CF600E.out", "w", stdout);
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    A = RD();
    Insert(T[i].Seg = ++CntN, 1, n);
  }
  for (register unsigned i(1); i < n; ++i) {
    C = T + RD(), D = T + RD();
    Link(C, D), Link(D, C);
  }
  DFS(T + 1);
  for (register unsigned i(1); i <= n; ++i) {
    printf("%llu ", T[i].Seg->Pos);
  }
  putchar('\n');
  return Wild_Donkey;
}
/*
10
10 3 4 4 3 6 6 1 5 7 
2 1
3 1
4 2
5 4
6 1
7 1
8 7
9 5
10 6

13 3 4 12 8 13 7 1 5 7

*/
