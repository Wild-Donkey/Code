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
unsigned m, n, mn;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Edge {
  Node* To;
  unsigned Cap, Inv;
};
struct Node {
  vector<Edge> E;
  unsigned Dep;
}N[10005], * Q[10005];
inline char BFS() {
  for (Node* i(N + mn); i > N; --i) i->Dep = 0x3f3f3f3f;
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->E) if((i.Cap) && (i.To->Dep >= 0x3f3f3f3f))
      i.To->Dep = Cur->Dep + 1, Q[++Tl] = i.To;
  }
  return N[1].Dep < 0x3f3f3f3f;
}
inline unsigned DFS(Node* x, unsigned Come) {
  if(x == N + 1) {Ans -= Come; return Come;}
  unsigned Res(Come);
  for (unsigned i(x->E.size() - 1); ~i; --i) 
    if((x->E[i].Cap) && (x->E[i].To->Dep == x->Dep + 1)) {
      unsigned Go(min(x->E[i].Cap, Res)), Push(DFS(x->E[i].To, Go));
      if(Push < Go) {x->E[i].To->Dep = 0x3f3f3f3f;}
      Res -= Push, x->E[i].Cap -= Push, x->E[i].To->E[x->E[i].Inv].Cap += Push;
    }
  return Come - Res;
}
inline void Link(Node* x, Node* y) {
  x->E.push_back((Edge){y, 0x3f3f3f3f, 0});
  y->E.push_back((Edge){x, 0, 0});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
  return;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD(), mn = (n * m) + 1;
  for (unsigned i(1), k(2); i <= n; ++i) {
    for (unsigned j(1); j <= m; ++j, ++k) {
      Ans += (A = RD());
      if((i ^ j) & 1) {
        N->E.push_back((Edge){N + k, A, 0});
        N[k].E.push_back((Edge){N, 0, 0});
        N[k].E[0].Inv = (k >> 1) - 1;
      } else {
        N[1].E.push_back((Edge){N + k, 0, 0});
        N[k].E.push_back((Edge){N + 1, A, 0});
        N[k].E[0].Inv = (k >> 1) - 1;
      }
    }
  }
  for (unsigned i(2), j; i <= mn; ++i)
    if (((((i - 2) / m) + 1) ^ (((i - 2) % m) + 1)) & 1) {
      if ((i - 2) % m) Link(N + i, N + i - 1);
      if ((i - 1) % m) Link(N + i, N + i + 1);
      if (i > m + 1) Link(N + i, N + i - m);
      if (i + m <= mn) Link(N + i, N + i + m);
    }
  while (BFS()) DFS(N, 0x3f3f3f3f);
  printf("%u\n", Ans);
  return Wild_Donkey;
}
