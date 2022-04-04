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
unsigned Link[6005][2];
unsigned m, n, q;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0); 
struct Node {
  vector<Node*> E, Control;
  unsigned Bectrl;
  char Ava;
  inline void DFS() {
    Ava = 1;
    for (auto i:E) if(!(i->Ava)) i->DFS();
  }
}N[3005];
struct Tree {
  bitset<3005> Available, Accessible;
  vector <Tree*> Son;
  Tree *Fa[13];
  unsigned Dep;
  inline void Init() {
    for (unsigned i(0); Fa[i]; ++i) Fa[i + 1] = Fa[i]->Fa[i];
    for (auto i:Son) {
      i->Fa[0] = this, i->Dep = Dep + 1;
      i->Init();
    }
  }
  inline void DFS() {
    for (auto i:Son) i->DFS(), Available |= i->Available;
  }
}T[3005];
inline Tree* LCA(Tree* x, Tree* y) {
  if(x->Dep < y->Dep) swap(x, y);
  for (unsigned i(11); ~i; --i) if(x->Fa[i] && (x->Fa[i]->Dep >= y->Dep)) x = x->Fa[i];
  if(x == y) return x;
  for (unsigned i(11); ~i; --i) if(x->Fa[i] != y->Fa[i]) x = x->Fa[i], y = y->Fa[i];
  return x->Fa[0];
}
//  inline void Clr() {}
signed main() {
//  freopen("P7520_2.in", "r", stdin);
//  freopen("P7520.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), q = RD();
  for (unsigned i(1); i <= m; ++i)
    Link[i][0] = RD(), Link[i][1] = RD(), N[Link[i][0]].E.push_back(N + Link[i][1]);
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) N[j].Ava = 0;
    N[i].Ava = 1, N[1].DFS();
    for (unsigned j(1); j <= n; ++j) if(!(N[j].Ava))
      N[i].Control.push_back(N + j), ++(N[j].Bectrl);// printf("%u Ctrl %u\n", i, j);
  }
  for (unsigned i(2); i <= n; ++i) if(!(N[i].Bectrl)) T[1].Son.push_back(T + i);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Bectrl); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) for (auto j:N[i].Control)
    if(j->Bectrl == N[i].Bectrl + 1) T[i].Son.push_back(T + (j - N));
  T[1].Init();
  for (unsigned i(1); i <= n; ++i) if(T[i].Fa[1]) T[i].Fa[1]->Available[i] = 1;
  T[1].DFS();
  for (unsigned i(1); i <= n; ++i) N[i].E.clear();
  for (unsigned i(1); i <= m; ++i) if(T + (A = Link[i][0]) != T[B = Link[i][1]].Fa[0]) N[A].E.push_back(N + B);
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) N[j].Ava = 0;
    N[i].DFS();
    for (unsigned j(1); j <= n; ++j) if(N[j].Ava) T[i].Accessible[j] = 1;
  }
//  for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= n; ++j) putchar('0' + T[i].Available[j]); putchar(0x0A);}
//  for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= n; ++j) putchar('0' + T[i].Accessible[j]); putchar(0x0A);}
  for (unsigned i(1); i <= n; ++i) printf("%u ", T[i].Fa[0] - T); putchar(0x0A);
//  for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, T[i].Fa[0] - T); putchar(0x0A);
  Tree *Fr, *To, *L;
  for (unsigned i(1); i <= q; ++i) {
    Fr = T + RD(), To = T + RD(), L = LCA(Fr, To);
    if((L == To) || (L == To->Fa[0])) {printf("0\n"); continue;}
//    printf("%u %u\n", Fr - T, To - T);
    printf("%u\n", (To->Accessible & L->Available).count());
  }
//  }
  return Wild_Donkey;
}
/*
6 7 0
1 2
2 3
2 4
2 6
3 5
4 5
5 2
4 4 1
1 3
3 4
4 2
2 4
1 2
*/
