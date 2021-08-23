#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <vector>
#define Wild_Donkey 0
using namespace std;
inline unsigned RD() {
  unsigned intmp(0);
  char rdch(getchar());
  while (rdch < '0' || rdch > '9') rdch = getchar();
  while (rdch >= '0' && rdch <= '9') {
    intmp = (intmp << 3) + (intmp << 1) + rdch - '0';
    rdch = getchar();
  }
  return intmp;
}
inline int RDsg() {
  int rdtp(0), rdsg(1);
  char rdch(getchar());
  while ((rdch < '0' || rdch > '9') && (rdch != '-')) rdch = getchar();
  if (rdch == '-') {
    rdsg = -1;
    rdch = getchar();
  }
  while (rdch >= '0' && rdch <= '9') {
    rdtp = (rdtp << 3) + (rdtp << 1) + rdch - '0';
    rdch = getchar();
  }
  return rdtp * rdsg;
}
struct EdIn {
  unsigned Fr, To;
  inline const char operator < (const EdIn &x) const {
    return (this->Fr ^ x.Fr) ? (this->Fr < x.Fr) : (this->To < x.To);
  }
  inline const char operator == (const EdIn &x) const {
    return (this->Fr == x.Fr) && (this->To == x.To);
  }
}EI[200005];
struct Edge;
struct Node {
  char Ava;
  unsigned Dep, ID, OD, Bel;
  Edge *Fst;
}N[100005], *Q[100005];
struct Edge {
  Node *To;
  Edge *Nxt;
}E[200005];
unsigned m, n, Hd, Tl, A, B;
unsigned long long Cnt(0), Cnt0(0), Ans(0);
void DFS (Node *x) {
  
}
int main() {
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
//  t = RD();
//  for (register unsigned T(1); T <= t; ++T){
//  Clr();
  n = RD(), m = RD();
  for (register unsigned i(1); i <= m; ++i) {
    A = RD(), B = RD();
    ++(N[B].ID);
    E[i].Nxt = N[A].Fst;
    N[A].Fst = E + i;
    E[i].To = N + B;
  }
  register Node *Now;
  register Edge *Sid;
  while (Hd < Tl) {
    Now = Q[++Hd];
    Sid = Now->Fst;
//    printf("BFS %u [%u, %u]\n", Now - N, Hd, Tl);
    while (Sid) {
      if(Sid->To->ID >= 3) {
        Sid = Sid->Nxt;
        continue;
      }
      if(!(Sid->To->Dep)) {
        Sid->To->Dep = Now->Dep + 1;
//        printf("To %u ToID %u MyDp %u\n", Sid->To - N, Sid->To->ID, Now->Dep);
        if((Sid->To->ID == 1) && ((Now->Dep) == 1)) { // Extentable
          Q[++Tl] = Sid->To;
          Sid->To->Ava = 1;
        } else {
          Sid->To->Fst = NULL;
          if((Sid->To->ID == 2) && (Now->Dep == 1)) { // Available
            Sid->To->Ava = 1;
            Sid = Sid->Nxt;
            continue;
          }
          if((Sid->To->ID == 1) && (Now->Dep == 2)) { // Available
            Sid->To->Ava = 1;
            Sid = Sid->Nxt;
            continue;
          }
        }
      } else {// Visited
        Sid->To->Dep = Now->Dep + 1;
        Sid->To->Fst = NULL;
        if((Sid->To->ID == 2) && (Sid->To->Dep == 2)) { // Available
          Sid->To->Ava = 1;
          Sid = Sid->Nxt;
          continue;
        }
        Sid->To->Ava = 0;
      }
      Sid = Sid->Nxt;
    }
  }
  for (register unsigned i(1); i <= n; ++i) {
    if(!(N[i].ID)) {
      DFS(N + i);
    }
  }
//  for (register unsigned i(1); i <= n; ++i) {
//    printf("Node %u ID %u OD %u Ava %u Dep %u\n", i, N[i].ID, N[i].OD, N[i].Ava, N[i].Dep);
//  }
  printf("%llu\n", Ans);
//  }
  return Wild_Donkey;
}
/*
4 4
1 2
1 3
1 2
3 4

9 8
1 4
2 4
2 5
3 6
5 7
6 5
6 8
6 9

4 3
1 3
2 4
1 4
*/
