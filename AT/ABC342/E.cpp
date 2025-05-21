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
inline unsigned long long RD() {
  unsigned long long intmp(0);
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
struct Edge;
struct Node {
  vector<Edge*> To;
  unsigned long long Late;
  char Used;
} N[200005];
priority_queue<pair<unsigned long long, Node*> > Que;
struct Edge {
  Node* To;
  unsigned long long Start, Travel, Delta, Count;
  unsigned long long Find(unsigned long long x) {
    if (x >= Start) return Start - Travel;
    unsigned long long Tmp((Start - x + Delta - 1) / Delta);
    if (Tmp > Count) return 0;
    return Start - (Tmp * Delta) - Travel;
  }
} E[200005];
unsigned m, n;
unsigned long long A, B, C, D;
unsigned S, T;
unsigned Cnt(0);
//  inline void Clr() {}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD() - 1, D = RD(), S = RD(), T = RD();
    E[i].Start = A + (B * C) + D;
    E[i].Delta = B;
    E[i].Count = C;
    E[i].Travel = D;
    E[i].To = N + S;
    N[T].To.push_back(E + i);
  }
  for (unsigned i(1); i < n; ++i) N[i].Late = 0, N[i].Used = 0;
  N[n].Late = 0x3f3f3f3f3f3f3f3f;
  /*Dijkstra*/
  Que.push({0x3f3f3f3f3f3f3f3f, N + n});
  while (Que.size()) {
    Node* Cur(Que.top().second);
    Que.pop();
    if (Cur->Used) continue;
    Cur->Used = 1;
    for (auto i : Cur->To) {
      unsigned long long Tmp(i->Find(Cur->Late));
      if (Tmp > i->To->Late) i->To->Late = Tmp;
      Que.push({Tmp, i->To});
    }
  }
  for (unsigned i(1); i < n; ++i)
    if (N[i].Late)
      printf("%llu\n", N[i].Late);
    else
      printf("Unreachable\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}