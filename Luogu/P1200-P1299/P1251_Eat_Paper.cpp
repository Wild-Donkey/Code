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
#define INF 20000000000
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0', rdch = getchar();
  return intmp;
}
long long a[4005]; 
long long QC, New, SC, Ans(0);
unsigned QD, SD, n, n2;
unsigned A, B, C, D, t;
unsigned Cnt(0);
struct Node;
struct Edge {
  Node* To;
  long long Val, Cap;
  unsigned Inv;
};
struct Node {
  vector<Edge> E;
  long long Dis;
  char InQ;
}N[4005], * Q[100005];
inline void Link(Node* x, Node* y, long long V) {
  x->E.push_back((Edge){y, V, INF, 0});
  y->E.push_back((Edge){x, -V, 0, 0});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
}
inline char SPFA () {
  for (Node* i(N + n2); i > N; --i) i->Dis = INF, i->InQ = 0; 
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dis = 0, N->InQ = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    Cur->InQ = 0;
//    printf("BFS %u Dis %lld\n", Cur - N, Cur->Dis);
    for (auto i:Cur->E) if((i.Cap) && (i.To->Dis > Cur->Dis + i.Val)) {
      i.To->Dis = Cur->Dis + i.Val;
      if(!(i.To->InQ)) Q[++Tl] = i.To, i.To->InQ = 1;
    }
  }
  return N[1].Dis < INF;
}
inline long long DFS (Node* x, long long Come) {
//  printf("DFS %u Come %lld Dis %lld\n", x - N, Come, x->Dis);
  x->InQ = 1;
  if(x == N + 1) {Ans += Come * x->Dis;return Come;}
  long long Res(Come);
  for (unsigned i(x->E.size() - 1); ~i; --i) 
    if((x->E[i].Cap) && (x->E[i].To->Dis == x->Dis + x->E[i].Val) && (!(x->E[i].To->InQ))) {
//      printf("%u Len %lld\n", i, x->E[i].Val);
      long long Go(min(x->E[i].Cap, Res)), Push(DFS(x->E[i].To, Go));
      x->E[i].To->InQ = 0;
      if(Go > Push) x->E[i].To->Dis = INF;
      Res -= Push, x->E[i].Cap -= Push, x->E[i].To->E[x->E[i].Inv].Cap += Push;
      if(!Res) break; 
    }
  return Come - Res;
}
signed main() {
//  freopen("P1251_2.in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n2 = ((n = RD()) << 1) + 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  New = RD(), QD = RD(), QC = RD(), SD = RD(), SC = RD();
  for (unsigned i(2); i <= n2; i += 2) {
    N->E.push_back((Edge){N + i, 0, a[i >> 1], 0});
    N[i].E.push_back((Edge){N, 0, 0, (i >> 1) - 1});
  }
  for (unsigned i(3); i <= n2; i += 2) {
    N->E.push_back((Edge){N + i, New, INF, 0});
    N[i].E.push_back((Edge){N, -New, 0, n + (i >> 1) - 1});
  }
  for (unsigned i(3); i <= n2; i += 2) {
    N[1].E.push_back((Edge){N + i, 0, 0, 1});
    N[i].E.push_back((Edge){N + 1, 0, a[i >> 1], (i >> 1) - 1});
  }
  for (unsigned i(4); i <= n2; i += 2) Link(N + i - 2, N + i, 0);
//  printf("Link %u %u\n", n2 - (((QD) << 1) ^ 1), )
  if(QD < n) for (unsigned i(n2 - ((QD) << 1) ^ 1); i >= 2; i -= 2) Link(N + i, N + i + (QD << 1) + 1, QC);
  if(SD < n) for (unsigned i(n2 - ((SD) << 1) ^ 1); i >= 2; i -= 2) Link(N + i, N + i + (SD << 1) + 1, SC);
  while (SPFA()) DFS(N, INF);
  printf("%lld\n", Ans);
//  } 
  return Wild_Donkey;
}
