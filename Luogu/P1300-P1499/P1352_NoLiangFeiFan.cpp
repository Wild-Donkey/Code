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
struct Node {
  vector<Node*> Son;
  Node* Fa;
  int Val, f[2];
}N[6005], * Root(N + 1);
inline void DFS(Node* x) {
  x->f[1] = x->Val, x->f[0] = 0;
  for (auto i:x->Son)
    DFS(i), x->f[0] += max(i->f[0], i->f[1]), x->f[1] += i->f[0];
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Val = RDsg();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[B].Son.push_back(N + A);
    N[A].Fa = N + B;
  }
  while (Root->Fa) Root = Root->Fa;
  DFS(Root);
  printf("%d\n", max(Root->f[0], Root->f[1]));
//  }
  return Wild_Donkey;
}

