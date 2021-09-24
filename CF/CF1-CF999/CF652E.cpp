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
unsigned a[10005], m, n, M;
unsigned Cnt(0), A, B, C, D, t, Ans(0), Tmp(0);
char b[10005];
struct BCC {
  BCC* Son, * Bro;
}B[300005], *CntB(B);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Type;
}E[600005];
struct Node {
  Edge* Fst;
}N[300005];
void Tarjan(Node* x, Edge* No) {
  
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), M = m << 1;
  for (unsigned i(0); i < M; i += 2) {
    A = RD(), B = RD(), E[i ^ 1].Type = E[i].Type = RD();
    E[i].To = N + B, E[i].Nxt = N[A].Fst, N[A].Fst = E + i;
    E[i ^ 1].To = N + A, E[i ^ 1].Nxt = N[B].Fst, N[B].Fst = E + (i ^ 1);
  }
  A = RD(), B = RD();
  Tarjan(N + 1, No), DFS(CntB);
//  }
  return Wild_Donkey;
}

