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
unsigned m, n, n2;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
unsigned char Nxt[155], Pre[155];
struct Node;
struct Edge {
  Node* To;
  unsigned char Val, Inv;
  Edge (Node* x, const unsigned char& y) {To = x, Val = y;}
  Edge (Node* x) {To = x, Val = 0;}
};
struct Node {
  vector<Edge> Ed;
  unsigned Dep;
}N[305], * Q[305];
inline char BFS() {
  for (Node* i(N + n2 + 1); i > N; --i) i->Dep = 0x3f3f3f3f; 
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->Ed) if((i.Val) && (i.To->Dep >= 0x3f3f3f3f))
      Q[++Tl] = i.To, i.To->Dep = Cur->Dep + 1;
  }
  return N[1].Dep < 0x3f3f3f3f;
}
inline char DFS(Node* x, unsigned char Come) {
//  printf("%u To %u\n", Come, x - N);
  if(x == N + 1) {--Ans; return 1;}
  unsigned char Res(Come);
  for (unsigned i(x->Ed.size() - 1); ~i; --i) 
    if((x->Ed[i].To->Dep == x->Dep + 1) && (x->Ed[i].Val)) {
      unsigned char Push(DFS(x->Ed[i].To, 1));
      if(!Push) { x->Ed[i].To->Dep = 0x3f3f3f3f; continue;}
      --(x->Ed[i].Val), --Res, ++(x->Ed[i].To->Ed[x->Ed[i].Inv].Val);
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
  n2 = ((Ans = n = RD()) << 1) + 1, m = RD();
  for (unsigned i(2); i <= n2; i += 2) {
//    printf("%u %u %u\n", i, N[0].Ed.size(), N[i].Ed.size());
    N->Ed.push_back(Edge(N + i, 1));
    N[i].Ed.push_back(Edge(N));
    N->Ed[(i >> 1) - 1].Inv = 0;
    N[i].Ed[0].Inv = (i >> 1) - 1;
  }
//  printf("Done\n");
  for (unsigned i(3); i <= n2; i += 2) {
//    printf("%u %u %u\n", i, N[1].Ed.size(), N[i].Ed.size());
    N[1].Ed.push_back(Edge(N + i));
    N[i].Ed.push_back(Edge(N + 1, 1));
    N[1].Ed[(i >> 1) - 1].Inv = 0;
    N[i].Ed[0].Inv = (i >> 1) - 1;
  }
//  printf("Done\n");
  for (unsigned i(1); i <= m; ++i) {
    A = RD() << 1, B = (RD() << 1) ^ 1;
    N[A].Ed.push_back(Edge(N + B, 1));
    N[B].Ed.push_back(Edge(N + A));
    N[A].Ed.back().Inv = N[B].Ed.size() - 1;
    N[B].Ed.back().Inv = N[A].Ed.size() - 1;
  }
  while (BFS()) DFS(N, 0xff);
  for (unsigned i(2); i <= n2; i += 2)
    for (auto j:N[i].Ed) if((j.To > N) && (!(j.Val))) {
      Nxt[i >> 1] = (j.To - N) >> 1, Pre[(j.To - N) >> 1] = 1; break;
    }
  for (unsigned char i(1), j; i <= n; ++i) {
    if(!Pre[i]) {
      j = i;
      while (j) printf("%u ", j), j = Nxt[j];
      putchar(0x0A);
    } 
  }
  printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}

