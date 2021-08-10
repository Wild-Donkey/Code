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
unsigned a[1000005],b[1000005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
struct Node {
  Node *LS, *RS;
  unsigned Val;
}N[40000005], *Order[1000005], *CntN(N);
void Add(Node *x, Node *y, unsigned L, unsigned R) {
//  printf("[%u, %u] %u %u\n", L, R, x - N, y - N);
  if(!x) {
    y->Val = 1;
    if (L == R) return;
    register unsigned Mid((L + R) >> 1);
    if(Mid >= A) {
      Add(NULL, y->LS = ++CntN, L, Mid);
    } else {
      Add(NULL, y->RS = ++CntN, Mid + 1, R);
    }
    return;
  }
  y->Val = x->Val + 1; 
  if(L == R) return;
  register unsigned Mid((L + R) >> 1);
  if(Mid >= A) {
    if(!y->LS) y->LS = ++CntN; 
    Add(x->LS, y->LS, L, Mid);
    y->RS = x->RS;
  } else {
    if(!y->RS) y->RS = ++CntN; 
    Add(x->RS, y->RS, Mid + 1, R);
    y->LS = x->LS;
  }
}
void Qry(Node *x, unsigned L, unsigned R){
//  printf("[%u, %u] Sons: [%u, %u] Qry %u Val %u\n", L, R, x->LS - N, x->RS - N, x - N, x->Val);
  if((A <= L) && (R <= B)) {
    Tmp += x->Val; return;
  }
  register unsigned Mid((L + R) >> 1);
  if ((A <= Mid) && (x->LS)) {
    Qry(x->LS, L, Mid);
  }
  if ((Mid < B) && (x->RS)) {
    Qry(x->RS, Mid + 1, R); 
  }
}
inline unsigned F(unsigned x) {
  return ((x - 1 + Ans) % n) + 1;
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (register unsigned i(1); i <= n; ++i) {
    a[RD()] = i;
  }
  for (register unsigned i(1); i <= n; ++i) {
    b[a[RD()]] = i;
  }
  Order[0] = N;
  for (register unsigned i(1); i <= n; ++i) {
    A = b[i], Add(Order[i - 1], Order[i] = ++CntN, 1, n);
  }
  m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    C = F(RD()), D = F(RD()), A = F(RD()), B = F(RD());
    if(C > D) swap(C, D); 
    if(A > B) swap(A, B);
    Tmp = 0, Qry(Order[D], 1, n);
    Ans = Tmp, Tmp = 0, Qry(Order[C - 1], 1, n);
    printf("%u\n", Ans = Ans - Tmp);
    ++Ans;
  }
//  }
  return Wild_Donkey;
}

