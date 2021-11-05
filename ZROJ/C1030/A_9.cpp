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
unsigned m, n, NowD(0), Now(0);
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans[2005], Tmp(0);
struct Node {
  vector <Node*> To;
  Node* Fa;
  unsigned Dep;
}N[2005];
inline void DFS(unsigned Deep, unsigned NowD) {
//  printf("Deep %u Now %u Dis %u\n", Deep, Now, NowD);
  if(Deep > n) {++Ans[NowD]; return;}
  DFS(Deep + 1, NowD);
  Now |= (1 << (Deep - 1));
  unsigned TmpD(NowD);
  for (unsigned i(1), j(1); i <= Now; i <<= 1, ++j) if(i & Now) TmpD = max(TmpD, Dist[j][Deep]);
  DFS(Deep + 1, TmpD);
  Now ^= (1 << (Deep - 1));
  return;
}
inline void PreDFS(Node* x) {
//  printf("PD %u\n", x - N);
  for (auto i:x->To) if(i != x->Fa) i->Fa = x, i->Dep = x->Dep + 1, PreDFS(i);
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  for (unsigned i(1); i <= n; ++i) {
    N[i].Fa = NULL, N[i].Dep = 0, PreDFS(N + i);
    for (unsigned j(1); j <= n; ++j) Dist[i][j] = N[j].Dep;
  }
  DFS(1, 0), m = RD();
  for (unsigned i(1); i <= m; ++i) printf("%u\n", Ans[RD()]);
//  }
  return Wild_Donkey;
}
