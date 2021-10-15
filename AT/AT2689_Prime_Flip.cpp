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
unsigned a[205], b[205], m, n;
unsigned A, B, C, D, t;
unsigned Ans(0), Tmp(0);
unsigned Prime[1000005], Cnt(0);
bitset <10000005> IsntP;
struct Node;
struct Edge {
  Node* To;
  unsigned Inv;
  char Cap;
};
struct Node {
  vector<Edge> E;
  unsigned Dep;
}N[205], * Q[205];
inline void GetPrime () {
  for (unsigned i(2); i <= 10000000; ++i) {
    if(!(IsntP[i])) Prime[++Cnt] = i;
    for (unsigned j(1); Prime[j] * i <= 10000000; ++j) {
      IsntP[Prime[j] * i] = 1;
      if(!(i % Prime[j])) break;
    }
  }
}
inline void Link(Node* x, Node* y) {
  x->E.push_back((Edge){y, 0, 1});
  y->E.push_back((Edge){x, 0, 0});
  x->E.back().Inv = y->E.size() - 1;
  y->E.back().Inv = x->E.size() - 1;
}
inline char BFS () {
  for (Node* i(N + Cnt + 1); i > N; --i) i->Dep = 0x3f3f3f3f;
  unsigned Hd(0), Tl(0);
  (Q[++Tl] = N)->Dep = 1;
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    for (auto i:Cur->E) if((i.Cap) && (i.To->Dep >= 0x3f3f3f3f)) 
      Q[++Tl] = i.To, i.To->Dep = Cur->Dep + 1;
  }
  return N[1].Dep < 0x3f3f3f3f;
}
inline unsigned DFS(Node* x, unsigned Come) {
  if(x == N + 1) {++Ans; return 1;}
  unsigned Res(Come);
  for (unsigned i(x->E.size() - 1); ~i; --i) 
    if((x->E[i].Cap) && (x->E[i].To->Dep == x->Dep + 1)) {
      char Push(DFS(x->E[i].To, 1));
      if(!Push) {x->E[i].To->Dep = 0x3f3f3f3f; continue;}
      --Res, --(x->E[i].Cap), ++(x->E[i].To->E[x->E[i].Inv].Cap);
      if(!Res) break;
    }
  return Come - Res;
}
signed main() {
  GetPrime();
  n = RD(), Cnt = 0, IsntP[0] = IsntP[1] = 1;
  for (unsigned i(1); i <= n; ++i) a[i] = RD();
  sort(a + 1, a + n + 1);
  for (unsigned i(1), j(1); i <= n;) {
    while (a[j] + 1 == a[j + 1]) ++j;
    b[++Cnt] = a[i], b[++Cnt] = a[j] + 1, i = j + 1, j = i;
  }
  for (unsigned i(1); i <= Cnt; ++i) {
    if(b[i] & 1) {
      Link(N, N + i + 1), ++A;
      for (unsigned j(1); j <= Cnt; ++j) if(!(b[j] & 1))
        if(!IsntP[max(b[j], b[i]) - min(b[j], b[i])]) Link(N + i + 1, N + j + 1);
    } else Link(N + i + 1, N + 1), ++B;
  }
  while (BFS()) DFS(N, 0x3f3f);
  A -= Ans, B -= Ans, Ans += A + B + (A & 1), printf("%u\n", Ans);
//  }
  return Wild_Donkey;
}
/*
5
5 6 7 9 10
*/
