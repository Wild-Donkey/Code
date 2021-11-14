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
unsigned a[200005], m, n, Cnt(0), A, B, C, D, t, Sum(0), Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val, Pos, Min;
}N[400005], *CntN(N);
inline void Clr() {
  n = RD(), Sum = 0, CntN = N, Cnt = 0;
}
void Udt(Node *x) {
  if(x->LS->Val <= x->RS->Val) {
    x->Val = x->LS->Val;
    x->Pos = x->LS->Pos;
  } else {
    x->Val = x->RS->Val;
    x->Pos = x->RS->Pos;
  }
}
void Build(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->LS = x->RS = NULL;
    x->Min = a[L], x->Pos = L, x->Val = 0x3f3f3f3f;
    return;
  }
  register unsigned Mid = ((L + R) >> 1);
  Build(x->LS = ++CntN, L, Mid);
  Build(x->RS = ++CntN, Mid + 1, R);
  x->Min = min(x->LS->Min, x->RS->Min);
  Udt(x);
}
void Chg(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->Val = B, x->Pos = A;
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) Chg(x->LS, L, Mid);
  else Chg(x->RS, Mid + 1, R);
  Udt(x);
}
void Chg2(Node *x, unsigned L, unsigned R) {
  if(L == R) {
    x->Min = a[A];
    return;
  }
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) Chg2(x->LS, L, Mid);
  else Chg2(x->RS, Mid + 1, R);
  x->Min = min(x->LS->Min, x->RS->Min);
}
void Add (unsigned x) {
//  printf("Add %u %u\n", x, a[x]);
  A = x;
  if(a[x] < 1000000) {
    B = 2000000 - a[x];
    if(x == 1) {
      if(a[n] > 1000000) B -= min(1000000 - a[x], a[n] - 1000000);
    } else {
      if(a[x - 1] > 1000000) B -= min(1000000 - a[x], a[x - 1] - 1000000);
    }
    if(x == n) {
      if(a[1] > 1000000) B -= min(1000000 - a[x], a[1] - 1000000);
    } else {
      if(a[x + 1] > 1000000) B -= min(1000000 - a[x], a[x + 1] - 1000000);
    }
    Chg(N, 1, n);
  } else {
    B = 0x3f3f3f3f;
    Chg(N, 1, n);
  }
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  while (1){
    Clr();
    if(!n) break;
    for (register unsigned i(1); i <= n; ++i) {
      Sum += (a[i] = (RDsg() + 1000000));
    }
    if(Sum <= (n * 1000000)) {
      printf("-1\n");
      continue;
    }
    Build(N, 1, n);
    if(N[0].Min >= 1000000) {
      printf("0\n");
      continue;
    }
    for (register unsigned i(1); i <= n; ++i) {
      Add(i);
    }
    register unsigned Now; 
    while (N[0].Min < 1000000) {
      ++Cnt;
      Now = N[0].Pos;
//      printf("Now %u %u %u\n", Cnt, Now, N[0].Min);
      if(Now == 1) {
        a[n] -= 1000000 - a[Now];
        A = n;
        Chg2(N, 1, n);
      } else {
        a[Now - 1] -= 1000000 - a[Now]; 
        A = Now - 1;
        Chg2(N, 1, n);
      }
      if(Now == n) {
        a[1] -= 1000000 - a[Now]; 
        A = 1;
        Chg2(N, 1, n);
      } else {
        a[Now + 1] -= 1000000 - a[Now];
        A = Now + 1;
        Chg2(N, 1, n);
      }
      a[Now] = 2000000 - a[Now];
      A = Now;
      Chg2(N, 1, n);
      Add(Now);
      if(Now == 1) Add(n);
      else Add(Now - 1);
      if(Now == n) Add(1);
      else Add(Now + 1); 
    }
    printf("%u\n", Cnt);
  }
  return Wild_Donkey;
}
/*
-1 2 -2 2: 3
-1 0 2 0: 1
1 -1 2 -1: 2
0 1 1 -1: 4
-1 1 0 1: 1
1 0 0 0


-1 2 -2 2: 1
1 1 -2 1: 3
1 -1 2 -1: 2
0 1 1 -1: 4
-1 1 0 1: 1
1 0 0 0

-1 -2 2 2
1 -3 2 1
-2 3 -1 1
-2 2 1 0
2 0 1 -2
0 0 -1 2
0 -1 1 1
-1 1 0 1
1 0 0 0

-1 -2 2 2
-3 2 0 2
3 -1 0 -1
2 1 -1 -1
1 1 -2 1
1 -1 2 -1
0 1 1 -1
-1 1 0 1
1 0 0 0
*/
