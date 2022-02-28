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
unsigned a[505][505], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector <Node*> To;
  unsigned Low, DFSr, Bel;
}N[505], * Stack[505], ** STop(Stack);
inline void Tarjan(Node* x) {
  // printf("Tarjan %u\n", x - N);
  x->Low = x->DFSr = ++Cnt, *(++STop) = x;
  for (auto i : x->To) {
    if (!(i->DFSr)) Tarjan(i);
    if (!(i->Bel)) x->Low = min(x->Low, i->Low);
  }
  if (x->Low == x->DFSr) {
    ++Cnt;
    do (*STop)->Bel = Cnt; while ((*STop--) != x);
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= n; ++j) a[i][j] = RD();
  for (unsigned i(1); i <= n; ++i) for (unsigned j(1); a[i][j] ^ i; ++j) N[i].To.push_back(N + a[i][j]);
  for (unsigned i(1); i <= n; ++i) if (!(N[i].DFSr)) Tarjan(N + i);
  for (unsigned i(1); i <= n; ++i) {
    Ans = i;
    for (unsigned j(1); a[i][j] ^ i; ++j) if (N[a[i][j]].Bel == N[i].Bel) { Ans = a[i][j]; break; }
    printf("%u\n", Ans);
  }
  //  }
  //  system("pause");
  return Wild_Donkey;
}