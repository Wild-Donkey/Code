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
unsigned a[10005], m, n;
unsigned A, B, C, D, t;
unsigned Cnt(0), Ans(0), Tmp(0);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
  char Ava;
}E[1005], * CntE(E);
struct Node {
  Edge* Fst;
  unsigned Idg;
  char Vis;
}N[10005], * Q[100005];
inline char Judge () {
//  printf("Judge\n");
  unsigned Hd(0), Tl(0);
  for (unsigned i(1); i <= n; ++i) N[i].Idg = 0;
  for (unsigned i(1); i <= m; ++i) if(E[i].Ava) ++(E[i].To->Idg);
  for (unsigned i(1); i <= n; ++i) if(!N[i].Idg) Q[++Tl] = N + i;
//  for (unsigned i(1); i <= m; ++i) printf("%u %u\n", i, N[i].Idg);
  while (Hd ^ Tl) {
    Node* Cur(Q[++Hd]);
    Edge* Sid(Cur->Fst);
    while (Sid) {
      if(Sid->Ava) {
        if(!(--(Sid->To->Idg))) {
          Q[++Tl] = Sid->To;
        }
      }
      Sid = Sid->Nxt;
    }
  }
  return Tl < n;
}
inline void Add(Node *x, Node *y) {
  (++CntE)->Nxt = x->Fst;
  x->Fst = CntE;
  CntE->To = y;
}
inline void DFS(unsigned Dep) {
  if(Dep > m) {
    Ans += Judge();
    return;
  }
  DFS(Dep + 1);
  E[Dep].Ava = 1;
  DFS(Dep + 1);
  E[Dep].Ava = 0;
}
signed main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  if(m > 20) {
    printf("0\n");
    return 0;
  }
  for (unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    Add(N + A, N + B);
  }
  DFS(1);
  printf("%u\n", Ans);
  
//  }
  return Wild_Donkey;
}

