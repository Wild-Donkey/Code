#include <algorithm>
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
int Deg[25];
char Ava[50], Flg(0);
struct Node;
struct Edge {
  Node* To;
  Edge* Nxt;
}E[4000005];
struct Node {
  Edge* Fst;
  Node* Fa;
  unsigned ToN;
}N[2000005];
inline char Judge () {
  memset(Deg, 0, sizeof(Deg));
  for (unsigned i(1); i <= m; ++i) 
    if(Ava[i]) {
      ++Deg[E[i << 1].To - N];
      ++Deg[E[(i << 1) ^ 1].To - N];
    } else {
      --Deg[E[i << 1].To - N];
      --Deg[E[(i << 1) ^ 1].To - N];
    }
  for (unsigned i(1); i <= n; ++i)
    if((Deg[i] < -1) || (Deg[i] > 1)) return 0;
  for (unsigned i(1); i <= m; ++i) printf("%u ", Ava[i]);
  putchar(0x0A);
  return 1;
}
inline void DFS(unsigned Dep) {
  if(Dep > m) {
    if(Judge()) Flg = 1;
    return;
  }
  DFS(Dep + 1);
  if(Flg) return;
  Ava[Dep] = 1;
  DFS(Dep + 1);
  Ava[Dep] = 0; 
}
inline void PreDFS (Node* x, char FC) {
  Edge* Sid(x->Fst);
  while (Sid) {
    if(Sid->To != x->Fa)
      FC ^= 1, Sid->To->Fa = x, Ava[(Sid - E) >> 1] = FC, PreDFS(Sid->To, FC);
    Sid = Sid->Nxt;
  }
  return;
}
signed main() {
  //  freopen(".in", "r", stdin);
  //  freopen(".out", "w", stdout);
  //  t = RD();
  //  for (unsigned T(1); T <= t; ++T){
  //  Clr();
  n = RD(), m = RD();
  if(m <= 20) {
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      E[i << 1].Nxt = N[A].Fst;
      E[(i << 1) ^ 1].Nxt = N[B].Fst; 
      E[i << 1].To = N + B;
      E[(i << 1) ^ 1].To = N + A;
      N[A].Fst = E + (i << 1);
      N[B].Fst = E + ((i << 1) ^ 1);
    }
    DFS(1);
    if(!Flg) printf("-1\n");
    return 0;
  }
  if(m == n - 1) {
    for (unsigned i(1); i <= m; ++i) {
      A = RD(), B = RD();
      E[i << 1].Nxt = N[A].Fst;
      E[(i << 1) ^ 1].Nxt = N[B].Fst; 
      E[i << 1].To = N + B;
      E[(i << 1) ^ 1].To = N + A;
      N[A].Fst = E + (i << 1);
      N[B].Fst = E + ((i << 1) ^ 1);
    }
    PreDFS(N + 1, 1);
    for (unsigned i(1); i <= m; ++i) printf("%u ", Ava[i]);
    putchar(0x0A);
    return 0;
  }
  printf("-1\n");
  //  }
  //  system("pause");
  return Wild_Donkey;
}
/*
8 7
1 2
1 4
2 3
2 8
4 5
4 6
4 7
*/
