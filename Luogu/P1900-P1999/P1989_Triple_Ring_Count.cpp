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
unsigned a[200005][2], m, n;
unsigned C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<Node*> E; 
  unsigned Dgr, Num;
  inline const char operator< (const Node& x) { return Dgr < x.Dgr; }
}N[100005], *List[100005], *A, *B;
//  inline void Clr() {}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) N[i].Num = i; 
  for (unsigned i(1); i <= m; ++i)
    ++(N[a[i][0] = RD()].Dgr), ++(N[a[i][1] = RD()].Dgr);
  sort(N + 1, N + n + 1);
  for (unsigned i(1); i <= n; ++i) List[N[i].Num] = N + i;
  for (unsigned i(1); i <= m; ++i) {
    A = List[a[i][0]], B = List[a[i][1]];
    if(A < B) A->E.push_back(B);
    else B->E.push_back(A); 
  }
  for (unsigned i(1); i <= n; ++i) sort(N[i].E.begin(), N[i].E.end());
  for (unsigned i(1); i <= n; ++i) {
    unsigned Bot(0);
    for (auto j:N[i].E) {
      unsigned Lim(N[i].E.size() - 1), l(Bot++); 
      for (auto k:j->E) {
        while (N[i].E[l] < k && l < Lim) ++l;
        if(N[i].E[l] == k) ++Ans;
      }
    }
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

