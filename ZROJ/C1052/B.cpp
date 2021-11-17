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
#define INFi 0x3f3f3f3f3f3f3f3f
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
//  inline void Clr() {}
struct Node; 
struct Edge {
  Node* To;
  unsigned Len, Peri, L, R;
  inline unsigned long long Calc(unsigned long long x) {
    unsigned long long Now(x % Peri), Lef(Len);
    x -= Now;
    if(Now > R) x += Peri, Now = 0;
    if(Now < L) Now = L;
    if((L <= Now) && (Now <= R)) {
      if(Lef > R - Now + 1) Lef -= R - Now + 1, Now = R + 1;
      else return x + Now + Lef;
    }
    Now += (Lef / (R - L + 1)) * Peri, Lef %= (R - L + 1);
    if(Lef) Now += Peri - R + L - 1, Now += Lef;
    return x + Now;
  }
}E[2000005];
struct Node {
  vector<Edge*> To;
  unsigned long long Dist;
  char Vis;
}N[500005];
inline void Dij() {
  for (unsigned i(2); i <= n; ++i) N[i].Dist = INFi;
  priority_queue<pair<unsigned long long, Node*> > Q;
  N[1].Dist = 0, Q.push(make_pair(INFi, N + 1));
  while (!(Q.empty())) {
    Node* Cur(Q.top().second);
    Q.pop();
    if(Cur->Vis) continue;
    Cur->Vis = 1;
    for (auto i:Cur->To) {
      unsigned long long Des(i->Calc(Cur->Dist));
      if(i->To->Dist >= Des)
        i->To->Dist = Des, Q.push(make_pair(INFi - i->To->Dist, i->To));
    }
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    E[i << 1].To = N + (A = RD());
    E[(i << 1) - 1].To = N + (B = RD());
    E[i << 1].Len = E[(i << 1) - 1].Len = RD();
    E[i << 1].Peri = E[(i << 1) - 1].Peri = RD();
    E[i << 1].L = E[(i << 1) - 1].L = RD();
    E[i << 1].R = E[(i << 1) - 1].R = RD();
    N[A].To.push_back(E + (i << 1) - 1);
    N[B].To.push_back(E + (i << 1));
  }
  Dij();
  for (unsigned i(1); i <= n; ++i) printf("%llu\n", N[i].Dist);
//  }
  return Wild_Donkey;
}
/*
5 5
1 2 893602 11 1 5
3 1 641088 17 8 8
4 1 823893 8 6 7
5 1 162402 12 1 11
2 3 161172 15 10 13
*/
