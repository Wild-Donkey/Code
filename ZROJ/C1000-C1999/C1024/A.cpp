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
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char IOC[5];
struct Node {
  vector<Node*> To;
  unsigned Len, Dep;
}N[1000005], * CntN (N);
struct PreN {
  vector<PreN*> To;
  Node* Bel;
  PreN* Fa;
  char Col, Vis;
}PN[1000005];
inline void PDFS(PreN* x) {
  for (auto i:x->To) if(i != x->Fa) {
    if(i->Col ^ x->Col) i->Bel = ++CntN, x->Bel->To.push_back(CntN);
    else i->Bel = x->Bel;
    i->Fa = x, PDFS(i);
  }
}
inline void DFS(Node* x) {
  for (auto i:x->To) {
    DFS(i);
    x->Len = max(x->Len, x->Dep + i->Dep + 1);
    x->Len = max(x->Len, i->Len);
    x->Dep = max(x->Dep, i->Dep + 1);
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) scanf("%s", IOC), PN[i].Col = (IOC[0] ^ 'R') ? 1 : 0;
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    PN[A].To.push_back(PN + B);
    PN[B].To.push_back(PN + A);
  }
  PN[1].Bel = CntN, PDFS(PN + 1), DFS(N);
  printf("%u\n", (N->Len + 1) >> 1);
//  }
  return Wild_Donkey;
}
/*

*/
