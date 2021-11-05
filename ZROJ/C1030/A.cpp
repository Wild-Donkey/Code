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
unsigned Dist[2005][2005];
unsigned m, n, n2, NowD(0), Now(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans[2005], Tmp(0);
struct Node {
  vector <Node*> To;
  Node* Fa;
  unsigned Up[1005], Down[1005], Dep, Higt;
}N[2005];
inline void DownDFS(Node* x) {
  x->Down[0] = 1, x->Higt = 0;
  for (auto i:x->To) if(i != x->Fa) {
    i->Fa = x, i->Dep = x->Dep + 1, DownDFS(i), x->Higt = max(x->Higt, i->Higt + 1);
    for (unsigned j(min(i->Higt, n2 - 1)); ~j; --j) x->Down[j + 1] += i->Down[j];
  }
  for (unsigned j(min(x->Higt, n2)); ~j; --j) printf("%u Down %u = %u\n", x - N, j, x->Down[j]);
}
inline void UpDFS(Node* x) {
  for (auto i:x->To) if(i != x->Fa) {
    for (unsigned j(n2); j; --j) i->Up[j] += x->Up[j - 1] + x->Down[j - 1];
    for (unsigned j(n2); j > 1; --j) i->Up[j] -= i->Down[j - 2];
    for (unsigned j(n2); j; --j) printf("%u Up %u = %u\n", i - N, j, i->Up[j]);
    UpDFS(i);
  }
}
inline void DFS(Node* x) {
  
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n2 = ((n = RD()) + 1) >> 1;
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  N[1].Fa = NULL, N[1].Dep = 0, DownDFS(N + 1), UpDFS(N + 1);
  m = RD();
  for (unsigned i(1); i <= m; ++i) printf("%u\n", Ans[RD()]);
//  }
  return Wild_Donkey;
}
/*
5
1 3
3 2
3 4
2 5
4
4
3
2
1
*/
