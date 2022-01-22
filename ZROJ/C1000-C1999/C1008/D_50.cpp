#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
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
unsigned m, n, k, q;
unsigned V, p, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
char Flg(0);
multiset <unsigned> Have;
struct Node {
  vector<Node*> To;
  Node* Fa;
  unsigned A, B;
  char Ava, Vis;
}N[100005];
//  inline void Clr() {}
inline void DFS(Node* x) {
//  printf("DFS %u\n", x - N)
  x->Vis = 1;
  if(!(x->Ava)) Have.insert(x->B);
  else Flg = 1;
  for (auto i:x->To) if((!(i->Vis)) && (V >= i->A)) DFS(i);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), k = RD();
  for (unsigned i(1); i <= n; ++i) N[i].A = RD();
  for (unsigned i(1); i <= n; ++i) N[i].B = RD();
  for (unsigned i(1); i <= m; ++i) {
    C = RD(), D = RD();
    N[C].To.push_back(N + D);
    N[D].To.push_back(N + C);
  }
  q = RD();
  for (unsigned i(1); i <= q; ++i) {
    V = RD(), p = RD(), Ans = 0;
    for (unsigned j(1); j <= n; ++j) N[j].Ava = N[j].Vis = 0;
    for (unsigned j(1); j <= p; ++j) N[RD()].Ava = 1;
    for (unsigned j(1); j <= n; ++j) if((!N[j].Vis) && (V >= N[j].A)) {
      Have.clear(), Flg = 0, DFS(N + j), Cnt = 0;
      if(Flg) continue;
      unsigned Last(0);
      for (auto l:Have) {
        if(l != Last) {
          if(!(Have.count(l) % k)) ++Cnt;
//          printf("Have %u\n", Have.count(l));
        }
        Last = l; 
      }
      Ans = max(Cnt, Ans);
    }
    printf("%u\n", Ans);
  }
//  }
  return Wild_Donkey;
}

