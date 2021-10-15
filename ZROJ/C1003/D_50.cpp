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
unsigned Cnt(0), Ans(0x3f3f3f3f), Tmp(0);
struct Node {
  vector<Node*> E;
  Node* Fa;
  unsigned Size;
  char Vis;
  void PreDFS() {
    Size = 1;
    for (auto i:E) if(i != Fa) i->Fa = this, i->PreDFS(), Size += i->Size;
  }
  void SonDFS() {
    Vis = 1;
    for (auto i:E) if(i != Fa) i->SonDFS();
  }
}N[200005], *Now;
inline void Udt (unsigned x, unsigned y) {
  unsigned z(n - x - y), xx(min(min(x, y), z)), yy(max(max(x, y), z));
  Ans = min(Ans, yy - xx);
}
signed main() {
  freopen("D.in", "r", stdin);
  freopen("D.ans", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD();
  for (unsigned i(1); i < n; ++i) {
    A = RD(), B = RD();
    N[A].E.push_back(N + B);
    N[B].E.push_back(N + A);
  }
  N[1].PreDFS();
  for (unsigned i(1); i <= n; ++i) {
    for (unsigned i(1); i <= n; ++i) N[i].Vis = 0;
    A = N[i].Size, N[i].SonDFS();
    Now = N[i].Fa;
    while (Now) Udt(A, Now->Size - A), Now->Vis = 1, Now = Now->Fa;
    for (unsigned i(1); i <= n; ++i) {
      if(!(N[i].Vis)) Udt(A, N[i].Size);
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

