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
unsigned a[100005], m, n, Cnt(0), A, B, C, D, t, Ans(0), Tmp(0), CQPos, CQVal, Len, Ty;
char Flg(0);
inline void Clr() {}
struct Node{
  Node *LS, *RS, *Val;
}N[1700005], Ver[100005], *CntN(N);
void Chg(Node *x, unsigned L, unsigned R) {
  if(L == R) {x->Val = Ver + CQVal; return;}
  unsigned Mid((L + R) >> 1);
  if(CQPos <= Mid) {
    ++CntN;
    if(x->LS) CntN->LS = x->LS->LS, CntN->RS = x->LS->RS;
    x->LS = CntN;
    Chg(x->LS, L, Mid);
  } else {
    ++CntN;
    if(x->RS) CntN->LS = x->RS->LS, CntN->RS = x->RS->RS;
    x->RS = CntN;
    Chg(x->RS, Mid + 1, R);
  }
}
Node *Qry(Node *x, unsigned L, unsigned R) {
  if(L == R) {return x->Val;}
  unsigned Mid((L + R) >> 1);
  if(CQPos <= Mid) {if(x->LS) return Qry(x->LS, L, Mid);}
  else if(x->RS) return Qry(x->RS, Mid + 1, R);
  return NULL;
}
int main() {
  Ty = RD(), n = RD(), t = RD(),   m = RD();
  for (register unsigned i(1); i <= n; ++i) a[i] = RD();
  for (register unsigned i(n - 1); i < 0x3f3f3f3f; --i) {
    Ver[i].LS = Ver[i + 1].LS, Ver[i].RS = Ver[i + 1].RS;// 继承上一个 
    CQPos = a[i + 1], CQVal = i + 1;
    Chg(Ver + i, 1, m);  // 后一个节点有到它自己后继的转移, 删除, 设为它自己
  }
  for (register unsigned i(1); i <= t; ++i) {
    Len = RD(), Flg = 0;
    register Node *Now(Ver);
    for (register unsigned j(1); j <= Len; ++j) {
      if(Flg) RD();
      else {
        CQPos = RD();
        Now = Qry(Now, 1, m);
        if(!Now) Flg = 1;
      }
    }
    printf(Flg ? "No\n" : "Yes\n");
  }
  return Wild_Donkey;
}
