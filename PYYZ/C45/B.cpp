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
int a[1005][1005];
unsigned c[205];
unsigned char b[1005][1005];
int C;
unsigned m, n, P;
unsigned A, B, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Edge {
  Node* To;
  unsigned Inv, Con;
};
struct Node {
  vector<Edge> E;
  unsigned Frm, Dep;
}N[205];
inline void Clr() {
  memset(b, 0, sizeof(b));
  for (Node* i(N + P + 1); i >= N; --i) i->E.clear();
  n = RD(), m = RD(), P = RD(), Ans = Tmp = 0;
}
inline void Link (Node* x, Node* y, unsigned Val) {
  x->E.push_back({y, y->E.size(), Val});
  y->E.push_back({x, x->E.size() - 1, 0});
}
inline void Judge (int z, unsigned x, unsigned y) {
  if(!x) return;
  unsigned TMul(c[x] * c[y]);
  Link(N + x, N + y, TMul), Link(N + y, N + x, TMul), Ans += TMul;
}
inline char BFS() {
  Node* Que[P + 2], **Hd(Que), **Tl(Que);
  for (Node* i(N + P + 1); i >= N; --i) i->Frm = 0, i->Dep = 0x3f3f3f3f;
  (*(++Hd) = N)->Dep = 0;
  while (Tl != Hd) {
    Node* Cur(*(++Tl));
    for (auto i:Cur->E) if((i.Con) && (i.To->Dep >= 0x3f3f3f3f)) 
      (*(++Hd) = i.To)->Dep = Cur->Dep + 1;
  }
  return N[P + 1].Dep < 0x3f3f3f3f;
}
inline unsigned DFS(Node* x, unsigned Come) {
  if(x == N + P + 1) return Come;
  unsigned Gone(0);
  for (unsigned &i(x->Frm); Come && (i < x->E.size()); ++i) if(x->E[i].Con && (x->E[i].To->Dep > x->Dep)) {
    unsigned Succ(DFS(x->E[i].To, min(Come, x->E[i].Con)));
    Come -= Succ, x->E[i].Con -= Succ, x->E[i].To->E[x->E[i].Inv].Con += Succ, Gone += Succ;
  }
  return Gone;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
  t = RD();
  for (unsigned T(1); T <= t; ++T){
    Clr();
    for (unsigned i(1); i <= n; ++i) for (unsigned j(1); j <= m; ++j) a[i][j] = RDsg();
    for (unsigned i(1); i <= P; ++i) {
      A = RD(), B = RD(), b[A][B] = i, C = a[A][B] * (int)(c[i] = RD());
      if(a[A][B] > 0) Link(N, N + i, C), Ans += C;
      else Link(N + i, N + P + 1, -C), Ans += -C;
      C = a[A][B];
      Judge(a[A - 1][B], b[A - 1][B], i), Judge(a[A][B - 1], b[A][B - 1], i);
      Judge(a[A + 1][B], b[A + 1][B], i), Judge(a[A][B + 1], b[A][B + 1], i);
    }
    while (BFS()) Tmp += DFS(N, 0x3f3f3f3f);
    printf("%u\n", Ans - (Tmp << 1));
  }
//  printf("%u %u\n", Ans, Tmp);
  return Wild_Donkey;
}
