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
long long b[305][305], a[305][305];
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
struct Node {
  vector<pair<long long, Node*> > E;
  long long Dis;
  unsigned Cnt;
}N[605], *Que[360005], **Tl(Que), **Hd(Que);
inline void Clr() {
  for (unsigned i(n + m); i; --i) N[i].E.clear();
  n = RD(), m = RD();
  Tl = Hd = Que;
}
inline char SPFA() {
  for (unsigned i(n + m); i; --i) N[i].Cnt = 1, *(++Tl) = N + i, N[i].Dis = 0;
  while (Hd < Tl) {
    Node* Cur(*(++Hd));
    for (auto i:Cur->E) if(Cur->Dis + i.first < i.second->Dis) {
      if(++(i.second->Cnt) > n + m) return 1;
      *(++Tl) = i.second, i.second->Dis = Cur->Dis + i.first;
    }
  }
  return 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(2); i <= n; ++i) for (unsigned j(2); j <= m; ++j) b[i][j] = RD();
    a[1][1] = 500000;
    for (unsigned i(3); i <= n; i += 2) a[1][i] = 0;
    for (unsigned i(2); i <= n; i += 2) a[1][i] = 1000000;
    for (unsigned j(2); j <= m; j += 2) a[j][1] = 0;
    for (unsigned j(3); j <= m; j += 2) a[j][1] = 1000000;
    for (unsigned i(2); i <= n; ++i) for (unsigned j(2); j <= m; ++j)
      a[i][j] = b[i][j] - a[i - 1][j - 1] - a[i - 1][j] - a[i][j - 1];
    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) {
      A = i, B = n + j; if((i ^ j) & 1) swap(A, B);
      N[B].E.push_back({1000000 - a[i][j], N + A}), N[A].E.push_back({a[i][j], N + B});
    }
    if(SPFA()) {printf("NO\n"); continue;}
    printf("YES\n");
    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] += ((i ^ j) & 1) ? (-N[i].Dis) : N[i].Dis;
    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] += ((i ^ j) & 1) ? N[n + j].Dis : (-N[n + j].Dis);
    for (unsigned i(1); i <= n; ++i) {for (unsigned j(1); j <= m; ++j) printf("%lld ", a[i][j]); putchar(0x0A);}
  }
  return Wild_Donkey;
}

