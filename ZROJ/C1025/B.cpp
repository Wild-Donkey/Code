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
unsigned long long Ans(0);
unsigned a[1000005], b[2000005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Magic{
  unsigned From, To, Cost;
}M[100005];
struct Node;
struct Edge {
  Node* To;
  unsigned Val;
};
struct Node {
  vector<Edge> To;
  unsigned Dis;
  char Vis;
}N[2000005];
priority_queue <pair<unsigned, unsigned> > Q;
inline void Dij () {
  for (unsigned i(1); i <= Cnt; ++i) N[i].Dis = 0x7f3f3f3f;
  Q.push(make_pair(0x7f3f3f3f, ((b[1] ^ 1) ? 2 : 1)));
  N[((b[1] ^ 1) ? 2 : 1)].Dis = 0;
  while (Q.size()) {
    Node* Cur(N + Q.top().second);
    Q.pop();
    if(Cur->Vis) continue;
    Cur->Vis = 1;
    for (auto i:Cur->To) {
      if(i.To->Dis > Cur->Dis + i.Val) {
        i.To->Dis = Cur->Dis + i.Val;
        Q.push(make_pair(0x7f3f3f3f - i.To->Dis, i.To - N));
      }
    }
  }
}
signed main() {
//  freopen("B.in", "r", stdin);
//  freopen("B.out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
  Cnt = n = RD(), m = RD(), b[++Cnt] = 1;
  for (unsigned i(1); i <= n; ++i) b[i] = a[i] = RD();
  for (unsigned i(1); i <= m; ++i) b[++Cnt] = M[i].From = RD(), b[++Cnt] = M[i].To = RD(), M[i].Cost = RD();
  sort(b + 1, b + Cnt + 1), Cnt = unique(b + 1, b + Cnt + 1) - b;
//  printf("%u\n", Cnt);
  for (unsigned i(1); i <= n; ++i) a[i] = lower_bound(b + 1, b + Cnt, a[i]) - b;
//  for (unsigned i(1); i <= Cnt; ++i) printf("b[%u] %u\n", i, b[i]);
  for (unsigned i(1); i <= m; ++i) {
//    printf("%u %u\n", A, B);
    A = lower_bound(b + 1, b + Cnt, M[i].From) - b;
    B = lower_bound(b + 1, b + Cnt, M[i].To) - b;
//    if(A <= B) continue;
//    if(!A) continue;
    N[B].To.push_back((Edge){N + A, M[i].Cost});
//    N[A].To.push_back((Edge){N + B, M[i].Cost});
  }
  --Cnt;
//  printf("b[%u] = %u\n", 1, )
  for (unsigned i((b[1] ^ 1) ? 2 : 1); i < Cnt; ++i) {
    N[i].To.push_back((Edge){N + i + 1, b[i + 1] - b[i]});
  }
  Dij();
  for (unsigned i(1); i <= n; ++i) Ans += N[a[i]].Dis;
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
2 0
1 10
*/
