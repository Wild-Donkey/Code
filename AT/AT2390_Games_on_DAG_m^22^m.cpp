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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
pair<unsigned, unsigned> Li[205];
char Con[20][20];
struct Node {
  vector<pair<Node*, char> > E;
}N[20];
inline void Check() {
  for (unsigned i(n); i; --i) {
    for (unsigned j(n); j; --j) {
      Con[i][j] = 0;
      for (auto iT : N[i].E) if (iT.second)
        Con[i][j] |= (1 ^ Con[iT.first - N][j]);
      for (auto jT : N[j].E) if (jT.second)
        Con[i][j] |= (1 ^ Con[i][jT.first - N]);
    }
  }
  // for (unsigned i(1); i <= n; ++i) {
  //   for (unsigned j(1); j <= n; ++j) putchar(Con[i][j] ? '1' : '0');
  //   putchar(0x0A);
  // }
  Ans += Con[1][2];
}
inline void DFS(unsigned Dep) {
  if (Dep > m) return Check();
  DFS(Dep + 1);
  N[Li[Dep].first].E[Li[Dep].second].second = 1;
  DFS(Dep + 1);
  N[Li[Dep].first].E[Li[Dep].second].second = 0;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), N[A].E.push_back(make_pair(N + RD(), 0));
    Li[i] = make_pair(A, N[A].E.size() - 1);
  }
  // for (unsigned i(1); i <= n; ++i) for (unsigned j(N[i].E.size() - 1); ~j; --j)
  //   N[i].E[j].second = 1;
  // Check();
  DFS(1);
  printf("%u\n", Ans);
  //  }
  system("pause");
  return Wild_Donkey;
}
/*
6 6
1 5
2 3
3 4
2 6
3 6
4 6
36
*/