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
#define INF 0x3f3f3f3f3f3f3f3f
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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node {
  vector<pair<Node*, unsigned> > E;
  unsigned long long Dis, DisM;
  unsigned Mx, Mn, MxM, MnM;
  char No;
}N[200005];
inline void Dij() {
  priority_queue<pair<unsigned long long, Node*> > Q;
  for (unsigned i(2); i <= n; ++i) N[i].Dis = INF;
  N[1].Mx = 0, N[1].Mn = 0x3f3f3f3f;
  Q.push(make_pair(INF, N + 1));
  while (Q.size()) {
    Node* Cur(Q.top().second);
    Q.pop();
    if (Cur->No) continue;
    Cur->No = 1;
    for (auto i : Cur->E) {
      unsigned long long Dist(Cur->Dis + i.second);
      if (i.first->Dis > Dist)
        i.first->Dis = Dist, i.first->Mx = max(Cur->Mx, i.second), i.first->Mn = min(Cur->Mn, i.second), Q.push(make_pair(INF - Dist, i.first));
    }
  }
}
inline void Dij2() {
  priority_queue<pair<unsigned long long, Node*> > Q;
  for (unsigned i(2); i <= n; ++i) N[i].DisM = INF, N[i].No = 0;
  N[1].MxM = 0, N[1].MnM = 0x3f3f3f3f, N[1].No = 0;
  Q.push(make_pair(INF, N + 1));
  while (Q.size()) {
    Node* Cur(Q.top().second);
    Q.pop();
    if (Cur->No) continue;
    Cur->No = 1;
    unsigned long long Dist(Cur->Dis - Cur->Mn + Cur->Mx);
    if (Dist <= Cur->DisM) Cur->DisM = Dist, Cur->MnM = Cur->Mn, Cur->MxM = Cur->Mx;
    for (auto i : Cur->E) {
      A = min(Cur->Mn, i.second), B = max(Cur->Mx, i.second);
      C = min(Cur->MnM, i.second), D = max(Cur->MxM, i.second);
      unsigned long long DistP(Cur->Dis + i.second - B + A), DistA(Cur->DisM + i.second - D + C + Cur->MxM - Cur->MnM);
      if (DistP < DistA) {
        if (i.first->DisM > DistP)
          i.first->DisM = DistP, i.first->MxM = max(Cur->Mx, i.second), i.first->MnM = min(Cur->Mn, i.second), Q.push(make_pair(INF - DistP, i.first)), i.first->No = 0;
      }
      else {
        if (i.first->DisM > DistA)
          i.first->DisM = DistA, i.first->MxM = max(Cur->MxM, i.second), i.first->MnM = min(Cur->MnM, i.second), Q.push(make_pair(INF - DistA, i.first)), i.first->No = 0;
      }
    }
  }
}
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    N[A].E.push_back(make_pair(N + B, C));
    N[B].E.push_back(make_pair(N + A, C));
  }
  Dij(), Dij2();
  for (unsigned i(2); i <= n; ++i) printf("%llu ", N[i].DisM); putchar(0x0A);
  //  }
  // system("pause");
  return Wild_Donkey;
}
/*
6 6
1 2 10
2 4 1
1 3 5
3 4 5
4 5 11
5 6 0
*/