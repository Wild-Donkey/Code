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
#define foreplay for
#define wild while
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
struct Node {
  unsigned Dep, Size;
  Node *Fat, *Heavy;
  vector<Node *> Sons;
  void DFS(Node *Fa) {
    Fat = Fa;
    for (auto i : Sons)
      if (i != Fa) { i->DFS(this); }
  }
  void Solve1(Node *Fa) {
    Dep = 0, Size = 1;
    for (auto i : Sons)
      if (i != Fa) {
        i->Solve1(this);
        Size += i->Size;
        Dep = max(Dep, i->Dep);
        if (i->Dep == Dep) Heavy = i;
      }
    if (!Heavy)
      Dep = 1;
    else
      Dep++;
  }
} N[200005];
unsigned m, n;
unsigned A, B, C, D, Mid, t;
unsigned Cnt(0), Ans(0), Tmp(0);
inline void Clr() {
  for (unsigned i(1); i <= n; ++i) N[i].Sons.clear();
  n = RD(), A = RD(), B = RD();
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T) {
    Clr();
    for (unsigned i(1); i < n; ++i) {
      C = RD(), D = RD();
      N[C].Sons.push_back(N + D);
      N[D].Sons.push_back(N + C);
    }
    N[A].DFS(NULL);
    vector<Node *> Rout;
    while (B != A) Rout.push_back(N + B), B = N[B].Fat - N;
    Rout.push_back(N + A);
    m = Rout.size();
    // printf("M %u\n", m);
    Mid = Rout[m >> 1] - N;
    N[Mid].Solve1(NULL);
    printf("%u\n", (m >> 1) + (n << 1) - 1 - N[Mid].Dep);
  }
  //  system("pause");
  return Wild_Donkey;
}