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
unsigned m, n, PQ[2];
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned f[500005];
char PrSu(0); 
struct Node {
  vector<Node*> To;
  Node* Fa, * Heavy;
  unsigned long long BeLCA[2], Tra[2];
  unsigned Dep, DFSr;
}N[500005];
inline void PreDFS (Node* x) {
  for (auto i:x->To) if(i != x->Fa) {
    i->Fa = x, PreDFS(i);
    if(x->Dep < i->Dep) x->Dep = i->Dep, x->Heavy = i;
  }
  ++(x->Dep);
}
inline void CutDFS(Node* x) {
  x->DFSr = ++Cnt;
  if(!(x->Heavy)) return;
  CutDFS(x->Heavy);
  for (auto i:x->To) if((i != x->Fa) && (i != x->Heavy)) CutDFS(i);
}
inline void DFS(Node *x) {
  if(x->Heavy) {
    DFS(x->Heavy);
    for (auto i:x->To) if((i != x->Fa) && (i != x->Heavy)) {//BeLCA 
      DFS(x->Heavy);
      for (unsigned j(1); j < i->Dep; ++j) {
        if(j < PQ[0]) x->BeLCA[0] = (x->BeLCA[0] + f[i->DFSr + j - 1] * f[x->DFSr + PQ[0] - j]) % Mod;
        if(j < PQ[1]) x->BeLCA[1] = (x->BeLCA[1] + f[i->DFSr + j - 1] * f[x->DFSr + PQ[1] - j]) % Mod;
      }
      for (unsigned j(0); j < i->Dep; ++j) f[x->DFSr + j + 1] += f[i->DFSr + j];
    }
  }
  if(x->Dep > PQ[0]) {x->BeLCA[0] += f[x->DFSr + PQ[0]]; if(x->BeLCA[0] >= Mod) x->BeLCA[0] -= Mod;}
  if(x->Dep > PQ[1]) {x->BeLCA[1] += f[x->DFSr + PQ[1]]; if(x->BeLCA[1] >= Mod) x->BeLCA[1] -= Mod;}
  ++(f[x->DFSr]);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), PQ[0] = RD(), PQ[1] = RD();
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  PreDFS(N + 1), CutDFS(N + 1), DFS(N + 1), PrSu = 1, DFS(N + 1);
//  }
  return Wild_Donkey;
}

