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
unsigned a[10005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), Level(100000);
char Op[5];
struct Node {
  Node *LS, *RS;
  unsigned Val;
}N[600005], *CntN(N);
void Del (Node *x, unsigned L, unsigned R){
  x->Val = 0;
  if(L == R) return;
  register unsigned Mid((L + R) >> 1);
  if(x->LS) {
    if(x->LS->Val) Del(x->LS, L, Mid);
    x->Val += x->LS->Val; 
  }
  if(x->RS) {
    if(Mid < Level - 1) if(x->RS->Val) Del(x->RS, Mid + 1, R); 
    x->Val += x->RS->Val;
  }
}
void Chg(Node *x, unsigned L, unsigned R) {
  ++(x->Val);
  if(L == R) return;
  register unsigned Mid((L + R) >> 1);
  if(A <= Mid) {
    if(!(x->LS)) x->LS = ++CntN;
    Chg(x->LS, L, Mid);
  } else {
    if(!(x->RS)) x->RS = ++CntN; 
    Chg(x->RS, Mid + 1, R);
  }
}
void Qry(Node *x, unsigned L, unsigned R) {
  if(L == R) {B = L;return;}
  register unsigned Mid((L + R) >> 1);
  if(x->RS) {
    if(x->RS->Val >= A) return Qry(x->RS, Mid + 1, R);
    A -= x->RS->Val;
  }
  Qry(x->LS, L, Mid);
}
int main() {
  n = RD(), Level += (m = RD());
  for (register unsigned i(1); i <= n; ++i) {
    scanf("%s", &Op[1]), A = RD();
    switch (Op[1]) {
      case ('I') :{
        if(A >= m) {
          A += Level - m;
          ++Ans;
          Chg(N, 1, 300000);
        }
        break;
      }
      case ('A') :{
        Level -= A;
        break;
      }
      case ('S') :{
        Level += A;
        Del(N, 1, 300000);
        break;
      }
      case ('F') :{
        if(A > N->Val) {
          printf("-1\n");
          break;
        }
        Qry(N, 1, 300000);
        printf("%u\n", B - Level + m);
        break;
      }
    }
  }
  printf("%u\n", Ans - N->Val);
  return Wild_Donkey;
}


