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
#define INF 2147483647
#define IINF 0x3f3f3f3f3f3f3f3f
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
long long Ans(0);
unsigned a[1005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Tmp(0);
struct Node;
struct Edge {
  Node* To;
  int Val; 
  unsigned Cap, Inv;
};
struct Node {
  vector<Edge> E;
  long long Dis;
  char InQ;
}N[1005], * Q[1000005];
inline void Link (Node* x, Node* y, const int& z) {
  x->E.push_back((Edge){y, z, INF, 0});
  y->E.push_back((Edge){x, -z, 0, 0});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
};
inline char SPFA () {
//  printf("Ans %lld\n", Ans);
  unsigned Hd(0), Tl(0);
  for (Node* i(N + n + 2); i > N; --i) i->Dis = IINF, i->InQ = 0;
  (Q[++Tl] = N)->Dis = 0;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
//    printf("Cur %u Dis %lld\n", Cur - N, Cur->Dis);
    for (auto i:Cur->E) if((i.To->Dis > Cur->Dis + i.Val) && (i.Cap)) {
      i.To->Dis = Cur->Dis + i.Val;
      if(!(i.To->InQ)) i.To->InQ = 1, Q[++Tl] = i.To;
    }
    Cur->InQ = 0;
  }
  return N[n + 2].Dis < IINF;
}
inline unsigned DFS(Node* x, unsigned Come) {
//  printf("DFS %u %u Dis %lld\n", x - N, Come, x->Dis);
  x->InQ = 1;
  if(x == N + n + 2) {Ans += x->Dis * Come; return Come;}
  unsigned Res(Come);
  for (unsigned i(x->E.size() - 1); ~i; --i)
    if((x->E[i].Cap) && (x->E[i].To->Dis == x->Dis + x->E[i].Val) && (!(x->E[i].To->InQ))) {
      unsigned Go(min(Res, x->E[i].Cap)), Push(DFS(x->E[i].To, Go));
      x->E[i].To->InQ = 0;
      if(Go ^ Push) x->E[i].To->Dis = IINF;
      Res -= Push, x->E[i].Cap -= Push, x->E[i].To->E[x->E[i].Inv].Cap += Push;
      if(!Res) break;
    }
  return Come - Res;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  for (Node* i(N + n + 2); i > N; --i) i->E.push_back((Edge){i - 1, 0, 0, 1});
  for (Node* i(N + n + 1); i >= N; --i) i->E.push_back((Edge){i + 1, 0, INF - a[i - N], 0});
  N[1].E[0].Inv = 0;
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD(), C = RD();
    Link(N + A, N + B + 1, C);
  }
  while (SPFA()) DFS(N, INF);
  printf("%lld\n", Ans);
//  }
  return Wild_Donkey;
}

