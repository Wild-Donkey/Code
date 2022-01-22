#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') rdsg = -1, rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0', rdch = getchar();
  return rdtp * rdsg;
}
unsigned long long Cnt(0), a[10005], m, n;
unsigned A, B, C, D, t;
unsigned  Ans(0), Tmp(0);
struct Node {
  unsigned Dep;
  unsigned long long Val;
  inline const char operator < (const Node& x)const {return Val > x.Val;}
}N[105];
struct Tr {
  Tr* LS, * RS;
  unsigned Dep;
  unsigned long long Val;
}Tree[205], * CntT(Tree);
priority_queue <Node> Hu;
inline void Clr() {
  n = RD(), m = RD(), Cnt = Ans = 0;
  CntT = Tree + n;
}
inline void DFS(Tr* x) {
  if(x->LS) {
    x->LS->Dep = x->Dep + 1;
    x->RS->Dep = x->Dep + 1;
    DFS(x->LS), DFS(x->RS);
  } else {
    if(x->Dep < m) Hu.push((Node){x->Dep, x->Val});
  }
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  for (unsigned T(1); ; ++T){
    Clr();
    if(!(n | m)) break;
    for (unsigned i(1); i <= n; ++i) a[i] = RD();
    unsigned BL(1), BR(n), BMid; 
    while (BL ^ BR) {
      BMid = (BL + BR) >> 1;
      for (unsigned i(BMid); i <= n; ++i) Hu.push((Node){1, a[i]});
      Cnt = 0;
      while (Hu.size() > 1) {
        A = Hu.top().Val, B = Hu.top().Dep, Hu.pop();
        A += Hu.top().Val, B = max(B, Hu.top().Dep), Hu.pop();
        Cnt += A, Hu.push((Node){B + 1, A});
      }
      if(Hu.top().Dep <= m + 1) BR = BMid;
      else BL = BMid + 1;
      Hu.pop();
    }
//    printf("BL %u\n", BL);
    memset(Tree, 0, sizeof(Tree));
    for (unsigned i(BL); i <= n; ++i) Hu.push((Node){i, a[i]});
    for (unsigned i(1); i <= n; ++i) Tree[i].Val = a[i];
    Cnt = 0;
    while (Hu.size() > 1) {
      Tr* Cur(++CntT);
      Cur->Val = Hu.top().Val, Cur->LS = Tree + Hu.top().Dep, Hu.pop();
      Cur->Val += Hu.top().Val, Cur->RS = Tree + Hu.top().Dep, Hu.pop();
      Cnt += Cur->Val, Hu.push((Node){Cur - Tree, Cur->Val});
    }
//    printf("Cnt %llu\n", Cnt);
    Tr* Root(Tree + Hu.top().Dep);
    Root->Dep = 0, Hu.pop(), DFS(Root);
    for (unsigned i(BL - 1); i; --i) {
      Node Cur(Hu.top());
      Hu.pop();
//      printf("Cur %u %llu\n", Cur.Dep, Cur.Val);
      Cnt += a[i] * (Cur.Dep + 1) + Cur.Val;
      ++(Cur.Dep);
      if(Cur.Dep < m) {
        Hu.push((Node){Cur.Dep, a[i]});
        Hu.push(Cur);
      }
    }
    printf("%llu\n", Cnt);
  }
  //  system("pause");
  return Wild_Donkey;
}

