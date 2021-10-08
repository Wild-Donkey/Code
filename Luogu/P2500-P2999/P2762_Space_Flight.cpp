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
unsigned m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0);
unsigned Hd, Tl;
char RDch, Prt[110];
struct Node;
struct Edge {
  Node* To;
  unsigned Cap, Inv;
  Edge (Node* x, const unsigned &y) { To = x, Cap = y; }
  Edge (Node* x) { To = x, Cap = 0; }
};
struct Node {
  vector<Edge> Ed;
  unsigned Dep;
}N[110], *Q[110], * E, * I;
inline unsigned RD() {
  unsigned intmp(0);
  RDch = getchar(); 
  while (RDch < '0' || RDch > '9') RDch = getchar();
  while (RDch >= '0' && RDch <= '9')
    intmp = (intmp << 3) + (intmp << 1) + RDch - '0', RDch = getchar();
  return intmp;
}
inline char BFS() {
  Hd = Tl = 0, (Q[++Tl] = N)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (unsigned i(Cur->Ed.size() - 1); ~i; --i)
      if((Cur->Ed[i].Cap) && (Cur->Ed[i].To->Dep >= 0x3f3f3f3f))
        Q[++Tl] = Cur->Ed[i].To, Cur->Ed[i].To->Dep = Cur->Dep + 1;
  }
  return (N[1].Dep < 0x3f3f3f3f);
}
inline unsigned DFS(Node* x, const unsigned& Come) {
  if(x == N + 1) {Ans -= Come; return Come;}
  unsigned Cur(Come);
  for (unsigned i(x->Ed.size() - 1); ~i; --i)
    if((x->Ed[i].Cap) && (x->Ed[i].To->Dep == x->Dep + 1)) {
      unsigned Go(min(Cur, x->Ed[i].Cap)), Push(DFS(x->Ed[i].To, Go));
      if(Push < Go) x->Ed[i].To->Dep = 0x3f3f3f3f;
      Cur -= Push, x->Ed[i].Cap -= Push, x->Ed[i].To->Ed[x->Ed[i].Inv].Cap += Push;
      if (!Cur) break;
    }
  return Come - Cur;
}
inline void SufDFS (Node* x) {
  Prt[x - N] = 1; 
  for (auto i:x->Ed) if((i.Cap) && (!Prt[i.To - N])) SufDFS(i.To);
}
signed main() {
  E = N + 1, I = E + (m = RD()), n = RD();
  for (unsigned i(1); i <= m; ++i) {
    Ans += (A = RD());
    N[0].Ed.push_back(Edge(E + i, A)), E[i].Ed.push_back(Edge(N));
    N[0].Ed.back().Inv = E[i].Ed.size() - 1;
    E[i].Ed.back().Inv = N[0].Ed.size() - 1;
    while (RDch > 0x0d) {
      A = RD();
      E[i].Ed.push_back(Edge(I + A, 0x3f2f2f2f)), I[A].Ed.push_back(Edge(E + i));
      E[i].Ed.back().Inv = I[A].Ed.size() - 1;
      I[A].Ed.back().Inv = E[i].Ed.size() - 1;
    }
  }
  for (unsigned i(1); i <= n; ++i) {
    I[i].Ed.push_back(Edge(N + 1, RD())), N[1].Ed.push_back(Edge(I + i));
    I[i].Ed.back().Inv = N[1].Ed.size() - 1;
    N[1].Ed.back().Inv = I[i].Ed.size() - 1;
  }
  for (Node* i(I + n); i > N; --i) i->Dep = 0x3f3f3f3f;
  while (BFS()) {
    DFS(N, 0x3f3f3f3f);
    for (Node* i(I + n); i > N; --i) i->Dep = 0x3f3f3f3f;
  }
  SufDFS(N);
  for (unsigned i(1); i <= m; ++i) if(Prt[i + 1]) {printf("%u ", i);}
  putchar(0x0A);
  for (unsigned i(1); i <= n; ++i) if(Prt[1 + m + i]) printf("%u ", i);
  putchar(0x0A);
  printf("%u\n", Ans);
  return Wild_Donkey;
}
