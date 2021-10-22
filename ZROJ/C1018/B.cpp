#include <algorithm>
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
  vector<Node*> To;
  char Col;
}N[1000005];
inline void DFS (Node* x) {
//  printf("DFS %u Col %u\n", x - N, x->Col);
  for (auto i:x->To) if(!i->Col)i->Col = x->Col ^ 3, DFS(i);
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD();
  for (unsigned i(0); i < n; ++i) {
    N[i << 1].To.push_back(N + ((i << 1) ^ 1));
    N[(i << 1) ^ 1].To.push_back(N + (i << 1));
  }
  for (unsigned i(1); i <= n; ++i) {
    A = RD() - 1, B = RD() - 1;
    N[A].To.push_back(N + B);
    N[B].To.push_back(N + A);
  }
  for (unsigned i((n << 1) - 1); ~i; --i) if(!(N[i].Col)) N[i].Col = 1, DFS(N + i);
  for (unsigned i(0); i < n; ++i) putchar((N[i << 1].Col & 1) ? 'X' : 'Y'), putchar((N[(i << 1) ^ 1].Col & 1) ? 'X' : 'Y');
  //  }
  //  system("pause");
  return Wild_Donkey;
}

