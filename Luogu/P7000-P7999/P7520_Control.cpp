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
unsigned m, n, q;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> E, IE, Control;
  unsigned Bectrl;
  char Ava;
  inline void DFS() {
    Ava = 1;
    for (auto i:E) if(!(i->Ava)) i->DFS();
  }
  inline void IDFS() {
    Ava = 1;
    for (auto i:IE) if(!(i->Ava)) i->IDFS();
  }
}N[3005];
struct Tree {
  bitset<3005> Available;
  vector <Tree*> Son;
  Tree *Fa;
  unsigned DFN, Size;
  char Ava;
  inline void Init() {
    DFN = ++Cnt, Size = 1;
    for (auto i:Son) i->Fa = this, i->Init(), Size += i->Size;
  }
}T[3005];
//  inline void Clr() {}
signed main() {
//  freopen("P7520_3.in", "r", stdin);
//  freopen("P7520.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), q = RD();
  for (unsigned i(1); i <= m; ++i)
    A = RD(), B = RD(), N[A].E.push_back(N + B), N[B].IE.push_back(N + A);
  for (unsigned i(2); i <= n; ++i) N[1].Control.push_back(N + i), ++(N[i].Bectrl);
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) N[j].Ava = 0;
    N[i].Ava = 1, N[1].DFS();
    for (unsigned j(1); j <= n; ++j) if(!(N[j].Ava))
      N[i].Control.push_back(N + j), ++(N[j].Bectrl);// printf("%u Ctrl %u\n", i, j);
  }
//  for (unsigned i(1); i <= n; ++i) printf("%u ", N[i].Bectrl); putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) for (auto j:N[i].Control)
    if(j->Bectrl == N[i].Bectrl + 1) T[i].Son.push_back(T + (j - N));// printf("%u -> %u\n", j - N, i);
  T[1].Init();
//  for (unsigned i(1); i <= n; ++i) printf("%u %u\n", i, T[i].Fa[0] - T); putchar(0x0A);
//  for (unsigned i(1); i <= n; ++i) printf("%u ", T[i].Fa - T); putchar(0x0A);
  for (unsigned i(2); i <= n; ++i) {
    for (unsigned j(1); j <= n; ++j) N[j].Ava = 0;
    N[T[i].Fa - T].Ava = 1, N[i].IDFS(), N[T[i].Fa - T].Ava = 0;
    for (unsigned j(1); j <= n; ++j) if(N[j].Ava) T[j].Available[i] = 1;
  }
//  for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= n; ++j) putchar('0' + T[i].Available[j]); putchar(0x0A);}
  int Delta[3005];
  for (unsigned i(1); i <= q; ++i) {
    Tree *Fr(T + RD()), *To(T + RD()), *TmpF(Fr);
    while (Fr) Fr->Ava = 1, Fr = Fr->Fa;
    memset(Delta, 0, (n + 1) << 2), Ans = 0;
    for (unsigned i(2); i <= n; ++i) if(To->Available[i] && (!(T[i].Fa->Ava))) ++Delta[T[i].DFN], --Delta[T[i].DFN + T[i].Size];
    int Cur(0);
    for (unsigned i(1); i <= n; ++i) {if(Cur + Delta[i]) ++Ans; Cur += Delta[i];}
    Fr = TmpF; while (Fr) Fr->Ava = 0, Fr = Fr->Fa;
//    printf("%u %u\n", Fr - T, To - T);
    printf("%u\n", Ans);
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
