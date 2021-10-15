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
#define INFi 200000
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
unsigned m, n, m3n1;
unsigned A, B, C, D, t;
unsigned Cnt(0);
unsigned Gap[805000];
struct Node;
struct Edge {
  Node* To;
  unsigned Cap, Inv;
};
struct Node {
  vector<Edge> E;
  unsigned Dep, Hav;
}N[800005], * Q[800005], * Peo, * Suf, * Pre, * Cha(N + 1);
struct Pntr {
  Node* Pn;
  const inline char operator<(const Pntr& x) const {Pn->Dep < x.Pn->Dep;}
};
priority_queue<Pntr> Que;
inline void Link(Node* x, Node* y) {
  x->E.push_back((Edge){y, INFi, 0});
  y->E.push_back((Edge){x, 0, 0});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
}
inline void BFS() {
  for (Node* i(Peo + n); i >= N; --i) i->Dep = 0x3f3f3f3f;
  unsigned Hd(0), Tl(0);
  ++Gap[(Q[++Tl] = N + 1)->Dep = 0];
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->E) if((i.To->E[i.Inv].Cap) && (i.To->Dep >= 0x3f3f3f3f)) 
      ++Gap[i.To->Dep = Cur->Dep + 1], Q[++Tl] = i.To;
  }
  --Gap[N->Dep], ++Gap[N->Dep = n];
}
inline void Ps () {
  for (unsigned i(N->E.size() - 1); ~i; --i)
    N->E[i].Cap = 0, N->E[i].To->Hav = 1, N->E[i].To->E[0].Cap = 1, Que.push((Pntr){N->E[i].To});
  while (Que.size()) {
    Node* x(Que.top().Pn);
    unsigned Lowest(0x3f3f3f3f);
    for (unsigned i(x->E.size() - 1); ~i; --i) if(x->E[i].Cap) 
      if(x->E[i].To->Dep > x->Dep) {
        unsigned Go(min(x->Hav, x->E[i].Cap));
        x->Hav -= Go, x->E[i].Cap -= Go;
        x->E[i].To->E[x->E[i].Inv].Cap += Go, x->E[i].To->Hav += Go;
        if((x->E[i].To != N) && (x->E[i].To != N + 1)) Que.push((Pntr){x->E[i].To});
        if(!(x->Hav)) break;
      } else Lowest = min(Lowest, x->E[i].To->Dep);
    if(x->Hav) {
      if(!(--Gap[x->Dep])) {
        for (Node* i(N + m3n1); i > N; --i)
          if(i->Dep > x->Dep) i->Dep = n + 1;
      }
      x->Dep = Lowest + 1;
    } else Que.pop();
    ++Gap[x->Dep];
  }
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), Pre = N + (m = RD()) + 1, Suf = Pre + m, Peo = Suf + m;
  m3n1 = (m << 1) + m + n;
  for (unsigned i(1); i <= m; ++i) {
    Cha[i].E.push_back((Edge){N + 1, 1, i - 1});
    N[1].E.push_back((Edge){Cha + i, 0, 0});
    Cha[i].E.push_back((Edge){Pre + i, 0, 0});
    Pre[i].E.push_back((Edge){Cha + i, 1, 1});
    Cha[i].E.push_back((Edge){Suf + i, 0, 0});
    Suf[i].E.push_back((Edge){Cha + i, 1, 2});
  }
  for (unsigned i(1); i <= n; ++i) {
    Peo[i].E.push_back((Edge){N, 0, i - 1});
    N->E.push_back((Edge){Peo + i, 1, 0});
  }
  for (unsigned i(2); i <= m; ++i) Link(Pre + i, Pre + i - 1);
  for (unsigned i(1); i < m; ++i) Link(Suf + i, Suf + i + 1);
  for (unsigned i(1); i <= n; ++i) {
    A = RD(), B = RD();
    if(A) Link(Peo + i, Pre + A);
    if(B <= m) Link(Peo + i, Suf + B);
  }
  BFS(), Ps();
//  for (Node* i(Peo + n); i >= N; --i) printf("%u Dep %u\n", i - N, i->Dep);
  printf("%u\n", N->Hav);
  return Wild_Donkey;
}

