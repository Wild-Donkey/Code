#include <algorithm>
#include <bitset>
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
unsigned a[10005], m, n;
unsigned A, B, BL(1), BR, t;
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned f; 
  inline void PreDFS() {
    for (auto i:To) if(i != Fa) i->Fa = this, i->PreDFS();
  }
}N[300005], * Link[300005], * Fst, * Scd, * BltS;
inline void GetLine(Node* Cur) {
  while (Cur) Link[++Cnt] = Cur, Cur = Cur->Fa;
}
inline void DP(Node* x) {
//  printf("DP %u Blts %u\n", x - N, BltS - N);
  x->f = 0;
  unsigned CtS(0);
  vector<unsigned> Son;
  for (auto i:(x->To)) if((i != x->Fa) && (i != BltS))
    i->Fa = x, DP(i), Son.push_back(i->f);
  sort(Son.begin(), Son.end(), greater<unsigned>());
  for (unsigned i(Son.size() - 1); ~i; --i)
    x->f = max(x->f, i + Son[i] + 1);
//  printf("f %u = %u\n", x - N, x->f);
  return;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Fst = N + RD(), Scd = N + RD(); 
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  Fst->Fa = NULL, Fst->PreDFS();
  GetLine(Scd), BR = --Cnt, Scd->Fa = NULL;
  while (BL <= BR) {
    unsigned Mid((BL + BR) >> 1); 
    BltS = Link[Mid + 1], DP(Scd), BltS = Link[Mid], DP(Fst);
    Ans = min(Ans, max(Scd->f, Fst->f));
    if(Scd->f < Fst->f) {BL = Mid + 1; continue;}
    if(Scd->f > Fst->f) {BR = Mid - 1; continue;}
    break;
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

