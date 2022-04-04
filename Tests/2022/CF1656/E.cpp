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
#include <set>
#include <string>
#include <unordered_map>
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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> E;
  unsigned Dep;
  inline void DFS(Node* Fa) {
    for (auto i:E) if(i != Fa) i->Dep = Dep + 1, i->DFS(this);
    return;
  }
}N[100005];
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].E.clear();
  n = RD();
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i < n; ++i) 
      A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].E.push_back(N + A);
    N[1].Dep = 1, N[1].DFS(NULL);
    for (unsigned i(1); i <= n; ++i) printf("%d ", (N[i].Dep & 1) ? N[i].E.size() : (-N[i].E.size()));
    putchar(0x0A);
  }
  return Wild_Donkey;
}

